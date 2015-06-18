  // define pin name
  #define pwm_2 4
  #define pwm_1 7
  #define dir_2 3
  #define dir_1 6
void setup() {
  pinMode(pwm_2, OUTPUT);
  pinMode(pwm_1, OUTPUT);
  pinMode(dir_1, OUTPUT);
  pinMode(dir_2, OUTPUT);
  Serial.begin(9600);
  //Serial.println("DIR");
}

void loop() {
  int pwm_value = 0;
  int opposite_i;
  digitalWrite(pwm_1,HIGH);
  digitalWrite(pwm_2,HIGH);
  
  for(int i=0;i<=255;i++){
    analogWrite(dir_1,i);
    opposite_i=255-i;
    analogWrite(dir_2,(255-i));
    delay(120);
  Serial.println(i);
  }
  while(1)
  continue;
}
