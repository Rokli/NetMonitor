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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QAction *createClient;
    QAction *settingsServer;
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
    QMenuBar *menubar;
    QMenu *menuClient;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        createClient = new QAction(MainWindow);
        createClient->setObjectName("createClient");
        settingsServer = new QAction(MainWindow);
        settingsServer->setObjectName("settingsServer");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
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

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuClient = new QMenu(menubar);
        menuClient->setObjectName("menuClient");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuClient->menuAction());
        menuClient->addAction(createClient);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NetMonitor", nullptr));
        createClient->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        settingsServer->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200", nullptr));
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
        menuClient->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
