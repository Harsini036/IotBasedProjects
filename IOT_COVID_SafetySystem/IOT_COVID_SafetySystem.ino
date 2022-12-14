#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>

#include <Servo.h>
#include <Wire.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x27,16,2);
Servo myservo1;  

int temp_reading =0;

#define red 8
#define green 7
int pos1;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  myservo1.attach(6);//attached to the 6th pin
  myservo1.write(90);
  Serial.println("Temp testing with led and lcd along with the servo!");
  lcd.init();
  lcd.backlight();
 /* if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
   
  }*/
}

void loop() {
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  temp_reading = mlx.readAmbientTempC();
  Serial.print("*C\tObject = "); 
  Serial.print(temp_reading ); 

  Serial.println("*C");
  Serial.print("Ambient = "); 
  temp_reading = mlx.readAmbientTempF();
  Serial.print(temp_reading);
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  if(temp_reading > 98)
   {
     digitalWrite(red,HIGH);
     digitalWrite(green,LOW);
     lcd.setCursor(0,1);
     lcd.print("Temp detected : ");
     lcd.print(temp_obj);
     lcd.setCursor(1,0);
     lcd.print("Abnormal temp!!!");
}

   if(temp_reading < 98)
   {
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Temp detected : ");
    lcd.print(temp_obj);
    lcd.setCursor(1,0);
           lcd.print("You can enter");

//servo code 0 to 90 degree-open and then closed
          for(pos1 = 0; pos1 <= 90; pos1 += 1)
          {                                 
            myservo1.write(pos1);        
            delay(15);
          }
            delay(5000);

           for(pos1 = 90; pos1>=0; pos1 -=1)
           {
            myservo1.write(pos1);
            delay(15);                     
           }
}

  Serial.println();
  delay(500);
}
