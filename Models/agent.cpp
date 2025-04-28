#include "agent.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

Agent::Agent(const std::string& serverIp, int serverPort)
    : serverIp_(serverIp), serverPort_(serverPort), clientSocket_(-1)
{
}

void Agent::connectToServer()
{
    clientSocket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket_ == -1)
    {
        qWarning() << "Сокет не получилось создать\n";
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort_);

    if (inet_pton(AF_INET, serverIp_.c_str(), &serverAddr.sin_addr) <= 0)
    {
        qWarning() << "Неправильный айпи\n";
        return;
    }

    if (connect(clientSocket_, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        qWarning() << "Не получилось подключиться к серверу.\n";
        return;
    }

    std::cout << "Подключился к серверу:" << serverIp_ << ":" << serverPort_ << "\n";
}

void Agent::sendData(const std::string& data)
{
    if (clientSocket_ == -1)
    {
        qWarning() << "Нет активный подключений.\n";
        return;
    }

    send(clientSocket_, data.c_str(), data.size(), 0);
}

void Agent::disconnect()
{
    if (clientSocket_ != -1)
    {
        close(clientSocket_);
        clientSocket_ = -1;
    }
}
