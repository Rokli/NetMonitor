#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonStart_clicked()
{
    server_ = new Server(1234);
    server_->setConsoleEdit(ui->consoleServer);
    server_->start();
}

void MainWindow::on_buttonStop_clicked()
{
    server_->stop();
}

void MainWindow::on_buttonWrite_clicked()
{

}

void MainWindow::on_buttonSendClient_clicked()
{
    agent_->sendData(ui->textEditInsert->toPlainText().toStdString());
    ui->textEditInsert->clear();
}


void MainWindow::on_buttonDisconnect_clicked()
{
    agent_->disconnect();
}


void MainWindow::on_buttonSettingClient_clicked()
{

}


void MainWindow::on_buttonConnect_clicked()
{
    agent_ = new Agent("127.0.0.1", 1234);
    agent_->setConsole(ui->consoleClient);
    agent_->connectToServer();
}

