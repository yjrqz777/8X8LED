#ifndef __dz2_H
#define __dz2_H
#ifdef __cplusplus
 extern "C" {
#endif


#include "main.h"


/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

void R88_row_control2(int i,GPIO_PinState c);
void R88_col_control2(int i,GPIO_PinState c);

void Display2(int dat[8][8],int s);

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

