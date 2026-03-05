// defines pins numbers
const int trigPin = 2;
const int echoPin = 3
const int buzzer = 4

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
}


void loop() {
// put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  
long duration = pulseIn(echoPin, HIGH);
int distance = duration*0.03421/2;

safetyDistance = distance;
if (safetyDistance <= 5){
digitalWrite(buzzer, HIGH);
}
else{
digitalWrite(buzzer, LOW);
}

Serial.print("Distance: ");
Serial.println(distance);
delay(1000);
}
