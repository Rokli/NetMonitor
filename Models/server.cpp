#include "server.h"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <errno.h>

Server::Server(int port)
    : port_(port), serverSocket_(-1), running_(false), dbConnection_(nullptr), console_(nullptr)
{
}

void Server::start()
{
    dbConnection_ = mysql_init(nullptr);

    if (!dbConnection_)
    {
        sendTextConsole("MySQL инициализация не удалась.");
        return;
    }

    const char* host = "localhost";
    const char* user = "root";
    const char* password = "xrxc321";
    const char* database = "rgz";

    if (!mysql_real_connect(dbConnection_, host, user, password, database, 0, nullptr, 0))
    {
        sendTextConsole(QString("MySQL подключение не удалось: ") + mysql_error(dbConnection_));
        return;
    }

    sendTextConsole("Успешное подключение к базе данных MySQL.");

    serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket_ == -1)
    {
        sendTextConsole("Ошибка создания сокета.");
        return;
    }

    int opt = 1;
    setsockopt(serverSocket_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port_);

    if (bind(serverSocket_, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        sendTextConsole("Ошибка при привязке: " + QString::fromStdString(strerror(errno)));
        return;
    }

    if (listen(serverSocket_, 5) < 0)
    {
        sendTextConsole("Ошибка при прослушивании.");
        return;
    }

    running_ = true;
    sendTextConsole("Сервер запущен на порту: " + QString::number(port_) + ". Ожидаем клиентов...");

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
            sendTextConsole("Сервер остановлен.");
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
                sendTextConsole("Ошибка accept: " + QString::fromStdString(strerror(errno)));
            continue;
        }

        clientThreads_.emplace_back(&Server::handleClient, this, clientSocket);
    }
}

void Server::handleClient(int clientSocket)
{
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));

    char buffer[1024];
    while (running_)
    {
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer) - 1);

        if (bytesRead <= 0)
        {
            if (errno == EWOULDBLOCK || errno == EAGAIN)
                continue;
            break;
        }

        std::string message(buffer, bytesRead);
        sendTextConsole("Сообщение: " + QString::fromStdString(message));

        char escapedMessage[2048];
        mysql_real_escape_string(dbConnection_, escapedMessage, message.c_str(), message.length());

        std::string query = "INSERT INTO agent_data (message) VALUES ('" + std::string(escapedMessage) + "')";

        if (mysql_query(dbConnection_, query.c_str()))
            sendTextConsole("Ошибка записи в БД: " + QString::fromStdString(mysql_error(dbConnection_)));
        else
            sendTextConsole("Данные добавлены в базу.");
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
    if (console_)
        QMetaObject::invokeMethod(console_, [this, text]() {
            console_->append(text);
        }, Qt::QueuedConnection);
}
