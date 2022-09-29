/* Statement of Authorship COMP-10184-01: I Gustavo Jose Marcano, 000812644 certify
 that this material is my original work. No other person's work has been used without
 due acknowledgement. I have not made my work available to anyone else */
#include <Arduino.h>

bool btnState = false; // state of the button
bool ledState = false; // state of the LED

void setup()
{

  // configure the USB serial monitor
  Serial.begin(115200);

  // configure pin D5 as an analog input - this is the pushbutton
  pinMode(D5, INPUT_PULLUP);

  // configure pin D4 as a digital output - this is the LED
  pinMode(D4, OUTPUT);

  analogWriteRange(1023);
}

void loop()
{

  int iVal = analogRead(A0);     // holds the analog value
  int iButton = digitalRead(D5); // holds the state of the button in the loop

  if (iButton == 0 && btnState == false)
  {
    btnState = true;
    ledState = !ledState;
  }
  else if (iButton == 1)
  {
    btnState = false;
  }

  
  if (ledState == true)
  {
    analogWrite(D4, iVal);
  }
  else
  {
    analogWrite(D4, 1023);
  }
}
