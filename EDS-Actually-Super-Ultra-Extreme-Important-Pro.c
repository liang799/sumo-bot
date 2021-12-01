// Ultra Sonic sensor - sense opponent
// ------------------------------------------
// For Movement
#define rightm 7
#define leftm 8
#define rightspeed 9
#define leftspeed 10
  
// For ultrasonic
#define echopin 2
#define trigpin 6
  
// Reference point 
int dist = 0; 

void setup() {
 // For troubleshooting:
 Serial.begin (9600);
  
 // Set up ultrasonic stuff
 pinMode(trigpin, OUTPUT);
 pinMode(echopin, INPUT_PULLUP);

}
void loop() {
  // Ultrasonic stuff:
  digitalWrite(trigpin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(15);
  dist = pulseIn(echopin, HIGH, 8000)/58;
  
  // For troubleshooting
  Serial.print("dist= ");
  Serial.println(dist);

   // The fidget spinner bull setup
   if (dist>2 && dist<20){          // Note: dist between arduino and target
    digitalWrite(rightm,LOW);
    digitalWrite(leftm,LOW);        // Overwriting input
    analogWrite(rightspeed, 250);
    analogWrite(leftspeed, 250);   // setting it to run at near full speed (Max spd is 255 btw)
     
    // For troubleshooting
    Serial.print("RUN ");   
    }
  
   else{
    // Will spin if condition above is not met
    digitalWrite(rightm,LOW);
    digitalWrite(leftm,HIGH);
    analogWrite(rightspeed, 100);
    analogWrite(leftspeed, 100);
     
    // For troubleshooting
    Serial.print("Spin ");
   }
}

// ----------------------------------------------------------------------------------------------------------------------------------------

// 9 movements

/* Defining Pins:
-----------------------------
      D7 - right motor dir
      D8 - left motor dir
      D9 - right motor spd
      D10 - left motor spd
*/
#define rightm 7
#define leftm 8
#define rightspeed 9
#define leftspeed 10



void setup() {
   // Ignore me. I will only help u when troubleshooting.
   Serial.begin(9600); 
   
   // Useful code:
   pinMode(rightm,OUTPUT);
   pinMode(leftm,OUTPUT);
   pinMode(rightspeed,OUTPUT);
   pinMode(leftspeed,OUTPUT);

}

void loop() {  
  /* From notes:
  -------------------------
      LOW - Moving forward
      HIGH - Moving backward
  */

  // Move Forward
   digitalWrite(rightm,LOW);
   digitalWrite(leftm,LOW);
   analogWrite(rightspeed, 180);
   analogWrite(leftspeed, 180);
   delay(1000); 
  
  //  ------ Stay on for 1000ms -------
  
  
  // Forward, Steering left
   digitalWrite(rightm,LOW);
   digitalWrite(leftm,LOW);
   analogWrite(rightspeed, 200);
   analogWrite(leftspeed, 120);
   delay(1000);
  
   //  ------ Stay on for 1000ms -------

   // Forward, Steering right
   digitalWrite(rightm,LOW);
   digitalWrite(leftm,LOW);
   analogWrite(rightspeed, 120);
   analogWrite(leftspeed, 200);
   delay(1000);
  
  //  ------ Stay on for 1000ms -------


   // Move Backward
   digitalWrite(rightm,HIGH);
   digitalWrite(leftm,HIGH);
   analogWrite(rightspeed, 180);
   analogWrite(leftspeed, 180);
   delay(1000);
  
  //  ------ Stay on for 1000ms -------


   // Reverse, Steering left
   digitalWrite(rightm,HIGH);
   digitalWrite(leftm,HIGH);
   analogWrite(rightspeed, 200);
   analogWrite(leftspeed, 120);
   delay(1000);
  
    //  ------ Stay on for 1000ms -------

   
   // Reverse, Steering Left
   digitalWrite(rightm,HIGH);
   digitalWrite(leftm,HIGH);
   analogWrite(rightspeed, 120);
   analogWrite(leftspeed, 200);
   delay(1000);
  
    //  ------ Stay on for 1000ms -------


   // Spin clockwise
   digitalWrite(rightm,HIGH);
   digitalWrite(leftm,LOW);
   analogWrite(rightspeed, 180);
   analogWrite(leftspeed, 180);
   delay(1000);

    //  ------ Stay on for 1000ms -------

  
   // Spin anti-clockwise
   digitalWrite(rightm,LOW);
   digitalWrite(leftm,HIGH);
   analogWrite(rightspeed, 180);
   analogWrite(leftspeed, 180);
   delay(1000);
  
    //  ------ pause for 1000ms -------

   // Stop 
   digitalWrite(rightm,LOW);
   digitalWrite(leftm,LOW);
   analogWrite(rightspeed, 0);
   analogWrite(leftspeed, 0);
   delay(1000);

   

}

// ----------------------------------------------------------------------------------------------------------------------------------------


// infrared -- edge detection 

#define rightm 7  
#define leftm 8
#define rightspeed 9
#define leftspeed 10

#define frontleftpin 4
#define frontrightpin 5

int frontleft = 0;
int frontright = 0;

void setup(){
  // Troubleshooting:
  Serial.begin(9600);
  
  /*Confused about input_pullup? 
  - Go learn what is a pullup resistor (optional)
  - https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins/#pullup-resistors-with-pins-configured-as-input      (not porn)
  */
  
  pinMode(frontleftpin, INPUT_PULLUP);
  pinMode(frontrightpin, INPUT_PULLUP);
  pinMode(right_m, OUTPUT);
  pinMode(leftm, OUTPUT);
  pinMode(rightspeed, OUTPUT);
  pinMode(leftspeed, OUTPUT);
}

void loop() 
{
   frontleft = digitalRead(frontleftpin);
   frontright = digitalRead(frontrightpin);
  
  /* Uncomment me when troubleshooting
  
  // For troubleshooting
   Serial.print("left = ");
   Serial.print(frontleft);
   Serial.print("right = ");
   Serial.print(frontright);
  */
  
   
   // Not detecting any line
   if(frontleft==0 && frontright==0)
    drivemotor(0,0,80,80); // IMPORTANT: need to define drivemotor function inorder to work
   
   // Right side of arduino detects line
   if(frontleft==0 && frontright==1)
    drivemotor(0,1,80,80);
     
  // Left side of arduino detects line
  if(frontleft==1 && frontright==0)
   drivemotor(1,0,80,80);
    
  // both sides detect line
  if(frontleft==1 && frontright==1)
   drivemotor(1,1,0,0);
}

// Defining drivemotor function
void drivemotor(byte leftmotor, byte rightmotor, int lefts, int rights){ // left/right motor- HIGH/LOW   &&   lefts/rights - speed (0 - 255)
   digitalWrite(rightm, rightmotor);
   digitalWrite(leftm, leftmotor);
   analogWrite(rightspeed, rights);
   analogWrite(leftspeed, lefts);
}



// ----------                              -!!!!!!!!!!!!!!!!!!!!!!!-------------
//TODO: ***create functions***   !!!!!!!!!
//---------------                                                                                !!!!!!!!!!!!!!!!!!!-------------------


// -------------------------------------------- BETTER CODE -------------------------------------------------------
//COMP CODE SUPER DUPER TOP SECRET DO NOT EXPOSE DO NOT SHARE BIG YEEEET ULTRA MAX PRO 
//Motor Control Pins
#define right_M 7
#define left_M 8
#define right_speed 9
#define left_speed 10

//IR Sensor Pins
#define frontleftpin 4
#define frontrightpin 5

//Misc Pins
#define Userpin  12
#define buzzerpin 3 

//Ultrasonic Sensor Pins
#define echopin 2
#define trigpin 6

//IR Sensor Variables
int frontleft = 0;
int frontright = 0;

//Ultrasonic Sensor Variables
int dist = 0;

 
void setup() {
  Serial.begin(9600);
  
  //Boot
  pinMode(Userpin, INPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(right_M, OUTPUT);
  pinMode(left_M, OUTPUT); 
  pinMode(right_speed, OUTPUT); 
  pinMode(left_speed, OUTPUT);
  pinMode(frontleftpin, INPUT_PULLUP);
  pinMode(frontrightpin, INPUT_PULLUP);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT_PULLUP);
  
  //Beeps and Boops
  while (digitalRead(Userpin)==1);
  Beeps(50);
  Beeps(150);
  Beeps(250);
  
  //Opening Move
  driveMotor(255,255); //Move
  delay(750);
  driveMotor(-255,255); //Rotate 180
  delay(280);
  driveMotor(0,0); // Tactical Stop
  delay(300);
}

 
void loop() {
   //IR 
   frontleft = digitalRead(frontleftpin);
   frontright = digitalRead(frontrightpin);
   
   //UltraSonic Sensor Pinging
   digitalWrite(trigpin, LOW);
   delayMicroseconds(10);
   digitalWrite(trigpin, HIGH);
   delayMicroseconds(15);
   
   //UltraSonic Sensor Calculation
   dist = pulseIn(echopin, HIGH, 8000)/58;
   
   // Not detecting any line (Normal Function)
   if(frontleft==0 && frontright==0){
   
    if (dist>1 && dist<45){
    //Charge
    driveMotor(255,255);
    //Troubleshooting
    Serial.print("RUN: ");
    Serial.println(dist); 
    delay(9);  
    }
    else{
    //Track
    driveMotor(200,200);
    //Troubleshooting
    Serial.print("Track: ");
    Serial.println(dist); 
    }
  }
   
   // Border On the Right
   if(frontleft==0 && frontright==1){
    driveMotor(-255,255);
    delay(500);
   }
     
  // Border On the Left
  if(frontleft==1 && frontright==0){
   driveMotor(255,-255);
   delay(500);
  }
    
  // both sides detect line
  if(frontleft==1 && frontright==1){
   driveMotor(-255,255);
   delay(500);
  }
  
}

//Beep Function
void Beeps(int beepInterval) {
  for (int i = 0; i <= 500; i++) { // play note C for 50 cycles (about 100 milliseconds)
    digitalWrite(buzzerpin, HIGH);
    delayMicroseconds(955);
    digitalWrite(buzzerpin, LOW);
    delayMicroseconds(955);
  }
  delay(beepInterval);  // space between beeps is beepInterval milliseconds
}

//Drivemotor function
void driveMotor(int leftS, int rightS){// 0-255
//Left Motor Decode
  if(leftS>=0){
    digitalWrite(left_M, 0);
    analogWrite (left_speed, leftS);
  }
  if(leftS<0){
    digitalWrite(left_M, 1);
    leftS=-leftS;
    analogWrite (left_speed, leftS);
  }
  
//Right Motor Decode
  if(rightS>=0){
    digitalWrite(right_M, 0);
    analogWrite (right_speed, rightS);
  }
  if(rightS<0){
    digitalWrite(right_M, 1);
    rightS=-rightS;
    analogWrite (right_speed, rightS);
  }
  
}
