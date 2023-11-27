// defines pins numbers
const int trigPin = 3;
const int echoPin = 4;
int motorPin = 5; //motor transistor is connected to pin 5

// defines variables
long duration;
int distance;
int safetyDistance;

void setup() 
{  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(motorPin, OUTPUT);

Serial.begin(9600);
}

void loop()
{
    distanceSensor();
      
}
void distanceSensor(){
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;

if (safetyDistance <= 7 ){
  
  digitalWrite(motorPin, HIGH); //vibrate
  delay(100);  // delay 0.1 second
  digitalWrite(motorPin, LOW);  //stop vibrating
  //delay(200); //wait 0.2 seconds.
}
else if(safetyDistance > 40){
  
}
else if(safetyDistance > 25){


  digitalWrite(motorPin, HIGH); //vibrate
  delay(800);  // delay 0.8 second
  digitalWrite(motorPin, LOW);  //stop vibrating
  //delay(1000); //wait 1 second.
}
else {
 
  digitalWrite(motorPin, HIGH); //vibrate
  delay(300);  // delay 0.3 second
  digitalWrite(motorPin, LOW);  //stop vibrating
  //delay(400); //wait 0.4 seconds.
}

 // Create a string to display the distance
  String distanceString = "Distance: " + String(distance);
  
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}


