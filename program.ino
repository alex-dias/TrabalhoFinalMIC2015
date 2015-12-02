/*
======================================================
                   ESTEIRA GENOMAX

Esteira com sensor de luz que detecta a peça passando.
Quando  nenhuma  peça  passa  pelo  sensor durante  5
segundos, a esteira para e é acionado um buzzer  como
alerta. Além disso, um visor LCD mostra o status atual
da esteira.

Autores:
Alexandre Negretti      558214
Igor Gallon             558320
======================================================
*/

#include <Time.h>  
#include <Wire.h>
#include <Stepper.h>
#include <rgb_lcd.h>
#include <Servo.h>
#define STEPS 200

Stepper stepper(STEPS,8,10,11,9); 
rgb_lcd lcd;
int ledR = 6;
int sensorLUZ = 0;
int buzzer = 3;
int servoMotor = 5;
volatile int flag = 1;
volatile int on = 1;
int leitura = 0;
time_t t;
Servo servo;

void setup() {
  attachInterrupt(0, onOff, RISING);
  pinMode(ledR, OUTPUT);
  pinMode(sensorLUZ, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  stepper.setSpeed(50);
  Serial.begin(9600);
  lcd.setCursor(0,1);
  lcd.print("Esteira GENOMAX");
  lcd.setCursor(0,0);
  digitalWrite(ledR,HIGH);
  setTime(0);
  servo.attach(servoMotor);
  servo.write(0);
}

void loop() {
  if(on){
      t = now();
      
      if(t > 1)
        empurra();
      if(t > 2)
        volta();
      
      if(t > 5)
        flag = 0;
      else
        flag = 1;
    
      leitura = analogRead(sensorLUZ);
      
      if(leitura < 600){
        setTime(0);
      }
      
      if(flag == 0){
        digitalWrite(buzzer, HIGH);
        servo.detach();
      }
      else{
        servo.attach(servoMotor);
        digitalWrite(buzzer, LOW);
      }
      
      tela();      
    }
    else{
      lcd.setRGB(0,0,0);
      lcd.clear();
      flag=0;
    }
    stepper.step(-200*flag);
}

void tela(){
  if(!flag){
    lcd.setRGB(100,0,0);
    lcd.print("Inserir peca!   ");
  }
  else{
    lcd.setRGB(255,255,255);
    lcd.print("Working well...");
  }
  lcd.setCursor(0,1);
  lcd.print("Esteira GENOMAX");
  lcd.setCursor(0,0);
}

void empurra(){
  servo.write(90);
}

void volta(){
  servo.write(0);
}

void onOff(){
  on = !on;
  if(!on){
    digitalWrite(ledR,LOW);
    digitalWrite(buzzer, LOW);
  }
  else{
      digitalWrite(ledR,HIGH);
      setTime(0);
    } 
}
