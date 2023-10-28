#include "Car.h";

Car car;

unsigned long t1; // переменная таймера millis
unsigned long TPeriod = 1; // шаг расчета, 1 мс
double dt = TPeriod*0.001; // шаг расчета, 1 мс

void setup() {
  Serial.begin(9600);
	car.initCar();
}

void loop() {
  if(millis()-t1>=TPeriod)
  {
    t1 += TPeriod;
    
    if (car.unlocked())
	  {
      car.go(0, 1, 50);
	  }
  }
}