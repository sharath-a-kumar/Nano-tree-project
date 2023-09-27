#include <LiquidCrystal.h>

const int rs = 13, en= 12, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int IR1=4;
int IR2=5;
int IR3=6;
int IR4=7;

int mob=15;


int RELAY1=18;
int RELAY2=19;

int RELAY3=2;
int RELAY4=16;

int RELAY5=14;

int fault_val;

void setup()
{
  
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);

  pinMode(mob,INPUT);
  

  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY2,OUTPUT);
  pinMode(RELAY3,OUTPUT);
  pinMode(RELAY4,OUTPUT);
  pinMode(RELAY5,OUTPUT);
  
  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY2,LOW);
   digitalWrite(RELAY3,LOW);
  digitalWrite(RELAY4,LOW);
   digitalWrite(RELAY5,LOW);



  lcd.begin(16,2);                      // Initialize the LCD
  
  lcd.clear();
  lcd.print("Nano Tree Based");
  lcd.setCursor(0, 1);
  lcd.print("Application");
  
  Serial.begin(9600);
delay(3000);

 
}
void loop()
{
  
  
  Streetlight();
  Traffic_Check();
  Mobile_Charge();
 
 
}
void Streetlight()
{
  lcd.clear();
  lcd.print("Streetlight..");
  Serial.println("Street light");
  delay(1000);
  if(digitalRead(IR1)==LOW)
  {
    digitalWrite(RELAY1,HIGH);
    FAULT_DETECTION();
    delay(5000);
    digitalWrite(RELAY1,LOW);
    
  }
  if(digitalRead(IR2)==LOW)
  {
    digitalWrite(RELAY2,HIGH);
    FAULT_DETECTION();
    delay(5000);
    digitalWrite(RELAY2,LOW);
  }
  
}
void FAULT_DETECTION()
{

  fault_val=analogRead(A3);
  fault_val=1023-fault_val;
  Serial.print("LDR2:");
  Serial.println(fault_val);
  lcd.clear();
lcd.setCursor(0,1);
  lcd.print("LDR2:");
  lcd.print(fault_val);
  delay(1000);
  if(fault_val<100)
  {
    Serial.println("$Streetlight Fault Occurs #");
    lcd.clear();
    lcd.print("Streetlight Fault");
    lcd.setCursor(0,1);
    lcd.print("Occurs");
    delay(1000);

  }

} 
void Traffic_Check()
{
   lcd.clear();
  lcd.print("Traffic..");
  Serial.println("Traffic");
  delay(1000);
  
  if(digitalRead(IR3)==LOW)
  {
    digitalWrite(RELAY3,HIGH);
    delay(5000);
    digitalWrite(RELAY3,LOW);
  }
  if(digitalRead(IR4)==LOW)
  {
    digitalWrite(RELAY4,HIGH);
    delay(5000);
    digitalWrite(RELAY4,LOW);
  
  }
  
}



void Mobile_Charge()
{
  int z;
  lcd.clear();
  lcd.print("Mobile");
  delay(100);
  if(digitalRead(mob)==LOW)
  {
    lcd.clear();
  lcd.print("Mobile Charging Start");
  delay(1000);
    for(z=0;z<60;z++)
    {
      lcd.clear();
      lcd.print("Charging Start");
      lcd.setCursor(0,1);
      lcd.print("Time:");
      lcd.print(z);
      digitalWrite(RELAY5,HIGH);
      delay(1000);
    }
    delay(1000);
    lcd.clear();
    lcd.print("Charging over");
    digitalWrite(RELAY5,LOW);
    delay(100);
  }  
  
}
