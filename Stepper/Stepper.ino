#include <Stepper.h> // библиотека для шагового двигателя

// количество шагов на 1 оборот, измените значение для вашего мотора
const int stepsPerRevolution = 2048;

// устанавливаем порты для подключения драйвера
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);

// начальное направление
int direction = 0;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(12); // устанавливаем скорость 12 об/мин - max
}

void loop() {
  // проверяем, поступают ли какие-то команды из Serial порта
  if (Serial.available()) {
    // переменная direction равна полученной команде
    direction = Serial.parseInt();
    myStepper.step(direction);
  } 
}