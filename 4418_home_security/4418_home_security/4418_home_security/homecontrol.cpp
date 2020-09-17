#include "homecontrol.h"
#include "ui_homecontrol.h"

#include "mainwindow.h"
#include "common.h"
#include "environmentalmonitor.h"

extern QString door_status_bak;
extern QString living_room_light_status_bak;
extern QString fan_status_bak;


HomeControl::HomeControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeControl)
{
    ui->setupUi(this);

    connect_to_server();

    qDebug() << living_room_light_status_bak;
    qDebug() << door_status_bak;
    qDebug() << fan_status_bak;

    if(living_room_light_status_bak == "开启")
    {
        light_on.load(":/rec/img/light_on.png");

        ui->light_icon_label->setPixmap(QPixmap::fromImage(light_on));
        ui->light_checkBox->setCheckState(Qt::Checked);
    }
    else
    {
        light_off.load(":/rec/img/light_off.png");
        ui->light_icon_label->setPixmap(QPixmap::fromImage(light_off));

    }
    if(door_status_bak == "开启")
    {
        door_open.load(":/rec/img/door.png");
        ui->door_icon_label->setPixmap(QPixmap::fromImage(door_open));

        ui->door_checkBox->setCheckState(Qt::Checked);
    }
    else
    {
        door_close.load(":/rec/img/door_close.png");
        ui->door_icon_label->setPixmap(QPixmap::fromImage(door_close));

    }
    if(fan_status_bak == "开启")
    {
        fan_open.load(":/rec/img/fan_on.png");
        ui->fan_icon_label->setPixmap(QPixmap::fromImage(fan_open));

        ui->fan_checkBox->setCheckState(Qt::Checked);
    }
    else
    {
        fan_close.load(":/rec/img/fan.png");
        ui->fan_icon_label->setPixmap(QPixmap::fromImage(fan_close));

    }
}

HomeControl::~HomeControl()
{
    delete ui;
}

//给界面添加可以缩放背景图片
void HomeControl::paintEvent(QPaintEvent *event)
{
    QPainter myPainter(this);
    myPainter.setOpacity(0.9);          //背景图片透明度
    myPainter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/rec/img/home_ctrl_background.png"));
}

void HomeControl::on_home_pushButton_clicked()
{
    this->close();
    MainWindow *mw = new MainWindow;
    mw->show();
}

void HomeControl::connect_to_server()
{
    client = new QMQTT::Client(QHostAddress("112.74.105.185"), port);
    client->setClientId(client_id);
    client->setUsername(user);
    client->setPassword(password.toUtf8());
    client-> setCleanSession(true);
    client->connectToHost();

    qDebug() << client->host();
    qDebug() << client->port();
    qDebug() << client->clientId();
    qDebug() << client->username();
    qDebug() << client->password();
    qDebug() << client->isConnectedToHost();

    Delay_MSec(30);

    //client->subscribe(topic, 0);
    qDebug() << client->isConnectedToHost() << "connected successful!";

    connect(client, SIGNAL(subscribed(const QString &)), this, SLOT(onSubscribed(const QString &)));
    connect(client, SIGNAL(published(const QMQTT::Message&)), this, SLOT(onPublished()));
}

void HomeControl::onSubscribed(const QString &topic)
{
    qDebug() << "subscribed " + topic + " successful!";
}

void HomeControl::onPublished()
{
    qDebug() << "published successful!";
}

void HomeControl::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

void HomeControl::on_light_checkBox_stateChanged(int arg1)
{

    if (arg1)
    {
        QMQTT::Message msg;
        QByteArray msgpay;
        msgpay[0] = 0x01;
        msgpay[1] = 0x01;
        msgpay[2] = 0x01;

        msg.setQos(0);
        msg.setTopic(topic);
        msg.setPayload(msgpay);

        client->publish(msg);

        light_on.load(":/rec/img/light_on.png");
        ui->light_icon_label->setPixmap(QPixmap::fromImage(light_on));
    }
    else
    {
        QMQTT::Message msg;
        QByteArray msgpay;
        msgpay[0] = 0x01;
        msgpay[1] = 0x01;
        msgpay[2] = 0x00;

        msg.setQos(0);
        msg.setTopic(topic);
        msg.setPayload(msgpay);

        client->publish(msg);

        light_off.load(":/rec/img/light_off.png");
        ui->light_icon_label->setPixmap(QPixmap::fromImage(light_off));

    }
}

void HomeControl::on_door_checkBox_stateChanged(int arg1)
{

    if (arg1)
    {
        QMQTT::Message msg;
        QByteArray msgpay;
        msgpay[0] = 0x04;
        msgpay[1] = 0x01;
        msgpay[2] = 0x01;

        msg.setQos(0);
        msg.setTopic(topic);
        msg.setPayload(msgpay);

        client->publish(msg);

        door_open.load(":/rec/img/door.png");
        ui->door_icon_label->setPixmap(QPixmap::fromImage(door_open));
    }
    else
    {
        QMQTT::Message msg;
        QByteArray msgpay;
        msgpay[0] = 0x04;
        msgpay[1] = 0x01;
        msgpay[2] = 0x00;

        msg.setQos(0);
        msg.setTopic(topic);
        msg.setPayload(msgpay);

        client->publish(msg);

        door_close.load(":/rec/img/door_close.png");
        ui->door_icon_label->setPixmap(QPixmap::fromImage(door_close));

    }
}

void HomeControl::on_fan_checkBox_stateChanged(int arg1)
{

    if (arg1)
    {
        QMQTT::Message msg;
        QByteArray msgpay;
        msgpay[0] = 0x05;
        msgpay[1] = 0x01;
        msgpay[2] = 0x01;

        msg.setQos(0);
        msg.setTopic(topic);
        msg.setPayload(msgpay);

        client->publish(msg);

        fan_open.load(":/rec/img/fan_on.png");
        ui->fan_icon_label->setPixmap(QPixmap::fromImage(fan_open));
    }
    else
    {
        QMQTT::Message msg;
        QByteArray msgpay;
        msgpay[0] = 0x05;
        msgpay[1] = 0x01;
        msgpay[2] = 0x00;

        msg.setQos(0);
        msg.setTopic(topic);
        msg.setPayload(msgpay);

        client->publish(msg);

        fan_close.load(":/rec/img/fan.png");
        ui->fan_icon_label->setPixmap(QPixmap::fromImage(fan_close));

    }
}


