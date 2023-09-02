int latchPin = 12;  //Pin connected to ST_CP of 1st 74595
int clockPin = 13;  //Pin connected to SH_CP of 1st 74595
int dataPin = 11;   //Pin connected to DS of 1st 74595

int latchPin2 = 6;  //Pin connected to ST_CP of 2nd 74595
int clockPin2 = 7;  //Pin connected to SH_CP of 2nd 74595
int dataPin2 = 5;   //Pin connected to DS of 2nd 74595

int anode_decimal[8]={1, 2, 4, 8, 16, 32, 64, 128}; //col
int cathode_decimal[8]={127, 191, 223, 239, 247, 251, 253, 254}; //row

int heartOne[8][8]
{
  {1, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 1},
};

/*
int heartTwo[8][8]
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 0, 0},
  {0, 1, 0, 0, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};
*/
void updateMatrix(int arr[8][8])
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(arr[i][j] == 1)
      {
        singleLED(j+1, i+1);
      }
    }
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

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);

  Serial.begin(9600);
}

void loop() { 

  int tempDelay = 100;

  for(int i = 0; i < tempDelay; i++)
  {
     for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
          if(heartOne[i][j] == 1)
          {
            singleLED(j+1, i+1);
          }
        }
     }
   }
/*
  for(int i = 0; i < tempDelay; i++)
  {
    updateMatrix(heartTwo);
  }
  */
}
