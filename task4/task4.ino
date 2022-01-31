const int trigPin = 6;
const int echoPin = 7;
long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  for (int i = 8; i<=13; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

  int x = map(distance, 0, 100, 0, 6);
  for (int i = 8; i <= 8+x; i++){
    digitalWrite(i, HIGH);
  }
  for (int i = 13; i >= 8+x; i--){
    digitalWrite(i, LOW);
  }
  Serial.println(distance);
  delay(100);
}
