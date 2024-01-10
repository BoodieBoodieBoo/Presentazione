const int triggerPin = 7;
const int echoPin = 6;
const int pot1Pin = A0;
const int pot2Pin = A1;
const int buzzerPin = 8;
const int ledPin = 9;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int pot1Value = analogRead(pot1Pin);
  int pot2Value = analogRead(pot2Pin);

  int duration;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  int distance = duration * 0.034 / 2;

  int thresholdDistance = map(pot1Value, 0, 1023, 2, 200);

  if (distance < thresholdDistance) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  int buzzerFrequency = map(pot2Value, 0, 1023, 200, 2000);
  tone(buzzerPin, buzzerFrequency);

  delay(100);
}
