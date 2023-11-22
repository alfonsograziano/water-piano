#include <CapacitiveSensor.h>

// Define an array of CapacitiveSensor objects
int enabledSensors = 18;
CapacitiveSensor sensors[] = {
  CapacitiveSensor(52,53), //Do
  CapacitiveSensor(34,35), //Do#
  CapacitiveSensor(48,49), //Re
  CapacitiveSensor(46,47), //Re#
  CapacitiveSensor(44,45), //Mi
  CapacitiveSensor(42,43), //Fa
  CapacitiveSensor(40,41), //Fa#
  CapacitiveSensor(38,39), //Sol
  CapacitiveSensor(36,37), //Sol#

  CapacitiveSensor(18,19), //La
  CapacitiveSensor(16,17), //La#
  CapacitiveSensor(14,15), //Si
  CapacitiveSensor(2,3), //Do
  CapacitiveSensor(4,5), //Do#
  CapacitiveSensor(6,7), //Re
  CapacitiveSensor(8,9), //Re#
  CapacitiveSensor(10,11), //Mi
  CapacitiveSensor(12,13), //Fa
  
};

int samples = 20;

long threshold = 80;

bool status[] = {
  false, false, false,
  false, false, false,
  false, false, false,
  false, false, false,
  false, false, false,
  false, false, false,
};


bool debug = true;

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < enabledSensors; i++){
    sensors[i].capacitiveSensor(1); 
  }
}

void loop() {
  
  for(int i = 0; i < enabledSensors; i++){
      float sensorValue = sensors[i].capacitiveSensorRaw(samples); 
     
      // Serial.print(i);
      // Serial.print(" - ");

      // Serial.println(sensorValue);

    if(status[i] == false && sensorValue > threshold){
      Serial.print("d:");
      Serial.println(i+1);
      status[i] = true;
    }
     if(status[i] == true && sensorValue < threshold){
      Serial.print("u:");
      Serial.println(i+1);
      status[i] = false;
    }

  }
}