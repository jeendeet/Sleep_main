#include "data.h"
void led_setup() {
  Serial.println("[LED] Start Setup");
  ledcSetup(ledChanelBlue   ,ledFreq,ledResolution);
  ledcSetup(ledPinYellow ,ledFreq,ledResolution);
  ledcAttachPin(ledPinBlue     ,ledChanelBlue);
  ledcAttachPin(ledPinYellow   ,ledChanelYellow);
  ledcWrite(ledChanelBlue  ,255);
  ledcWrite(ledChanelYellow,100);

}
void led_change(int chanel, int percent) {
  ledcWrite(chanel, ledConvert(percent));
  Serial.println("[LED] Set led " + String(chanel) + " at " + String(percent));
}
void data_setup(){
  database.control_mode = 0;
  database.blue_bright = 100;
  database.yellow_bright=50;
}

void dht_setup() {
  DHT dht(DHT_PIN, DHT_TYPE);
  Serial.println("[DHT] task begin");
  dht.begin();
}
void dht_get_data()
{
  int t = 0;
  int h = 0;
  while( isnan(t) || isnan(h) ) {
      t = dht.readTemperature();
      h = dht.readHumidity();
  }
  database.temperature = t;
  database.humid = h;
}
