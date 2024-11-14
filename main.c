#include <stdio.h>
#include <stdint.h>

#include "system.h"
#include "io.h"
#include "timer.h"
#include "oled.h"
#include "hi2c.h"
#include "INA219.h"

void init(void)
{
  // I/O portlar� ba�lang��
  Sys_IoInit();
  
  // System Clock Tick ba�lang��
  //Sys_TickInit();
  
  // Konsol ba�lang��
  Sys_ConsoleInit();

  INA219_Init();

  // LED ba�lang��
  IO_Write(IOP_LED, 1);
  IO_Init(IOP_LED, IO_MODE_OUTPUT_OD);  
}



float current, voltage;


void Task_Print(void)
{

   OLED_SetCursor(0, 0);
   printf("cur: %3f", current);
   OLED_SetCursor(0, 15);
   printf("mA");
  
   OLED_SetCursor(1, 0);
   printf("volt: %3f  V", voltage);
   
   DelayMs(500);
}



void main()
{
// Ba�lang�� yap�land�rmalar�
  init();//
  
  OLED_SetFont(FNT_SMALL);
  setCalibration_32V_2A();
  uint16_t calValue = 4096;  // Kalibrasyon i�in sabit bir de�er
  wireWriteRegister(INA219_REG_CALIBRATION, calValue);  // Yaz�yoruz

  uint16_t readBack;
  wireReadRegister(INA219_REG_CALIBRATION, &readBack);  // Geri okuyoruz

if (calValue != readBack) {
    // Burada hata oldu�unu bildir
  OLED_SetCursor(2, 0);
    printf("Register yazma/okuma hatas�! Beklenen: %d, Okunan: %d\n", calValue, readBack);
}

  while (1) 
  {
    current = getCurrent_mA();
    voltage = getBusVoltage_V();

    Task_Print();
  }
}


