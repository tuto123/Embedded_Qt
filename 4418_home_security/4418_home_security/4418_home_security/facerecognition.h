#ifndef FACERECOGNITION_H
#define FACERECOGNITION_H

#include <QWidget>
#include <QMessageBox>
#include <QImage>
#include <QLineEdit>
#include <QObject>
#include <QBoxLayout>
#include <QTimer>
#include <QDebug>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/types_c.h>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

#include <sys/time.h>
#include "video_device.h"
#include "v4l2grab.h"
#include "common.h"

namespace Ui {
class FaceRecognition;
}

class FaceRecognition : public QWidget
{
    Q_OBJECT

public:
    explicit FaceRecognition(QWidget *parent = nullptr);
    ~FaceRecognition();

    unsigned char rgb_frame_buffer[IMAGEWIDTH*IMAGEHEIGHT*3];

private slots:
    void on_home_pushButton_clicked();

    void InitWindow();

    void on_start_detect_pushButton_clicked();

    void update_video();
    void update_face();

    QImage MatToQImage(cv::Mat mtx);
    Mat detect_and_draw(Mat image);
    IplImage* QImageToIplImage(const QImage * qImage);

    void on_openc_video_pushButton_clicked();

    void paintEvent(QPaintEvent *event);   //添加可调节背景图功能函数

    void on_rt_detect_pushButton_clicked();

private:
    Ui::FaceRecognition *ui;

    QImage faceok;
    QImage face_detecting;
    QImage facefail;

    int open_whether;
    int detect_whether;
    int rt_detect_whether;

    QTimer *timer_open_video;
    QTimer *timer_detect_face;

    video_device *vd;
    size_t len;
    unsigned char *yuv_buffer_pointer;

    QImage src_image;
    IplImage *src_bak;
    Mat face_out;
    QImage face;

    int faces_num;




};

#endif // FACERECOGNITION_H
