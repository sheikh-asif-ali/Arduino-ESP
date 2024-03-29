// Define pins for ultrasonic and buzzer
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;

void setup(){
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}

void loop(){

int duration, distance; // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
digitalWrite(trigPin, HIGH);  // Output pulse with 1ms width on trigPin
delay(1);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);  // Measure the pulse input in echo pin
distance = (duration/2) / 29.1; // Distance is half the duration devided by 29.1 (from datasheet)
if (distance <= 50 && distance >= 0)  // if distance less than 0.5 meter and more than 0 (0 or less means over range)
{
  // Turn Buzzer on for 5 times
  for(int i=0;i<5;i++)
  {
    digitalWrite(buzzPin, HIGH);
    delay(100);
    digitalWrite(buzzPin, LOW);
    delay(100);
  }
} 
else {

digitalWrite(buzzPin, LOW); // Don't buzz
}
delay(600);  // Repeat whole process after 6secs
}
