//define pin name
#define dir_1 7
#define pwm_1 6
#define switch_1 13
#define switch_2 12
#define dir_2 4
#define pwm_2 3
#define pot 1   //potentiometer

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm_1,OUTPUT);
  pinMode(dir_1,OUTPUT);
  pinMode(pwm_2,OUTPUT);
  pinMode(dir_2,OUTPUT);
  pinMode(pot,INPUT);
  pinMode(switch_1, INPUT);
  pinMode(switch_2, INPUT);
  Serial.begin(9600);  //I am using Serial Monitor instead of LCD display
}
void loop() {
  // put your main code here, to run repeatedly:
  int pwm_value=0;
  int reading=0;
  int prev_reading=0;
  
  //controls the direction the motor
  digitalWrite(dir_1,digitalRead(switch_1));    
  digitalWrite(dir_2,!digitalRead(switch_2));
  //controls the speed of the motor
  for (int i=0;i<5;i++)    //gets the average value of the pot value for better accuracy
    reading+= analogRead(pot);
  reading/=5;
  pwm_value = reading>>2;  //convert the 10-bit values to 8-bit values

  analogWrite(pwm_1,pwm_value);
  analogWrite(pwm_2,pwm_value);  
  Serial.println("PWM:");
  Serial.println(pwm_value);  //Display the value of PWM
  delay(100);
}
