#ifndef SERVER_H
#define SERVER_H
#include <vector>
#include <QDebug>
#include <string>
#include <thread>
#include <atomic>
#include <netinet/in.h>

class Server
{
public:
    Server(int port);
    void start();
    void stop();
private:
    void run();
    void handleClient(int clientSocket);

    int serverSocket_;
    int port_;
    std::atomic<bool> running_;
    std::vector<std::thread> clientThreads_;
};

#endif // SERVER_H
