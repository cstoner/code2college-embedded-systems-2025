#include "interiorlights.h"
#include "ui_interiorlights.h"

#include "mainwindow.h"

InteriorLights::InteriorLights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteriorLights)
{
    ui->setupUi(this);
    mainWindow = qobject_cast<MainWindow*>(parent);
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

