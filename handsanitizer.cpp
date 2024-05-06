#define echoPin 2
#define trigPin 3

long duration;
float distance; // Changed data type to float for more accurate distance measurements

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;
  
  Serial.print("Duration: ");
  Serial.print(duration); // Print the duration for debugging
  Serial.print(" microseconds, Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance <= 3) {
    digitalWrite(5, HIGH);
    Serial.println("Pump On"); // Print a line to indicate pump status
    delay(150);
    digitalWrite(5, LOW);
    Serial.println("Pump OFF"); // Print a line to indicate pump status
    delay(2000);
  } else {
    digitalWrite(5, LOW);
    Serial.println("Pump OFF"); // Print a line to indicate pump status
  }
  
  delay(50);
}
