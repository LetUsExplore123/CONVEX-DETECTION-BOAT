int enA = 10;
int in2 = 2;
int in1 = 8;
int enB = 5;
int in4 = 7;
int in3 = 6;
int degree=0;
int ledpin = 13;
int ledpin2 = 9;


int ultrasonic(int trigPin,int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  long duration;
  int distance;


  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  Serial.begin(9600);
  // Set motor control pins as OUTPUT
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(3, OUTPUT);  // Trig pin for first sensor
  pinMode(4, INPUT);   // Echo pin for first sensor
  pinMode(11, OUTPUT); // Trig pin for second sensor
  pinMode(12, INPUT);  // Echo pin for second sensor
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 166);
  analogWrite(enB, 200); 
}
void forward1() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // analogWrite(enA, 120);
  // analogWrite(enB, 160);
  analogWrite(enA, 140);
  analogWrite(enB, 180);
}


void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 220); // Motor A at full speed
  analogWrite(enB, 120); // Motor B at full speed
  degree=degree-22;
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 130);
  analogWrite(enB, 200);
  degree=degree+22;
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}


void loop() {
  int ultf=ultrasonic(3,4);
  int ults=ultrasonic(11,12);
  Serial.println("Front Sensor Reading : ");
  Serial.println(ultf);
  Serial.println("Right Sensor Reading : ");
  Serial.println(ults);
  if (degree>=360){
    while(true){
      digitalWrite(13,HIGH);
      Stop();
    }
  }
  if (ultf<15){
    while (true){
      digitalWrite(9,HIGH);
      Stop();
    }
  }

  else if (ults<=7 && ultf>=15){
    Serial.println("Left");
    turnLeft();
    delay(500);
    forward1();
    delay(500);
  }

  else if (ults<=20 && ultf>=15){
    forward();
    delay(1000);
  }
  else if (ults>10 && ultf>=15){
    turnRight();
    delay(500);
    forward1();
    delay(500);

  }
  
  else{
    Stop();
}
}
