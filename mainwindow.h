#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCoreApplication>
#include <QtGui>
#include <QString>
#include <QThread>
#include <QMutex>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>

//GPIO related
#define PWM_NUMBER 1
#define LED 7
#define RESET_BUTTON 5
#define BUTTON_LEFT 3
#define BUTTON_RIGHT 0

//PWM related
#define PWM_RANGE 2000
#define RESET_POS 90

//Global Functions
void resetPositionISR(void);
//void turnLeftISR(void);
void setMotorPosition(int);

//Global Variables
static int MotorPos = 90;
static QMutex mutex;

//Did not work, Qt does not see libraries of wiring pi as it should
/*//Thread Function
PI_THREAD (Buttons_Thread){
//    (void)piHiPri(3); //Set it as low priority
    for(;;){
        delay(500);
        digitalWrite(LED, 1);
        delay(500);
        digitalWrite(LED, 0);
    }
};*/

class ButtonsThread : public QThread{
    Q_OBJECT
    void run();
    bool BtnFlag;
public:
    ButtonsThread():QThread(){BtnFlag = FALSE;}
    void setBtnFlag(bool s){BtnFlag = s;}
signals:
    void keyrelease();
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//    void runBtnThreads(){btnThread->start();}

    ~MainWindow();

private slots:
    void on_dial_angle_valueChanged(int value);
    void on_pBtn_exit_clicked();
    void on_keyRelease();
//    void on_cBx_controlPass_clicked(bool checked);

    void on_cBx_controlPass_clicked();

private:
    Ui::MainWindow *ui;    
    ButtonsThread *btnThread;
};

#endif // MAINWINDOW_H
