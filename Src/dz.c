#include "dz.h"

GPIO_TypeDef *a[3]={GPIOA,GPIOB,GPIOC};
uint16_t high[8]={GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7};
uint16_t low[8]={GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15};
//A0、A1、A2、A3、A4、A5、A6、A7


void Clear()                          //清空显示
{
  for(int i = 0;i<8;i++)
  {
    R88_row_control(i,0);
    R88_col_control(i,1);
  }
}
double i3=50;


void Display(int dat[8][8],int s)   //显示函数
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


void Display2(int dat[8][8],int s)
{
  for(int c = 0; c<8;c++)
  {
    R88_col_control(c,0);
    for(int r = 0;r<8;r++)
    {
      R88_row_control(r,dat[r][c]);
			
    }
    Clear();
  }
}



void R88_row_flush(){
  int i,j,n;
    R88_off();//关闭所有
    for(i=0;i<8;i++){
     for(n=0;n<8;n++) R88_row_control(n,0);//关闭所有行
     R88_row_control(i,1);//行移动
     for(j=0;j<8;j++){
         for(n=0;n<8;n++) R88_col_control(n,1);//关闭所有列
         R88_col_control(j,0);//列移动
         HAL_Delay(10);
     }
    }
}

void R88_col_flush(){
  int i,j,n;
    R88_off();//关闭所有
    for(i=0;i<8;i++){
     for(n=0;n<8;n++) R88_col_control(n,1);//关闭所有列
     R88_col_control(i,0);//列移动
     for(j=0;j<8;j++){
          for(n=0;n<8;n++) R88_row_control(n,0);//关闭所有行
          R88_row_control(j,1);//行移动
          HAL_Delay(10);
     }
    }
}

int Small_Arr1[8]={0x04,0x02,0x24,0x40,0x40,0x24,0x02,0x04};
int Small_Arr2[8]={0xFF,0x02,0x22,0x40,0x40,0x26,0x02,0x02};
void R88_show_img(int arr[]){
   int i,j,n;
    for(i=0;i<8;i++){
     R88_off();//关闭所有
     R88_col_control(i,0);//列移动ˉ
     //行控制
     if(arr[i]&0x01) R88_row_control(0,1);
     if(arr[i]&0x02) R88_row_control(1,1);
     if(arr[i]&0x04) R88_row_control(2,1);
     if(arr[i]&0x08) R88_row_control(3,1);
     if(arr[i]&0x10) R88_row_control(4,1);
     if(arr[i]&0x20) R88_row_control(5,1);
     if(arr[i]&0x40) R88_row_control(6,1);
     if(arr[i]&0x80) R88_row_control(7,1);
		 //HAL_Delay(i);
    }
}

void scan(int arr[8][8]){
  int i,j;
	for(i=0;i<8;i++)
	{
	R88_col_control(i,0);
		for(j=0;j<8;j++)
		{

				R88_row_control(j,arr[i][j]);
        //R88_col_control(j,0);
			}
			//R88_col_control(i,0);
	}
		for(i=0;i<8;i++)
	{
	R88_col_control(i,1);
	R88_row_control(i,0);
	}

}




void MX_GPIO_Init_PC14(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOC_CLK_ENABLE();
//  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

void MX_GPIO_Init2(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOC_CLK_ENABLE();
//  __HAL_RCC_GPIOD_CLK_ENABLE();
//  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

void MX_GPIO_Init3(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void MX_GPIO_Init_A(void)
{
	//A0、A1、A2、A3、A4、A5、A6、A7
  for(int i=0;i<8;i++)
	{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = high[i];
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	}
	
}

void MX_GPIO_Init_B(void)
{
	for(int i=0;i<8;i++)
	{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = low[i];
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	}

}

//行控制
void R88_row_control(int i,GPIO_PinState c){
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
void R88_col_control(int i,GPIO_PinState c){
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
GPIO_TypeDef *h2[8]={GPIOB,GPIOB,GPIOA,GPIOB,GPIOA,GPIOA,GPIOA,GPIOA};
uint16_t high2[8]={GPIO_PIN_0,GPIO_PIN_13,GPIO_PIN_7,GPIO_PIN_11,GPIO_PIN_0,GPIO_PIN_6,GPIO_PIN_1,GPIO_PIN_4};

//行控制
void R88_row_control2(int i,GPIO_PinState c){
	for(int i=0;i<8;i++)
	{
		HAL_GPIO_WritePin(h2[i],high[i],c);
	}
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




void R88_on(){
    int i=0;
    for( i=0;i<8;i++) 
    {
        R88_row_control(i,1);
        R88_col_control(i,0);
				HAL_Delay(50);
    }
}


void R88_off(){
    int i=0;
    for( i=7;i>=0;i--) 
    {
        R88_row_control(i,0);
        R88_col_control(i,1);
				HAL_Delay(50);
    }
}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
