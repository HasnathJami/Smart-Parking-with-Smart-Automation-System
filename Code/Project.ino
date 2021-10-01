//Space for including Library
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <Servo.h>
#include <String.h>


//Space for Declaring Pin
LiquidCrystal lcd(13, 12, 29, 28, 27, 26); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcdSlot(36,35,31,32,33,34);



const int trigPin1 = 3;
const int echoPin1 = 2;
const int greenLEDPin1 = 22;
const int redLEDPin1 = 23;
const int buzzerPin1 = 53;
const int trigPin2 = 11;
const int echoPin2 = 10;
const int greenLEDPin2 = 24;
const int redLEDPin2 = 25;
const int buzzerPin2 = 52;

const int greenPinLdr=47;
const int redPinLdr=38;
const int bluePinLdr=37;
const int yellowPinLdr=30;


const int ldrPin=A0;
 int ldrValue=0;



const int zeroState=0;
const int firstState=1;
const int secondState=2;
const int thirdState=3;
const int unknownState=4;
int carGCrossing = zeroState;
int carOCrossing;

int fireAlarmCheck;


long duration1;
int distanceCm1;

int slotRem = 4;
int carCount = 0;
long duration2;
int distanceCm2;




int trigger[4]={46,44,42,40};
int echo[4]={45,43,41,39}; 


bool danger;
const int buzzerPin3=51;
const int flameSensor=50;
const int gasSensor=49;
const int EQSensor=48;
const int motorPin=5;
Servo entranceServo,exitServo;
Servo entranceFlipper,exitFlipper;








void setup() {
  Serial.begin(9600);

 
  lcd.begin(20, 4);  
  lcdSlot.begin(16,2);


 
  
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(redLEDPin1, OUTPUT);
  pinMode(greenLEDPin1, OUTPUT);
  pinMode(buzzerPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(redLEDPin2, OUTPUT);
  pinMode(greenLEDPin2, OUTPUT);
  pinMode(buzzerPin2, OUTPUT);

  


  



 pinMode(greenPinLdr,OUTPUT);
  pinMode(redPinLdr,OUTPUT);
  pinMode(yellowPinLdr,OUTPUT);
  pinMode(bluePinLdr,OUTPUT);

  
 
 for(int i=0;i<4;i++)
    pinMode(trigger[i],OUTPUT);

  for(int i=0;i<4;i++)
    pinMode(echo[i],INPUT);







  pinMode(buzzerPin3,OUTPUT);
  pinMode(flameSensor,INPUT);
  pinMode(gasSensor,INPUT);
  pinMode(EQSensor,INPUT);
  
  danger=false;
  //Water Motor
  analogWrite(motorPin,0); //Clockwise
  analogWrite(4,0);  //AntiClock 4th pin of arduino

  entranceServo.attach(9); //9th pin of arduino
  exitServo.attach(8);
  entranceFlipper.attach(7);
  exitFlipper.attach(6);
  entranceServo.write(0); //initial degree
  exitServo.write(0);
  entranceFlipper.write(0);
  exitFlipper.write(0);
}


bool isTaken(int i)
{
  digitalWrite(trigger[i],LOW);
  delayMicroseconds(2);
  digitalWrite(trigger[i],HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger[i],LOW);

  long T=pulseIn(echo[i],HIGH);
  long S=0.034*T*0.5; // V=0.034 cm/microsecond


  Serial.print("Distance for sensor:");
  Serial.print(i+1);
  Serial.print(" ");
  Serial.println(S);

 
  
  if(S<=150)  // random value for test
    return true;
  else
    return false;
}






void loop() {
  if(digitalRead(flameSensor)==HIGH || digitalRead(gasSensor)==HIGH || digitalRead(EQSensor)==HIGH )
    danger=true;



  //  digitalWrite(greenPinLdr, LOW);
    
    //  digitalWrite(redPinLdr, LOW);
     
     //  digitalWrite(yellowPinLdr, LOW);
      
      //  digitalWrite(bluePinLdr, LOW);
       

  ldrValue=analogRead(ldrPin);
  if(digitalRead(flameSensor)==LOW)
  {

    if(ldrValue>=0 && ldrValue<=300)
    {

      digitalWrite(greenPinLdr, HIGH);
      digitalWrite(redPinLdr, LOW);
      digitalWrite(yellowPinLdr, HIGH);
      digitalWrite(bluePinLdr, HIGH);
     
     
    }

    if(ldrValue>=301 && ldrValue<=600)
    {

      digitalWrite(greenPinLdr, HIGH);
      digitalWrite(redPinLdr, LOW);
      digitalWrite(yellowPinLdr, LOW);
      digitalWrite(bluePinLdr, LOW);
     
     
    }

    if(ldrValue>600)
    {
  
        digitalWrite(greenPinLdr,LOW);
        digitalWrite(redPinLdr, LOW);
        digitalWrite(yellowPinLdr, LOW);
        digitalWrite(bluePinLdr, LOW);
       
       
    }    
  }



   if(digitalRead(flameSensor)==HIGH)
  {
    digitalWrite(greenPinLdr,LOW);
    digitalWrite(redPinLdr, HIGH);
    digitalWrite(yellowPinLdr, LOW);
    digitalWrite(bluePinLdr, LOW);
  }
    





  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceCm1 = duration1 * 0.034 / 2;

  int distanceFeet1 = distanceCm1 / 30.48;
 
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distanceCm2 = duration2 * 0.034 / 2;

  int distanceFeet2 = distanceCm2 / 30.48;
  
  
  //Car In To The Parking
  if (distanceFeet1 <= 6 && distanceFeet1 >= 4 && carGCrossing == zeroState && !danger)
  {
    digitalWrite(redLEDPin1, HIGH);
    delay(100);
    digitalWrite(greenLEDPin1, LOW);
    carGCrossing = firstState;

  }
  else if (distanceFeet1 <= 3 && distanceFeet1 >= 0 && carGCrossing == firstState && !danger)
  {
    tone(buzzerPin1, 1000);
    delay(100);
    noTone(buzzerPin1);
    
    digitalWrite(redLEDPin1, LOW);   // turn the LED on (LOW is the voltage level)
    // delay(100);
    digitalWrite(greenLEDPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
    carGCrossing = secondState;

    
    entranceServo.write(90);   //Entrance gate  opens and servo turns into 90degree

   
  }
  else if (distanceFeet1 >=0 && distanceFeet1 <= 8 && carGCrossing == secondState && !danger)
  {

     carGCrossing = thirdState;

    // digitalWrite(redLEDPin, LOW);   // turn the LED on (HIGH is the voltage level)
    // delay(100);
    //digitalWrite(greenLEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    // delay(100);
//    for (int pos = 0; pos <=180; pos++) {
//        entranceFlipper.write(pos);
//        delay(20);
//      }
    entranceFlipper.write(180);   
   
  }
  
  // Car Passes Its Full Length 
  else if (distanceFeet1 >= 9 && carGCrossing == thirdState && !danger)
  {
    digitalWrite(redLEDPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
    digitalWrite(greenLEDPin1, LOW);
    carCount++;
    slotRem--;
    carGCrossing = zeroState;
    carOCrossing = zeroState; // allowing cars to exit

   
    entranceServo.write(0);   // entrance gate close and servo turns into 0 degree 
  
    entranceFlipper.write(0);  //car comes inside parking fully and sonar sensor flips at 0 degree 
      
  }

  
 // FULL Slot 
  if (carCount == 4 && slotRem == 0)
  {
    digitalWrite(redLEDPin1, LOW);
    delay(100);
    digitalWrite(greenLEDPin1, LOW);
    carGCrossing = unknownState;
  }

  

//Car Out From The Parking

  if (distanceFeet2 <= 6 && distanceFeet2 >= 4 && carOCrossing == zeroState && !danger)
  {
    digitalWrite(redLEDPin2, HIGH);
    delay(100);
    digitalWrite(greenLEDPin2, LOW);
    carOCrossing = firstState;

  }
  else if ((distanceFeet2 <= 3 && distanceFeet2 >= 0 && carOCrossing == firstState && !danger))
  {
    tone(buzzerPin2, 1000);
    delay(100);
    noTone(buzzerPin2);

    digitalWrite(redLEDPin2, LOW);
    // delay(100);
    digitalWrite(greenLEDPin2, HIGH);
    delay(100);

    
    exitServo.write(90); 

    carOCrossing = secondState;
  }


    else if (distanceFeet2 >=0 && distanceFeet2 <= 8 && carOCrossing == secondState && !danger)
    {
  
      // digitalWrite(redLEDPin, LOW);
      // delay(100);
      //digitalWrite(greenLEDPin, HIGH);
      // delay(100);
       carOCrossing= thirdState;
      
      exitFlipper.write(180); 
     
    }


    else if (distanceFeet2 >= 9 && carOCrossing == thirdState && !danger)
    {
  
      digitalWrite(redLEDPin2, HIGH);
      delay(100);
      digitalWrite(greenLEDPin2, LOW);
      carCount--;
      slotRem++;

          carOCrossing = zeroState;
          carGCrossing = zeroState;
  
      
      exitServo.write(0); 

      exitFlipper.write(0);  

  
    }
    

  // EMPTY SLOT
  if (carCount == 0 && slotRem == 4 && !danger)
  {
    digitalWrite(redLEDPin2, LOW);
    delay(100);
    digitalWrite(greenLEDPin2, LOW);
    carOCrossing = unknownState; 
  }





 

  if(digitalRead(flameSensor)==HIGH || digitalRead(gasSensor)==HIGH || digitalRead(EQSensor)==HIGH )
  {
    
       

    
    danger=true;

    
    if(entranceServo.read()==90) //Angle measure for emergency situation 
      entranceServo.write(0);
    if(exitServo.read()==0)
      exitServo.write(90);
    
    if(digitalRead(flameSensor)==HIGH)
    {
      digitalWrite(redPinLdr, HIGH);
           
      analogWrite(motorPin,200);  //Motor Speed
      lcd.clear();
      lcd.setCursor(6,1);
      lcd.print("Fire Alert!");
    }
    else
    {
      analogWrite(motorPin,0);
      digitalWrite(redPinLdr, LOW);
    }
    
    if(digitalRead(gasSensor)==HIGH)
    {
      lcd.clear();
      lcd.setCursor(3,1);
      lcd.print("Gas Leak Alert!");
    }
    else if(digitalRead(EQSensor)==HIGH)
    {
      lcd.clear();
      lcd.setCursor(2,1);
      lcd.print("Earthquake Alert!");
    }
     
    tone(buzzerPin3,1000);
    delay(500);
    noTone(buzzerPin3);
    lcd.clear();
    delay(500); ////after 500 ms Continuosly
  }
  else
  {
    if(danger)
    {
      danger=false;
      
      if(exitServo.read()==90)
        exitServo.write(0);

      analogWrite(motorPin,0);//water Motor
      digitalWrite(redPinLdr, LOW);
    }


    Serial.print("Car Count: ");
    Serial.println(carCount);
    Serial.print("Slot remaining: ");
    Serial.println(slotRem);
    
    lcd.setCursor(0, 1);
    lcd.print("CC: ");
    lcd.print(carCount);
    lcd.setCursor(8, 1);
    lcd.print("SR: ");
    lcd.print(slotRem);
  
    delay(10);

 //   Serial.print("Entrance Distance: ");
 //   Serial.println(distanceFeet1);
 //   Serial.print("Exit Distance: ");
  //  Serial.println(distanceFeet2);
  
    lcd.setCursor(0, 0);
    lcd.print("DistEn:");
    lcd.print(distanceFeet1);
    lcd.print("ft");
    delay(10);
  
  
  
    lcd.setCursor(0,2);
    lcd.print("DistEx:");
    lcd.print(distanceFeet2);
    lcd.print("ft");
    delay(10);


    lcd.setCursor(0,3);
    lcd.print("Light Intensity:");
    lcd.print(ldrValue);
   
    delay(10);

  // Serial.print("Intensity:");
   // Serial.print("ldrValue");

   

  }
 




  String out[2]={"OO","OO"};
  
  for(int i=0;i<4;i++)
  {
    int row=i/2; //
    int col=i%2;

    if(isTaken(i))
      out[row][col]='X';
    else
      out[row][col]='O';
  }

//  lcd.setCursor(0,0);
//  lcd.print("Col 0 Row 0");
//  delay(1000);
//  
//  lcd.setCursor(0,1);
//  lcd.print("Col 0 Row 1");
//  delay(2000);

  for(int i=0;i<2;i++)
  {
    //Serial.println(out[i]);
    lcdSlot.setCursor(0,i); // (column,row)
    lcdSlot.print(out[i]);
  }
}

