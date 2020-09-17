#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void InitWindow();

    void paintEvent(QPaintEvent *event);   //添加可调节背景图功能函数

    void on_face_reg_pushButton_clicked();

    void on_env_moni_pushButton_clicked();

    void on_home_ctrl_pushButton_clicked();

    void on_weather_query_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
