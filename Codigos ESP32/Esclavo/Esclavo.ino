#include <RF24.h>

#define CE_PIN 5
#define CSN_PIN 17

RF24 radio(CE_PIN, CSN_PIN);

const uint64_t canal = 0xE8E8F0F0E1LL;
int potValue = 0;
int LED1 = 12;
int LED2 = 13;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setChannel(115);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  radio.openReadingPipe(1, canal);
  radio.startListening();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  if (radio.available() > 0) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    radio.read(&potValue, sizeof(potValue));
    Serial.println(potValue);
  }


  delay(100);

  if (radio.available() == 0) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
    }
}
