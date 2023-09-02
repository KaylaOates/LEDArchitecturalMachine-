#define echoRight 10 //FACING TOWARD ME
#define trigRight 9
#define echoMidRight 3
#define trigMidRight 2
#define echoMidLeft 8
#define trigMidLeft 1
#define echoLeft 4
#define trigLeft A0

int latchPin = 12;  
int clockPin = 13;  
int dataPin = 11;   
int latchPin2 = 6;  
int clockPin2 = 7; 
int dataPin2 = 5;   

int anode_decimal[8]={1, 2, 4, 8, 16, 32, 64, 128}; //col
int cathode_decimal[8]={127, 191, 223, 239, 247, 251, 253, 254}; //row

int ledsOn[8] = {0};

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

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
}

void loop() {
  
  int sensorOneLEDS = getLEDS(trigRight, echoRight);
  int sensorTwoLEDS = getLEDS(trigMidRight, echoMidRight);
  int sensorThreeLEDS = getLEDS(trigMidLeft, echoMidLeft);
  int sensorFourLEDS = getLEDS(trigLeft, echoLeft);

  ledsOn[0] = sensorOneLEDS;
  ledsOn[1] = leanLEDS(sensorOneLEDS, sensorTwoLEDS);
  ledsOn[2] = leanLEDS(sensorTwoLEDS, sensorOneLEDS);
  ledsOn[3] = leanLEDS(sensorTwoLEDS, sensorThreeLEDS);
  ledsOn[4] = leanLEDS(sensorThreeLEDS, sensorTwoLEDS);
  ledsOn[5] = leanLEDS(sensorThreeLEDS, sensorFourLEDS);
  ledsOn[6] = leanLEDS(sensorFourLEDS, sensorThreeLEDS);
  ledsOn[7] = sensorFourLEDS;

  int tempDelay = 100;

  for(int i = 0; i < tempDelay; i++)
  {
    for(int x = 0; x < 8; x++)
    {
      for(int y = 0; y < ledsOn[x]; y++)
      {
        singleLED(y+1,x+1);
        
        //Serial.print("-");
      }
     // Serial.println();
    }
  }
  //Serial.println("=================================");
}

int leanLEDS(int sensorOne, int sensorTwo) 
{
  //assume sensorOne is the lean sensor
  int avg = (abs(sensorOne - sensorTwo) / 2);
  int numLEDS = ((sensorOne - avg) / 2) + avg;
  return numLEDS;
}

int getLEDS(int trigPin, int echoPin)
{
  //find the distance 
  digitalWrite(trigPin, LOW); 
  //delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10); //this is the only delay needed at any length
  digitalWrite(trigPin, LOW);  
  float duration = pulseIn(echoPin, HIGH); 
  float distance = (duration / 2) * 0.034;
  //delayMicroseconds(10);

  //convert the distance to num of leds:
  if(distance > 5 && distance < 30) {
    return map(distance, 5,30,1,8);
  } else {
    return 0;
  }
}

void singleLED(int x, int y)
{
  int anodeNum = anode_decimal[8 - y];
  int cathodeNum = cathode_decimal[x - 1];

  digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, cathodeNum);
    // shift out the bits:    
    digitalWrite(latchPin, HIGH);


    // take the latchPin low so the LEDs don't change while you're sending in bits:    
    digitalWrite(latchPin2, LOW);
    shiftOut(dataPin2, clockPin2, MSBFIRST, anodeNum);
    // shift out the bits:  
    digitalWrite(latchPin2, HIGH);   
  
    /**************************  TURN OFF ALL LEDs  ***************************/    
  
    /*** Send LOW to all Anode pins (16, 15, 11, 3, 10, 5, 6, 13) of LED matrix ***/    

    // take the latchPin low so the LEDs don't change while you're sending in bits:  
    digitalWrite(latchPin, LOW);
    //Send 0 0 0 0 0 0 0 0 (1) to Q7 Q6 Q5 Q4 Q3 Q2 Q1 Q0 of 1st 74595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);
    // shift out the bits:    
    digitalWrite(latchPin, HIGH);

    /*** Send HIGH to all cathode pins (4, 7, 2, 8, 12, 1, 14 and 9) of LED matrix ***/    
  
    // take the latchPin low so the LEDs don't change while you're sending in bits:    
    digitalWrite(latchPin2, LOW);
    //Send 1 1 1 1 1 1 1 1 (255) to Q7 Q6 Q5 Q4 Q3 Q2 Q1 Q0 of 2nd 74595
    shiftOut(dataPin2, clockPin2, MSBFIRST, 0);
    // shift out the bits:  
    digitalWrite(latchPin2, HIGH);
 }
