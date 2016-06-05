
#ifndef _MYSOBEL_H_
#define _MYSOBEL_H_

#include "common.h"
#include "include.h"



#define CAMERA_GET_H 40
#define CAMERA_GET_W 160

void Sobel(char imgaddr[CAMERA_GET_H][CAMERA_GET_W],char img_addr[CAMERA_GET_H][CAMERA_GET_W]);
void Sobel_1(char imgaddr[CAMERA_GET_H][CAMERA_GET_W],char img_addr[4][CAMERA_GET_W]);

#endif 