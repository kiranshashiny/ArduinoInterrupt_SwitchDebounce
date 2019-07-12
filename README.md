# ArduinoInterrupt_SwitchDebounce
## This example blog is about how to control the button switches on an Arduino Uno and Nano.

Here, I have set up two buttons on a breadboard and each time I press the button, a counter internally is
incremented. 

There are several examples of this on the internet - that uses a LED to light up when button is pressed.
The problem is that the switch is still in ON state even after the switch is physically released in microseconds and 
thereby counting numbers harder. In this view this code is modified to utilize the Interrupts feature of the
microcontroller and also a timer set so that the switch being on is not being counted repeatedly !


One of the button is the Hour button, next is the Minute button.

Since I want to do some logic programming in the void loop(), I introduced the Arduino Interrupt feature
where the Microcontroller lets the loop() do other things while waiting for an user interrupt on 
Pins 2 and 3.

The main loop is used to keep track of the current time and display Hour:Minute:Seconds

Concept is to set the time to Hour and Minute and once done it starts counting the time.

Eventually a 7 segment LED display will be configured to display the Hour and Minute real time.

For now the display is on Serial Monitor.

### Connection configuration of the button

![Screen Shot 2019-07-12 at 4 47 37 PM](https://user-images.githubusercontent.com/14288989/61124558-c9efec00-a4c4-11e9-92d1-f60a1f84bca5.png)

