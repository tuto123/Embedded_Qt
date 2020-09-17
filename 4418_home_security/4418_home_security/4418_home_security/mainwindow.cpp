#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "facerecognition.h"
#include "environmentalmonitor.h"
#include "homecontrol.h"
#include "weatherquery.h"
#include "common.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//给界面添加可以缩放背景图片
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter myPainter(this);
    myPainter.setOpacity(0.9);          //背景图片透明度
    myPainter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/rec/img/home_background.png"));
}

void MainWindow::InitWindow()
{


}
void MainWindow::on_face_reg_pushButton_clicked()
{
    this->close();
    FaceRecognition *face_reg = new FaceRecognition;
    face_reg->show();
}

void MainWindow::on_env_moni_pushButton_clicked()
{
    this->close();
    EnvironmentalMonitor *env_mon = new EnvironmentalMonitor;
    env_mon->show();
}

void MainWindow::on_home_ctrl_pushButton_clicked()
{
    this->close();
    HomeControl *home_ctrl = new HomeControl;
    home_ctrl->show();
}

void MainWindow::on_weather_query_pushButton_clicked()
{
    this->close();
    WeatherQuery *weather_que = new WeatherQuery;
    weather_que->show();
}
