/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_O;
    QAction *action_N;
    QAction *action_U;
    QAction *action_S;
    QAction *action_V;
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    mylabel *label;
    QLabel *label_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_select1;
    QLabel *label_select2;
    QLabel *label_select3;
    QLabel *label_select;
    QPushButton *start_video;
    QPushButton *pause_button;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1303, 729);
        action_O = new QAction(MainWindow);
        action_O->setObjectName(QStringLiteral("action_O"));
        action_N = new QAction(MainWindow);
        action_N->setObjectName(QStringLiteral("action_N"));
        action_U = new QAction(MainWindow);
        action_U->setObjectName(QStringLiteral("action_U"));
        action_S = new QAction(MainWindow);
        action_S->setObjectName(QStringLiteral("action_S"));
        action_V = new QAction(MainWindow);
        action_V->setObjectName(QStringLiteral("action_V"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 821, 501));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 819, 499));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new mylabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(850, 30, 301, 191));
        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(850, 200, 441, 431));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 439, 429));
        label_select1 = new QLabel(scrollAreaWidgetContents_2);
        label_select1->setObjectName(QStringLiteral("label_select1"));
        label_select1->setGeometry(QRect(20, 320, 111, 71));
        label_select2 = new QLabel(scrollAreaWidgetContents_2);
        label_select2->setObjectName(QStringLiteral("label_select2"));
        label_select2->setGeometry(QRect(190, 340, 91, 61));
        label_select3 = new QLabel(scrollAreaWidgetContents_2);
        label_select3->setObjectName(QStringLiteral("label_select3"));
        label_select3->setGeometry(QRect(320, 350, 91, 51));
        label_select = new QLabel(scrollAreaWidgetContents_2);
        label_select->setObjectName(QStringLiteral("label_select"));
        label_select->setGeometry(QRect(30, 10, 331, 291));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        start_video = new QPushButton(centralWidget);
        start_video->setObjectName(QStringLiteral("start_video"));
        start_video->setGeometry(QRect(30, 540, 93, 28));
        pause_button = new QPushButton(centralWidget);
        pause_button->setObjectName(QStringLiteral("pause_button"));
        pause_button->setGeometry(QRect(150, 540, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1303, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_O);
        menu->addAction(action_N);
        menu->addAction(action_U);
        menu->addAction(action_V);
        menu_2->addAction(action_S);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_O->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", 0));
        action_O->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        action_N->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240(&N)", 0));
        action_N->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        action_U->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\345\274\240(&U)", 0));
        action_U->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", 0));
        action_S->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", 0));
        action_S->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        action_V->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\247\206\351\242\221(&V)", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_select1->setText(QApplication::translate("MainWindow", "label_select1", 0));
        label_select2->setText(QApplication::translate("MainWindow", "label_select2", 0));
        label_select3->setText(QApplication::translate("MainWindow", "label_select3", 0));
        label_select->setText(QApplication::translate("MainWindow", "label_select", 0));
        start_video->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276", 0));
        pause_button->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\227\205\347\201\266\345\214\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
