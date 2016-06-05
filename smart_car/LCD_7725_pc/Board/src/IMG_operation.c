

#include "common.h"
#include "IMG_operation.h"



int Middle_old = 0;
int x_middle = 0;
//int x_middle;
int i=0;
///////////////////////////////////////////////////////////////////////////////
//标志位
uint8 flag_zhijiao = 0;
uint8 flag_shizi = 0;
uint8 flag_shx=0;
uint8 flag_danxian = 0;
uint8 flag_bizhang = 0;

//extern uint8 img_get_ima[CAMERA_H][2];

//unsigned char IMG_Area[5] = {1,2,3,4,5};
//图像分割;
void IMG_Cut(char imgaddr[CAMERA_H][CAMERA_W],char img_addr[CAMERA_CUT_H][CAMERA_CUT_W])
{
    uint8 cut_x,cut_y;
    for(cut_y=0;cut_y<40;cut_y++)
    {
        for(cut_x=0;cut_x<160;cut_x++)
        {
            img_addr[cut_y][cut_x] = imgaddr[cut_y+20][cut_x];
        }
    }
}

int IMG_Scan(char imgaddr[CAMERA_IMA_H][CAMERA_IMA_W],char img_addr[CAMERA_H][CAMERA_W],uint16 s)
{
    uint8 warebuff_1[2];
    uint8 flag_test = 0;
    int scan_x;
    
    uint8 flag_buxian = 1;
    
    int x_left_38 = 160,x_right_38 = 0,x_middle_38;
    int x_left_30 = 160,x_right_30 = 0,x_middle_30;
    int x_left_24 = 160,x_right_24 = 0,x_middle_24;
    int x_left_18 = 160,x_right_18 = 0,x_middle_18;
    
    uint8 x_down_36 = 1;
    uint8 x_up_36 = 0;
    uint8 x_down_37 = 1;
    uint8 x_up_37 = 0;
    uint8 x_down_38 = 1;
    uint8 x_up_38 = 0;
    
    int x_single_left_36 = 0;
    int x_single_right_36 = 160;
    int x_single_width_36 = 160;
    int x_single_middle_36 = 0;
    int x_single_flag_36 = 0;
    
    int x_single_left_37 = 0;
    int x_single_right_37 = 160;
    int x_single_width_37 = 160;
    int x_single_middle_37 = 0;
    int x_single_flag_37 = 0;
    
    int x_single_left_38 = 0;
    int x_single_right_38 = 160;
    int x_single_width_38 = 160;
    int x_single_middle_38 = 0;
    int x_single_flag_38 = 0;
    
    uint8 x_down_43 = 1;
    uint8 x_up_43 = 0;
    uint8 x_down_44 = 1;
    uint8 x_up_44 = 0;
    uint8 x_down_45 = 1;
    uint8 x_up_45 = 0;
    
    int x_single_left_43 = 0;
    int x_single_right_43 = 160;
    int x_single_width_43 = 160;
    int x_single_middle_43 = 0;
    int x_single_flag_43 = 0;
    
    int x_single_left_44 = 0;
    int x_single_right_44 = 160;
    int x_single_width_44 = 160;
    int x_single_middle_44 = 0;
    int x_single_flag_44 = 0;
    
    int x_single_left_45 = 0;
    int x_single_right_45 = 160;
    int x_single_width_45 = 160;
    int x_single_middle_45 = 0;
    int x_single_flag_45 = 0;
    
    int x_single_up = 0;
    int x_single_down = 1;
    
    int x_single_left = 160;
    int x_single_right = 0;
    int x_single_width = 160;
    int x_single_middle = 80;
    
    int x_single_ima =0;
    int x_single_ima_1 = 0;
    int x_single_ima_2 = 0;
    
    int x_bizhang_down_43 = 1;
    int x_bizhang_up_43 = 0;
    int x_bizhang_down_44 = 1;
    int x_bizhang_up_44 = 0;
    
    int x_bizhang_down_58 = 1;
    int x_bizhang_up_58 = 0;
    int x_bizhang_down_59 = 1;
    int x_bizhang_up_59 = 0;
    
    int x_bizhang_left_43 = 160;
    int x_bizhang_right_43 = 0;
    int x_bizhang_left_44 = 160;
    int x_bizhang_right_44 = 0;
    
    int x_bizhang_left_58 = 160;
    int x_bizhang_right_58 = 0;
    int x_bizhang_left_59 = 160;
    int x_bizhang_right_59 = 0;
    
    int x_bizhang_width_43 = 0;
    int x_bizhang_width_44 = 0;
    
    int x_bizhang_width_58 = 0;
    int x_bizhang_width_59 = 0;
    
    int x_bizhang_flag_43 = 0;
    int x_bizhang_flag_44 = 0;
    
    int x_bizhang_flag_58 = 0;
    int x_bizhang_flag_59 = 0;
    
    int x_bizhang_width_44_1 = 160 ;
    int x_bizhang_width_44_2 = 160 ;
    
    int x_bizhang_width_58_1 = 160 ;
    int x_bizhang_width_58_2 = 160 ;
    
    int x_bizhang_left1_44 = 160 ;
    int x_bizhang_right1_44 = 0 ;
    int x_bizhang_left2_44 = 160 ;
    int x_bizhang_right2_44 = 0 ;
    
    int x_bizhang_left1_58 = 160 ;
    int x_bizhang_right1_58 = 0 ;
    int x_bizhang_left2_58 = 160 ;
    int x_bizhang_right2_58 = 0 ;
    
    int x_bizhang_up1_44 = 1;
    int x_bizhang_down1_44 = 0;
    int x_bizhang_up2_44 = 0;
    int x_bizhang_down2_44 = 0;
    
    int x_bizhang_up1_58 = 1;
    int x_bizhang_down1_58 = 0;
    int x_bizhang_up2_58 = 0;
    int x_bizhang_down2_58 = 0;
    
    int x_bizhang_middle = 80 ;
    
    int flag_baochi = 0;
    
    int x_left_k_1;
    int x_left_k_2;
    
    int x_right_k_1;
    int x_right_k_2;
    
    int x_width_38 = 160 ,x_width_30 = 160 ,x_width_24 = 160 ,x_width_18 = 160;
    
    for( scan_x = 0 ; scan_x <159 ; scan_x++ )
    {
        if( (imgaddr[3][scan_x] < (Threshold + 1 )) && (imgaddr[3][scan_x + 1] > Threshold ) )
        {
            x_right_38 = scan_x;
        }
        if( (imgaddr[3][159 - scan_x] < (Threshold + 1 )) && (imgaddr[3][158 - scan_x] > Threshold ) )
        {
            x_left_38 = 159 - scan_x;
        }
    }
    
    for( scan_x = 0 ; scan_x <159 ; scan_x++ )
    {
        if( (imgaddr[2][scan_x] < (Threshold + 1 )) && (imgaddr[2][scan_x + 1] > Threshold ) )
        {
            x_right_30 = scan_x;
        }
        if( (imgaddr[2][159 - scan_x] < (Threshold + 1 )) && (imgaddr[2][158 - scan_x] > Threshold ) )
        {
            x_left_30 = 159 - scan_x;
        }
    }
    
    for( scan_x = 0 ; scan_x <159 ; scan_x++ )
    {
        if( (imgaddr[1][scan_x] < (Threshold + 1 )) && (imgaddr[1][scan_x + 1] > Threshold ) )
        {
            x_right_24 = scan_x;
        }
        if( (imgaddr[1][159 - scan_x] < (Threshold + 1 )) && (imgaddr[1][158 - scan_x] > Threshold ) )
        {
            x_left_24 = 159 - scan_x;
        }
    }
    
    for( scan_x = 0 ; scan_x <159 ; scan_x++ )
    {
        if( (imgaddr[0][scan_x] < (Threshold + 1 )) && (imgaddr[0][scan_x + 1] > Threshold ) )
        {
            x_right_18 = scan_x;
        }
        if( (imgaddr[0][159 - scan_x] < (Threshold + 1 )) && (imgaddr[0][158 - scan_x] > Threshold ) )
        {
            x_left_18 = 159 - scan_x;
        }
    }
    
    if( ( flag_danxian == 0 ) && (( x_width_24 > 0 ) || ( x_width_24 <-70 ) ) )
    {
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if( ( img_addr[36][scan_x] ==1 ) && ( img_addr[36][scan_x + 1] ==0 ) && ( x_down_36 == 1 ) )
            {
                x_single_left_36 = scan_x;
                x_down_36 = 0;
                x_up_36 = 1;
            }
            if(( img_addr[36][scan_x] ==0 ) && ( img_addr[36][scan_x + 1] ==1 ) && ( x_up_36 == 1 ) )
            {
                x_single_right_36 = scan_x;
                x_up_36 = 0;
                x_single_width_36 = x_single_right_36 - x_single_left_36;
                if(( x_single_width_36 < 10 ) && ( x_single_width_36 >0 ) )
                {
                    x_single_flag_36 = 1;
                }
                else
                {
                    x_down_36 = 1;
                }
            }
            
            
            if(( img_addr[37][scan_x] ==1 ) && ( img_addr[37][scan_x + 1] ==0 ) && ( x_down_37 == 1 ) )
            {
                x_single_left_37 = scan_x;
                x_down_37 = 0;
                x_up_37 = 1;
            }
            if(( img_addr[37][scan_x] ==0 ) && ( img_addr[37][scan_x + 1] ==1 ) && ( x_up_37 == 1 ) )
            {
                x_single_right_37 = scan_x;
                x_up_37 = 0;
                x_single_width_37 = x_single_right_37 - x_single_left_37;
                if(( x_single_width_37 < 10 ) && ( x_single_width_37 >0 ) )
                {
                    x_single_flag_37 = 1;
                }
                else
                {
                    x_down_37 = 1;
                }
            }
            
            if(( img_addr[38][scan_x] ==1 ) && ( img_addr[38][scan_x + 1] ==0 ) && ( x_down_38 == 1 ) )
            {
                x_single_left_38 = scan_x;
                x_down_38 = 0;
                x_up_38 = 1;
            }
            if(( img_addr[38][scan_x] ==0 ) && ( img_addr[38][scan_x + 1] ==1 ) && ( x_up_38 == 1 ) )
            {
                x_single_right_38 = scan_x;
                x_up_38 = 0;
                x_single_width_38 = x_single_right_38 - x_single_left_38;
                if(( x_single_width_38 < 10 ) && ( x_single_width_38 >0 ) )
                {
                    x_single_flag_38 = 1;
                }
                else
                {
                    x_down_38 = 1;
                }
            }
           
           
        }
        
        if( ( x_single_flag_36 == 1 ) && ( x_single_flag_37 == 1 ) && ( x_single_flag_38 == 1 ) )
        {
            flag_danxian = 1;
        }
         
    }
    
    if (( flag_danxian == 0 ) &&  (( x_width_24 > 0 ) || ( x_width_24 <-70 ) ) )
    {
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if(( img_addr[43][scan_x] ==1 ) && ( img_addr[43][scan_x + 1] ==0 ) && ( x_down_43 == 1 ) )
            {
                x_single_left_43 = scan_x;
                x_down_43 = 0;
                x_up_43 = 1;
            }
            if(( img_addr[43][scan_x] ==0 ) && ( img_addr[43][scan_x + 1] ==1 ) && ( x_up_43 == 1 ) )
            {
                x_single_right_43 = scan_x;
                x_up_43 = 0;
                x_single_width_43 = x_single_right_43 - x_single_left_43;
                if(( x_single_width_43 < 10 ) && ( x_single_width_43 >0 ) )
                {
                    x_single_flag_43 = 1;
                }
                else
                {
                    x_down_43 = 1;
                }
            }
            
            
            if(( img_addr[44][scan_x] ==1 ) && ( img_addr[44][scan_x + 1] ==0 ) && ( x_down_44 == 1 ) )
            {
                x_single_left_44 = scan_x;
                x_down_44 = 0;
                x_up_44 = 1;
            }
            if(( img_addr[44][scan_x] ==0 ) && ( img_addr[44][scan_x + 1] ==1 ) && ( x_up_44 == 1 ) )
            {
                x_single_right_44 = scan_x;
                x_up_44 = 0;
                x_single_width_44 = x_single_right_44 - x_single_left_44;
                if(( x_single_width_44 < 10 ) && ( x_single_width_44 >0 ) )
                {
                    x_single_flag_44 = 1;
                }
                else
                {
                    x_down_44 = 1;
                }
            }
            
            if(( img_addr[45][scan_x] ==1 ) && ( img_addr[45][scan_x + 1] ==0 ) && ( x_down_45 == 1 ) )
            {
                x_single_left_45 = scan_x;
                x_down_45 = 0;
                x_up_45 = 1;
            }
            if(( img_addr[45][scan_x] ==0 ) && ( img_addr[45][scan_x + 1] ==1 ) && ( x_up_45 == 1 ) )
            {
                x_single_right_45 = scan_x;
                x_up_45 = 0;
                x_single_width_45 = x_single_right_45 - x_single_left_45;
                if(( x_single_width_45 < 10 ) && ( x_single_width_45 >0 ) )
                {
                    x_single_flag_45 = 1;
                }
                else
                {
                    x_down_45 = 1;
                }
            }
           
           
        }
        
        if( ( x_single_flag_43 == 1 ) && ( x_single_flag_44 == 1 ) && ( x_single_flag_45 == 1 ) )
        {
            flag_danxian = 1;
        }
         
    }
    
    
    x_middle_38 = ( x_left_38 + x_right_38 ) / 2 ;//- 80;
    x_middle_30 = ( x_left_30 + x_right_30 ) / 2 ;//- 80;
    x_middle_24 = ( x_left_24 + x_right_24 ) / 2 ;//- 80;
    x_middle_18 = ( x_left_18 + x_right_18 ) / 2 ;//- 80;
    
    x_width_38 = (x_right_38 - x_left_38);
    x_width_30 = (x_right_30 - x_left_30);
    x_width_24 = (x_right_24 - x_left_24);
    x_width_18 = (x_right_18 - x_left_18);
    
    x_left_k_1 = abs( x_left_24 - x_left_30 );
    x_left_k_2 = abs( x_left_30 - x_left_38 );
    
    x_right_k_1 = abs( x_right_24 - x_right_30 );
    x_right_k_2 = abs( x_right_30 - x_right_38 );
    
    
    if( ( flag_bizhang == 0 ) && ( flag_danxian ==0 ) && ( x_left_k_1 <9 ) && ( x_right_k_1 < 9 ) )
    {
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if(( img_addr[43][scan_x] ==1 ) && ( img_addr[43][scan_x + 1] ==0 ) && ( x_bizhang_down_43 == 1 ) )
            {   
                x_bizhang_down_43 = 0;
                x_bizhang_up_43 = 1;
                x_bizhang_left_43 = scan_x;
            }
            if(( img_addr[43][scan_x] ==0 ) && ( img_addr[43][scan_x + 1] ==1 ) && ( x_bizhang_up_43 == 1 ) )
            {
                x_bizhang_up_43 = 0;
                x_bizhang_right_43 = scan_x;
                x_bizhang_width_43 = x_bizhang_right_43 - x_bizhang_left_43;
                if(( x_bizhang_width_43 > 18 ) && ( x_bizhang_width_43 < 25 ) )
                {
                    x_bizhang_flag_43 = 1;
                }
                else
                {
                    x_bizhang_up_43 = 1;
                }
            }
            
            if(( img_addr[44][scan_x] ==1 ) && ( img_addr[44][scan_x + 1] ==0 ) && ( x_bizhang_down_44 == 1 ) )
            {   
                x_bizhang_down_44 = 0;
                x_bizhang_up_44 = 1;
                x_bizhang_left_44 = scan_x;
            }
            if(( img_addr[44][scan_x] ==0 ) && ( img_addr[44][scan_x + 1] ==1 ) && ( x_bizhang_up_44 == 1 ) )
            {
                x_bizhang_up_44 = 0;
                x_bizhang_right_44 = scan_x;
                x_bizhang_width_44 = x_bizhang_right_44 - x_bizhang_left_44;
                if(( x_bizhang_width_44 > 18 ) && ( x_bizhang_width_44 < 25 ) )
                {
                    x_bizhang_flag_44 = 1;
                }
                else
                {
                    x_bizhang_up_44 = 1;
                }
            }
            
        }
        
        if( ( x_bizhang_flag_43 == 1 ) && ( x_bizhang_flag_44 == 1 ) )
        {
            flag_bizhang = 1;
        }
        else
        {
            flag_bizhang = 0;
        }
        
    }
    
    if(( flag_bizhang == 1 ) )
    {
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if(( img_addr[44][scan_x] ==1 ) && ( img_addr[44][scan_x + 1] ==0 ) && ( x_bizhang_down_44 == 1 ) )
            {   
                x_bizhang_down_44 = 0;
                x_bizhang_up_44 = 1;
                x_bizhang_left_44 = scan_x;
            }
            if(( img_addr[44][scan_x] ==0 ) && ( img_addr[44][scan_x + 1] ==1 ) && ( x_bizhang_up_44 == 1 ) )
            {
                x_bizhang_up_44 = 0;
                x_bizhang_right_44 = scan_x;
                x_bizhang_width_44 = x_bizhang_right_44 - x_bizhang_left_44;
                if(( x_bizhang_width_44 > 18 ) && ( x_bizhang_width_44 < 25 ) )
                {
                    x_bizhang_flag_44 = 1;
                }
                else
                {
                    x_bizhang_up_44 = 1;
                    x_bizhang_flag_44 = 0;
                }
            }
            if(( img_addr[43][scan_x] ==1 ) && ( img_addr[43][scan_x + 1] ==0 ) && ( x_bizhang_down_43 == 1 ) )
            {   
                x_bizhang_down_43 = 0;
                x_bizhang_up_43 = 1;
                x_bizhang_left_43 = scan_x;
            }
            if(( img_addr[43][scan_x] ==0 ) && ( img_addr[43][scan_x + 1] ==1 ) && ( x_bizhang_up_43 == 1 ) )
            {
                x_bizhang_up_43 = 0;
                x_bizhang_right_43 = scan_x;
                x_bizhang_width_43 = x_bizhang_right_43 - x_bizhang_left_43;
                if(( x_bizhang_width_43 > 18 ) && ( x_bizhang_width_43 < 25 ) )
                {
                    x_bizhang_flag_43 = 1;
                }
                else
                {
                    x_bizhang_up_43 = 1;
                    x_bizhang_flag_43 = 0;
                }
            }
        }
        
        if( ( x_bizhang_flag_44 == 1 ) && ( x_bizhang_flag_43 == 1 ) )
        {
           // flag_bizhang = 2;
        }
        else
        {
            if( flag_bizhang == 1 )
            {
                flag_bizhang = 0;
            }
        }
        
    }
    
    if(( flag_bizhang == 1 ) )
    {
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if(( img_addr[58][scan_x] ==1 ) && ( img_addr[58][scan_x + 1] ==0 ) && ( x_bizhang_down_58 == 1 ) )
            {   
                x_bizhang_down_58 = 0;
                x_bizhang_up_58 = 1;
                x_bizhang_left_58 = scan_x;
            }
            if(( img_addr[58][scan_x] ==0 ) && ( img_addr[58][scan_x + 1] ==1 ) && ( x_bizhang_up_58 == 1 ) )
            {
                x_bizhang_up_58 = 0;
                x_bizhang_right_58 = scan_x;
                x_bizhang_width_58 = x_bizhang_right_58 - x_bizhang_left_58;
                if( x_bizhang_width_58 > 25 )
                {
                    x_bizhang_flag_58 = 1;
                }
                else
                {
                    x_bizhang_up_58 = 1;
                    x_bizhang_flag_58 = 0;
                }
            }
            if(( img_addr[59][scan_x] ==1 ) && ( img_addr[59][scan_x + 1] ==0 ) && ( x_bizhang_down_59 == 1 ) )
            {   
                x_bizhang_down_59 = 0;
                x_bizhang_up_59 = 1;
                x_bizhang_left_59 = scan_x;
            }
            if(( img_addr[59][scan_x] ==0 ) && ( img_addr[59][scan_x + 1] ==1 ) && ( x_bizhang_up_59 == 1 ) )
            {
                x_bizhang_up_59 = 0;
                x_bizhang_right_59 = scan_x;
                x_bizhang_width_59 = x_bizhang_right_59 - x_bizhang_left_59;
                if( x_bizhang_width_59 > 25 )
                {
                    x_bizhang_flag_59 = 1;
                }
                else
                {
                    x_bizhang_up_59 = 1;
                    x_bizhang_flag_59 = 0;
                }
            }
        }
        
        if( ( x_bizhang_flag_58 == 1 ) && ( x_bizhang_flag_59 == 1 ) )
        {
            flag_bizhang = 2;
        }
        else
        {
            if( flag_bizhang == 2 )
            {
               // flag_bizhang = 0;
            }
        }
        
    }
    
    if(( flag_bizhang == 2 ) )
    {
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if(( img_addr[58][scan_x] ==1 ) && ( img_addr[58][scan_x + 1] ==0 ) && ( x_bizhang_down_58 == 1 ) )
            {   
                x_bizhang_down_58 = 0;
                x_bizhang_up_58 = 1;
                x_bizhang_left_58 = scan_x;
            }
            if(( img_addr[58][scan_x] ==0 ) && ( img_addr[58][scan_x + 1] ==1 ) && ( x_bizhang_up_58 == 1 ) )
            {
                x_bizhang_up_58 = 0;
                x_bizhang_right_58 = scan_x;
                x_bizhang_width_58 = x_bizhang_right_58 - x_bizhang_left_58;
                if( x_bizhang_width_58 > 25 )
                {
                    x_bizhang_flag_58 = 1;
                }
                else
                {
                    x_bizhang_up_58 = 1;
                    x_bizhang_flag_58 = 0;
                }
            }
            if(( img_addr[59][scan_x] ==1 ) && ( img_addr[59][scan_x + 1] ==0 ) && ( x_bizhang_down_59 == 1 ) )
            {   
                x_bizhang_down_59 = 0;
                x_bizhang_up_59 = 1;
                x_bizhang_left_59 = scan_x;
            }
            if(( img_addr[59][scan_x] ==0 ) && ( img_addr[59][scan_x + 1] ==1 ) && ( x_bizhang_up_59 == 1 ) )
            {
                x_bizhang_up_59 = 0;
                x_bizhang_right_59 = scan_x;
                x_bizhang_width_59 = x_bizhang_right_59 - x_bizhang_left_59;
                if( x_bizhang_width_59 > 25 )
                {
                    x_bizhang_flag_59 = 1;
                }
                else
                {
                    x_bizhang_up_59 = 1;
                    x_bizhang_flag_59 = 0;
                }
            }
        }
        
        if( ( x_bizhang_flag_58 == 1 ) && ( x_bizhang_flag_59 == 1 ) )
        {
           // flag_bizhang = 2;
        }
        else
        {
            if( flag_bizhang == 2 )
            {
                flag_bizhang = 0;
            }
        }
        
    }
    
    if( flag_bizhang == 1 )
    {
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if(( img_addr[44][scan_x] ==0 ) && ( img_addr[44][scan_x + 1] ==1 ) && ( x_bizhang_up1_44 == 1 ) )
            {
                x_bizhang_up1_44 = 0;
                x_bizhang_down1_44 = 1;
                x_bizhang_left1_44 = scan_x;
            }
            if(( img_addr[44][scan_x] ==1 ) && ( img_addr[44][scan_x + 1] ==0 ) && ( x_bizhang_down1_44 == 1 ) )
            {
                x_bizhang_down1_44 = 0;
                x_bizhang_up2_44 = 1;
                x_bizhang_right1_44 = scan_x;
            }
            if(( img_addr[44][scan_x] ==0 ) && ( img_addr[44][scan_x + 1] ==1 ) && ( x_bizhang_up2_44 == 1 ) )
            {
                x_bizhang_up2_44 = 0;
                x_bizhang_down2_44 = 1;
                x_bizhang_left2_44 = scan_x;
            }
            if(( img_addr[44][scan_x] ==1 ) && ( img_addr[44][scan_x + 1] ==0 ) && ( x_bizhang_down2_44 == 1 ) )
            {
                x_bizhang_down2_44 = 0;
                x_bizhang_right2_44 = scan_x;
            }
        }
        
        x_bizhang_width_44_1 = x_bizhang_right1_44 - x_bizhang_left1_44;
        x_bizhang_width_44_2 = x_bizhang_right2_44 - x_bizhang_left2_44;
        
        if( x_bizhang_width_44_1 > x_bizhang_width_44_2 )
        {
            x_bizhang_middle = ( x_bizhang_left1_44 + x_bizhang_right1_44 ) / 2;
        }
        else
        {
            x_bizhang_middle = ( x_bizhang_left2_44 + x_bizhang_right2_44 ) / 2;
        }
        
    }
    
    
    if( flag_bizhang == 2 )
    {
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if(( img_addr[58][scan_x] ==0 ) && ( img_addr[58][scan_x + 1] ==1 ) && ( x_bizhang_up1_58 == 1 ) )
            {
                x_bizhang_up1_58 = 0;
                x_bizhang_down1_58 = 1;
                x_bizhang_left1_58 = scan_x;
            }
            if(( img_addr[58][scan_x] ==1 ) && ( img_addr[58][scan_x + 1] ==0 ) && ( x_bizhang_down1_58 == 1 ) )
            {
                x_bizhang_down1_58 = 0;
                x_bizhang_up2_58 = 1;
                x_bizhang_right1_58 = scan_x;
            }
            if(( img_addr[58][scan_x] ==0 ) && ( img_addr[58][scan_x + 1] ==1 ) && ( x_bizhang_up2_58 == 1 ) )
            {
                x_bizhang_up2_58 = 0;
                x_bizhang_down2_58 = 1;
                x_bizhang_left2_58 = scan_x;
            }
            if(( img_addr[58][scan_x] ==1 ) && ( img_addr[58][scan_x + 1] ==0 ) && ( x_bizhang_down2_58 == 1 ) )
            {
                x_bizhang_down2_58 = 0;
                x_bizhang_right2_58 = scan_x;
            }
        }
        
        x_bizhang_width_58_1 = x_bizhang_right1_58 - x_bizhang_left1_58;
        x_bizhang_width_58_2 = x_bizhang_right2_58 - x_bizhang_left2_58;
        
        if( x_bizhang_width_58_1 > x_bizhang_width_58_2 )
        {
            x_bizhang_middle = ( x_bizhang_left1_58 + x_bizhang_right1_58 ) / 2;
        }
        else
        {
            x_bizhang_middle = ( x_bizhang_left2_58 + x_bizhang_right2_58 ) / 2;
        }
        
    }
    
    
    
    
    
    
    if(x_width_24 < -100)
    {
        flag_shizi = 1;
    }
    else
    {
        if( x_width_30 > 10 )
        {
            flag_shizi = 0;
        }
    }
    
    if( flag_danxian == 1 )
    {
      for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
      {
        if( (imgaddr[1][scan_x] > (Threshold  )) && (imgaddr[1][scan_x + 1] < Threshold + 1 ) && (x_single_down ==1) )
        {
            x_single_up = 1;
            x_single_down = 0;
            x_single_left = scan_x;
        }
        if( (imgaddr[1][scan_x] < (Threshold + 1 )) && (imgaddr[1][scan_x + 1] > Threshold  ) && (x_single_up == 1) )
        {
            x_single_up = 0;
            x_single_right = scan_x;
            x_single_width = x_single_right - x_single_left;
            x_single_middle = ( x_single_right + x_single_left ) /2 ;
            if( (x_single_width < 10) && ( x_single_width >-1 ) )
            {
               // flag_danxian = 1;
                x_single_down = 0;
                x_single_ima = 1;
            }
            else
            {
              //  flag_danxian = 0;
                x_single_down = 1;
                x_single_ima = 0;
            }
         }
      }
      if( x_single_ima == 0 )
      {
          flag_danxian = 0;
      }
    }
    
    if( ( x_single_ima == 1 ) || ( flag_danxian == 2 )  )
    {
        x_single_left = 160;
        x_single_right = 0;
        x_single_down = 1;
        x_single_up = 0;
        for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
        {
            if( (imgaddr[2][scan_x] > (Threshold  )) && (imgaddr[2][scan_x + 1] < Threshold + 1 ) && (x_single_down ==1) )
            {
                x_single_up = 1;
                x_single_down = 0;
                x_single_left = scan_x;
            }
            if( (imgaddr[2][scan_x] < (Threshold + 1 )) && (imgaddr[2][scan_x + 1] > Threshold  ) && (x_single_up == 1) )
            {
                x_single_up = 0;
                x_single_right = scan_x;
                x_single_width = x_single_right - x_single_left;
                
                if( (x_single_width < 10) && ( x_single_width >-1 ) )
                {
                   // flag_danxian = 1;
                    x_single_down = 0;
                    x_single_ima_2 = 1;
                    flag_danxian = 2;
                    x_single_middle = ( x_single_right + x_single_left ) /2 ;
                }
                else
                {
                  //  flag_danxian = 0;
                    x_single_down = 1;
                    x_single_ima_2 = 0;
                }
             }
        }
        
        if (( x_single_ima_2 == 0 ) && ( flag_danxian == 2 ) )
        {
            flag_danxian = 3;
        }
    }
    
    if( flag_danxian == 3 )
    {
      for( scan_x = 0 ; scan_x < 160 ; scan_x++ )
      {
        if( (imgaddr[3][scan_x] > (Threshold  )) && (imgaddr[3][scan_x + 1] < Threshold + 1 ) && (x_single_down ==1) )
        {
            x_single_up = 1;
            x_single_down = 0;
            x_single_left = scan_x;
        }
        if( (imgaddr[3][scan_x] < (Threshold + 1 )) && (imgaddr[3][scan_x + 1] > Threshold  ) && (x_single_up == 1) )
        {
            x_single_up = 0;
            x_single_right = scan_x;
            x_single_width = x_single_right - x_single_left;
            x_single_middle = ( x_single_right + x_single_left ) /2 ;
            if( (x_single_width < 10) && ( x_single_width >-1 ) )
            {
                x_single_down = 0;
                x_single_ima_1 = 1;
            }
            else
            {
                x_single_down = 1;
                x_single_ima_1 = 0;
            }
         }
      }
      if( x_single_ima_1 == 0 )
      {
        flag_danxian = 0;              /////////////////
        if( x_width_30 <-100 )
        {
           // flag_baochi = 1;
        }
      }
      
    }
    
    
  //  if( flag_danxian == 3 )
   // {
   //     if( x_width_30 >50 )
   //     {
   //         flag_danxian = 0;
   //     }
          
  //  }
    

    
    if( (x_width_24 > 0) && ( x_width_24 < 75 ) )
    {
        flag_zhijiao = 0;
        ftm_pwm_duty(FTM0, FTM_CH3, s );
        ftm_pwm_duty(FTM0, FTM_CH5, s );
    }
    

    
    if( ( flag_danxian ==0 ) && (x_left_k_1 < 9) && (x_right_k_1 < 9) && (flag_shx==0) && ( flag_shizi == 0 ) )
    {
        if( (x_width_18 < 1) && ( x_width_18 > -100 )  )
        {                      //直角是否提前转向
            flag_zhijiao = 1;
            if( x_width_24 < 1 )
            {
                flag_zhijiao = 2;
            }
        }
    }
    
    
    
    if(x_width_24>10)
    {
        flag_shx=1;
    }
    else
        flag_shx=0;
    
    
    if( ( flag_bizhang == 0 ) && ( flag_baochi == 0 ) && (flag_danxian == 0) &&( flag_zhijiao == 0 ) && (x_width_30 > 35) && ( flag_shizi == 0 ) &&(flag_shx==1||(x_right_k_1>8&&x_left_k_1>8)))
    {
        x_middle = 7 * ( x_middle_30 -80 );
        
      //  if( ( x_middle_30 > 75 ) && ( x_middle_30 < 85 ) )
      //  {
      //      x_middle = 6 * ( x_middle_30 -80 );
      //  }
      //  else
      //  {
            
      //  }
        
    }
    
    if( ( flag_bizhang == 0 ) && ( flag_baochi == 0 ) && (x_width_30 < 0) && ( flag_shizi == 0 ) && ( flag_zhijiao == 0 ) && (flag_danxian == 0) )
    {
        if((x_middle_30 < 80) && (flag_buxian ==1) )
        {    
            flag_buxian = 0;
            if(img_addr[50][x_middle_30 + 35] == 1)
            {
               // if(img_addr[50][x_middle_30 - 5] == 0)
                x_middle_30 = ( x_middle_30 + 159 ) / 2 ;
            }
            if(img_addr[50][x_middle_30 + 35] == 0)
            {
               // if(img_addr[50][x_middle_30 - 5] == 1)
                x_middle_30 = ( x_middle_30 + 0 ) / 2 ;
            }
        }
        if((x_middle_30 > 79) && (flag_buxian ==1) )
        {   
            flag_buxian = 0;
            if(img_addr[50][x_middle_30 - 35] == 1)
            {  
               // if(img_addr[50][x_middle_30 + 5] == 0)
                x_middle_30 = ( x_middle_30 + 0 ) / 2 ;
            }
            if(img_addr[50][x_middle_30 - 35] == 0)
            {
               // if(img_addr[50][x_middle_30 + 5] == 1)
                x_middle_30 = ( x_middle_30 + 159 ) / 2 ;
            }
        }
        x_middle = 8 * ( x_middle_30 -80 );
    }
    
    
    
    if( (flag_shizi == 1) )
    {
        x_middle = 0;
    }
    
    if( flag_bizhang != 0 )
    {
        x_middle = 6 * ( x_bizhang_middle -80 );
    }
    
    
    


            
        if(flag_zhijiao==2)
        {  
           if(x_middle_30 > 79)
              {
                 x_middle = -140;
                 ftm_pwm_duty(FTM0, FTM_CH3, 560 );
                 ftm_pwm_duty(FTM0, FTM_CH5, 950 );
              }
              else
              {
                  x_middle = 140;
                  ftm_pwm_duty(FTM0, FTM_CH5, 560 );
                  ftm_pwm_duty(FTM0, FTM_CH3, 950 );
              }
           flag_zhijiao = 1;
           

        }
    
    
    
    if( flag_danxian == 1 )
    {
        x_middle = 8 * ( x_single_middle -80 );
    }
    
    if( flag_danxian == 2 )
    {
        x_middle = 8 * ( x_single_middle -80 );
    }
    
    if( flag_danxian == 3 )
    {
        x_middle = 8 * ( x_single_middle -80 );
    }
    
    
    


    
    warebuff_1[0] =  flag_zhijiao ;
    warebuff_1[1] =  x_middle_30 ;
   // vcan_sendware(warebuff_1, sizeof(warebuff_1));
    
    flag_baochi = 0;
    
    return x_middle;
    
    
}


