# Philips TV Remote (Uno and 13-pin Keypad)

A basic Arduino remote control project. Currently programmed for the RC5 protocol, since that's what my TV at home uses.

The code has been adapted from a few different sources.

Keypad Code: [Instructables](http://www.instructables.com/id/12-Key-Common-Terminal-Keypad/)

IR library (Specific to ESP82660: [markszabo on GitHub](https://github.com/markszabo/IRremoteESP8266)

The code looks messy because it is. I wanted a prototype up and running as quickly as possible.

I'll post more details soon. I'd love to see some PR's with more features, because this entire project was done in a few hours as a fun idea.


# Usage and modification
To change a button's command, use the last two digits of the RC5 code.
For example, `Change Source`'s code on the list is `0.056`. In the Arduino sketch, I have the pound key set to transmit `56`.
Change the number on this line: `mysend.sendRC5(*56*, 12)`
Have fun!

# Circuitry
The pinout is pretty messy. The particular keypad I have has 13 GPIO pins (an Arduino uno has 14, leaving only one to spare) and the final one for the LED had to be a PWM port. 

The farthest-left first pin on the listed keypad (see the Instructable above) is a common ground wire. So ground that guy.
For the rest of the pins, I have them wired in order from left to right.
It's not that simple, though. I start at 0 and skip 1 to avoid the TX port.
I put the next wire in port 2.

*PORT 3 IS FOR THE IR LED. THIS IS NOT EXPLICITLY STATED IN THE CODE.*

After that, the rest of the keypad pins are in order from 4 to 13.
The LED needs to have a resistor and a ground, as you probably know.
And you're done.

![close-up of pinout](https://github.com/micah-raney/Philips_Remote_Uno_13pin/blob/master/close_up.jpg)
