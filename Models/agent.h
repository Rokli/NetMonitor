#ifndef AGENT_H
#define AGENT_H

#include <string>
#include <QString>
#include <QDebug>
#include <QTextEdit>

class Agent
{
public:
    Agent(const std::string& serverIp, int serverPort);

    void connectToServer();
    void sendData(const std::string& data);
    void disconnect();
    void setConsole(QTextEdit *console);
    std::string getServerIp();
    int getServerPort();
    void setServerIp(std::string serverIp);
    void setServerPort(int serverPort);
private:
    int clientSocket_;
    std::string serverIp_;
    int serverPort_;
    QTextEdit *console_;
    void SendConsoleText(QString text);
};

#endif // AGENT_H
