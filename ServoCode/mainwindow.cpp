#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (wiringPiSetup() == -1){
           QMessageBox::information(this,"Error conf gpio","The gpio could not be configured");
           QApplication::quit();}

//Setting the pins
    pinMode(PWM_NUMBER, PWM_OUTPUT);
    wiringPiISR(RESET_BUTTON, INT_EDGE_RISING, &resetPositionISR);
//    wiringPiISR(BUTTON_LEFT, INT_EDGE_RISING, &turnLeftISR);
    pinMode(LED, OUTPUT);
    pinMode(BUTTON_LEFT, INPUT);
    pinMode(BUTTON_RIGHT, INPUT);

//PWM frequency Hz = 19,2Mhz / Clock / Range
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(PWM_RANGE);
    pwmSetClock(192);

//Buttons Thread realted
    btnThread = new ButtonsThread();
    connect(btnThread,SIGNAL(keyrelease()),this,SLOT(on_keyRelease()));
//    connect(btnThread,SIGNAL(finished()),this,SLOT(deleteLater())); //Not sure about this line because I want to try to make it sleep and go back and so on, not just run ones
    btnThread->setParent(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete btnThread;
}

void MainWindow::on_dial_angle_valueChanged(int value)
{
    setMotorPosition(value);

    mutex.lock();
    MotorPos = value;
    mutex.unlock();

    ui->lbl_MotorPos->setText("MotorPos: " + QString::number(MotorPos));    
    ui->label->setText("Motor A: angle: "+ QString::number(value) +" degrees");
}

void MainWindow::on_pBtn_exit_clicked()
{
    QApplication::quit();
}

void ButtonsThread::run(){
    while(BtnFlag){
        if(digitalRead(BUTTON_LEFT)){
                digitalWrite(LED, 1);
                delay(500);
                digitalWrite(LED, 0);

                mutex.lock();
                MotorPos+=5;
                mutex.unlock();
                setMotorPosition(MotorPos);

        }
        if(digitalRead(BUTTON_RIGHT)){

                digitalWrite(LED, 1);
                delay(250);
                digitalWrite(LED, 0);

                mutex.lock();
                MotorPos-=5;
                mutex.unlock();
                setMotorPosition(MotorPos);
        }
    }//and while
emit keyrelease();
}

void MainWindow::on_keyRelease(){
    btnThread->wait();
    btnThread->terminate();
}

void resetPositionISR(){
/*Here goes the code for reset actions */

    setMotorPosition(RESET_POS);
    QApplication::quit();
}

/*void MainWindow::on_cBx_controlPass_clicked(bool checked)
{
    if(checked){
        btnThread->start();
    }
    else{
        btnThread->terminate();
    }
}*/

void setMotorPosition(int value){
    int pos = (int)(value*170/180+50);
    pwmWrite(PWM_NUMBER,pos);
}

void MainWindow::on_cBx_controlPass_clicked()
{
    if(ui->cBx_controlPass->isChecked()){
        btnThread->setBtnFlag(TRUE);
        btnThread->start();
    }
    else
        btnThread->setBtnFlag(FALSE);
}
