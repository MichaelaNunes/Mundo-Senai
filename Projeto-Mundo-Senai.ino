// C++ code

const int trigPin = 13;
const int echoPin = 11;
const int ledPin = 13;
const int buzzerPin = 10;

long duracao;
float distancia;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duracao = pulseIn(echoPin, HIGH);
    distancia = duracao * 0.0343 / 2;

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    if (distancia <= 20) {
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 5000);
    } else {
        digitalWrite(ledPin, LOW);
        noTone(buzzerPin);
    }

    delay(100);
}