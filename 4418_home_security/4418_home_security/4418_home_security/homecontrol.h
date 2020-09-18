#ifndef HOMECONTROL_H
#define HOMECONTROL_H

#include <QWidget>
#include <QString>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QMessageBox>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QDebug>

#include <qmqtt.h>

#include "common.h"

namespace Ui {
class HomeControl;
}

class HomeControl : public QWidget
{
    Q_OBJECT

public:
    explicit HomeControl(QWidget *parent = nullptr);
    ~HomeControl();

    QMQTT::Client *client;

private slots:
    void on_home_pushButton_clicked();

    void paintEvent(QPaintEvent *event);   //添加可调节背景图功能函数

    void on_light_checkBox_stateChanged(int arg1);

    void on_door_checkBox_stateChanged(int arg1);

    void on_fan_checkBox_stateChanged(int arg1);

    void Delay_MSec(unsigned int msec);

    void connect_to_server();

    void onSubscribed(const QString &topic);

    void onPublished();

private:
    Ui::HomeControl *ui;

    QImage light_on;
    QImage light_off;
    QImage door_open;
    QImage door_close;
    QImage fan_open;
    QImage fan_close;

    QImage on;
    QImage off;

    quint16 port = 1883;
    QString client_id = "control";
    QString user = "arm_4418";
    QString password = "123456";
    QString topic = "/light/deviceIn";


};

#endif // HOMECONTROL_H
