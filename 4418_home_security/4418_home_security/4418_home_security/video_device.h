#ifndef VIDEO_DEVICE_H
#define VIDEO_DEVICE_H

#include <QObject>

#define V4L_BUFFERS_DEFAULT     6//16
#define V4L_BUFFERS_MAX         16//32

class video_device : public QObject
{
    Q_OBJECT
public:
    explicit video_device(QString dev_name);
    int get_frame(unsigned char **yuv_buffer_pointer, size_t *len);
    int unget_frame();
    int yuyv_2_rgb888(const void *p, int size, unsigned char *frame_buffer);
    ~video_device();

private:
    int camera_v4l2_setting(int *dev, unsigned int width, unsigned int height, unsigned int pixelformat, const char *camera_dev, int nbufs, void **mem0);
    int video_open(const char *devname);
    void errno_exit(const char *s);
    int xioctl(int fh, int request, void *arg);
    int video_set_format(int dev, unsigned int w, unsigned int h, unsigned int format);
    int video_set_framerate(int dev);
    int GetFreeRam(int* freeram);
    int video_reqbufs(int dev, int nbufs);
    int video_enable(int dev, int enable);

    unsigned int image_width;
    unsigned int image_hight;
    unsigned int pixelformat;
    unsigned int nbufs;
    int ssss;
    void *mem0[V4L_BUFFERS_MAX];
    char *dev_name;
    int fd;//video0 file
    int index;

signals:

public slots:

};

#endif // VIDEO_DEVICE_H
