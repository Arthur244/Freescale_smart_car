
/********************************************************************
    http://www.cnblogs.com/lancidie/archive/2011/07/17/2108885.html
********************************************************************/

#include   "MySobel.h"

void Sobel(char imgaddr[CAMERA_GET_H][CAMERA_GET_W],char img_addr[CAMERA_GET_H][CAMERA_GET_W])
{
    unsigned char Sobel_i,Sobel_j;
    
    char Sobel_x[CAMERA_GET_H][CAMERA_GET_W]={0};
    char Sobel_y[CAMERA_GET_H][CAMERA_GET_W]={0};
    
    for(Sobel_i=1;Sobel_i<(CAMERA_GET_H-1);Sobel_i++)
    {
        for(Sobel_j=1;Sobel_j<(CAMERA_GET_W-1);Sobel_j++)
        {
            Sobel_x[Sobel_i][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j+1] + 2*imgaddr[Sobel_i][Sobel_j+1] + imgaddr[Sobel_i+1][Sobel_j+1] 
                                      - imgaddr[Sobel_i-1][Sobel_j-1] - 2*imgaddr[Sobel_i][Sobel_j-1] - imgaddr[Sobel_i+1][Sobel_j-1] ;  
            Sobel_y[Sobel_i][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j-1] + 2*imgaddr[Sobel_i-1][Sobel_j] + imgaddr[Sobel_i-1][Sobel_j+1]
                                      - imgaddr[Sobel_i+1][Sobel_j-1] - 2*imgaddr[Sobel_i+1][Sobel_j] - imgaddr[Sobel_i+1][Sobel_j+1] ;
            
            img_addr[Sobel_i][Sobel_j] = abs(Sobel_x[Sobel_i][Sobel_j]) + abs(Sobel_y[Sobel_i][Sobel_j]) ;
            
        }
    }
    
}


void Sobel_1(char imgaddr[CAMERA_GET_H][CAMERA_GET_W],char img_addr[4][CAMERA_GET_W])
{
    unsigned char Sobel_i,Sobel_j;
    
    char Sobel_x[4][CAMERA_GET_W]={0};
    char Sobel_y[4][CAMERA_GET_W]={0};
    
    
    for(Sobel_j=1;Sobel_j<(CAMERA_GET_W-1);Sobel_j++)
        {
            Sobel_i = 38;
          
            Sobel_x[0][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j+1] + 2*imgaddr[Sobel_i][Sobel_j+1] + imgaddr[Sobel_i+1][Sobel_j+1] 
                                      - imgaddr[Sobel_i-1][Sobel_j-1] - 2*imgaddr[Sobel_i][Sobel_j-1] - imgaddr[Sobel_i+1][Sobel_j-1] ;  
            Sobel_y[0][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j-1] + 2*imgaddr[Sobel_i-1][Sobel_j] + imgaddr[Sobel_i-1][Sobel_j+1]
                                      - imgaddr[Sobel_i+1][Sobel_j-1] - 2*imgaddr[Sobel_i+1][Sobel_j] - imgaddr[Sobel_i+1][Sobel_j+1] ;
            
            img_addr[0][Sobel_j] = abs(Sobel_x[0][Sobel_j]) + abs(Sobel_y[0][Sobel_j]) ;
            
        }
    
    for(Sobel_j=1;Sobel_j<(CAMERA_GET_W-1);Sobel_j++)
        {
            Sobel_i = 44;
          
            Sobel_x[1][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j+1] + 2*imgaddr[Sobel_i][Sobel_j+1] + imgaddr[Sobel_i+1][Sobel_j+1] 
                                      - imgaddr[Sobel_i-1][Sobel_j-1] - 2*imgaddr[Sobel_i][Sobel_j-1] - imgaddr[Sobel_i+1][Sobel_j-1] ;  
            Sobel_y[1][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j-1] + 2*imgaddr[Sobel_i-1][Sobel_j] + imgaddr[Sobel_i-1][Sobel_j+1]
                                      - imgaddr[Sobel_i+1][Sobel_j-1] - 2*imgaddr[Sobel_i+1][Sobel_j] - imgaddr[Sobel_i+1][Sobel_j+1] ;
            
            img_addr[1][Sobel_j] = abs(Sobel_x[1][Sobel_j]) + abs(Sobel_y[1][Sobel_j]) ;
            
        }
    
    for(Sobel_j=1;Sobel_j<(CAMERA_GET_W-1);Sobel_j++)
        {
            Sobel_i = 50;
          
            Sobel_x[2][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j+1] + 2*imgaddr[Sobel_i][Sobel_j+1] + imgaddr[Sobel_i+1][Sobel_j+1] 
                                      - imgaddr[Sobel_i-1][Sobel_j-1] - 2*imgaddr[Sobel_i][Sobel_j-1] - imgaddr[Sobel_i+1][Sobel_j-1] ;  
            Sobel_y[2][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j-1] + 2*imgaddr[Sobel_i-1][Sobel_j] + imgaddr[Sobel_i-1][Sobel_j+1]
                                      - imgaddr[Sobel_i+1][Sobel_j-1] - 2*imgaddr[Sobel_i+1][Sobel_j] - imgaddr[Sobel_i+1][Sobel_j+1] ;
            
            img_addr[2][Sobel_j] = abs(Sobel_x[2][Sobel_j]) + abs(Sobel_y[2][Sobel_j]) ;
            
        }
    
    for(Sobel_j=1;Sobel_j<(CAMERA_GET_W-1);Sobel_j++)
        {
            Sobel_i = 58;
          
            Sobel_x[3][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j+1] + 2*imgaddr[Sobel_i][Sobel_j+1] + imgaddr[Sobel_i+1][Sobel_j+1] 
                                      - imgaddr[Sobel_i-1][Sobel_j-1] - 2*imgaddr[Sobel_i][Sobel_j-1] - imgaddr[Sobel_i+1][Sobel_j-1] ;  
            Sobel_y[3][Sobel_j] = imgaddr[Sobel_i-1][Sobel_j-1] + 2*imgaddr[Sobel_i-1][Sobel_j] + imgaddr[Sobel_i-1][Sobel_j+1]
                                      - imgaddr[Sobel_i+1][Sobel_j-1] - 2*imgaddr[Sobel_i+1][Sobel_j] - imgaddr[Sobel_i+1][Sobel_j+1] ;
            
            img_addr[3][Sobel_j] = abs(Sobel_x[3][Sobel_j]) + abs(Sobel_y[3][Sobel_j]) ;
            
        }
    
}
