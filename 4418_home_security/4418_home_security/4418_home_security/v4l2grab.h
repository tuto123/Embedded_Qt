#ifndef __V4L2GRAB_H__
#define __V4L2GRAB_H__

typedef unsigned char  BYTE;
typedef unsigned short	WORD;
typedef unsigned int  DWORD;

#pragma pack(1)

typedef struct tagBITMAPFILEHEADER{
     WORD	  bfType;                // the flag of bmp, value is "BM"
     DWORD    bfSize;                // size BMP file ,unit is bytes
     DWORD    bfReserved;            // 0
     DWORD    bfOffBits;             // must be 54

}BITMAPFILEHEADER;

 
typedef struct tagBITMAPINFOHEADER{
     DWORD    biSize;                // must be 0x28
     DWORD    biWidth;               //
     DWORD    biHeight;              //
     WORD     biPlanes;              // must be 1
     WORD     biBitCount;            //
     DWORD    biCompression;         //
     DWORD    biSizeImage;           //
     DWORD    biXPelsPerMeter;       //
     DWORD    biYPelsPerMeter;       //
     DWORD    biClrUsed;             //
     DWORD    biClrImportant;        //
}BITMAPINFOHEADER;

typedef struct tagRGBQUAD{
     BYTE	rgbBlue;
     BYTE	rgbGreen;
     BYTE	rgbRed;
     BYTE	rgbReserved;
}RGBQUAD;

#define  IMAGEWIDTH    640
#define  IMAGEHEIGHT   480

#endif //__V4LGRAB_H___
