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

// Motor de passo
Stepper stepper(STEPS,8,10,11,9); 

// Display LCD
rgb_lcd lcd;

// Servomotor
Servo servo;

time_t t;              // Variável que conta o tempo
int ledR = 6;          // LED do sensor de peça
int sensorLUZ = 0;     // Sensor de presença da peça
int buzzer = 3;        // Buzzer que alerta a falta de peça
int servoMotor = 5;    // Servomotor
volatile int flag = 1; // Indica se há falta de peça na esteira
volatile int on = 1;   // Indica se a esteira está ligada ou não
int leitura = 0;       // Leitura do sensor de peça

void setup() {
  
  attachInterrupt(0, onOff, RISING);  // Interrupção do botão On/Off

  Serial.begin(9600);

  pinMode(ledR, OUTPUT);
  pinMode(sensorLUZ, INPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(ledR,HIGH);
  
  lcd.begin(16, 2);                  // Inicia LCD
  stepper.setSpeed(50);              // Velocidade do motor de passo

  lcd.setCursor(0,1);
  lcd.print("Esteira GENOMAX");      // Inicia letreiro no LCD
  lcd.setCursor(0,0);                // Volta cursor para o inicio

  setTime(0);                        // Inicia com tempo zero
  servo.attach(servoMotor);          // Inicia servo motor
  servo.write(0);                    // Posição inicial em zero
}

void loop() {
  if(on){            // Se botão On/Off estiver acionado
      t = now();
      
      if(t > 1)      // Após 1s a caixa ter passado pelo sensor
        empurra();   // Empurra a caixa da esteira         
      if(t > 2)
        volta();     // Volta pistão para posição inicial
        
      if(t > 6)      // Verifica se por 6s não detecta peça na esteira
        flag = 0;
      else
        flag = 1;
    
      leitura = analogRead(sensorLUZ);
      
      Serial.println(leitura);
      
      if(leitura < 650){  // Cada vez que uma peça passa pelo sensor (Valor de referência varia muito dependendo das condições do sensor)
        setTime(0);       // Reinicia contagem do tempo
      }
      
      if(flag == 0){                 // Se não detectar peça por 6s
        digitalWrite(buzzer, HIGH);  // Ativa buzzer sinalizador
        servo.detach();              // Desativa pistão que empurra peça
      }
      else{
        servo.attach(servoMotor);
        digitalWrite(buzzer, LOW);
      }
      
      tela();                 // Mostra status no LCD 
    }
    else{                     // Se botão On/Off estiver desativado
      lcd.setRGB(0,0,0);      // Desativa luz de fundo do LCD
      lcd.clear();            // Limpa tela do LCD
      flag=0;
    }
    stepper.step(-200*flag);  // Aciona motor de passo
}

void tela(){
  if(!flag){                      // Se não detecta peça na esteira
    lcd.setRGB(100,0,0);          // Luz de fundo vermelho
    lcd.print("Inserir peca!   ");
  }
  else{                           // Se estiver detectando notmalmente
    lcd.setRGB(255,255,255);      // Luz de fundo azul
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
  if(!on){                      // Se botão On/Off desativado
    digitalWrite(ledR,LOW);     // Desativa LED do Sensor de presença de peça
    digitalWrite(buzzer, LOW);  // Desativa buzzer sinalizador
  }
  else{
      digitalWrite(ledR,HIGH);
      setTime(0);               // Cada vez que a esteira é reiniciada, zera contador de tempo
    } 
}
