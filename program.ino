#include <Time.h>  
#include <Wire.h>
#include <Stepper.h>
#include <rgb_lcd.h>
#define STEPS 200

Stepper stepper(STEPS,8,10,11,9); 
rgb_lcd lcd;
int ledR = 3;
int sensorLUZ = 0;
int buzzer = 4;
volatile int flag = 1;
int leitura = 0;
time_t t;

void setup() {
  attachInterrupt(0, parae, RISING);
  pinMode(ledR, OUTPUT);
  pinMode(sensorLUZ, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  stepper.setSpeed(50);
  Serial.begin(9600);
  digitalWrite(ledR, HIGH);
  setTime(0); 
}

void loop() {
  
  t = now();
    
  if(t > 5)
    flag = 0;
  else
    flag = 1;
    
  leitura = analogRead(sensorLUZ);
    
  if(leitura < 600){
    setTime(0);}
  
  if(flag == 0)
    digitalWrite(buzzer, HIGH);
  else
    digitalWrite(buzzer, LOW);

  stepper.step(-200*flag);
  
    
  Serial.println(t);
//stepper.setSpeed(50);  

//  if(!flag)
//      lcd.print("Esteiras GENOMAX");
//  else
//      lcd.print("ESTEIRA PARADA");

}

void parae(){
  flag = 0;
  digitalWrite(ledR, LOW);
}
