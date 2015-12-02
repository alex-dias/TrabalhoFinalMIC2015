#include <Wire.h>
#include <Stepper.h>
#include <rgb_lcd.h>
#define STEPS 200

Stepper stepper(STEPS,8,10,11,9); 
rgb_lcd lcd;
int button = 2;
volatile int flag = 1;

void setup() {
//  pinMode(button, INPUT);
  attachInterrupt(0, parae, RISING);
  //stepper.setSpeed(50);
  lcd.begin(16, 2);
  stepper.setSpeed(50);
  Serial.begin(9600);

}

void loop() {
  stepper.step(-200*flag);
  
    
  Serial.println(flag);
//stepper.setSpeed(50);  

//  if(!flag)
//      lcd.print("Esteiras GENOMAX");
//  else
//      lcd.print("ESTEIRA PARADA");

}


//void parae(){
//  if(flag == 0){
//    lcd.print("ESTEIRA VAZIA");
//    stepper.setSpeed(0);
//    flag = 1;
//  }
//   else{
//     stepper.setSpeed(50);
//     lcd.print("Esteiras GENOMAX");
//     flag = 0;
//  }
//}

void parae(){
  flag = !flag;
}
