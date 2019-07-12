# ArduinoInterrupt_SwitchDebounce
## This example blog is about how to control the button switches on an Arduino Uno and Nano.

Here, I have set up two buttons on a breadboard and each time I press the button, a counter internally is
incremented.

One of the button is the Hour button, next is the Minute button.

Since I want to do some logic programming in the void loop(), I introduced the Arduino Interrupt feature
where the Microcontroller lets the loop() do other things while waiting for an user interrupt on 
Pins 2 and 3.

The main loop is used to keep track of the current time.

Concept is to set the time to Hour and Minute and once done it starts counting the time.

Eventually a 7 segment LED display will be configured to display the Hour and Minute real time.

For now the display is on Serial Monitor.


