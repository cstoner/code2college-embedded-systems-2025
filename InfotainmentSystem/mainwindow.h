#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "about.h"
#include "brightnesscontrol.h"
#include "interiorlights.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_aboutButton_clicked();

    void on_brightnessControlButton_clicked();

    void on_interiorLightsButton_clicked();

    void on_headlightsButton_clicked();

private:
    Ui::MainWindow *ui;
    About *about;
    BrightnessControl *brightnessControl;
    InteriorLights *interiorLights;
};
#endif // MAINWINDOW_H
