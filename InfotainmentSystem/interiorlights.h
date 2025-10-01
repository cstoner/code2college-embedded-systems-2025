#ifndef INTERIORLIGHTS_H
#define INTERIORLIGHTS_H

#include <QDialog>

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

private:
    Ui::InteriorLights *ui;
    MainWindow *mainWindow;
};

#endif // INTERIORLIGHTS_H
