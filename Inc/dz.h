#ifndef __dz_H
#define __dz_H
#ifdef __cplusplus
 extern "C" {
#endif


#include "main.h"

#define A_num 9

#define B_num 7
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
extern uint16_t gpio_A[A_num];
extern uint16_t gpio_B[B_num];
/* USER CODE END Private defines */
extern double i3;

extern int Small_Arr1[8];
extern int Small_Arr2[8];

void MX_GPIO_Init(void);
void MX_GPIO_Init2(void);
void MX_GPIO_Init3(void);
void MX_GPIO_Init_A(void);
void MX_GPIO_Init_B(void);
void MX_GPIO_Init_PC14(void);

void R88_row_control(int i,GPIO_PinState c);
void R88_col_control(int i,GPIO_PinState c);

void R88_row_control2(int i,GPIO_PinState c);
void R88_col_control2(int i,GPIO_PinState c);

void R88_on();
void R88_off();

void R88_row_flush();
void R88_col_flush();

void R88_show_img(char arr[]);
void scan(char arr[8][8]);
void Display(char dat[8][8]);
void Display2(char dat[8][8],int s);
void Display_plus(char dat[8][8],int s,int times);   //显示函数

void fillBinaryArray(char binaryArray[][8], int n);


void Clear();
/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

