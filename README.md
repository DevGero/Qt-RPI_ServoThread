# Qt-RPI_ServoThread

An example program using Qt widgets and Raspberry Pi to control a motor from a Qt interface. It can be control with a Dial on the mainwindow or by external buttons. Also includes the use of interrupts using a third button to reset the motor position and close the aplication. For accesing the gpio and the interrupts is use the wiringPi library.
This projects use for creating a Thread the class provide by Qt 

Qt is a cross platform framework for developing graphical applications, for more information please visit the links below:
* [Qt5 Homepage](https://www.qt.io/)
* [wiringPi](http://wiringpi.com/reference/priority-interrupts-and-threads/)

# Making it work

Hardware
--------------
Left button    -> GPIO22 (3)
Right button   -> GPIO17 (0)
Reset          -> GPIO24 (5)
Indicator Led  -> GPIO4  (7)

PWM            -> GPIO18 (1)

If use a small servo motor as SG90, it can be power off from the RPI. If using external source remember to set a commun ground

Software

To clone the git repository:

    git clone https://github.com/DevGero/Qt-RPI_ServoThread.git    

To build:

    cd Qt-RPI_ServoThread/ServoCode
    qmake
    make

To run it needs to be as root user to be able to access the PWM.

    sudo ./Servo_Butons_Threads

Possible trouble
----------------

If it screen an error of not been able to access the interface resources type:

    sudo cp /home/pi/.Xauthority /root

and try again.
