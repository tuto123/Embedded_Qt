/********************************************************************************
** Form generated from reading UI file 'homecontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMECONTROL_H
#define UI_HOMECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeControl
{
public:
    QPushButton *home_pushButton;
    QCheckBox *light_checkBox;
    QCheckBox *door_checkBox;
    QCheckBox *fan_checkBox;
    QLabel *door_icon_label;
    QLabel *fan_icon_label;
    QLabel *fan_intensity_text_label;
    QLabel *door_intensity_text_label;
    QLabel *light_intensity_text_label_2;
    QLabel *light_icon_label;

    void setupUi(QWidget *HomeControl)
    {
        if (HomeControl->objectName().isEmpty())
            HomeControl->setObjectName(QStringLiteral("HomeControl"));
        HomeControl->resize(1024, 600);
        HomeControl->setStyleSheet(QStringLiteral(""));
        home_pushButton = new QPushButton(HomeControl);
        home_pushButton->setObjectName(QStringLiteral("home_pushButton"));
        home_pushButton->setGeometry(QRect(20, 20, 100, 80));
        home_pushButton->setStyleSheet(QStringLiteral("background-image: url(:/rec/img/home.png);"));
        home_pushButton->setFlat(true);
        light_checkBox = new QCheckBox(HomeControl);
        light_checkBox->setObjectName(QStringLiteral("light_checkBox"));
        light_checkBox->setGeometry(QRect(340, 170, 100, 60));
        light_checkBox->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/rec/img/close.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/rec/img/open.png);\n"
"}"));
        light_checkBox->setCheckable(true);
        light_checkBox->setChecked(false);
        light_checkBox->setAutoRepeat(false);
        light_checkBox->setAutoExclusive(false);
        door_checkBox = new QCheckBox(HomeControl);
        door_checkBox->setObjectName(QStringLiteral("door_checkBox"));
        door_checkBox->setGeometry(QRect(720, 170, 100, 60));
        door_checkBox->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/rec/img/close.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/rec/img/open.png);\n"
"}"));
        door_checkBox->setCheckable(true);
        door_checkBox->setChecked(false);
        door_checkBox->setAutoRepeat(false);
        fan_checkBox = new QCheckBox(HomeControl);
        fan_checkBox->setObjectName(QStringLiteral("fan_checkBox"));
        fan_checkBox->setGeometry(QRect(340, 340, 100, 60));
        fan_checkBox->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
"image: url(:/rec/img/close.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/rec/img/open.png);\n"
"}"));
        fan_checkBox->setCheckable(true);
        fan_checkBox->setChecked(false);
        fan_checkBox->setAutoRepeat(false);
        door_icon_label = new QLabel(HomeControl);
        door_icon_label->setObjectName(QStringLiteral("door_icon_label"));
        door_icon_label->setGeometry(QRect(550, 150, 120, 100));
        door_icon_label->setStyleSheet(QStringLiteral("image: url(:/rec/img/door_close.png);"));
        fan_icon_label = new QLabel(HomeControl);
        fan_icon_label->setObjectName(QStringLiteral("fan_icon_label"));
        fan_icon_label->setGeometry(QRect(210, 320, 120, 100));
        fan_icon_label->setStyleSheet(QStringLiteral("background-image: url(:/rec/img/fan.png);"));
        fan_intensity_text_label = new QLabel(HomeControl);
        fan_intensity_text_label->setObjectName(QStringLiteral("fan_intensity_text_label"));
        fan_intensity_text_label->setGeometry(QRect(220, 430, 130, 30));
        QFont font;
        font.setPointSize(22);
        fan_intensity_text_label->setFont(font);
        fan_intensity_text_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        door_intensity_text_label = new QLabel(HomeControl);
        door_intensity_text_label->setObjectName(QStringLiteral("door_intensity_text_label"));
        door_intensity_text_label->setGeometry(QRect(570, 260, 91, 41));
        door_intensity_text_label->setFont(font);
        door_intensity_text_label->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        light_intensity_text_label_2 = new QLabel(HomeControl);
        light_intensity_text_label_2->setObjectName(QStringLiteral("light_intensity_text_label_2"));
        light_intensity_text_label_2->setGeometry(QRect(220, 260, 130, 30));
        light_intensity_text_label_2->setFont(font);
        light_intensity_text_label_2->setStyleSheet(QStringLiteral("color: rgb(115, 210, 22);"));
        light_icon_label = new QLabel(HomeControl);
        light_icon_label->setObjectName(QStringLiteral("light_icon_label"));
        light_icon_label->setGeometry(QRect(210, 150, 120, 100));
        light_icon_label->setStyleSheet(QStringLiteral("background-image: url(:/rec/img/light_off.png);"));

        retranslateUi(HomeControl);

        QMetaObject::connectSlotsByName(HomeControl);
    } // setupUi

    void retranslateUi(QWidget *HomeControl)
    {
        HomeControl->setWindowTitle(QApplication::translate("HomeControl", "Form", nullptr));
        home_pushButton->setText(QString());
        light_checkBox->setText(QString());
        door_checkBox->setText(QString());
        fan_checkBox->setText(QString());
        door_icon_label->setText(QString());
        fan_icon_label->setText(QString());
        fan_intensity_text_label->setText(QApplication::translate("HomeControl", "\351\243\216\346\211\207\346\216\247\345\210\266", nullptr));
        door_intensity_text_label->setText(QApplication::translate("HomeControl", "\351\227\250\346\216\247\345\210\266", nullptr));
        light_intensity_text_label_2->setText(QApplication::translate("HomeControl", "\347\201\257\345\205\211\346\216\247\345\210\266", nullptr));
        light_icon_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomeControl: public Ui_HomeControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMECONTROL_H
