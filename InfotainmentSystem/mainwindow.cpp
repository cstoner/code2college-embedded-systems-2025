#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

class About;
class BrightnessControl;
class InteriorLights;

static bool headLightStatus = false;
static const QString HEADLIGHTS_ON_CSS =
        "background-color:rgb(255,255,255);"
        "border: 1px solid black;";
static const QString HEADLIGHTS_OFF_CSS =
        "background-color:rgb(135,135,135);"
        "border: 1px solid black;";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    about = new About(this);
    brightnessControl = new BrightnessControl(this);
    interiorLights = new InteriorLights(this);

    if (headLightStatus) {
        ui->headlightsButton->setStyleSheet(HEADLIGHTS_ON_CSS);
    } else {
        ui->headlightsButton->setStyleSheet(HEADLIGHTS_OFF_CSS);
    }
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


void MainWindow::on_headlightsButton_clicked()
{
    headLightStatus = !headLightStatus;

    if (headLightStatus) {
        ui->headlightsButton->setStyleSheet(HEADLIGHTS_ON_CSS);
    } else {
        ui->headlightsButton->setStyleSheet(HEADLIGHTS_OFF_CSS);
    }
}

