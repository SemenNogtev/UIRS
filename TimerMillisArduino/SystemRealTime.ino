unsigned long t1; // переменная таймера millis
unsigned long TPeriod = 1; // шаг расчета, 1 мс
unsigned int k = 0; // счетчик вывода

double dt = TPeriod*0.001; // шаг расчета апериодического звена, 1 мс
double T = 0.1; // постоянная времени апериодического звена, с
double y = 0, y0 = 0; // начальные условия апериодического звена

void aperiodic(double x, double dt);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(millis()-t1>=TPeriod)
  {
    t1 += TPeriod;
    if((k%10==0)&&(k<500)) Serial.println(y);
    k++;
    aperiodic(1, dt);
  }
}

void aperiodic(double x, double dt)
{
  y = y0+1/T*(x-y0)*dt;
  y0 = y;
}
