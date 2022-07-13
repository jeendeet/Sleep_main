#ifndef DATA_H
#define DATA_H
#include <DHT.h>

typedef struct{
  int control_mode;
  int blue_bright; 
  int yellow_bright;
  int alarm_h;
  int alarm_m;
  int temperature;
  int humid;
  int heartrate;
  int movement;
  int ircontrol;
} f_data;
volatile f_data database;

#define ledPinBlue      16
#define ledChanelBlue   0
#define ledPinYellow    17
#define ledChanelYellow 1
#define ledFreq         5000
#define ledResolution   8
#define ledConvert(percent) (((percent)*255)/100)

#define DHT_PIN             5         
#define DHT_TYPE            DHT11 
#endif
