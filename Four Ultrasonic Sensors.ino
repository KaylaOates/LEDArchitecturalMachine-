#define echoRight 10 //FACING TOWARD ME
#define trigRight 9
#define echoMidRight 3
#define trigMidRight 2
#define echoMidLeft 8
#define trigMidLeft 1
#define echoLeft 4
#define trigLeft A0

void setup() {
  Serial.begin(9600);  
  
  pinMode(trigRight, OUTPUT);   
  pinMode(echoRight, INPUT); 
  pinMode(trigMidRight, OUTPUT);   
  pinMode(echoMidRight, INPUT);
  pinMode(trigMidLeft, OUTPUT);   
  pinMode(echoMidLeft, INPUT);
  pinMode(trigLeft, OUTPUT);   
  pinMode(echoLeft, INPUT);
}

void loop() {
  //ultra sonic sensor 1
  digitalWrite(trigRight, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigRight, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigRight, LOW);  
  float duration = pulseIn(echoRight, HIGH); 
  float distance = (duration / 2) * 0.034;
  delay(5);
  
  //sensor2
  digitalWrite(trigMidRight, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigMidRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigMidRight, LOW); 
  float duration2 = pulseIn(echoMidRight, HIGH); 
  float distance2 = (duration2 / 2) * 0.034; 
  delay(5);

  //sensor3
  digitalWrite(trigMidLeft, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigMidLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigMidLeft, LOW); 
  float duration3 = pulseIn(echoMidLeft, HIGH); 
  float distance3 = (duration3 / 2) * 0.034; 
  delay(5);

  //sensor4
  digitalWrite(trigLeft, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigLeft, LOW); 
  float duration4 = pulseIn(echoLeft, HIGH); 
  float distance4 = (duration4 / 2) * 0.034; 
  delay(5);
  
  float pwmVal = 0; 
  float pwmVal2 = 0;
  float pwmVal3 = 0;
  float pwmVal4 = 0;

  //sensor 1
  if(distance >= 5 && distance <= 15)
  {
    pwmVal = map(distance, 5,15,255,0);  // Convert 10-100 to 255-0.
  }
  if(distance < 5)
  {
    pwmVal = 255;
  }
  if(distance > 15)
  {
    pwmVal = 0;
  }
  
  //sensor 2
  if(distance2 >= 5 && distance2 <= 15)
  {
    pwmVal2 = map(distance2, 5,15,255,0);  // Convert 10-100 to 255-0.
  }
  if(distance2 < 5)
  {
    pwmVal2 = 255;
  }
  if(distance2 > 15)
  {
    pwmVal2 = 0;
  }

  //sensor3
   if(distance3 >= 5 && distance3 <= 15)
  {
    pwmVal3 = map(distance3, 5,15,255,0);  // Convert 10-100 to 255-0.
  }
  if(distance3 < 5)
  {
    pwmVal3 = 255;
  }
  if(distance3 > 15)
  {
    pwmVal3 = 0;
  }
  
  //sensor4
   if(distance4 >= 5 && distance4 <= 15)
  {
    pwmVal4 = map(distance4, 5,15,255,0);  // Convert 10-100 to 255-0.
  }
  if(distance4 < 5)
  {
    pwmVal4 = 255;
  }
  if(distance4 > 15)
  {
    pwmVal4 = 0;
  }


  Serial.print(distance4);
  Serial.print("   ");
  Serial.print(distance3);
  Serial.print("   ");
  Serial.print(distance2);
  Serial.print("   ");
  Serial.println(distance);
  
  /*
  Serial.print("Right Sensor: ");
  Serial.println(distance);
  Serial.print("MidRight Sensor: ");
  Serial.println(distance2);
  Serial.print("MidLeft Sensor: ");
  Serial.println(distance3);
  Serial.print("Left Sensor: ");
  Serial.println(distance4);
  */
}
