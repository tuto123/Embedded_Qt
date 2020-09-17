#include "mqttserver.h"
#include "common.h"

MqttServer::MqttServer()
{

}

void MqttServer::connect_to_server()
{
    client = new QMQTT::Client(ip_address, port.toUShort());
    client->setClientId(client_id);
    client->setUsername(user);
    client->setPassword(password.toUtf8());
    client->connectToHost();

    qDebug() << client->host();
    qDebug() << client->port();
    qDebug() << client->clientId();
    qDebug() << client->username();
    qDebug() << client->password();
    qDebug() << client->isConnectedToHost();


    if(1)
    {
        client->subscribe("zigbee", 0);
        qDebug() << client->host();
        QObject::connect(client,&QMQTT::Client::received, this, &MqttServer::onreceived);
    }
    else
    {
        QMessageBox::about(nullptr, nullptr, "请检查服务器连接!");
    }
}

void MqttServer::disconnct_to_server()
{
    client->unsubscribe("zigbee");
    client->disconnectFromHost();
}

void MqttServer::onreceived(const QMQTT::Message &message)
{
    received_message = message.payload();

    parse_message(received_message);
    qDebug() << client->host();
}

void MqttServer::parse_message(QString received_message)
{
    QByteArray received_json_data = received_message.toUtf8();
    QJsonParseError json_error;
    QJsonDocument parse_document = QJsonDocument::fromJson(received_json_data, &json_error);

    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_document.isObject())
        {
           QJsonObject obj = parse_document.object();
           if(obj.contains("Door"))
           {
               QJsonValue door_status_value = obj.take("Door");
               door_status = door_status_value.toString();
           }
           if(obj.contains("Living_room_light"))
           {
               QJsonValue living_room_light_status_value = obj.take("Living_room_light");
               living_room_light_status = living_room_light_status_value.toString();
           }
           if(obj.contains("Fan"))
           {
               QJsonValue fan_status_value = obj.take("Fan");
               fan_status= fan_status_value.toString();
           }
           if(obj.contains("Gas_sensitive"))
           {
               QJsonValue gas_sensitive_value = obj.take("Gas_sensitive");
               gas_sensitive = gas_sensitive_value.toString();
           }
           if(obj.contains("Light_sensitive"))
           {
               QJsonValue light_sensitive_value = obj.take("Light_sensitive");
               light_sensitive = light_sensitive_value.toString();
           }
           if(obj.contains("Temperture"))
           {
               QJsonValue temperture_value = obj.take("Temperture");
               temperture = temperture_value.toString();
           }
           if(obj.contains("Humidity"))
           {
               QJsonValue humidity_value = obj.take("Humidity");
               humidity = humidity_value.toString();
           }
        }
    }
}
