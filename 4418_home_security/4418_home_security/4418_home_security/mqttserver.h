#ifndef MQTTSERVER_H
#define MQTTSERVER_H

#include <QString>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QMessageBox>
#include <QObject>
#include <QDebug>
#include <qmqtt.h>

class MqttServer : public QObject
{
    Q_OBJECT

public:
    explicit MqttServer();

    QMQTT::Client *client;

    QHostAddress ip_address = QHostAddress("localhost");
    QString port = "1883";
    QString client_id = "03";
    QString user = "arm_4418";
    QString password = "123456";

    QString received_message;

    QString door_status;
    QString living_room_light_status;
    QString fan_status;
    QString gas_sensitive;
    QString light_sensitive;
    QString temperture;
    QString humidity;

    void connect_to_server();
    void disconnct_to_server();

    void onreceived(const QMQTT::Message &message);

    void parse_message(QString received_message);
};

#endif // MQTTSERVER_H
