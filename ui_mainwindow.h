/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDial *dial_angle;
    QCheckBox *cBx_controlPass;
    QLabel *lbl_MotorPos;
    QPushButton *pBtn_exit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(289, 335);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        dial_angle = new QDial(centralWidget);
        dial_angle->setObjectName(QStringLiteral("dial_angle"));
        dial_angle->setMaximum(180);
        dial_angle->setValue(90);
        dial_angle->setTracking(true);
        dial_angle->setWrapping(false);
        dial_angle->setNotchTarget(6.7);
        dial_angle->setNotchesVisible(true);

        verticalLayout->addWidget(dial_angle);

        cBx_controlPass = new QCheckBox(centralWidget);
        cBx_controlPass->setObjectName(QStringLiteral("cBx_controlPass"));

        verticalLayout->addWidget(cBx_controlPass);

        lbl_MotorPos = new QLabel(centralWidget);
        lbl_MotorPos->setObjectName(QStringLiteral("lbl_MotorPos"));

        verticalLayout->addWidget(lbl_MotorPos);

        pBtn_exit = new QPushButton(centralWidget);
        pBtn_exit->setObjectName(QStringLiteral("pBtn_exit"));

        verticalLayout->addWidget(pBtn_exit);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 289, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Motor A. current angle: 90", Q_NULLPTR));
        cBx_controlPass->setText(QApplication::translate("MainWindow", "Pass Control to Buttons", Q_NULLPTR));
        lbl_MotorPos->setText(QApplication::translate("MainWindow", "MotorPos: ", Q_NULLPTR));
        pBtn_exit->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
