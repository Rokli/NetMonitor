#include "dialogclient.h"
#include "ui_dialogclient.h"

DialogClient::DialogClient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogClient)
{
    ui->setupUi(this);
}

DialogClient::~DialogClient()
{
    delete ui;
}

void DialogClient::setIpClient(QString text)
{
    ui->ipclient->setPlaceholderText(text);
}

void DialogClient::setPortclient(QString text)
{
    ui->portclient->setPlaceholderText(text);
}

void DialogClient::on_pushButton_clicked()
{
    this->close();
}

std::string DialogClient::getServerIp()
{
    return ui->ipclient->placeholderText().toStdString();
}

int DialogClient::getServerPort()
{
    return ui->portclient->text().toInt();
}
