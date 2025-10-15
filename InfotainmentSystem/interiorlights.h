#ifndef INTERIORLIGHTS_H
#define INTERIORLIGHTS_H

#include <QDialog>

#include "wiringPi.h"

class MainWindow;

namespace Ui {
class InteriorLights;
}

class InteriorLights : public QDialog
{
    Q_OBJECT

public:
    explicit InteriorLights(QWidget *parent = nullptr);
    ~InteriorLights();

private slots:
    void on_pushButton_clicked();

    void on_frontCheckbox_stateChanged(int arg1);

    void on_midCheckbox_stateChanged(int arg1);

    void on_backCheckbox_stateChanged(int arg1);

    void on_resetButton_clicked();

private:
    Ui::InteriorLights *ui;
    MainWindow *mainWindow;
};

#endif // INTERIORLIGHTS_H
