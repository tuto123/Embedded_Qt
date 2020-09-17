#include <QDebug>
#include <QByteArray>
#include <QFile>
#include <QtGui>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/time.h>
#include <linux/videodev2.h>
#include <linux/version.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include "video_device.h"
#include "v4l2grab.h"

static int verbose = 1;
#define pr_debug(fmt, arg...) \
    if (verbose) qDebug(fmt, ##arg)

#define CLEAR(x) memset(&(x), 0, sizeof(x))

video_device::video_device(QString devn)
{
    int ret, dev;

    QByteArray ba = devn.toLocal8Bit();
    char *c_str = ba.data();

    this->dev_name = c_str;
    this->image_width = 640;
    this->image_hight = 480;
    this->nbufs = 6;
    this->fd = -1;
    this->pixelformat = V4L2_PIX_FMT_YUYV;

    ret = camera_v4l2_setting(&dev, image_width, image_hight, pixelformat, dev_name, nbufs, mem0 );
    if ((-1 == dev) || (-1 == ret))
    {
        qDebug("Cannot open '%s': %d, %s\n", dev_name, errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Start streamin
    ret = video_enable(dev, 1);
    if(-1 == ret)
    {
        qDebug("starting video streaming fail");
        exit(EXIT_FAILURE);
    }
}

video_device::~video_device()
{
    int ret;
    unsigned int i;

    ret = video_enable(fd, 0);
    if(-1 == ret)
    {
        qDebug("stoping video streaming fail");
       // exit(EXIT_FAILURE);
    }
    //uninit_device
    for (i = 0; i < nbufs; ++i)
    {
        if (-1 == munmap(mem0[i], ssss))
        {
            errno_exit("munmap");
           // return 1;
        }
    }
    //close device
    if (-1 == close(fd))
    {
        errno_exit("close");
        //return 1;
    }
    printf("close video device successful!\n");
    fd = -1;
}

int video_device::camera_v4l2_setting(int *dev, unsigned int width, unsigned int height, unsigned int pixelformat, const char *camera_dev, int nbufs, void **mem0)
{
    int freeram;
    struct v4l2_buffer buf0;
    int i, ret;

    *dev = video_open(camera_dev);
    if (*dev < 0)
    {
        qDebug("Cannot identify '%s': %d, %s\n", camera_dev, errno, strerror(errno));
        return -1;
    }
    fd = *dev;

    printf("%d\n", *dev);

    // Set the video format
    if(-1 == video_set_format(*dev, width, height, pixelformat))
    {
        if(pixelformat == V4L2_PIX_FMT_H264)
        {
            fprintf(stderr, " === Set Format Failed : skip for H264 ===  \n");
            return -1;
        }
        else
        {
            close(*dev);
            return -1;
        }
    }

    // Set the frame rate.
    if(-1 == video_set_framerate(*dev))
    {
        close(*dev);
        return -1;
    }

    if((-1 == GetFreeRam(&freeram)) || freeram<1843200*nbufs+4194304)
    {
        qDebug("free memory isn't enough(%d)\n",freeram);
        close(*dev);
        return -1;
    }

    // Allocate buffers.
    if (-1 == video_reqbufs(*dev, nbufs))
    {
        close(*dev);
        return -1;
    }

    // Map the buffe
    for (i = 0; i < nbufs; ++i)
    {
        CLEAR(buf0);
        buf0.index = i;
        buf0.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf0.memory = V4L2_MEMORY_MMAP;

        if (-1 == xioctl(*dev, VIDIOC_QUERYBUF, &buf0))
        {
            errno_exit("VIDIOC_QUERYBUF");
            close(*dev);
            return -1;
        }
        /*
            pr_debug("\n");
            pr_debug("\tbuf.index: %d\n", buf0.index);
            pr_debug("\tbuf.type: %d\n", buf0.type);
            pr_debug("\tbuf.bytesused: %d\n", buf0.bytesused);
            pr_debug("\tbuf.flags: %d\n", buf0.flags);
            pr_debug("\tbuf.field: %d\n", buf0.field);
            pr_debug("\tbuf.timestamp.tv_sec: %ld\n", (long) buf0.timestamp.tv_sec);
            pr_debug("\tbuf.timestamp.tv_usec: %ld\n", (long) buf0.timestamp.tv_usec);
            pr_debug("\tbuf.timecode.type: %d\n", buf0.timecode.type);
            pr_debug("\tbuf.timecode.flags: %d\n", buf0.timecode.flags);
            pr_debug("\tbuf.timecode.frames: %d\n", buf0.timecode.frames);
            pr_debug("\tbuf.timecode.seconds: %d\n", buf0.timecode.seconds);
            pr_debug("\tbuf.timecode.minutes: %d\n", buf0.timecode.minutes);
            pr_debug("\tbuf.timecode.hours: %d\n", buf0.timecode.hours);
            pr_debug("\tbuf.timecode.userbits: %d,%d,%d,%d\n",
            buf0.timecode.userbits[0],
            buf0.timecode.userbits[1],
            buf0.timecode.userbits[2],
            buf0.timecode.userbits[3]);
            pr_debug("\tbuf.sequence: %d\n", buf0.sequence);
            pr_debug("\tbuf.memory: %d\n", buf0.memory);
            pr_debug("\tbuf.m.offset: %d\n", buf0.m.offset);
            pr_debug("\tbuf.length: %d\n", buf0.length);
            pr_debug("\tbuf.input: %d\n", buf0.input);
            */
        qDebug("length: %u offset: %10u     --  ", buf0.length, buf0.m.offset);

        mem0[i] = mmap(NULL /*  start anywhere */,
                buf0.length,
                PROT_READ,// | PROT_WRITE /*  required */,
                MAP_SHARED /*  recommended */,
                *dev, buf0.m.offset);
        if (mem0[i] == MAP_FAILED)
        {
            qDebug("Unable to map buffer %u (%d)\n", i, errno);
            close(*dev);
            return -1;
        }
        qDebug("Buffer %u mapped at address %p.\n", i, mem0[i]);
        ssss = buf0.length;
    }

    // Queue the buffer
    for (i = 0; i < nbufs; i++)
    {
        CLEAR(buf0);
        buf0.index = i;
        buf0.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf0.memory = V4L2_MEMORY_MMAP;
        ret = xioctl(*dev, VIDIOC_QBUF, &buf0);
        pr_debug("\terr: %d   ---   ", ret);

        if (-1 == ret)
        {
            errno_exit("VIDIOC_QBUF");
            close(*dev);
            return -1;
        }
        pr_debug("buffer %d -> queued!\n",i);
    }

    qDebug() << "camera_v4l2_setting ok------------";
    return 0;
}
void video_device::errno_exit(const char *s)
{
    qDebug("%s error %d, %s\n", s, errno, strerror(errno));
}
int video_device::xioctl(int fh, int request, void *arg)
{
    int r;

    do
    {
        r = ioctl(fh, request, arg);
    } while (-1 == r && EINTR == errno);

    return r;
}
int video_device::video_open(const char *devname)
{
    struct v4l2_capability cap;
    struct v4l2_cropcap cropcap;
    struct v4l2_crop crop;
    int dev, ret;

    dev = open(devname, O_RDWR/*   | O_NONBLOCK*/);
    if (dev < 0)
    {
        qDebug("Cannot open '%s': %d, %s\n", devname, errno, strerror(errno));
        return -1;
    }

    // VIDIOC_QUERYCAP : It is used to identify kernel devices compatible with this specification
    // 		     and to obtain information about driver and hardware capabilities.
    CLEAR(cap);
    ret = xioctl(dev, VIDIOC_QUERYCAP, &cap);
    if (ret < 0)
    {
        if (EINVAL == errno)
        {
            qDebug("%s is no V4L2 device\n", devname);
            return -1;
        }
        else
        {
            errno_exit("VIDIOC_QUERYCAP");
            return -1;
        }
    }

    pr_debug("\tdriver: %s\n" "\tcard: %s \n" "\tbus_info: %s\n", cap.driver, cap.card, cap.bus_info);
    pr_debug("\tversion: %u.%u.%u\n", (cap.version >> 16) & 0xFF, (cap.version >> 8) & 0xFF, cap.version & 0xFF);
    pr_debug("\tcapabilities: 0x%08x\n", cap.capabilities);

    if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE))
    {
        qDebug("%s is no video capture device\n", devname);
        return -1;
    }
    if (!(cap.capabilities & V4L2_CAP_STREAMING))
    {
        qDebug("%s does not support streaming i/o\n", devname);
        return -1;
    }
    /*  Select video input, video standard and tune here. */
    CLEAR(cropcap);
    cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    if (0 == xioctl(dev, VIDIOC_CROPCAP, &cropcap))
    {
        pr_debug("\tcropcap.type: %d\n", cropcap.type);
        pr_debug("\tcropcap.bounds.left: %d\n", cropcap.bounds.left);
        pr_debug("\tcropcap.bounds.top: %d\n", cropcap.bounds.top);
        pr_debug("\tcropcap.bounds.width: %d\n", cropcap.bounds.width);
        pr_debug("\tcropcap.bounds.height: %d\n", cropcap.bounds.height);

        pr_debug("\tcropcap.defrect.left: %d\n", cropcap.defrect.left);
        pr_debug("\tcropcap.defrect.top: %d\n", cropcap.defrect.top);
        pr_debug("\tcropcap.defrect.width: %d\n", cropcap.defrect.width);
        pr_debug("\tcropcap.defrect.height: %d\n", cropcap.defrect.height);

        pr_debug("\tcropcap.pixelaspect.numerator: %d\n", cropcap.pixelaspect.numerator);
        pr_debug("\tcropcap.pixelaspect.denominator: %d\n", cropcap.pixelaspect.denominator);
        pr_debug("\n");

        CLEAR(crop);
        crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        crop.c = cropcap.defrect; /*  reset to default */

        if (-1 == xioctl(dev, VIDIOC_S_CROP, &crop))
        {
            switch (errno)
            {
                case EINVAL:
                    /*  Cropping not supported. */
                    break;
                default:
                    /*  Errors ignored. */
                    pr_debug("\tcropping not supported\n");
                    break;
            }
        }
    }
    else
    {
        /*  Errors ignored. */
    }

    qDebug() << "video_open finish------------";
    return dev;
}
int video_device::video_set_format(int dev, unsigned int w, unsigned int h, unsigned int format)
{
    struct v4l2_format fmt;
    unsigned int min;

    CLEAR(fmt);

    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = w;
    fmt.fmt.pix.height = h;
    fmt.fmt.pix.pixelformat = format;
    fmt.fmt.pix.field = V4L2_FIELD_ANY;

    pr_debug("\tfmt.fmt.pix.pixelformat: %c,%c,%c,%c\n",
            fmt.fmt.pix.pixelformat & 0xFF,
            (fmt.fmt.pix.pixelformat >> 8) & 0xFF,
            (fmt.fmt.pix.pixelformat >> 16) & 0xFF,
            (fmt.fmt.pix.pixelformat >> 24) & 0xFF);

    if (-1 == xioctl(dev, VIDIOC_S_FMT, &fmt))
    {
        errno_exit("VIDIOC_S_FMT");
        return -1;
    }

    pr_debug("\tVideo format set: width: %u height: %u buffer size: %u\n",
            fmt.fmt.pix.width, fmt.fmt.pix.height, fmt.fmt.pix.sizeimage);

    /*  Buggy driver paranoia. */
    min = fmt.fmt.pix.width * 2;
    if (fmt.fmt.pix.bytesperline < min)
        fmt.fmt.pix.bytesperline = min;
    min = fmt.fmt.pix.bytesperline * fmt.fmt.pix.height;
    if (fmt.fmt.pix.sizeimage < min)
        fmt.fmt.pix.sizeimage = min;

    return 0;
}
int video_device::video_set_framerate(int dev)
{
    struct v4l2_streamparm parm;

    CLEAR(parm);
    parm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    if(-1 ==  xioctl(dev, VIDIOC_G_PARM, &parm))
    {
        errno_exit("VIDIOC_G_PARM");
        return -1;
    }

    pr_debug("\tCurrent frame rate: %u/%u\n",
            parm.parm.capture.timeperframe.numerator,
            parm.parm.capture.timeperframe.denominator);

    parm.parm.capture.timeperframe.numerator = 1;
    parm.parm.capture.timeperframe.denominator = 30;//25;

    if(-1 == xioctl(dev, VIDIOC_S_PARM, &parm))
    {
        errno_exit("VIDIOC_S_PARM");
        return -1;
    }

    if(-1 == xioctl(dev, VIDIOC_G_PARM, &parm))
    {
        errno_exit("VIDIOC_G_PARM");
        return -1;
    }

    pr_debug("\tFrame rate set: %u/%u\n",
            parm.parm.capture.timeperframe.numerator,
            parm.parm.capture.timeperframe.denominator);
    return 0;
}
int video_device::GetFreeRam(int* freeram)
{
    FILE *meminfo = fopen("/proc/meminfo", "r");
    char line[256];

    if(meminfo == NULL)
    {
        qDebug("/proc/meminfo can't open\n");
        return -1;
    }
    while(fgets(line, sizeof(line), meminfo))
    {
        if(sscanf(line, "MemFree: %d kB", freeram) == 1)
        {
            qDebug("\tfreeram = %d\n",*freeram);
            *freeram <<= 10;
            fclose(meminfo);
            return 1;
        }
    }

    fclose(meminfo);
    return -1;
}
int video_device::video_reqbufs(int dev, int nbufs)
{
    struct v4l2_requestbuffers rb;

    CLEAR(rb);
    rb.count = nbufs;
    rb.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    rb.memory = V4L2_MEMORY_MMAP;

    if (-1 == xioctl(dev, VIDIOC_REQBUFS, &rb))
    {
        if (EINVAL == errno)
        {
            qDebug("%d does not support memory mapping\n", dev);
            return -1;
        } else
        {
            errno_exit("VIDIOC_REQBUFS");
            return -1;
        }
    }
    pr_debug("\treq.count: %d\n", rb.count);
    pr_debug("\treq.type: %d\n", rb.type);
    pr_debug("\treq.memory: %d\n", rb.memory);
    pr_debug("\n");

    if (rb.count < 2)
    {
        qDebug("Insufficient buffer memory on %d\n", dev);
        return -1;
    }

    nbufs = rb.count;

    return 0;
}
int video_device::video_enable(int dev, int enable)
{
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    pr_debug("\t%s \n ",enable ? "Before STREAMON" : "Before STREAMOFF");

    if(-1 == xioctl(dev, enable ? VIDIOC_STREAMON : VIDIOC_STREAMOFF, &type))
    {
        pr_debug("\t%s \n ",enable ? "Before STREAMON" : "Before STREAMOFF");
        return -1;
    }

    pr_debug("\t%s \n ",enable ? "After STREAMON" : "After STREAMOFF");

    return 0;
}
int video_device::get_frame(unsigned char **yuv_buffer_pointer, size_t *len)
{
    struct v4l2_buffer buf0;

    // Dequeue a buffe
    CLEAR(buf0);
    buf0.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf0.memory = V4L2_MEMORY_MMAP;

    if (-1 == xioctl(fd, VIDIOC_DQBUF, &buf0))
    {
        switch (errno) {
            case EAGAIN:
                close(fd);
                errno_exit("VIDIOC_DQBUF EAGAIN");
                return -1;
            case EIO:
                //  Could ignore EIO, see spec.
                //  fall through
            default:
                errno_exit("VIDIOC_DQBUF");
                close(fd);
                return -1;
        }
    }
    assert(buf0.index < nbufs);

    *yuv_buffer_pointer = (unsigned char *)mem0[buf0.index];
    *len =  buf0.bytesused;
    index = buf0.index;

    return 0;
}

int video_device::unget_frame()
{
    if(index != -1)
    {
        v4l2_buffer buf0;
        CLEAR(buf0);
        buf0.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf0.memory = V4L2_MEMORY_MMAP;
        buf0.index = index;

        // Requeue the buffe
        if (-1 == xioctl(fd, VIDIOC_QBUF, &buf0))
        {
            errno_exit("VIDIOC_QBUF");
            close(fd);
            return -1;
        }
        return 0;
    }
    return -1;
}

int video_device::yuyv_2_rgb888(const void *p, int size, unsigned char *frame_buffer)
{
    int i,j;
    unsigned char y1,y2,u,v;
    int r1,g1,b1,r2,g2,b2;
    const char *pointer;
    size++;

    pointer = (const char *)p;

    for(i=0;i<480;i++)
    {
        for(j=0;j<320;j++)
        {
            y1 = *( pointer + (i*320+j)*4);
            u  = *( pointer + (i*320+j)*4 + 1);
            y2 = *( pointer + (i*320+j)*4 + 2);
            v  = *( pointer + (i*320+j)*4 + 3);

            r1 = y1 + 1.042*(v-128);
            g1 = y1 - 0.34414*(u-128) - 0.71414*(v-128);
            b1 = y1 + 1.772*(u-128);

            r2 = y2 + 1.042*(v-128);
            g2 = y2 - 0.34414*(u-128) - 0.71414*(v-128);
            b2 = y2 + 1.772*(u-128);

            if(r1>255)                r1 = 255;
            else if(r1<0)             r1 = 0;

            if(b1>255)                b1 = 255;
            else if(b1<0)             b1 = 0;

            if(g1>255)                g1 = 255;
            else if(g1<0)             g1 = 0;

            if(r2>255)                r2 = 255;
            else if(r2<0)             r2 = 0;

            if(b2>255)                b2 = 255;
            else if(b2<0)             b2 = 0;

            if(g2>255)                g2 = 255;
            else if(g2<0)             g2 = 0;

            *(frame_buffer + ((480-1-i)*320+j)*6    ) = (unsigned char)b1;
            *(frame_buffer + ((480-1-i)*320+j)*6 + 1) = (unsigned char)g1;
            *(frame_buffer + ((480-1-i)*320+j)*6 + 2) = (unsigned char)r1;
            *(frame_buffer + ((480-1-i)*320+j)*6 + 3) = (unsigned char)b2;
            *(frame_buffer + ((480-1-i)*320+j)*6 + 4) = (unsigned char)g2;
            *(frame_buffer + ((480-1-i)*320+j)*6 + 5) = (unsigned char)r2;
        }
    }
   // pr_debug("\tchange to RGB OK \n");
    return 0;
}
