/********************************************************************************
** Form generated from reading UI file 'environmentalmonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVIRONMENTALMONITOR_H
#define UI_ENVIRONMENTALMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnvironmentalMonitor
{
public:
    QPushButton *home_pushButton;
    QLCDNumber *light_intensity_lcdNumber;
    QLCDNumber *temperture_lcdNumber;
    QLCDNumber *humidity_intensity_lcdNumber;
    QLCDNumber *gas_intensity_lcdNumber;
    QLabel *light_intensity_text_label;
    QLabel *light_intensity_icon_label;
    QLabel *temperture_icon_label;
    QLabel *temperture_text_label;
    QLabel *humidity_icon_label;
    QLabel *humidity__text_label;
    QLabel *gas_icon_label;
    QLabel *gas_text_label;
    QLabel *fan_icon_label;
    QLabel *door_icon_label;
    QLabel *fan_status_label;
    QLabel *door_status_label;
    QLabel *light_icon_label;
    QLabel *light_status_label;
    QLabel *body_icon_label;
    QLabel *body_status_label;

    void setupUi(QWidget *EnvironmentalMonitor)
    {
        if (EnvironmentalMonitor->objectName().isEmpty())
            EnvironmentalMonitor->setObjectName(QStringLiteral("EnvironmentalMonitor"));
        EnvironmentalMonitor->resize(1024, 600);
        home_pushButton = new QPushButton(EnvironmentalMonitor);
        home_pushButton->setObjectName(QStringLiteral("home_pushButton"));
        home_pushButton->setGeometry(QRect(20, 20, 100, 80));
        home_pushButton->setStyleSheet(QStringLiteral("background-image: url(:/rec/img/home.png);"));
        home_pushButton->setFlat(true);
        light_intensity_lcdNumber = new QLCDNumber(EnvironmentalMonitor);
        light_intensity_lcdNumber->setObjectName(QStringLiteral("light_intensity_lcdNumber"));
        light_intensity_lcdNumber->setGeometry(QRect(310, 70, 181, 51));
        light_intensity_lcdNumber->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        temperture_lcdNumber = new QLCDNumber(EnvironmentalMonitor);
        temperture_lcdNumber->setObjectName(QStringLiteral("temperture_lcdNumber"));
        temperture_lcdNumber->setGeometry(QRect(630, 70, 181, 51));
        temperture_lcdNumber->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        humidity_intensity_lcdNumber = new QLCDNumber(EnvironmentalMonitor);
        humidity_intensity_lcdNumber->setObjectName(QStringLiteral("humidity_intensity_lcdNumber"));
        humidity_intensity_lcdNumber->setGeometry(QRect(310, 200, 181, 51));
        humidity_intensity_lcdNumber->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        gas_intensity_lcdNumber = new QLCDNumber(EnvironmentalMonitor);
        gas_intensity_lcdNumber->setObjectName(QStringLiteral("gas_intensity_lcdNumber"));
        gas_intensity_lcdNumber->setGeometry(QRect(630, 200, 181, 51));
        gas_intensity_lcdNumber->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        light_intensity_text_label = new QLabel(EnvironmentalMonitor);
        light_intensity_text_label->setObjectName(QStringLiteral("light_intensity_text_label"));
        light_intensity_text_label->setGeometry(QRect(200, 130, 70, 40));
        QFont font;
        font.setPointSize(22);
        light_intensity_text_label->setFont(font);
        light_intensity_text_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        light_intensity_icon_label = new QLabel(EnvironmentalMonitor);
        light_intensity_icon_label->setObjectName(QStringLiteral("light_intensity_icon_label"));
        light_intensity_icon_label->setGeometry(QRect(190, 60, 90, 70));
        light_intensity_icon_label->setStyleSheet(QStringLiteral("image: url(:/rec/img/light.png);"));
        temperture_icon_label = new QLabel(EnvironmentalMonitor);
        temperture_icon_label->setObjectName(QStringLiteral("temperture_icon_label"));
        temperture_icon_label->setGeometry(QRect(530, 60, 90, 70));
        temperture_icon_label->setStyleSheet(QStringLiteral("image: url(:/rec/img/temperture.png);"));
        temperture_text_label = new QLabel(EnvironmentalMonitor);
        temperture_text_label->setObjectName(QStringLiteral("temperture_text_label"));
        temperture_text_label->setGeometry(QRect(550, 130, 70, 40));
        temperture_text_label->setFont(font);
        temperture_text_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        humidity_icon_label = new QLabel(EnvironmentalMonitor);
        humidity_icon_label->setObjectName(QStringLiteral("humidity_icon_label"));
        humidity_icon_label->setGeometry(QRect(190, 190, 90, 70));
        humidity_icon_label->setStyleSheet(QStringLiteral("image: url(:/rec/img/humidity.png);"));
        humidity__text_label = new QLabel(EnvironmentalMonitor);
        humidity__text_label->setObjectName(QStringLiteral("humidity__text_label"));
        humidity__text_label->setGeometry(QRect(200, 260, 70, 40));
        humidity__text_label->setFont(font);
        humidity__text_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        gas_icon_label = new QLabel(EnvironmentalMonitor);
        gas_icon_label->setObjectName(QStringLiteral("gas_icon_label"));
        gas_icon_label->setGeometry(QRect(530, 190, 90, 70));
        gas_icon_label->setStyleSheet(QStringLiteral("image: url(:/rec/img/gas.png);"));
        gas_text_label = new QLabel(EnvironmentalMonitor);
        gas_text_label->setObjectName(QStringLiteral("gas_text_label"));
        gas_text_label->setGeometry(QRect(550, 260, 70, 40));
        gas_text_label->setFont(font);
        gas_text_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        fan_icon_label = new QLabel(EnvironmentalMonitor);
        fan_icon_label->setObjectName(QStringLiteral("fan_icon_label"));
        fan_icon_label->setGeometry(QRect(30, 310, 120, 100));
        fan_icon_label->setStyleSheet(QStringLiteral(""));
        door_icon_label = new QLabel(EnvironmentalMonitor);
        door_icon_label->setObjectName(QStringLiteral("door_icon_label"));
        door_icon_label->setGeometry(QRect(360, 310, 120, 100));
        door_icon_label->setStyleSheet(QStringLiteral(""));
        fan_status_label = new QLabel(EnvironmentalMonitor);
        fan_status_label->setObjectName(QStringLiteral("fan_status_label"));
        fan_status_label->setGeometry(QRect(200, 320, 131, 91));
        QFont font1;
        font1.setPointSize(47);
        fan_status_label->setFont(font1);
        fan_status_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        door_status_label = new QLabel(EnvironmentalMonitor);
        door_status_label->setObjectName(QStringLiteral("door_status_label"));
        door_status_label->setGeometry(QRect(520, 320, 131, 91));
        door_status_label->setFont(font1);
        door_status_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        light_icon_label = new QLabel(EnvironmentalMonitor);
        light_icon_label->setObjectName(QStringLiteral("light_icon_label"));
        light_icon_label->setGeometry(QRect(690, 310, 120, 100));
        light_icon_label->setStyleSheet(QStringLiteral(""));
        light_status_label = new QLabel(EnvironmentalMonitor);
        light_status_label->setObjectName(QStringLiteral("light_status_label"));
        light_status_label->setGeometry(QRect(850, 320, 131, 91));
        light_status_label->setFont(font1);
        light_status_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        body_icon_label = new QLabel(EnvironmentalMonitor);
        body_icon_label->setObjectName(QStringLiteral("body_icon_label"));
        body_icon_label->setGeometry(QRect(30, 450, 120, 100));
        body_icon_label->setStyleSheet(QStringLiteral(""));
        body_status_label = new QLabel(EnvironmentalMonitor);
        body_status_label->setObjectName(QStringLiteral("body_status_label"));
        body_status_label->setGeometry(QRect(200, 460, 131, 91));
        body_status_label->setFont(font1);
        body_status_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));

        retranslateUi(EnvironmentalMonitor);

        QMetaObject::connectSlotsByName(EnvironmentalMonitor);
    } // setupUi

    void retranslateUi(QWidget *EnvironmentalMonitor)
    {
        EnvironmentalMonitor->setWindowTitle(QApplication::translate("EnvironmentalMonitor", "Form", nullptr));
        home_pushButton->setText(QString());
        light_intensity_text_label->setText(QApplication::translate("EnvironmentalMonitor", "\345\205\211\345\274\272", nullptr));
        light_intensity_icon_label->setText(QString());
        temperture_icon_label->setText(QString());
        temperture_text_label->setText(QApplication::translate("EnvironmentalMonitor", "\346\270\251\345\272\246", nullptr));
        humidity_icon_label->setText(QString());
        humidity__text_label->setText(QApplication::translate("EnvironmentalMonitor", "\346\271\277\345\272\246", nullptr));
        gas_icon_label->setText(QString());
        gas_text_label->setText(QApplication::translate("EnvironmentalMonitor", "\346\260\224\344\275\223", nullptr));
        fan_icon_label->setText(QString());
        door_icon_label->setText(QString());
        fan_status_label->setText(QApplication::translate("EnvironmentalMonitor", "\345\205\263\351\227\255", nullptr));
        door_status_label->setText(QApplication::translate("EnvironmentalMonitor", "\345\205\263\351\227\255", nullptr));
        light_icon_label->setText(QString());
        light_status_label->setText(QApplication::translate("EnvironmentalMonitor", "\345\205\263\351\227\255", nullptr));
        body_icon_label->setText(QString());
        body_status_label->setText(QApplication::translate("EnvironmentalMonitor", "\346\262\241\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnvironmentalMonitor: public Ui_EnvironmentalMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVIRONMENTALMONITOR_H
