#ifndef SERVER_H
#define SERVER_H
#include <vector>
#include <QDebug>
#include <string>
#include <thread>
#include <atomic>
#include <mysql/mysql.h>
#include <netinet/in.h>
#include <QObject>
#include <QTextEdit>

class Server
{
public:
    Server(int port);
    void start();
    void stop();
    void setConsoleEdit(QTextEdit *console);
private:
    void run();
    void handleClient(int clientSocket);
    void sendTextConsole(QString text);
    int serverSocket_;
    int port_;
    QTextEdit *console_;
    std::atomic<bool> running_;
    std::vector<std::thread> clientThreads_;
    MYSQL* dbConnection_;
};

#endif // SERVER_H
