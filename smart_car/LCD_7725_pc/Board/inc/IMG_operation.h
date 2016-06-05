
#ifndef _IMG_OPERATION_H_
#define _IMG_OPERATION_H_

#include "common.h"
#include "include.h"

//#define Middle_Dot_R 40
//#define Middle_Dot_L 39

//#define IMG_Bottom 59
#define CAMERA_CUT_H 40
#define CAMERA_CUT_W 160

#define CAMERA_IMA_H 40
#define CAMERA_IMA_W 160

#define Threshold 3

/*******************
#define IMG_Area_1 1
#define IMG_Area_2 2
#define IMG_Area_3 3
#define IMG_Area_4 4
#define IMG_Area_5 5
*******************/


//extern char Middle_old = 0;

void IMG_Cut(char imgaddr[CAMERA_H][CAMERA_W],char img_addr[CAMERA_CUT_H][CAMERA_CUT_W]);
int IMG_Scan(char imgaddr[CAMERA_IMA_H][CAMERA_IMA_W],char img_addr[CAMERA_H][CAMERA_W],uint16 s);

//void IMG_Classify_Ima(char imgaddr[CAMERA_IMA_H][CAMERA_IMA_W],unsigned char img_addr[CAMERA_IMA_H][CAMERA_IMA_W]);

#endif 

