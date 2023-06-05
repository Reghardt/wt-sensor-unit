#include <Arduino.h>
#include <NewPing.h>

#define RS_MODE_PIN 7

#define MAX_DISTANCE 600
// put function declarations here:
int myFunction(int, int);

NewPing ultra = NewPing(2, 3, MAX_DISTANCE);

bool testMode = false;

unsigned int interval=1000;
unsigned long previousMillis=0;

int reading = 100;
bool isFilling = true;

void setup() {
  pinMode(RS_MODE_PIN, OUTPUT);
  digitalWrite(RS_MODE_PIN, HIGH); // if low, is receiver

  Serial.begin(9600);

  if(!testMode)
  {
    interval = 3000;
  }
}




//   ###S1:294!$$$
void loop() {
  

  unsigned long currentMillis = millis();





     
  if((unsigned long)(currentMillis - previousMillis) >= interval) {
    if(testMode)
    {
      Serial.println("###SR:" + String(reading) + "!$$$");

      if(isFilling)
      {
        reading++;
        if(reading >= 300)
        {
          isFilling = false;
        }
      }
      else
      {
        reading--;
        if(reading <= 100)
        {
          isFilling = true;
        }
      }
    }
    else
    {
      auto ultraReading = ultra.ping_cm();
      Serial.println("###SR:" + String(ultraReading) + "!$$$");
    }

    

    previousMillis = currentMillis;
  }

}

