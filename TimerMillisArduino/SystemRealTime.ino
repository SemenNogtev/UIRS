unsigned long t1;
unsigned long k = 0;
double y = 0, y0 = 0;
double T = 0.1;
double dt = 0.001; // 1 мс
double TPeriod = dt*1000;

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
