/********************************************************************************
** Form generated from reading UI file 'facerecognition.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNITION_H
#define UI_FACERECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRecognition
{
public:
    QPushButton *home_pushButton;
    QLabel *face_detect_label;
    QLabel *tips_label;
    QLabel *face_ok_label;
    QLabel *video_label;
    QPushButton *start_detect_pushButton;
    QPushButton *openc_video_pushButton;
    QPushButton *rt_detect_pushButton;

    void setupUi(QWidget *FaceRecognition)
    {
        if (FaceRecognition->objectName().isEmpty())
            FaceRecognition->setObjectName(QStringLiteral("FaceRecognition"));
        FaceRecognition->resize(1024, 600);
        FaceRecognition->setMinimumSize(QSize(2, 0));
        FaceRecognition->setStyleSheet(QStringLiteral(""));
        home_pushButton = new QPushButton(FaceRecognition);
        home_pushButton->setObjectName(QStringLiteral("home_pushButton"));
        home_pushButton->setGeometry(QRect(20, 20, 100, 80));
        home_pushButton->setStyleSheet(QStringLiteral("background-image: url(:/rec/img/home.png);"));
        home_pushButton->setFlat(true);
        face_detect_label = new QLabel(FaceRecognition);
        face_detect_label->setObjectName(QStringLiteral("face_detect_label"));
        face_detect_label->setGeometry(QRect(520, 180, 500, 400));
        tips_label = new QLabel(FaceRecognition);
        tips_label->setObjectName(QStringLiteral("tips_label"));
        tips_label->setGeometry(QRect(730, 10, 231, 81));
        QFont font;
        font.setPointSize(19);
        tips_label->setFont(font);
        face_ok_label = new QLabel(FaceRecognition);
        face_ok_label->setObjectName(QStringLiteral("face_ok_label"));
        face_ok_label->setGeometry(QRect(770, 70, 100, 100));
        face_ok_label->setStyleSheet(QStringLiteral(""));
        video_label = new QLabel(FaceRecognition);
        video_label->setObjectName(QStringLiteral("video_label"));
        video_label->setGeometry(QRect(4, 180, 500, 400));
        start_detect_pushButton = new QPushButton(FaceRecognition);
        start_detect_pushButton->setObjectName(QStringLiteral("start_detect_pushButton"));
        start_detect_pushButton->setGeometry(QRect(360, 30, 151, 71));
        start_detect_pushButton->setStyleSheet(QLatin1String("QPalette{background:#D7DBE4;}QGroupBox#gboxDevicePanel>QLabel{color:#E7ECF0;}\n"
"\n"
"QWidget#frmMain,QWidget[Form=\"true\"]{\n"
"border:1px solid #738393;\n"
"border-radius:0px;\n"
"}\n"
"\n"
".QFrame{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"}\n"
"\n"
"QLabel,QLineEdit,QTextEdit,QPlainTextEdit,QSpinBox,QGroupBox,QComboBox,QDateEdit,QTimeEdit,QDateTimeEdit,QSpinBox,QTreeView,QListView,QTableView,QTabWidget::pane{\n"
"color:#3D3E42;\n"
"}\n"
"\n"
"QWidget#widget_title{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QLabel#lab_Ico,QLabel#lab_Title{\n"
"border-radius:0px;\n"
"color:#E7ECF0;\n"
"background-color:rgba(0,0,0,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator{\n"
"image:None;\n"
"}\n"
"\n"
"QToolButton,QWidget#widget_frm>QLabel{\n"
"border-style:none;\n"
"padding:10px;\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QToolBut"
                        "ton:hover,QWidget#widget_frm>QLabel:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QLabel[labVideo=\"true\"]{\n"
"color:#E7ECF0;\n"
"border:1px solid #738393;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QLabel[labVideo=\"true\"]:focus{\n"
"border:1px solid #FF0000;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QLineEdit,QTextEdit,QPlainTextEdit,QSpinBox{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"padding:2px;\n"
"background:none;\n"
"selection-background-color:#667481;\n"
"selection-color:#E7ECF0;\n"
"}\n"
"\n"
"QLineEdit[echoMode=\"2\"]{\n"
"lineedit-password-character:9679;\n"
"}\n"
"\n"
".QGroupBox{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"}\n"
"\n"
".QPushButton{\n"
"border-style:none;\n"
"border:1px solid #C2CCD8;\n"
"color:#E7ECF0;\n"
"padding:5px;\n"
"min-height:20px;\n"
"border-r"
                        "adius:5px;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
".QPushButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
".QPushButton:pressed{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
".QPushButton:disabled{\n"
"color:#838383;\n"
"background:#F4F4F4;\n"
"}\n"
"\n"
"QPushButton#btnSplitterH{\n"
"padding:2px;\n"
"min-height:8px;\n"
"}\n"
"\n"
"QPushButton#btnMenu,QPushButton#btnMenu_Min,QPushButton#btnMenu_Max,QPushButton#btnMenu_Close,QPushButton#btnSplitterV,QPushButton#btnSplitterH{\n"
"border-radius:0px;\n"
"color:#E7ECF0;\n"
"background-color:rgba(0,0,0,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QPushButton#btnMenu:hover,QPushButton#btnMenu_Min:hover,QPushButton#btnMenu_Max:hover,QPushButton#btnSplitterV:hover,QPushButton#btnSplitterH:hover{\n"
"background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 r"
                        "gba(25,134,199,0),stop:1 #778899);\n"
"}\n"
"\n"
"QPushButton#btnMenu_Close:hover{\n"
"background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 rgba(238,0,0,128),stop:1 rgba(238,44,44,255));\n"
"}\n"
"\n"
"QCheckBox{\n"
"color:#3D3E42;\n"
"spacing:2px;\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"width:20px;\n"
"height:20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"image:url(:/image/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"image:url(:/image/checkbox_checked.png);\n"
"}\n"
"\n"
"QRadioButton{\n"
"color:#3D3E42;\n"
"spacing:2px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"width:15px;\n"
"height:15px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image:url(:/image/radio_normal.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"image:url(:/image/radio_selected.png);\n"
"}\n"
"\n"
"QSpinBox::up-button,QDateEdit::up-button,QTimeEdit::up-button,QDateTimeEdit::up-button{\n"
"image:url(:/image/add_top.png);\n"
"}\n"
"\n"
"QSpinBox::down-button,QDateE"
                        "dit::down-button,QTimeEdit::down-button,QDateTimeEdit::down-button{\n"
"image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QComboBox,QDateEdit,QTimeEdit,QDateTimeEdit,QSpinBox{\n"
"border-radius:3px;\n"
"padding:3px 5px 3px 5px;\n"
"border:1px solid #C2CCD8;\n"
"background:none;\n"
"selection-background-color:#667481;\n"
"selection-color:#E7ECF0;\n"
"}\n"
"\n"
"QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{\n"
"subcontrol-origin:padding;\n"
"subcontrol-position:top right;\n"
"width:15px;\n"
"border-left-width:1px;\n"
"border-left-style:solid;\n"
"border-top-right-radius:3px;\n"
"border-bottom-right-radius:3px;\n"
"border-left-color:#C2CCD8;\n"
"}\n"
"\n"
"QComboBox::down-arrow,QDateEdit::down-arrow,QTimeEdit::down-arrow,QDateTimeEdit::down-arrow{\n"
"image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QMenu{\n"
"color:#E7ECF0;\n"
"background-color:#667481;\n"
"margin:2px;\n"
"}\n"
"\n"
"QMenu::item{\n"
"padding:3px 20px 3px 20px;\n"
"}\n"
"\n"
"QMenu::indicator{\n"
"width"
                        ":13px;\n"
"height:13px;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#E7ECF0;\n"
"border:0px solid #738393;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QMenu::separator{\n"
"height:1px;\n"
"background:#738393;\n"
"}\n"
"\n"
"QProgressBar{\n"
"background:#C2CCD8;\n"
"border-radius:5px;\n"
"text-align:center;\n"
"border:1px solid #C2CCD8;\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"width:5px;\n"
"margin:0.5px;\n"
"background-color:#667481;\n"
"}\n"
"\n"
"QSlider::groove:horizontal,QSlider::add-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QSlider::handle:horizontal{\n"
"width:13px;\n"
"margin-top:-3px;\n"
"margin-bottom:-3px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #667481,stop:0.8 #778899);\n"
"}\n"
"\n"
"QSlider::groove:ve"
                        "rtical,QSlider::sub-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QSlider::add-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QSlider::handle:vertical{\n"
"height:13px;\n"
"margin-left:-2px;\n"
"margin-right:-3px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #667481,stop:0.8 #778899);\n"
"}\n"
"\n"
"QScrollBar:vertical{\n"
"width:10px;\n"
"background-color:rgba(0,0,0,0%);\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"}\n"
"\n"
"QScrollBar:horizontal{\n"
"height:10px;\n"
"background-color:rgba(0,0,0,0%);\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical,QScrollBar::handle:horizontal{\n"
"width:10px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover,QScrollBar::handle:horizontal:hover{\n"
"width:10px;\n"
"background:#566373;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical{\n"
"height:10px;\n"
""
                        "width:10px;\n"
"subcontrol-position:bottom;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:right;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_right.png);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:top;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_top.png);\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:left;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_left.png);\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical,QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{\n"
"width:10px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QScrollArea{\n"
"border:0px;\n"
"}\n"
"\n"
"QTreeView,QListView,QTableView,QTabWidget::pane{\n"
"border:1px solid #C2CCD8;\n"
"selection-background-color:#77"
                        "8899;\n"
"selection-color:#E7ECF0;\n"
"alternate-background-color:#DDE0E7;\n"
"}\n"
"\n"
"QTableView::item:selected,QListView::item:selected,QTreeView::item:selected{\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QTableView::item:hover,QListView::item:hover,QTreeView::item:hover{\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTableView::item,QListView::item,QTreeView::item{\n"
"padding:5px;\n"
"margin:0px;\n"
"}\n"
"\n"
"QHeaderView::section,QTableCornerButton:section{\n"
"padding:3px;\n"
"margin:0px;\n"
"color:#E7ECF0;\n"
"border:1px solid #C2CCD8;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTabBar::tab{\n"
"border-radius:5px;\n"
"border:1px solid #C2CCD8;\n"
"color:#E7ECF0;\n"
"min-width:55px;\n"
"min-height:20px;\n"
"padding:3px 8px 3px 8px;\n"
"margin:1px;\n"
"background:qlineargr"
                        "adient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTabBar::tab:selected,QTabBar::tab:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QStatusBar::item{\n"
"border:0px solid #667481;\n"
"border-radius:3px;\n"
"}\n"
"\n"
"QToolBox::tab,QToolTip,QGroupBox#gboxDevicePanel{\n"
"padding:3px;\n"
"border-radius: 5px;\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QToolBox::tab:selected{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
""));
        openc_video_pushButton = new QPushButton(FaceRecognition);
        openc_video_pushButton->setObjectName(QStringLiteral("openc_video_pushButton"));
        openc_video_pushButton->setGeometry(QRect(160, 30, 151, 71));
        openc_video_pushButton->setStyleSheet(QLatin1String("QPalette{background:#D7DBE4;}QGroupBox#gboxDevicePanel>QLabel{color:#E7ECF0;}\n"
"\n"
"QWidget#frmMain,QWidget[Form=\"true\"]{\n"
"border:1px solid #738393;\n"
"border-radius:0px;\n"
"}\n"
"\n"
".QFrame{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"}\n"
"\n"
"QLabel,QLineEdit,QTextEdit,QPlainTextEdit,QSpinBox,QGroupBox,QComboBox,QDateEdit,QTimeEdit,QDateTimeEdit,QSpinBox,QTreeView,QListView,QTableView,QTabWidget::pane{\n"
"color:#3D3E42;\n"
"}\n"
"\n"
"QWidget#widget_title{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QLabel#lab_Ico,QLabel#lab_Title{\n"
"border-radius:0px;\n"
"color:#E7ECF0;\n"
"background-color:rgba(0,0,0,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator{\n"
"image:None;\n"
"}\n"
"\n"
"QToolButton,QWidget#widget_frm>QLabel{\n"
"border-style:none;\n"
"padding:10px;\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QToolBut"
                        "ton:hover,QWidget#widget_frm>QLabel:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QLabel[labVideo=\"true\"]{\n"
"color:#E7ECF0;\n"
"border:1px solid #738393;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QLabel[labVideo=\"true\"]:focus{\n"
"border:1px solid #FF0000;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QLineEdit,QTextEdit,QPlainTextEdit,QSpinBox{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"padding:2px;\n"
"background:none;\n"
"selection-background-color:#667481;\n"
"selection-color:#E7ECF0;\n"
"}\n"
"\n"
"QLineEdit[echoMode=\"2\"]{\n"
"lineedit-password-character:9679;\n"
"}\n"
"\n"
".QGroupBox{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"}\n"
"\n"
".QPushButton{\n"
"border-style:none;\n"
"border:1px solid #C2CCD8;\n"
"color:#E7ECF0;\n"
"padding:5px;\n"
"min-height:20px;\n"
"border-r"
                        "adius:5px;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
".QPushButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
".QPushButton:pressed{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
".QPushButton:disabled{\n"
"color:#838383;\n"
"background:#F4F4F4;\n"
"}\n"
"\n"
"QPushButton#btnSplitterH{\n"
"padding:2px;\n"
"min-height:8px;\n"
"}\n"
"\n"
"QPushButton#btnMenu,QPushButton#btnMenu_Min,QPushButton#btnMenu_Max,QPushButton#btnMenu_Close,QPushButton#btnSplitterV,QPushButton#btnSplitterH{\n"
"border-radius:0px;\n"
"color:#E7ECF0;\n"
"background-color:rgba(0,0,0,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QPushButton#btnMenu:hover,QPushButton#btnMenu_Min:hover,QPushButton#btnMenu_Max:hover,QPushButton#btnSplitterV:hover,QPushButton#btnSplitterH:hover{\n"
"background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 r"
                        "gba(25,134,199,0),stop:1 #778899);\n"
"}\n"
"\n"
"QPushButton#btnMenu_Close:hover{\n"
"background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 rgba(238,0,0,128),stop:1 rgba(238,44,44,255));\n"
"}\n"
"\n"
"QCheckBox{\n"
"color:#3D3E42;\n"
"spacing:2px;\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"width:20px;\n"
"height:20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"image:url(:/image/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"image:url(:/image/checkbox_checked.png);\n"
"}\n"
"\n"
"QRadioButton{\n"
"color:#3D3E42;\n"
"spacing:2px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"width:15px;\n"
"height:15px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image:url(:/image/radio_normal.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"image:url(:/image/radio_selected.png);\n"
"}\n"
"\n"
"QSpinBox::up-button,QDateEdit::up-button,QTimeEdit::up-button,QDateTimeEdit::up-button{\n"
"image:url(:/image/add_top.png);\n"
"}\n"
"\n"
"QSpinBox::down-button,QDateE"
                        "dit::down-button,QTimeEdit::down-button,QDateTimeEdit::down-button{\n"
"image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QComboBox,QDateEdit,QTimeEdit,QDateTimeEdit,QSpinBox{\n"
"border-radius:3px;\n"
"padding:3px 5px 3px 5px;\n"
"border:1px solid #C2CCD8;\n"
"background:none;\n"
"selection-background-color:#667481;\n"
"selection-color:#E7ECF0;\n"
"}\n"
"\n"
"QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{\n"
"subcontrol-origin:padding;\n"
"subcontrol-position:top right;\n"
"width:15px;\n"
"border-left-width:1px;\n"
"border-left-style:solid;\n"
"border-top-right-radius:3px;\n"
"border-bottom-right-radius:3px;\n"
"border-left-color:#C2CCD8;\n"
"}\n"
"\n"
"QComboBox::down-arrow,QDateEdit::down-arrow,QTimeEdit::down-arrow,QDateTimeEdit::down-arrow{\n"
"image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QMenu{\n"
"color:#E7ECF0;\n"
"background-color:#667481;\n"
"margin:2px;\n"
"}\n"
"\n"
"QMenu::item{\n"
"padding:3px 20px 3px 20px;\n"
"}\n"
"\n"
"QMenu::indicator{\n"
"width"
                        ":13px;\n"
"height:13px;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#E7ECF0;\n"
"border:0px solid #738393;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QMenu::separator{\n"
"height:1px;\n"
"background:#738393;\n"
"}\n"
"\n"
"QProgressBar{\n"
"background:#C2CCD8;\n"
"border-radius:5px;\n"
"text-align:center;\n"
"border:1px solid #C2CCD8;\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"width:5px;\n"
"margin:0.5px;\n"
"background-color:#667481;\n"
"}\n"
"\n"
"QSlider::groove:horizontal,QSlider::add-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QSlider::handle:horizontal{\n"
"width:13px;\n"
"margin-top:-3px;\n"
"margin-bottom:-3px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #667481,stop:0.8 #778899);\n"
"}\n"
"\n"
"QSlider::groove:ve"
                        "rtical,QSlider::sub-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QSlider::add-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QSlider::handle:vertical{\n"
"height:13px;\n"
"margin-left:-2px;\n"
"margin-right:-3px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #667481,stop:0.8 #778899);\n"
"}\n"
"\n"
"QScrollBar:vertical{\n"
"width:10px;\n"
"background-color:rgba(0,0,0,0%);\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"}\n"
"\n"
"QScrollBar:horizontal{\n"
"height:10px;\n"
"background-color:rgba(0,0,0,0%);\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical,QScrollBar::handle:horizontal{\n"
"width:10px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover,QScrollBar::handle:horizontal:hover{\n"
"width:10px;\n"
"background:#566373;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical{\n"
"height:10px;\n"
""
                        "width:10px;\n"
"subcontrol-position:bottom;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:right;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_right.png);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:top;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_top.png);\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:left;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_left.png);\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical,QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{\n"
"width:10px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QScrollArea{\n"
"border:0px;\n"
"}\n"
"\n"
"QTreeView,QListView,QTableView,QTabWidget::pane{\n"
"border:1px solid #C2CCD8;\n"
"selection-background-color:#77"
                        "8899;\n"
"selection-color:#E7ECF0;\n"
"alternate-background-color:#DDE0E7;\n"
"}\n"
"\n"
"QTableView::item:selected,QListView::item:selected,QTreeView::item:selected{\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QTableView::item:hover,QListView::item:hover,QTreeView::item:hover{\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTableView::item,QListView::item,QTreeView::item{\n"
"padding:5px;\n"
"margin:0px;\n"
"}\n"
"\n"
"QHeaderView::section,QTableCornerButton:section{\n"
"padding:3px;\n"
"margin:0px;\n"
"color:#E7ECF0;\n"
"border:1px solid #C2CCD8;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTabBar::tab{\n"
"border-radius:5px;\n"
"border:1px solid #C2CCD8;\n"
"color:#E7ECF0;\n"
"min-width:55px;\n"
"min-height:20px;\n"
"padding:3px 8px 3px 8px;\n"
"margin:1px;\n"
"background:qlineargr"
                        "adient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTabBar::tab:selected,QTabBar::tab:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QStatusBar::item{\n"
"border:0px solid #667481;\n"
"border-radius:3px;\n"
"}\n"
"\n"
"QToolBox::tab,QToolTip,QGroupBox#gboxDevicePanel{\n"
"padding:3px;\n"
"border-radius: 5px;\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QToolBox::tab:selected{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
""));
        rt_detect_pushButton = new QPushButton(FaceRecognition);
        rt_detect_pushButton->setObjectName(QStringLiteral("rt_detect_pushButton"));
        rt_detect_pushButton->setGeometry(QRect(560, 30, 151, 71));
        rt_detect_pushButton->setStyleSheet(QLatin1String("QPalette{background:#D7DBE4;}QGroupBox#gboxDevicePanel>QLabel{color:#E7ECF0;}\n"
"\n"
"QWidget#frmMain,QWidget[Form=\"true\"]{\n"
"border:1px solid #738393;\n"
"border-radius:0px;\n"
"}\n"
"\n"
".QFrame{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"}\n"
"\n"
"QLabel,QLineEdit,QTextEdit,QPlainTextEdit,QSpinBox,QGroupBox,QComboBox,QDateEdit,QTimeEdit,QDateTimeEdit,QSpinBox,QTreeView,QListView,QTableView,QTabWidget::pane{\n"
"color:#3D3E42;\n"
"}\n"
"\n"
"QWidget#widget_title{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QLabel#lab_Ico,QLabel#lab_Title{\n"
"border-radius:0px;\n"
"color:#E7ECF0;\n"
"background-color:rgba(0,0,0,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QToolButton::menu-indicator{\n"
"image:None;\n"
"}\n"
"\n"
"QToolButton,QWidget#widget_frm>QLabel{\n"
"border-style:none;\n"
"padding:10px;\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QToolBut"
                        "ton:hover,QWidget#widget_frm>QLabel:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QLabel[labVideo=\"true\"]{\n"
"color:#E7ECF0;\n"
"border:1px solid #738393;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QLabel[labVideo=\"true\"]:focus{\n"
"border:1px solid #FF0000;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QLineEdit,QTextEdit,QPlainTextEdit,QSpinBox{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"padding:2px;\n"
"background:none;\n"
"selection-background-color:#667481;\n"
"selection-color:#E7ECF0;\n"
"}\n"
"\n"
"QLineEdit[echoMode=\"2\"]{\n"
"lineedit-password-character:9679;\n"
"}\n"
"\n"
".QGroupBox{\n"
"border:1px solid #C2CCD8;\n"
"border-radius:5px;\n"
"}\n"
"\n"
".QPushButton{\n"
"border-style:none;\n"
"border:1px solid #C2CCD8;\n"
"color:#E7ECF0;\n"
"padding:5px;\n"
"min-height:20px;\n"
"border-r"
                        "adius:5px;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
".QPushButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
".QPushButton:pressed{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
".QPushButton:disabled{\n"
"color:#838383;\n"
"background:#F4F4F4;\n"
"}\n"
"\n"
"QPushButton#btnSplitterH{\n"
"padding:2px;\n"
"min-height:8px;\n"
"}\n"
"\n"
"QPushButton#btnMenu,QPushButton#btnMenu_Min,QPushButton#btnMenu_Max,QPushButton#btnMenu_Close,QPushButton#btnSplitterV,QPushButton#btnSplitterH{\n"
"border-radius:0px;\n"
"color:#E7ECF0;\n"
"background-color:rgba(0,0,0,0);\n"
"border-style:none;\n"
"}\n"
"\n"
"QPushButton#btnMenu:hover,QPushButton#btnMenu_Min:hover,QPushButton#btnMenu_Max:hover,QPushButton#btnSplitterV:hover,QPushButton#btnSplitterH:hover{\n"
"background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 r"
                        "gba(25,134,199,0),stop:1 #778899);\n"
"}\n"
"\n"
"QPushButton#btnMenu_Close:hover{\n"
"background-color:qlineargradient(spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 rgba(238,0,0,128),stop:1 rgba(238,44,44,255));\n"
"}\n"
"\n"
"QCheckBox{\n"
"color:#3D3E42;\n"
"spacing:2px;\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"width:20px;\n"
"height:20px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"image:url(:/image/checkbox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"image:url(:/image/checkbox_checked.png);\n"
"}\n"
"\n"
"QRadioButton{\n"
"color:#3D3E42;\n"
"spacing:2px;\n"
"}\n"
"\n"
"QRadioButton::indicator{\n"
"width:15px;\n"
"height:15px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image:url(:/image/radio_normal.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"image:url(:/image/radio_selected.png);\n"
"}\n"
"\n"
"QSpinBox::up-button,QDateEdit::up-button,QTimeEdit::up-button,QDateTimeEdit::up-button{\n"
"image:url(:/image/add_top.png);\n"
"}\n"
"\n"
"QSpinBox::down-button,QDateE"
                        "dit::down-button,QTimeEdit::down-button,QDateTimeEdit::down-button{\n"
"image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QComboBox,QDateEdit,QTimeEdit,QDateTimeEdit,QSpinBox{\n"
"border-radius:3px;\n"
"padding:3px 5px 3px 5px;\n"
"border:1px solid #C2CCD8;\n"
"background:none;\n"
"selection-background-color:#667481;\n"
"selection-color:#E7ECF0;\n"
"}\n"
"\n"
"QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{\n"
"subcontrol-origin:padding;\n"
"subcontrol-position:top right;\n"
"width:15px;\n"
"border-left-width:1px;\n"
"border-left-style:solid;\n"
"border-top-right-radius:3px;\n"
"border-bottom-right-radius:3px;\n"
"border-left-color:#C2CCD8;\n"
"}\n"
"\n"
"QComboBox::down-arrow,QDateEdit::down-arrow,QTimeEdit::down-arrow,QDateTimeEdit::down-arrow{\n"
"image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QMenu{\n"
"color:#E7ECF0;\n"
"background-color:#667481;\n"
"margin:2px;\n"
"}\n"
"\n"
"QMenu::item{\n"
"padding:3px 20px 3px 20px;\n"
"}\n"
"\n"
"QMenu::indicator{\n"
"width"
                        ":13px;\n"
"height:13px;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#E7ECF0;\n"
"border:0px solid #738393;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QMenu::separator{\n"
"height:1px;\n"
"background:#738393;\n"
"}\n"
"\n"
"QProgressBar{\n"
"background:#C2CCD8;\n"
"border-radius:5px;\n"
"text-align:center;\n"
"border:1px solid #C2CCD8;\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"width:5px;\n"
"margin:0.5px;\n"
"background-color:#667481;\n"
"}\n"
"\n"
"QSlider::groove:horizontal,QSlider::add-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal{\n"
"height:8px;\n"
"border-radius:3px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QSlider::handle:horizontal{\n"
"width:13px;\n"
"margin-top:-3px;\n"
"margin-bottom:-3px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #667481,stop:0.8 #778899);\n"
"}\n"
"\n"
"QSlider::groove:ve"
                        "rtical,QSlider::sub-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QSlider::add-page:vertical{\n"
"width:8px;\n"
"border-radius:3px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QSlider::handle:vertical{\n"
"height:13px;\n"
"margin-left:-2px;\n"
"margin-right:-3px;\n"
"border-radius:6px;\n"
"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #667481,stop:0.8 #778899);\n"
"}\n"
"\n"
"QScrollBar:vertical{\n"
"width:10px;\n"
"background-color:rgba(0,0,0,0%);\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"}\n"
"\n"
"QScrollBar:horizontal{\n"
"height:10px;\n"
"background-color:rgba(0,0,0,0%);\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical,QScrollBar::handle:horizontal{\n"
"width:10px;\n"
"background:#708090;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover,QScrollBar::handle:horizontal:hover{\n"
"width:10px;\n"
"background:#566373;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical{\n"
"height:10px;\n"
""
                        "width:10px;\n"
"subcontrol-position:bottom;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_bottom.png);\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:right;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_right.png);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:top;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_top.png);\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal{\n"
"height:10px;\n"
"width:10px;\n"
"subcontrol-position:left;\n"
"subcontrol-origin:margin;\n"
"border-image:url(:/image/add_left.png);\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical,QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{\n"
"width:10px;\n"
"background:#C2CCD8;\n"
"}\n"
"\n"
"QScrollArea{\n"
"border:0px;\n"
"}\n"
"\n"
"QTreeView,QListView,QTableView,QTabWidget::pane{\n"
"border:1px solid #C2CCD8;\n"
"selection-background-color:#77"
                        "8899;\n"
"selection-color:#E7ECF0;\n"
"alternate-background-color:#DDE0E7;\n"
"}\n"
"\n"
"QTableView::item:selected,QListView::item:selected,QTreeView::item:selected{\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QTableView::item:hover,QListView::item:hover,QTreeView::item:hover{\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTableView::item,QListView::item,QTreeView::item{\n"
"padding:5px;\n"
"margin:0px;\n"
"}\n"
"\n"
"QHeaderView::section,QTableCornerButton:section{\n"
"padding:3px;\n"
"margin:0px;\n"
"color:#E7ECF0;\n"
"border:1px solid #C2CCD8;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTabBar::tab{\n"
"border-radius:5px;\n"
"border:1px solid #C2CCD8;\n"
"color:#E7ECF0;\n"
"min-width:55px;\n"
"min-height:20px;\n"
"padding:3px 8px 3px 8px;\n"
"margin:1px;\n"
"background:qlineargr"
                        "adient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
"\n"
"QTabBar::tab:selected,QTabBar::tab:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QStatusBar::item{\n"
"border:0px solid #667481;\n"
"border-radius:3px;\n"
"}\n"
"\n"
"QToolBox::tab,QToolTip,QGroupBox#gboxDevicePanel{\n"
"padding:3px;\n"
"border-radius: 5px;\n"
"color:#E7ECF0;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #667481,stop:1 #566373);\n"
"}\n"
"\n"
"QToolBox::tab:selected{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #778899,stop:1 #708090);\n"
"}\n"
""));

        retranslateUi(FaceRecognition);

        QMetaObject::connectSlotsByName(FaceRecognition);
    } // setupUi

    void retranslateUi(QWidget *FaceRecognition)
    {
        FaceRecognition->setWindowTitle(QApplication::translate("FaceRecognition", "Form", nullptr));
        home_pushButton->setText(QString());
        face_detect_label->setText(QString());
        tips_label->setText(QApplication::translate("FaceRecognition", "\350\257\267\345\257\271\345\207\206\346\221\204\345\203\217\345\244\264^  ^", nullptr));
        face_ok_label->setText(QString());
        video_label->setText(QString());
        start_detect_pushButton->setText(QApplication::translate("FaceRecognition", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
        openc_video_pushButton->setText(QApplication::translate("FaceRecognition", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", nullptr));
        rt_detect_pushButton->setText(QApplication::translate("FaceRecognition", "\345\256\236\346\227\266\346\243\200\346\265\213\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceRecognition: public Ui_FaceRecognition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNITION_H
