/* 
 * Code which looks at Interrupts when push button is pressed when connected to the Arduino Uno, 
 * and also handles debouncing of the tactile switch.
 * 
 *
 * Interrupts example was taken from 
 * https://www.allaboutcircuits.com/technical-articles/using-interrupts-on-arduino/
 * 
 * The debouncing logic was taken from 
 * https://educ8s.tv/arduino-button-debounce-tutorial/
 * 
 * Here, this example shows incrementing a simple counter each time the button is pressed.
 * 
 * Open the Serial monitor and look for the ouput of mint ( minute )
 * 
 * Incidentally only pin 1 and 2 of the Arduino Uno can identify the "Interrupts".
 * 
 */

const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
volatile int buttonState = 0;         // variable for reading the pushbutton status
int mint=0;
int counter = 0;       // how many times we have seen new value
int reading;           // the current value read from the input pin
int current_state = LOW;    // the debounced input value

// the following variable is a long because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was sampled
int debounce_count = 10; // number of millis/samples to consider before declaring a debounced input

void setup() {
  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(0, pin_ISR, CHANGE);
  Serial.begin(9600);
}

void loop() {
  // Nothing here! Some dummy number and the number of times the button is pressed is listed.
  Serial.print ("Time: 9: ");
  Serial.println( mint);
  delay(1000);
}

void pin_ISR() {
  // If we have gone on to the next millisecond
  if(debounceButton(buttonState) == HIGH && buttonState == LOW)
  {
    buttonState = HIGH;
    Serial.println ("High");
    mint++;
    
  }
  else if(debounceButton(buttonState) == LOW && buttonState == HIGH)
  {
       buttonState = LOW;
  }
  
}
boolean debounceButton(boolean state)
{
  boolean stateNow = digitalRead(buttonPin);
  if(state!=stateNow)
  {
    delay(10);
    stateNow = digitalRead(buttonPin);
  }
  return stateNow;  
}


