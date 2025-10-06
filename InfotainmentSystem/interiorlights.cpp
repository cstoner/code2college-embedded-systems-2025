#include "interiorlights.h"
#include "ui_interiorlights.h"

#include "mainwindow.h"

static bool front = false;
static bool middle = false;
static bool back = false;


InteriorLights::InteriorLights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteriorLights)
{
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
}


void InteriorLights::on_midCheckbox_stateChanged(int arg1)
{
    if (arg1 == 0) {
        middle = false;
    } else {
        middle = true;
    }
}


void InteriorLights::on_backCheckbox_stateChanged(int arg1)
{
    if (arg1 == 0) {
        back = false;
    } else {
        back = true;
    }
}

