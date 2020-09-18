#include "environmentalmonitor.h"
#include "ui_environmentalmonitor.h"

#include "mainwindow.h"
#include "common.h"

QString door_status_bak;
QString living_room_light_status_bak;
QString fan_status_bak;

EnvironmentalMonitor::EnvironmentalMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvironmentalMonitor)
{
    ui->setupUi(this);

    connect_to_server();

    fan_off.load(":/rec/img/fan.png");
    ui->fan_icon_label->setPixmap(QPixmap::fromImage(fan_off));
    door_off.load(":/rec/img/door_close.png");
    ui->door_icon_label->setPixmap(QPixmap::fromImage(door_off));
    light_off.load(":/rec/img/big_light_off.png");
    ui->light_icon_label->setPixmap(QPixmap::fromImage(light_off));
    body_off.load(":/rec/img/body_off.png");
    ui->body_icon_label->setPixmap(QPixmap::fromImage(body_off));
}

EnvironmentalMonitor::~EnvironmentalMonitor()
{
    delete ui;
}

//给界面添加可以缩放背景图片
void EnvironmentalMonitor::paintEvent(QPaintEvent *event)
{
    QPainter myPainter(this);
    myPainter.setOpacity(0.9);          //背景图片透明度
    myPainter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/rec/img/env_moni_background.png"));
}

void EnvironmentalMonitor::on_home_pushButton_clicked()
{
    this->close();
    MainWindow *mw = new MainWindow;
    mw->show();
}

void EnvironmentalMonitor::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

void EnvironmentalMonitor::connect_to_server()
{
    client = new QMQTT::Client(QHostAddress("localhost"), port);
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

    client->subscribe(topic, 0);
    qDebug() << client->isConnectedToHost() << "connected successful!";

    connect(client, SIGNAL(subscribed(const QString &)), this, SLOT(onSubscribed(const QString &)));
    connect(client, SIGNAL(received(const QMQTT::Message &)), this, SLOT(onreceived(const QMQTT::Message &)));
}

void EnvironmentalMonitor::onSubscribed(const QString &topic)
{
    qDebug() << "subscribed " + topic + " successful!";
}

void EnvironmentalMonitor::onreceived(const QMQTT::Message &message)
{
    qDebug() << "received message: \"" << QString::fromUtf8(message.payload())
                << "\"" << endl;

    parse_message(message.payload());

    ui->door_status_label->setText(door_status);
    ui->fan_status_label->setText(fan_status);
    ui->light_intensity_lcdNumber->display(light_sensitive);
    ui->temperture_lcdNumber->display(temperture);
    ui->humidity_intensity_lcdNumber->display(humidity);
    ui->gas_intensity_lcdNumber->display(gas_sensitive);
    ui->light_status_label->setText(living_room_light_status);
    ui->body_status_label->setText(body);

    fan_status_bak = fan_status;
    door_status_bak = door_status;
    living_room_light_status_bak = living_room_light_status;

    if(fan_status == "开启")
    {
        fan_on.load(":/rec/img/fan_on.png");
        ui->fan_icon_label->setPixmap(QPixmap::fromImage(fan_on));
    }
    else
    {
        fan_off.load(":/rec/img/fan.png");
        ui->fan_icon_label->setPixmap(QPixmap::fromImage(fan_off));
    }

    if(door_status == "开启")
    {
        door_on.load(":/rec/img/door.png");
        ui->door_icon_label->setPixmap(QPixmap::fromImage(door_on));
    }
    else
    {
        door_off.load(":/rec/img/door_close.png");
        ui->door_icon_label->setPixmap(QPixmap::fromImage(door_off));
    }

    if( living_room_light_status == "开启")
    {
        light_on.load(":/rec/img/big_light_on.png");
        ui->light_icon_label->setPixmap(QPixmap::fromImage(light_on));
    }
    else
    {
        light_off.load(":/rec/img/big_light_off.png");
        ui->light_icon_label->setPixmap(QPixmap::fromImage(light_off));
    }

    if( body == "有人")
    {
        body_off.load(":/rec/img/body_on.png");
        ui->body_icon_label->setPixmap(QPixmap::fromImage(body_off));
    }
    else
    {
        body_on.load(":/rec/img/body_off.png");
        ui->body_icon_label->setPixmap(QPixmap::fromImage(body_on));
    }
}

void EnvironmentalMonitor::parse_message(QByteArray received_message)
{
    QJsonParseError json_error;
    QJsonDocument parse_document = QJsonDocument::fromJson(received_message, &json_error);

    received_message.clear();

    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_document.isObject())
        {
           QJsonObject obj = parse_document.object();
           if(obj.contains("Door"))
           {
               QJsonValue door_status_value = obj.take("Door");
               if(door_status_value.toString() == "1")
               {
                   door_status = "开启";
               }
               else
               {
                   door_status = "关闭";
               }
           }
           if(obj.contains("LED"))
           {
               QJsonValue living_room_light_status_value = obj.take("LED");
               if(living_room_light_status_value.toString() == "1")
               {
                   living_room_light_status = "开启";
               }
               else
               {
                   living_room_light_status = "关闭";
               }
           }
           if(obj.contains("Fan"))
           {
               QJsonValue fan_status_value = obj.take("Fan");
               if(fan_status_value.toString() == "1")
               {
                   fan_status = "开启";
               }
               else
               {
                   fan_status = "关闭";
               }
           }
           if(obj.contains("Gas"))
           {
               QJsonValue gas_sensitive_value = obj.take("Gas");
               gas_sensitive = gas_sensitive_value.toString();
           }
           if(obj.contains("Light"))
           {
               QJsonValue light_sensitive_value = obj.take("Light");
               light_sensitive = light_sensitive_value.toString();
           }
           if(obj.contains("Temp"))
           {
               QJsonValue temperture_value = obj.take("Temp");
               temperture = temperture_value.toString();
           }
           if(obj.contains("Humi"))
           {
               QJsonValue humidity_value = obj.take("Humi");
               humidity = humidity_value.toString();
           }
           if(obj.contains("Body"))
           {
               QJsonValue body_value = obj.take("Body");
               if(body_value.toString() == "1")
               {
                   body = "有人";
               }
               else
               {
                   body = "没人";
               }
           }
        }
    }
}
