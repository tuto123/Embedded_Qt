#ifndef WEATHERQUERY_H
#define WEATHERQUERY_H

#include <QWidget>
#include <QMessageBox>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class WeatherQuery;
}

class WeatherQuery : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherQuery(QWidget *parent = nullptr);
    ~WeatherQuery();

private slots:
    void InitWindow();  //初始化界面功能

    void paintEvent(QPaintEvent *event);   //添加可调节背景图功能函数

    void on_home_pushButton_clicked();

    void on_ch_que_city_comboBox_activated(const QString &arg1);

    void on_weather_que_pushButton_clicked();

    void weather_que(); //天气查询功能

    void finish_weather_que(QNetworkReply *reply);

private:
    Ui::WeatherQuery *ui;

    QNetworkAccessManager *manager;  //请求句柄
    QNetworkRequest weather_que_req;    //天气查询请求网址

    QString weather_website;    //查询所需天气的网址
    QString que_city;           //需要查询天气的城市
    QString weather;            //获取的天气
    QString temperture;         //获取的温度
    QString wind;               //获取的风力
    QString advice;             //获取的推荐


};

#endif // WEATHERQUERY_H
