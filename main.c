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
  // I/O portlarý baþlangýç
  Sys_IoInit();
  
  // System Clock Tick baþlangýç
  //Sys_TickInit();
  
  // Konsol baþlangýç
  Sys_ConsoleInit();

  INA219_Init();

  // LED baþlangýç
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
// Baþlangýç yapýlandýrmalarý
  init();//
  
  OLED_SetFont(FNT_SMALL);
  setCalibration_32V_2A();
  uint16_t calValue = 4096;  // Kalibrasyon için sabit bir deðer
  wireWriteRegister(INA219_REG_CALIBRATION, calValue);  // Yazýyoruz

  uint16_t readBack;
  wireReadRegister(INA219_REG_CALIBRATION, &readBack);  // Geri okuyoruz

if (calValue != readBack) {
    // Burada hata olduðunu bildir
  OLED_SetCursor(2, 0);
    printf("Register yazma/okuma hatasý! Beklenen: %d, Okunan: %d\n", calValue, readBack);
}

  while (1) 
  {
    current = getCurrent_mA();
    voltage = getBusVoltage_V();

    Task_Print();
  }
}


