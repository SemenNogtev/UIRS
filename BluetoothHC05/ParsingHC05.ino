void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(13,OUTPUT);  
}

void loop() {
  if(Serial.available()>1)
  {
    char key = Serial.read();
    int val = Serial.parseInt();
    switch(key)
    {
      case 'a': digitalWrite(13, val);// do something
      break;
      case 'x': Serial.print("x="); Serial.println(val);// вперед
      break;
      case 'y': Serial.print("y="); Serial.println(val);// поворот
      break;
    }
  }
}

// {keydata}
// key - 1 буква