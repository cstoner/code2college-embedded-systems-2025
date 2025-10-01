#include "about.h"
#include "ui_about.h"
#include "mainwindow.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    mainWindow = qobject_cast<MainWindow*>(parent);
}

About::~About()
{
    delete ui;
}

void About::on_backButton_clicked()
{
    hide();
    mainWindow->show();
}

