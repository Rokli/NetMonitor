#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>
#include <QString>

namespace Ui {
class DialogClient;
}

class DialogClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClient(QWidget *parent = nullptr);
    void setIpClient(QString text);
    void setPortclient(QString text);
    std::string getServerIp();
    int getServerPort();
    ~DialogClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogClient *ui;
};

#endif // DIALOGCLIENT_H
