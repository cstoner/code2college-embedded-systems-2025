#include "brightnesscontrol.h"
#include "ui_brightnesscontrol.h"

#include "mainwindow.h"

BrightnessControl::BrightnessControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessControl)
{
    ui->setupUi(this);
    mainWindow = qobject_cast<MainWindow*>(parent);
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

