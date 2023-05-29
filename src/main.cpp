#include <Arduino.h>
#include <NewPing.h>

#define RS_MODE_PIN 7

#define MAX_DISTANCE 600
// put function declarations here:
int myFunction(int, int);

NewPing ultra = NewPing(2, 3, MAX_DISTANCE);

void setup() {
  pinMode(RS_MODE_PIN, OUTPUT);
  digitalWrite(RS_MODE_PIN, HIGH); // if low, is receiver

  Serial.begin(9600);
}


int reading = 100;
bool isFilling = true;

//   ###S1:294!$$$
void loop() {
  //auto reading = ultra.ping_cm();

  Serial.println("###SR:" + String(reading) + "!$$$");
  delay(200);

  
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

