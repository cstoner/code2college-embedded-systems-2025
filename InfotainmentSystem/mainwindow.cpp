#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    about = new About(this);
    brightnessControl = new BrightnessControl(this);
    interiorLights = new InteriorLights(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete about;
    delete brightnessControl;
    delete interiorLights;
}


void MainWindow::on_aboutButton_clicked()
{
    hide();
    about->show();
}


void MainWindow::on_brightnessControlButton_clicked()
{
    hide();
    brightnessControl->show();
}


void MainWindow::on_interiorLightsButton_clicked()
{
    hide();
    interiorLights->show();
}

