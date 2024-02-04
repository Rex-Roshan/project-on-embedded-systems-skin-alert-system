//over head -> bad
//over wind -> bad
//over intensity -> bad

/*components used
 * leds - 3
 * buzzer - 1
 * lcd - 1 (16,2)
 * ldr - 1 (to detect light)
 * temperature sensor - 1  (to detect the temperature
 * pir sensor - 1 (a motion detector to check for the wind strength) 
 */

 
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int safeled=10;  // glows if the condition  is good
int avgled=9;       // glows if the condition is okish
int notsafeled=7;      // glows if the condition is bad

int buzzpin=A0;   // tones if the condition is bad or avg
int temppin=A1;
int ldrpin=A2;
int pirpin=A3;





void setup() {
  // put your setup code here, to run once:
  pinMode(safeled,OUTPUT);
  pinMode(avgled,OUTPUT);
  pinMode(notsafeled,OUTPUT);
  pinMode(buzzpin,OUTPUT);
  pinMode(temppin,INPUT);
  pinMode(ldrpin,INPUT);
  pinMode(pirpin,INPUT);
  lcd.begin(16,2);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  int temp=analogRead(temppin);
  temp=temp*.48812;
  int ldrval=analogRead(ldrpin);
  int pirval=analogRead(pirpin);

  if (temp >= 10)
  {
    if(ldrval <=200)
    {
      if(pirval < 100 )
      {
        lcd.print("Not Good");
        lcd.setCursor(0,0);
        digitalWrite(notsafeled,HIGH);
        digitalWrite(safeled,LOW);
        digitalWrite(avgled,LOW);
        tone(buzzpin,1000);
      }
      else
      {
        lcd.print("Heat-Windny");
        lcd.setCursor(0,0);
        digitalWrite(notsafeled,HIGH);
        digitalWrite(safeled,LOW);
        digitalWrite(avgled,LOW);
        tone(buzzpin,1000);
      }
    }
    else
    {
       if(pirval < 100 )
      {
        lcd.print("H-Radiation");
        lcd.setCursor(0,0);
        digitalWrite(notsafeled,HIGH);
        digitalWrite(safeled,LOW);
        digitalWrite(avgled,LOW);
        tone(buzzpin,1000); 
      }
      else
      {
        lcd.print("W-Radiation");
        lcd.setCursor(0,0);
        digitalWrite(notsafeled,HIGH);
        digitalWrite(safeled,LOW);
        digitalWrite(avgled,LOW);
        tone(buzzpin,1000);
      }
    }
  }
  else
  {
    if(ldrval >=200)
    {
      if(pirval < 100 )
      {
        lcd.print("Night_light");
        lcd.setCursor(0,0); 
        digitalWrite(notsafeled,LOW);
        digitalWrite(safeled,HIGH);
        digitalWrite(avgled,LOW);
        noTone(buzzpin);
      }
      else
      {
        lcd.print("Good-W-Day");
        lcd.setCursor(0,0);
        digitalWrite(notsafeled,LOW);
        digitalWrite(safeled,HIGH);
        digitalWrite(avgled,LOW);
        noTone(buzzpin);
      }
    }
    else
    {
       if(pirval < 100 )
      {
        lcd.print("Cloudy-Good");
        lcd.setCursor(0,0);
        digitalWrite(notsafeled,LOW);  
        digitalWrite(safeled,HIGH);
        digitalWrite(avgled,LOW);
        noTone(buzzpin); 
      }
      else
      {
        lcd.print("Windy-OK");
        lcd.setCursor(0,0);
        digitalWrite(notsafeled,LOW);
        digitalWrite(safeled,LOW);
        digitalWrite(avgled,HIGH);
        tone(buzzpin,100);
      }
    }
  }
  delay(3000);
}
