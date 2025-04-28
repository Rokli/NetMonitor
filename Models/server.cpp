#include "server.h"
#include <iostream>
#include <unistd.h>
#include <cstring>

Server::Server(int port)
    : port_(port), serverSocket_(-1), running_(false) {}


void Server::start()
{
    serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket_ == -1)
    {
        qWarning() << "Failed to create socket.\n";
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port_);

    if (bind(serverSocket_, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        qWarning() << "Bind failed.\n";
        return;
    }

    if (listen(serverSocket_, 5) < 0)
    {
        qWarning() << "Listen failed.\n";
        return;
    }

    running_ = true;
    qWarning() << "Server started on port " << port_ << ". Waiting for connections...\n";

    std::thread serverThread(&Server::run, this);
    serverThread.detach();
}

void Server::stop()
{
    if (running_)
    {
        running_ = false;
        close(serverSocket_);
        for (auto& thread : clientThreads_)
        {
            if (thread.joinable())
                thread.join();
        }
        qWarning() << "Server stopped.\n";
    }
}

void Server::run()
{
    while (running_)
    {
        sockaddr_in clientAddr{};
        socklen_t clientSize = sizeof(clientAddr);

        int clientSocket = accept(serverSocket_, (struct sockaddr*)&clientAddr, &clientSize);
        if (clientSocket < 0)
        {
            if (running_)
                qWarning() << "Accept failed.\n";
            continue;
        }

        clientThreads_.emplace_back(&Server::handleClient, this, clientSocket);
    }
}

void Server::handleClient(int clientSocket)
{
    char buffer[1024];
    while (true)
    {
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer) - 1);

        if (bytesRead <= 0)
            break;

        std::string message(buffer);
        qWarning() << "Received: " << message << "\n";
    }
    close(clientSocket);
}
