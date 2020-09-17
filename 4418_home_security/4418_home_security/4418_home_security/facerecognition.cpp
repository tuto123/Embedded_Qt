#include "facerecognition.h"
#include "ui_facerecognition.h"

#include "mainwindow.h"
#include "common.h"

#define image_width 320 //图片显示宽度
#define image_height 240    //图片显示高度
#define image_Format QImage::Format_RGB888 //图片显示格式
#define cameraDevice "/dev/video0"  //摄像头设备
#define imgSizeScaleSmall 0.5    //图像防缩比例
#define imgSizeScaleBig 2    //图像防缩比例

FaceRecognition::FaceRecognition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaceRecognition)
{
    ui->setupUi(this);
    InitWindow();

    vd = new video_device("/dev/video0");
    timer_open_video = new QTimer(this);
    timer_detect_face = new QTimer(this);

    connect(timer_open_video, SIGNAL(timeout()), this, SLOT(update_video()));
    connect(timer_detect_face, SIGNAL(timeout()), this, SLOT(update_face()));
}

FaceRecognition::~FaceRecognition()
{
    delete ui;
}

//给界面添加可以缩放背景图片
void FaceRecognition::paintEvent(QPaintEvent *event)
{
    QPainter myPainter(this);
    myPainter.setOpacity(0.9);          //背景图片透明度
    myPainter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/rec/img/face_rec_background.png"));
}

void FaceRecognition::on_home_pushButton_clicked()
{
    vd->~video_device();
    timer_open_video->stop();
    timer_detect_face->stop();
    this->close();
    MainWindow *mw = new MainWindow;
    mw->show();
}

void FaceRecognition::InitWindow()
{
    face_detecting.load(":/rec/img/face_decting.png"); //mnt/qt_projects/4418_home_security/4418_home_security/4418_home_security
    faceok.load(":/rec/img/face_ok.png");
    facefail.load(":/rec/img/face_fail.png");

    detect_whether = 1;
    open_whether = 1;
    rt_detect_whether = 1;
    ui->face_ok_label->clear();

    ui->tips_label->setVisible(false);
    ui->face_ok_label->setVisible(false);

}

void FaceRecognition::on_openc_video_pushButton_clicked()
{
    if(open_whether)
    {
        open_whether = 0;
        ui->tips_label->setVisible(true);
        ui->openc_video_pushButton->setText("关闭摄像头");
        timer_open_video->start(30);
    }
    else
    {
        open_whether = 1;
        ui->tips_label->setVisible(false);
        ui->face_ok_label->setVisible(false);
        ui->face_detect_label->setVisible(false);
        ui->openc_video_pushButton->setText("开启摄像头");
        timer_open_video->stop();
        timer_detect_face->stop();
        ui->video_label->clear();
        ui->face_detect_label->clear();
    }
}


void FaceRecognition::on_start_detect_pushButton_clicked()
{
    if(detect_whether && !open_whether)
    {
        detect_whether = 0;
        ui->face_ok_label->setVisible(true);
        ui->face_detect_label->setVisible(true);
        ui->start_detect_pushButton->setText("停止检测");
        timer_detect_face->start(30);
    }
    else if(!detect_whether && !open_whether)
    {
        detect_whether = 1;
        ui->face_ok_label->setVisible(false);
        ui->face_detect_label->clear();
        ui->start_detect_pushButton->setText("开始检测");
        timer_detect_face->stop();
    }
    else if (detect_whether && open_whether)
    {
        QMessageBox::about(NULL, "提示", "请先打开摄像头!");
    }
}

void FaceRecognition::on_rt_detect_pushButton_clicked()
{
    if(rt_detect_whether && !open_whether)
    {
        rt_detect_whether = 0;
        timer_detect_face->start(30);
        ui->face_detect_label->setVisible(true);
        ui->rt_detect_pushButton->setText("实时检测开");
    }
    else if(!rt_detect_whether && !open_whether)
    {
        rt_detect_whether = 1;
        timer_detect_face->stop();
        ui->rt_detect_pushButton->setText("实时检测关");
    }
    else if (rt_detect_whether && open_whether)
    {
        QMessageBox::about(NULL, "提示", "请先打开摄像头!");
    }
}

void FaceRecognition::update_video()
{
    QPixmap pix;
    QByteArray aa ;
    BITMAPFILEHEADER   bf;
    BITMAPINFOHEADER   bi;

    //Set BITMAPINFOHEADER
    bi.biSize = 40;
    bi.biWidth = IMAGEWIDTH;
    bi.biHeight = IMAGEHEIGHT;
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biCompression = 0;
    bi.biSizeImage = IMAGEWIDTH*IMAGEHEIGHT*3;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    //Set BITMAPFILEHEADER
    bf.bfType = 0x4d42;
    bf.bfSize = 54 + bi.biSizeImage;
    bf.bfReserved = 0;
    bf.bfOffBits = 54;

   if(-1 == vd->get_frame(&yuv_buffer_pointer, &len))
   {
        qDebug() << " get_frame fail";
   }

   vd->yuyv_2_rgb888(yuv_buffer_pointer,len, rgb_frame_buffer);

   aa.append((const char *)&bf, 14);
   aa.append((const char *)&bi, 40);
   aa.append((const char *)rgb_frame_buffer, bi.biSizeImage);

   pix.loadFromData(aa);
   ui->video_label->setPixmap(pix);

   if(!detect_whether || !rt_detect_whether)
   {
       src_image = pix.toImage();
       src_bak = QImageToIplImage(&src_image);
   }
   if(-1 == vd->unget_frame())
   {
        qDebug() << " unget_frame fail";
   }
}

void FaceRecognition::update_face()
{
    struct timeval tpstart,tpend;
    float timeuse;
    gettimeofday(&tpstart,NULL);
    face_out = detect_and_draw(cvarrToMat(src_bak));
    gettimeofday(&tpend,NULL);
    timeuse=(1000000*(tpend.tv_sec-tpstart.tv_sec) + tpend.tv_usec-tpstart.tv_usec)/1000000.0;
    printf("detect time:    %f\n",timeuse);
    face = MatToQImage(face_out);
    ui->face_detect_label->setPixmap(QPixmap::fromImage(face));
    qDebug() << "face detecting!\n";
}

Mat FaceRecognition::detect_and_draw(Mat src)
{
    faces_num=0;
    CascadeClassifier ccf;   //创建分类器对象
    if(!ccf.load("/mnt/xml/haarcascade_frontalface_alt.xml")) //加载训练文件
    {
       QMessageBox::about(NULL, "提示", "加载分类器失败!");
       timer_detect_face->stop();
       return src;
    }

    std::vector<Rect> faces;        //创建一个容器保存检测出来的脸
    Mat gray;
    cvtColor(src,gray,CV_BGR2GRAY); //转换成灰度图，因为harr特征从灰度图中提取
    equalizeHist(gray,gray);        //直方图均衡行

    ccf.detectMultiScale(gray,faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) ); //检测人脸

   for(std::vector<Rect>::const_iterator iter=faces.begin();iter!=faces.end();iter++)
    {
        rectangle(src,*iter,Scalar(0,0,255),2,8); //画出脸部矩形
        ++faces_num;
    }
   if(faces_num == 0)
   {
       ui->face_ok_label->setPixmap(QPixmap::fromImage(face_detecting));
   }
   if(faces_num >= 1 && rt_detect_whether)
   {
       ui->face_ok_label->setPixmap(QPixmap::fromImage(faceok));
       ui->start_detect_pushButton->setText("开始检测");
       timer_detect_face->stop();
       detect_whether = 1;
   }
    printf("faces_num:\t%d\n",faces_num);
    return src;
}

QImage FaceRecognition::MatToQImage(cv::Mat mtx)   //将Mat图像转为QImage格式
{
    switch (mtx.type())  {
    case CV_8UC3:
        {
            QImage img((const unsigned char *)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 3, QImage::Format_RGB888);
            return img.rgbSwapped();                            //返回将RGB格式转换为BGR格式
        }
        break;
    default:
        {
            QImage img;
            return img;
        }
        break;
    }
}

//QImage 转 IplImage
IplImage* FaceRecognition::QImageToIplImage(const QImage * qImage)
{
    int width = qImage->width();
    int height = qImage->height();
    CvSize Size;
    Size.height = height;
    Size.width = width;
    IplImage *IplImageBuffer = cvCreateImage(Size, IPL_DEPTH_8U, 3);    //记着释放内存
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            QRgb rgb = qImage->pixel(x, y);
            cvSet2D(IplImageBuffer, y, x, CV_RGB(qRed(rgb), qGreen(rgb), qBlue(rgb)));
        }
    }
    return IplImageBuffer;
}





