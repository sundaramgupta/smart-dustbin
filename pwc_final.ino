const int trigPin = 5;
const int echoPin = 6;

// defines variables
long duration;
int distance;
#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9); //D1
    servo.write(0);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
  
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

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance<30)
{
    servo.write(0);
    delay(3000);
    servo.write(180);
    delay(1000);

    
   

//    delay(1000);

   
}

}
