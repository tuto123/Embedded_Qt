#ifndef ENVIRONMENTALMONITOR_H
#define ENVIRONMENTALMONITOR_H

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

extern QString door_status_bak;
extern QString living_room_light_status_bak;
extern QString fan_status_bak;

namespace Ui {
class EnvironmentalMonitor;
}

class EnvironmentalMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit EnvironmentalMonitor(QWidget *parent = nullptr);
    ~EnvironmentalMonitor();

    QMQTT::Client *client;



private slots:
    void on_home_pushButton_clicked();

    void paintEvent(QPaintEvent *event);   //添加可调节背景图功能函数

    void connect_to_server();

    void onreceived(const QMQTT::Message &message);

    void onSubscribed(const QString &topic);

    void parse_message(QByteArray received_message);

    void Delay_MSec(unsigned int msec);

private:
    Ui::EnvironmentalMonitor *ui;

    quint16 port = 1883;
    QString client_id = "monitor";
    QString user = "arm_4418";
    QString password = "123";
    QString topic = "/light/deviceOut";

    QString door_status;
    QString living_room_light_status;
    QString fan_status;
    QString gas_sensitive;
    QString light_sensitive;
    QString temperture;
    QString humidity;
    QString body;

    QImage fan_on;
    QImage door_on;
    QImage light_on;
    QImage door_off;
    QImage fan_off;
    QImage light_off;
    QImage body_on;
    QImage body_off;
};

#endif // ENVIRONMENTALMONITOR_H
