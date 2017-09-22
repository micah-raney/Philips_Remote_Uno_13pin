# Philips TV Remote (Uno and 13-pin Keypad)

A basic Arduino remote control project. Currently programmed for the RC5 protocol, since that's what my TV at home uses.

The code has been adapted from a few different sources.

Keypad Code: [Instructables](http://www.instructables.com/id/12-Key-Common-Terminal-Keypad/)

IR library: [z3t0 on GitHub](https://github.com/z3t0/Arduino-IRremote)

The code looks messy because it is. I wanted a prototype up and running as quickly as possible.

The pinout is pretty messy. The particular keypad I have has 13 GPIO pins (an Arduino uno has 14, leaving only one to spare) and the final one for the LED had to be a PWM port. 

I'll post more details soon. I'd love to see some PR's with more features, because this entire project was done in a few hours as a fun idea.

To change a button's command, use the last two digits of the RC5 code.
For example, `Change Source`'s code on the list is `0.056`. In the Arduino sketch, I have the pound key set to transmit `56`.
Change the number on this line: `mysend.sendRC5(*56*, 12)`
Have fun!
