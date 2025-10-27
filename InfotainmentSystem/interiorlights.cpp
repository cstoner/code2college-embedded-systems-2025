#include <softPwm.h>

#include "interiorlights.h"
#include "ui_interiorlights.h"

#include "mainwindow.h"

static bool front = false;
static int frontBright = 100;
static bool middle = false;
static bool back = false;

const int FRONT_PIN_1=22;
const int FRONT_PIN_2=13;
const int MID_PIN_1=27;
const int MID_PIN_2=6;
const int BACK_PIN_1=17;
const int BACK_PIN_2=5;

InteriorLights::InteriorLights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteriorLights)
{
    wiringPiSetupGpio();
    softPwmCreate(FRONT_PIN_1, 0, 100);
    softPwmCreate(FRONT_PIN_2, 0, 100);
    pinMode(MID_PIN_1,OUTPUT);
    pinMode(MID_PIN_2,OUTPUT);
    pinMode(BACK_PIN_1,OUTPUT);
    pinMode(BACK_PIN_2,OUTPUT);

    mainWindow = qobject_cast<MainWindow*>(parent);
    ui->setupUi(this);
    ui->frontCheckbox->setChecked(front);
    ui->midCheckbox->setChecked(middle);
    ui->backCheckbox->setChecked(back);
}

InteriorLights::~InteriorLights()
{
    delete ui;
}

void InteriorLights::on_pushButton_clicked()
{
    hide();
    mainWindow->show();
}


void InteriorLights::on_frontCheckbox_stateChanged(int arg1)
{
    if (arg1 == 0) {
        front = false;
    } else {
        front = true;
    }
    softPwmWrite(FRONT_PIN_1, frontBright);
    softPwmWrite(FRONT_PIN_2, frontBright);

}


void InteriorLights::on_midCheckbox_stateChanged(int arg1)
{
    if (arg1 == 0) {
        middle = false;
        digitalWrite(MID_PIN_1,LOW);
        digitalWrite(MID_PIN_2,LOW);
    } else {
        middle = true;
        digitalWrite(MID_PIN_1,HIGH);
        digitalWrite(MID_PIN_2,HIGH);
    }
}


void InteriorLights::on_backCheckbox_stateChanged(int arg1)
{
    if (arg1 == 0) {
        back = false;
        digitalWrite(BACK_PIN_1,LOW);
        digitalWrite(BACK_PIN_2,LOW);
    } else {
        back = true;
        digitalWrite(BACK_PIN_1,HIGH);
        digitalWrite(BACK_PIN_2,HIGH);
    }
}


void InteriorLights::on_resetButton_clicked()
{
    front = false;
    middle = false;
    back = false;

    ui->frontCheckbox->setChecked(front);
    ui->midCheckbox->setChecked(middle);
    ui->backCheckbox->setChecked(back);
}


void InteriorLights::on_brightenFrontButton_clicked()
{
    if (front) {
        if (frontBright <= 100) {
            frontBright += 5;
        }

        softPwmWrite(FRONT_PIN_1, frontBright);
        softPwmWrite(FRONT_PIN_2, frontBright);
    }
}


void InteriorLights::on_dimFrontButton_clicked()
{
    if (front) {
        if (frontBright > 0) {
            frontBright -= 5;
        }

        softPwmWrite(FRONT_PIN_1, frontBright);
        softPwmWrite(FRONT_PIN_2, frontBright);
    }
}

