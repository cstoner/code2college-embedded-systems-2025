#include <QPixmap>
#include <string>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
using namespace std;

static string playerChoice;
static string computerChoice;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));

    ui->setupUi(this);

    QPixmap opp("/home/speedyfight/Pictures/computer.jpg");
    ui->oppPic->setPixmap(opp);
    ui->oppPic->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rockButton_clicked()
{
    QPixmap opp("/home/speedyfight/Pictures/rock.jpg");
    ui->playerChoicePic->setPixmap(opp);
    ui->playerChoicePic->setScaledContents(true);
    playerChoice = "Rock";
}


void MainWindow::on_paperButton_clicked()
{
    QPixmap opp("/home/speedyfight/Pictures/paper.jpg");
    ui->playerChoicePic->setPixmap(opp);
    ui->playerChoicePic->setScaledContents(true);
    playerChoice = "Paper";
}


void MainWindow::on_scissorsButton_clicked()
{
    QPixmap opp("/home/speedyfight/Pictures/scissors.jpg");
    ui->playerChoicePic->setPixmap(opp);
    ui->playerChoicePic->setScaledContents(true);
    playerChoice = "Scissors";
}


void MainWindow::on_playButton_clicked()
{
    string choices[3] = {"Rock","Paper","Scissors"};
    computerChoice = choices[rand()%3];

    ui->oppChoice->setText(QString::fromStdString(computerChoice));

    if (playerChoice == computerChoice){
        ui->gameResult->setText("It's a tie");
    }
    else if (playerChoice == "Rock"){
      if (computerChoice == "Paper"){
        ui->gameResult->setText("You lose!");
      }
      else {
        ui->gameResult->setText("You win!");
      }
    }
    else if (playerChoice == "Paper"){
      if (computerChoice == "Rock"){
        ui->gameResult->setText("You lose!");
      }
      else {
        ui->gameResult->setText("You win!");
      }
    }
    else if (playerChoice == "Scissors"){
      if(computerChoice == "Rock"){
        ui->gameResult->setText("You lose!");
      }
      else {
        ui->gameResult->setText("You win!");
      }
    }

}

