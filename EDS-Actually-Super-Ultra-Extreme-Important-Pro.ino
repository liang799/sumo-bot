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

 
void setup() 
{
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
  if (frontleft==0 && frontright==0) {
  
    if (dist>1 && dist<45) {
      //Charge
      driveMotor(255,255);
      //Troubleshooting
      Serial.print("RUN: ");
      Serial.println(dist); 
      delay(9);  
    } else {
      //Track
      driveMotor(200,200);
      //Troubleshooting
      Serial.print("Track: ");
      Serial.println(dist); 
    }
  }
   
   // Border On the Right
  if (frontleft==0 && frontright==1) {
    driveMotor(-255,255);
    delay(500);
  }
     
  // Border On the Left
  if (frontleft==1 && frontright==0) {
   driveMotor(255,-255);
   delay(500);
  }
    
  // both sides detect line
  if (frontleft==1 && frontright==1) {
   driveMotor(-255,255);
   delay(500);
  }
  
}

/* ----------------------------------- Functions ------------------------------------------*/

//Beep Function
void Beeps(int beepInterval) 
{
  for (int i = 0; i <= 500; i++) { // play note C for 50 cycles (about 100 milliseconds)
    digitalWrite(buzzerpin, HIGH);
    delayMicroseconds(955);
    digitalWrite(buzzerpin, LOW);
    delayMicroseconds(955);
  }
  delay(beepInterval);  // space between beeps is beepInterval milliseconds
}

//Drivemotor function
void driveMotor(int leftS, int rightS) // 0-255
{
  //Left Motor Decode
  if (leftS >= 0) {
    digitalWrite(left_M, 0);
    analogWrite (left_speed, leftS);
  }
  if (leftS < 0) {
    digitalWrite(left_M, 1);
    leftS=-leftS;
    analogWrite (left_speed, leftS);
  }
  
  //Right Motor Decode
  if (rightS >= 0) {
    digitalWrite(right_M, 0);
    analogWrite (right_speed, rightS);
  }
  if (rightS < 0) {
    digitalWrite(right_M, 1);
    rightS=-rightS;
    analogWrite (right_speed, rightS);
  }
}
