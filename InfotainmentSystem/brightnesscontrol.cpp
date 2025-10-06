#include "brightnesscontrol.h"
#include "ui_brightnesscontrol.h"

#include "mainwindow.h"

static int brightnessValue=50;

BrightnessControl::BrightnessControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessControl)
{
    ui->setupUi(this);
    mainWindow = qobject_cast<MainWindow*>(parent);

    ui->brightnessSlider->setValue(brightnessValue);
    ui->brightnessDisplay->setValue(brightnessValue);
}

BrightnessControl::~BrightnessControl()
{
    delete ui;
}

void BrightnessControl::on_backButton_clicked()
{
    hide();
    mainWindow->show();
}


void BrightnessControl::on_brightnessSlider_valueChanged(int value)
{
    brightnessValue = value;
    ui->brightnessDisplay->setValue(brightnessValue);
}

