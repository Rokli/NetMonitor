/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tabServer;
    QVBoxLayout *verticalLayout;
    QTextEdit *consoleServer;
    QSplitter *splitter;
    QPushButton *buttonStart;
    QPushButton *buttonStop;
    QPushButton *buttonWrite;
    QWidget *tabClient;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *consoleClient;
    QPlainTextEdit *textEditInsert;
    QSplitter *splitter_2;
    QPushButton *buttonSendClient;
    QPushButton *buttonConnect;
    QPushButton *buttonDisconnect;
    QPushButton *buttonSettingClient;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabServer = new QWidget();
        tabServer->setObjectName("tabServer");
        verticalLayout = new QVBoxLayout(tabServer);
        verticalLayout->setObjectName("verticalLayout");
        consoleServer = new QTextEdit(tabServer);
        consoleServer->setObjectName("consoleServer");
        consoleServer->setEnabled(true);
        consoleServer->setReadOnly(true);

        verticalLayout->addWidget(consoleServer);

        splitter = new QSplitter(tabServer);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        buttonStart = new QPushButton(splitter);
        buttonStart->setObjectName("buttonStart");
        splitter->addWidget(buttonStart);
        buttonStop = new QPushButton(splitter);
        buttonStop->setObjectName("buttonStop");
        splitter->addWidget(buttonStop);
        buttonWrite = new QPushButton(splitter);
        buttonWrite->setObjectName("buttonWrite");
        splitter->addWidget(buttonWrite);

        verticalLayout->addWidget(splitter);

        tabWidget->addTab(tabServer, QString());
        tabClient = new QWidget();
        tabClient->setObjectName("tabClient");
        verticalLayout_2 = new QVBoxLayout(tabClient);
        verticalLayout_2->setObjectName("verticalLayout_2");
        consoleClient = new QTextEdit(tabClient);
        consoleClient->setObjectName("consoleClient");
        consoleClient->setReadOnly(true);

        verticalLayout_2->addWidget(consoleClient);

        textEditInsert = new QPlainTextEdit(tabClient);
        textEditInsert->setObjectName("textEditInsert");
        textEditInsert->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(textEditInsert);

        splitter_2 = new QSplitter(tabClient);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Orientation::Horizontal);
        buttonSendClient = new QPushButton(splitter_2);
        buttonSendClient->setObjectName("buttonSendClient");
        splitter_2->addWidget(buttonSendClient);
        buttonConnect = new QPushButton(splitter_2);
        buttonConnect->setObjectName("buttonConnect");
        splitter_2->addWidget(buttonConnect);
        buttonDisconnect = new QPushButton(splitter_2);
        buttonDisconnect->setObjectName("buttonDisconnect");
        splitter_2->addWidget(buttonDisconnect);
        buttonSettingClient = new QPushButton(splitter_2);
        buttonSettingClient->setObjectName("buttonSettingClient");
        splitter_2->addWidget(buttonSettingClient);

        verticalLayout_2->addWidget(splitter_2);

        tabWidget->addTab(tabClient, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NetMonitor", nullptr));
        consoleServer->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        buttonStart->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200", nullptr));
        buttonStop->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200", nullptr));
        buttonWrite->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\321\221\321\202 \321\201\320\265\321\200\320\262\320\265\321\200\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabServer), QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\265\321\200", nullptr));
        buttonSendClient->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        buttonConnect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        buttonDisconnect->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        buttonSettingClient->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabClient), QCoreApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
