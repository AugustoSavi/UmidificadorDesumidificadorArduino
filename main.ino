#include <LiquidCrystal.h>

// initialize pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Sensor Pin
const int analogInPin = A0;
const int umidificar = 8;
const int desumidificar = 7;

//Variables
int sensorValue = 0;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  sensorValue = map(((analogRead(analogInPin) - 20) * 3.04), 0, 1023, -40, 125);
  delay(1000);
  verificaAcao();
}

void verificaAcao(){
  if(sensorValue < 85){
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    
    lcd.clear();
  	lcd.print("UMID. ATUAL:"+ String(sensorValue));
    lcd.setCursor(0, 1);
    lcd.print("ACAO: UMIDIFICANDO");
  }
  else if(sensorValue > 90){
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    
    lcd.clear();
  	lcd.print("UMID. ATUAL:"+ String(sensorValue));
    lcd.setCursor(0, 1);
    lcd.print("ACAO: DESUMIDIFICANDO");
  }
  else {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  	lcd.clear();
  	lcd.print("UMID. ATUAL:"+ String(sensorValue));
    lcd.setCursor(0, 1);
    lcd.print("ACAO: ESPERANDO");
  }
}
