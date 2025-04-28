#ifndef AGENT_H
#define AGENT_H

#include <string>
#include <QDebug>

class Agent
{
public:
    Agent(const std::string& serverIp, int serverPort);

    void connectToServer();
    void sendData(const std::string& data);
    void disconnect();

private:
    int clientSocket_;
    std::string serverIp_;
    int serverPort_;
};

#endif // AGENT_H
