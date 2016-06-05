

#include "common.h"
#include "include.h"




/***********************舵机宏定义****************************/

#define S3010_FTM   FTM3
#define S3010_CH    FTM_CH1
#define S3010_HZ    (100)
#define S3010_Middle     (1425)

/***********************电机宏定义****************************/
#define MOTOR_FTM   FTM0
#define MOTOR1_PWM  FTM_CH3
#define MOTOR2_PWM  FTM_CH4
#define MOTOR3_PWM  FTM_CH5
#define MOTOR4_PWM  FTM_CH6
#define MOTOR_HZ    (20*1000)

uint16 speed = 730 ;

uint8 imgbuff[CAMERA_SIZE];  

uint8 imgbuff_1[CAMERA_SIZE]; 

char warebuff[1];

//定义存储接收图像的数组
char img[CAMERA_H][CAMERA_W];

//char img_sobel[CAMERA_H][CAMERA_W];
char img_sobel[4][CAMERA_W];

//char img_cut[CAMERA_CUT_H][CAMERA_CUT_W];

uint8 img_operation[CAMERA_H][CAMERA_W];                //最终处理

uint8 img_operation_1[CAMERA_H][CAMERA_W];

uint8 img_middle[CAMERA_H];

uint8 img_ima[CAMERA_H][2];

uint8 key_1 = 0;
uint8 key_2 = 0;
uint8 key_3 = 0;
uint8 key_4 = 0;
uint8 key_5 = 0;
uint8 key_6 = 0;
uint8 key_7 = 0;
uint8 key_8 = 0;

int Middle = 0;

uint16 maichomg = 0;

uint8 flag_stop = 0;



//函数声明
void PORTA_IRQHandler();
void DMA0_IRQHandler(); 




/*!
 *  @brief      main函数
 *  @since      v5.3
 *  @note       
 */
void  main(void)
{

    gpio_init (PTD7, GPI,0);
    gpio_init (PTD9, GPI,0);
    gpio_init (PTD11, GPI,0);
    gpio_init (PTD13, GPI,0);
    gpio_init (PTD15, GPI,0);
    gpio_init (PTE1, GPI,0);
    gpio_init (PTE3, GPI,0);
    gpio_init (PTD5, GPI,0);
    
  
    ftm_pwm_init(S3010_FTM, S3010_CH,  S3010_HZ,S3010_Middle);
    
    ftm_pwm_init(MOTOR_FTM, MOTOR1_PWM,MOTOR_HZ,1000);
    ftm_pwm_init(MOTOR_FTM, MOTOR2_PWM,MOTOR_HZ,1000);
    ftm_pwm_init(MOTOR_FTM, MOTOR3_PWM,MOTOR_HZ,1000);
    ftm_pwm_init(MOTOR_FTM, MOTOR4_PWM,MOTOR_HZ,1000);
    lptmr_pulse_init(LPT0_ALT1,0xFFFF,LPT_Rising);
    
    camera_init(imgbuff);
    gpio_init(PTE27,GPO,1);
    
    key_1 = gpio_get (PTD7);
    key_2 = gpio_get (PTD9);
    key_3 = gpio_get (PTD11);
    key_4 = gpio_get (PTD13);
    key_5 = gpio_get (PTD15);
    key_6 = gpio_get (PTE1);
    key_7 = gpio_get (PTE3);
    key_8 = gpio_get (PTD5);
    
    if( ( key_5 == 1 ) && ( key_6 ==0 ) && ( key_7 == 0 ) )
    {
        speed =630;
    }
    else
    {
        speed = 730;
    }
    
   // DELAY_MS( 40 );


    //配置中断服务函数
    set_vector_handler(PORTA_VECTORn , PORTA_IRQHandler);   //设置LPTMR的中断服务函数为 PORTA_IRQHandler
    set_vector_handler(DMA0_VECTORn  , DMA0_IRQHandler );     //设置LPTMR的中断服务函数为 PORTA_IRQHandler
    lptmr_pulse_clean();
    do
    {
        DELAY_MS( 100 );
        maichomg = lptmr_pulse_get();
        lptmr_pulse_clean();
        warebuff[0] =   maichomg ;
        vcan_sendware(warebuff, sizeof(warebuff));
    }
    while( (maichomg > 80) && ( maichomg < 120 ) );
    
    maichomg = 0;
    
    ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM, speed );
    ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM, 1000 );
    ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM, speed );
    ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM, 1000 );

    while(1)
    {
      
       // maichomg = lptmr_pulse_get();
       // lptmr_pulse_clean();
      
      lptmr_pulse_clean();
      camera_get_img();  
      
     
   
    //  memcpy(imgbuff_1,imgbuff,CAMERA_SIZE);
    //  IMG_Get_Ima(img,img_ima);
    //  vcan_sendware(warebuff, sizeof(warebuff));
    //  vcan_sendimg(imgbuff,CAMERA_SIZE);
   //   warebuff[0]=img_ima[IMG_Bottom][0];
   //   warebuff[1]=img_ima[IMG_Bottom][1];
      
      

      img_extract(img, imgbuff, CAMERA_SIZE);        //解压为灰度图像，方便发送到上位机显
      PTE27_OUT=1;
     // Sobel(img,img_sobel);
      Sobel_1(img,img_sobel);
      PTE27_OUT=0;
      Middle = IMG_Scan(img_sobel,img,speed);
      
      
      
      if( Middle > 140)
      {
          Middle = 140;
      }
      
      if( Middle < -140)
      {
          Middle = -140;
      }
      
   //   warebuff[0] =   maichomg ;
   //   vcan_sendware(warebuff, sizeof(warebuff));
      
      ftm_pwm_duty(S3010_FTM, S3010_CH, S3010_Middle - Middle );
      
    //  ftm_pwm_duty(S3010_FTM, S3010_CH, S3010_Middle + 130);
      
     // PTE27_OUT=1;
    //  vcan_sendimg(img_sobel,4*160);
     // PTE27_OUT=0;
     // memcpy(imgbuff_1,imgbuff,CAMERA_SIZE);
      
      maichomg = lptmr_pulse_get();
      lptmr_pulse_clean();
      
      if( (maichomg > 10) && ( maichomg < 15 ) )
      {
          if( flag_stop == 0 )
          {
              flag_stop = 1;
          }
      }
      else
      {
          if( flag_stop == 1 )
          {
              flag_stop = 2;
          }
      }
      
      if( flag_stop == 2 )
      {
          ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM, 1000 );
          ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM, 1000 );
          ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM, 1000 );
          ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM, 1000 );
      }
      
      warebuff[0] =   maichomg ;
      vcan_sendware(warebuff, sizeof(warebuff));
        
        

    }
}


/*!
 *  @brief      PORTA中断服务函数
 *  @since      v5.0
 */
void PORTA_IRQHandler()
{
    uint8  n;    //引脚号 
    uint32 flag;

    while(!PORTA_ISFR);
    flag = PORTA_ISFR;
    PORTA_ISFR  = ~0;                                   //清中断标志位

    n = 29;                                             //场中断
    if(flag & (1 << n))                                 //PTA29触发中断
    {
        camera_vsync();
    }
#if ( CAMERA_USE_HREF == 1 )                            //使用行中断
    n = 28;
    if(flag & (1 << n))                                 //PTA28触发中断
    {
        camera_href();
    }
#endif


}

/*!
 *  @brief      DMA0中断服务函数
 *  @since      v5.0
 */
void DMA0_IRQHandler()
{
    camera_dma();
}


