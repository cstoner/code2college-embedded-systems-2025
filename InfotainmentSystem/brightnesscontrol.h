#ifndef BRIGHTNESSCONTROL_H
#define BRIGHTNESSCONTROL_H

#include <QDialog>

class MainWindow;

namespace Ui {
class BrightnessControl;
}

class BrightnessControl : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessControl(QWidget *parent = nullptr);
    ~BrightnessControl();

private slots:
    void on_backButton_clicked();

private:
    Ui::BrightnessControl *ui;
    MainWindow *mainWindow;
};

#endif // BRIGHTNESSCONTROL_H
