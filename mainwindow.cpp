#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogclient.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->createClient,&QAction::triggered,this,&MainWindow::on_menuClient_clicked);
    connect(ui->settingsServer,&QAction::triggered,this,&MainWindow::on_menuServer_clicked);
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




void MainWindow::on_buttonDisconnect_clicked()
{
    agent_->disconnect();
}


void MainWindow::on_buttonSettingClient_clicked()
{
    QWidget* currentTab = ui->tabWidget->currentWidget();

    if (!tabToAgent_.contains(currentTab)) {
        QMessageBox::warning(this, "Ошибка", "Клиент не найден для текущей вкладки.");
        return;
    }

    Agent* agent = tabToAgent_[currentTab];
    if (!agent) {
        QMessageBox::warning(this, "Ошибка", "Указатель на агента null.");
        return;
    }

    DialogClient *dialog = new DialogClient(this);
    dialog->setIpClient(QString::fromStdString(agent->getServerIp()));
    dialog->setPortclient(QString::number(agent->getServerPort()));
    dialog->exec();
    agent->setServerIp(dialog->getServerIp());
    agent->setServerPort(dialog->getServerPort());
}


void MainWindow::on_menuClient_clicked()
{
    QWidget *newTab = new QWidget;

    QTextEdit* console = new QTextEdit;
    QTextEdit* input = new QTextEdit;
    QPushButton* sendButton = new QPushButton("Отправить");
    QPushButton* connectButton = new QPushButton("Подключиться");
    QPushButton* disconnectButton = new QPushButton("Отключиться");
    QPushButton* settingsButton = new QPushButton("Настройка клиента");

    console->setReadOnly(true);
    input->setFixedHeight(50);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(sendButton);
    buttonLayout->addWidget(connectButton);
    buttonLayout->addWidget(disconnectButton);
    buttonLayout->addWidget(settingsButton);

    QVBoxLayout* layout = new QVBoxLayout(newTab);
    layout->addWidget(console);
    layout->addWidget(input);
    layout->addLayout(buttonLayout);

    Agent* newAgent = new Agent("127.0.0.1", 1234);
    newAgent->setConsole(console);
    agents_.append(newAgent);
    tabToAgent_.insert(newTab, newAgent);

    connect(connectButton, &QPushButton::clicked, this, [=]() {
        newAgent->connectToServer();
    });

    connect(sendButton, &QPushButton::clicked, this, [=]() {
        newAgent->sendData(input->toPlainText().toStdString());
        input->clear();
    });

    connect(disconnectButton, &QPushButton::clicked, this, [=]() {
        newAgent->disconnect();
    });

    connect(settingsButton, &QPushButton::clicked, this, [=]() {
        on_buttonSettingClient_clicked();
    });

    ui->tabWidget->addTab(newTab, "Клиент " + QString::number(agents_.size()));
    ui->tabWidget->setCurrentWidget(newTab);
}


void MainWindow::on_menuServer_clicked()
{
    qWarning() << "Нажата кнопка настройка сервера";
}

