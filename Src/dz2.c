#include "dz2.h"
#include "dz.h"
GPIO_TypeDef *a[3]={GPIOA,GPIOB,GPIOC};
uint16_t high[8]={GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7};
uint16_t low[8]={GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15};
//A0、A1、A2、A3、A4、A5、A6、A7


double i3=50;





void Display2(int dat[8][8],int s)   //显示函数
{
	i3 = (int)i3;
  for(int c = 0; c<8;c++)
  {
    R88_col_control(c,0);//选通第c列
 
    //循环
    for(int r = 0;r<8;r++)
    {
      R88_row_control(r,dat[r][c]);
			
    }
		if(s==1)
		{
    if(i3>0)
		{
			i3 = i3-1;
			if(i3<10)HAL_Delay(i3*2);
			
			HAL_Delay(i3);
		}
		//i3 = i3-4;
//		if(i3<5) i3=0;
}
    Clear();  //清空显示去除余晖
  }
}

//行控制
void R88_row_control2(int i,GPIO_PinState c){
     if(i==0) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,c); //1
     if(i==1) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,c); //1
     if(i==2) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,c); //1
     if(i==3) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,c); //1
     if(i==4) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,c); //1
     if(i==5) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,c); //1
     if(i==6) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,c); //1
     if(i==7) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,c); //1
		 //HAL_Delay(1);
}

//列控制
void R88_col_control2(int i,GPIO_PinState c){
     if(i==0) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,c); //0
     if(i==1) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,c); //0
     if(i==2) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,c); //0
     if(i==3) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,c); //0
     if(i==4) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,c); //0
     if(i==5) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,c); //0
     if(i==6) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,c); //0
     if(i==7) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,c); //0
		 //HAL_Delay(1);

}


