#include "GyverStepper2.h" // библиотека для шагового двигателя

int steps = 2048; // число шаг/об
GStepper2< STEPPER4WIRE> stepper(steps, 2, 4, 3, 5); // объект - шаговый двигатель

int directionZero = 0; // заданное направление вручную через Serial порт
int directionInput = 0; // заданное направление от САУ

void setup() {
  Serial.begin(9600);

  // настройка шагового двигателя
  stepper.setTarget(directionZero); // угол поворота, шаг
  stepper.setMaxSpeed(400);         // угловая скорость, шаг/сек
  stepper.setAcceleration(0);       // угловое ускорение = 0, шаг/сек/сек
  stepper.autoPower(true);         // отключать мотор, когда он не вращается
}

void loop() {
  stepper.tick();   // мотор асинхронно крутится тут

  if (Serial.available()) { // если пришла команда из Serial порта
    directionZero = Serial.parseInt(); // переменная directionZero равна полученной команде
    if (stepper.ready()) // если приехали, шаговый двигатель не вращается
    { 
      stepper.setTarget(directionInput + directionZero); // угол поворота
    }
  }

  // асинхронный вывод в порт
  static uint32_t tmr;
  if (millis() - tmr >= 100) {
    tmr = millis();
    Serial.println(stepper.pos);
  }
}