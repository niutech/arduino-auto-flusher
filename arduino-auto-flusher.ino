/**
 * Arduino Auto Flusher
 * (c) 2014 Jerzy Głowacki
 * MIT License
 */

// Pins
const int relayVcc = 2;
const int relayOut = 3;
const int detectorVcc = 4;
const int detectorIn = 5;
const int ledOut = 13;

// Delays (s)
const int armingDelay = 30;
const int disappearDelay = 15;
const int flushDelay = 5;

// Initial states
int detectorState = LOW;
int previousDetectorState = LOW;
int relayState = HIGH;
int previousRelayState = HIGH;

void flushStop()
{
    Serial.print(millis()/1000);
    Serial.println(" s: Flush stopped!");

    digitalWrite(relayOut, HIGH);
}

void flushStart()
{
    Serial.print(millis()/1000);
    Serial.println(" s: Flush started!");

    digitalWrite(relayOut, LOW);

    delay(flushDelay * 1000);

    flushStop();
}

void targetDisppeared()
{
    Serial.print(millis()/1000);
    Serial.println(" s: Target disappeared!");

    //Blink the LED for disappearDelay seconds
    for(int i = 0; i < disappearDelay; i++) {
      digitalWrite(ledOut, HIGH);    
      delay(500);
      digitalWrite(ledOut, LOW);
      delay(500);
    }
    flushStart();
}

void targetAppeared()
{
    Serial.print(millis()/1000);
    Serial.println(" s: Target appeared!");

    digitalWrite(ledOut, HIGH);
}

void setup()
{
    pinMode(relayOut, OUTPUT);
    pinMode(relayVcc, OUTPUT);
    pinMode(detectorVcc, OUTPUT);
    pinMode(detectorIn, INPUT);
    pinMode(ledOut, OUTPUT);

    digitalWrite(relayOut, HIGH);
    digitalWrite(relayVcc, HIGH);
    digitalWrite(detectorVcc, HIGH);

    Serial.begin(9600);

    delay(armingDelay * 1000);

    Serial.print(millis()/1000);
    Serial.println(" s: Armed!");
}

void loop()
{
    detectorState = digitalRead(detectorIn);
    if(detectorState == HIGH && previousDetectorState == LOW) {
	previousDetectorState = HIGH;
	targetAppeared();
    } else if(detectorState == LOW && previousDetectorState == HIGH) {
	previousDetectorState = LOW;
	targetDisppeared();
    }
    //Check once a second
    delay(1000);
}
