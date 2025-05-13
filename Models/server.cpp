#include "server.h"
#include <iostream>
#include <unistd.h>
#include <cstring>

Server::Server(int port)
    : port_(port), serverSocket_(-1), running_(false) {}


void Server::start()
{
    dbConnection_ = mysql_init(nullptr);

    if (!dbConnection_)
    {
        sendTextConsole("MySQL initialization failed.");
        return;
    }

    const char* host = "localhost";
    const char* user = "root";
    const char* password = "xrxc321";
    const char* database = "rgz";

    if (!mysql_real_connect(dbConnection_, host, user, password, database, 0, nullptr, 0))
    {
        sendTextConsole(QString("MySQL connection failed: ") + mysql_error(dbConnection_));
        return;
    }

    sendTextConsole("Connected to MySQL database successfully.");

    serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket_ == -1)
    {
        sendTextConsole("Ошибка в создании сокета.\n");
        return;
    }

    int opt = 1;
    if (setsockopt(serverSocket_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        sendTextConsole("setsockopt failed\n");
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port_);

    if (bind(serverSocket_, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        sendTextConsole("Ошибка при настройке: " + QString::fromStdString(strerror(errno)) + "\n");
        return;
    }

    if (listen(serverSocket_, 5) < 0)
    {
        sendTextConsole("Не может слушать.\n");
        return;
    }

    running_ = true;
    sendTextConsole("Сервер начал работу на порту: " + QString::number(port_) + ".\n Ждём клиентов...\n");

    std::thread serverThread(&Server::run, this);
    serverThread.detach();
}

void Server::stop()
{
    if (!running_)
        return;

    running_ = false;

    if (serverSocket_ != -1)
    {
        shutdown(serverSocket_, SHUT_RDWR);
        close(serverSocket_);
        serverSocket_ = -1;
    }

    for (auto& thread : clientThreads_)
    {
        if (thread.joinable())
            thread.join();
    }
    clientThreads_.clear();

    if (dbConnection_)
    {
        mysql_close(dbConnection_);
        dbConnection_ = nullptr;
    }

    if (console_)
    {
        QMetaObject::invokeMethod(console_, [this]() {
            sendTextConsole("Сервер остановился.\n");
        }, Qt::QueuedConnection);
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
                sendTextConsole("Ошибка при принятии.\n");
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

        std::string message(buffer, bytesRead);
        sendTextConsole("Сообщение: " + QString::fromStdString(message));

        char escapedMessage[2048];
        mysql_real_escape_string(dbConnection_, escapedMessage, message.c_str(), message.length());

        std::string query = "INSERT INTO agent_data (message) VALUES ('" + std::string(escapedMessage) + "')";

        if (mysql_query(dbConnection_, query.c_str()))
        {
            sendTextConsole(QString("Ошибка вставки в БД: ") + mysql_error(dbConnection_));
        }
        else
        {
            sendTextConsole("Данные добавлены в БД.");
        }
    }

    close(clientSocket);
    sendTextConsole("Клиент отключён.");
}


void Server::setConsoleEdit(QTextEdit *console)
{
    console_ = console;
}

void Server::sendTextConsole(QString text)
{
    console_->append(text);
}
