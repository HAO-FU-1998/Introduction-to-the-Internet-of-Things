//温度传感器定义接口
float temp;
int tempPin = 0;
//人体红外动作侦测传感器定义接口
int ripPin = 8;
//水位传感器定义接口
int waterPin = 13;
//超声波及蜂鸣传感器定义接口
int trigPin = 9;
int echoPin = 10;
long distance;
long duration;
int  soundPin = 11;
//LED灯定义接口
int greenLED = 2;
int redLED = 3;
int yellowLED = 4;
int whiteLED = 5;
//小车电机驱动接口
int motorPin = 6;
int motorPin2 = 7;

void setup() {
   Serial.begin(9600);
   
   pinMode(waterPin, INPUT);
   pinMode(whiteLED, OUTPUT);
   
   pinMode(greenLED,OUTPUT);
   pinMode(redLED, OUTPUT);
   pinMode(yellowLED, OUTPUT);
   
   pinMode(echoPin, INPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(soundPin, OUTPUT);

   pinMode(motorPin, OUTPUT);
   pinMode(motorPin2, OUTPUT);

}

void loop() {

   //启动电机
   digitalWrite(motorPin, HIGH);
   digitalWrite(motorPin2, HIGH);
  
  //温度传感器应用
   temp = analogRead(tempPin);
   temp = temp * 0.48828125;
   if(temp >= 29){
    digitalWrite(greenLED, HIGH);
   }
   else{
    digitalWrite(greenLED, LOW);
   }

  //水位传感器应用
   if( digitalRead(waterPin) == LOW ){
    digitalWrite(whiteLED, LOW);
   }
   else{
    digitalWrite(whiteLED, HIGH);
   }

  //PIR传感器应用
   if(digitalRead(ripPin) == HIGH) {
    digitalWrite(redLED, HIGH);
   }
   else if(digitalRead(ripPin) == LOW){
    digitalWrite(redLED, LOW);
   }

  //超声波及蜂鸣传感器应用
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 15) {  
    digitalWrite(yellowLED,HIGH); 
    digitalWrite(soundPin, LOW);
  }
  else {
    digitalWrite(yellowLED,LOW);
    digitalWrite(soundPin, HIGH);
  }
  
  delay(1000); 
}
