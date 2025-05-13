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
        SendConsoleText("Сокет не получилось создать\n");
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort_);

    if (inet_pton(AF_INET, serverIp_.c_str(), &serverAddr.sin_addr) <= 0)
    {
        SendConsoleText("Неправильный айпи\n");
        return;
    }

    if (connect(clientSocket_, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        SendConsoleText("Не получилось подключиться к серверу.\n");
        return;
    }

    SendConsoleText("Подключился к серверу: " + QString::fromStdString(serverIp_) + ":" + QString::number(serverPort_) + "\n");
}

void Agent::sendData(const std::string& data)
{
    if (clientSocket_ == -1)
    {
        SendConsoleText("Нет активных подключений.\n");
        return;
    }

    std::string toSend = data + "\n";
    ssize_t sent = send(clientSocket_, toSend.c_str(), toSend.size(), 0);

    if (sent == -1)
    {
        SendConsoleText("Ошибка отправки. Соединение разорвано сервером.");
        close(clientSocket_);
        clientSocket_ = -1;
        return;
    }

    SendConsoleText("Сообщение отправлено: " + QString::fromStdString(data));
}


void Agent::disconnect()
{
    if (clientSocket_ != -1)
    {
        close(clientSocket_);
        clientSocket_ = -1;
        SendConsoleText("Отключён от сервера");
    }
}

void Agent::setConsole(QTextEdit *console)
{
    console_ = console;
}

void Agent::SendConsoleText(QString text)
{
    console_->append(text);
}

std::string Agent::getServerIp()
{
    return serverIp_;
}

int Agent::getServerPort()
{
    return serverPort_;
}


void Agent::setServerIp(std::string serverIp)
{
    this->serverIp_ = serverIp;
}

void Agent::setServerPort(int serverPort)
{
    this->serverPort_ = serverPort;
}
