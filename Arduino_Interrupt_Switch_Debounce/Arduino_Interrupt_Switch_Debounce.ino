/* 
 * Code which looks at Interrupts when push button is pressed when connected to the Arduino Uno, 
 * and also handles debouncing of the tactile switch.
 * 
 * Arduino Uno and other variants recognize the interrupts when an user presses certain buttons
 * On an Uno it is Pin 2 and 3
 * An a Nano it is D2 and D3
 * The examples here were done on an Uno.
 *
 * The button switch is connected to Arduino using the diagram in this link.
 * https://www.arduino.cc/en/tutorial/button
 *
 * Interrupts example was taken from 
 * https://www.allaboutcircuits.com/technical-articles/using-interrupts-on-arduino/
 * 
 * The debouncing logic was taken from 
 * https://educ8s.tv/arduino-button-debounce-tutorial/
 * 
 * Here, this example shows incrementing a simple counter each time the button is pressed.
 * One of the button is used to increment the Hour, and another button to increment Minute.
 * Each time one of the button is set, the 'seconds' timer is reset back to 0.
 * The Hour counter is set to go from 1...23 and resets to 0.
 * The minute counter is set to go from 1...59 and resets to 0.
 * 
 * Open the Serial monitor and look for the ouput of mint ( minute )
 * 
 * Incidentally only pin 1 and 2 of the Arduino Uno can identify the "Interrupts".
 * Another interesting blog but using an Arduino Nano is :
 * 
 * http://www.martyncurrey.com/switching-things-on-and-off-with-an-arduino/
 */

const int buttonPin = 2;     // the number of the pushbutton pin
const int hrPin     = 3;

// variables will change:
volatile int buttonState = 0;         // variable for reading the pushbutton status
int mint=0;
int hr =0;
int secs =0;

int counter = 0;       // how many times we have seen new value
int reading;           // the current value read from the input pin
int current_state = LOW;    // the debounced input value

// the following variable is a long because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was sampled
int debounce_count = 10; // number of millis/samples to consider before declaring a debounced input
char buf[20];

void setup() {
  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(hrPin, INPUT);
  // Attach an interrupt to the ISR vector
  //attachInterrupt(0, pin_ISR, CHANGE); // Unreliable ! see below for reliable function call
  //attachInterrupt(1, hr_ISR,  CHANGE );
  attachInterrupt(digitalPinToInterrupt(2), min_ISR,CHANGE);  //  function for creating external interrupts at pin2 on Rising (LOW to HIGH)
  attachInterrupt(digitalPinToInterrupt(3), hr_ISR, CHANGE); 
  Serial.begin(9600);
}

void loop() {
  // Print the Hour and Minutes number of times the button is pressed is listed.
  Serial.print ("");
  Serial.print ( hr );
  Serial.print (" " );
  Serial.print( mint );
  Serial.print ( " " );
  Serial.print (secs );
  Serial.print (" .  Time now is : " );
  secs++;
  if ( secs >59) { secs =0;}
  sprintf ( buf, "%d:%d:%d", hr, mint, secs );
  Serial.println ( buf );
  delay(1000);
}


void hr_ISR() {
  // If we have gone on to the next millisecond
  if(HrdebounceButton(buttonState) == HIGH && buttonState == LOW)
  {
    buttonState = HIGH;
    //Serial.println ("Hour Button was pressed");
    hr++;
    if ( hr > 23 ) { hr =0; }
    secs =0; // reset secs to 0.
    
  }
  else if(HrdebounceButton(buttonState) == LOW && buttonState == HIGH)
  {
       buttonState = LOW;
  }
  
}

void min_ISR() {
  // If we have gone on to the next millisecond
  if(debounceButton(buttonState) == HIGH && buttonState == LOW)
  {
    buttonState = HIGH;
    //Serial.println ("Min is High ");
    mint++;
    if ( mint >59) { mint = 0; }
    secs =0; // reset secs to 0;
    
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
boolean HrdebounceButton(boolean state)
{
  boolean stateNow = digitalRead(hrPin);
  if(state!=stateNow)
  {
    delay(10);
    stateNow = digitalRead(hrPin);
  }
  return stateNow;  
}
