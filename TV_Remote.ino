#include <IRremote.h>
#include <IRremoteInt.h>

IRsend mysend;

// Keypad code provided by:
// DavidE 2/4/15
// "This is my first Keypad sketch.  I am using a 12 key 13 pin common terminal
// keypad from SeeedStudio."

void setup(){
  Serial.begin(9600);
  Serial.print("Receiving Input.");
  /*
  Set pins 2-13 as inputs and enable the internal pull-up resistor 
  with the INPUT_PULLUP constant.  Wire each of these pins directly 
  to a unique pin on the keypad thus addressing each key.  
  The common terminal is connected to ground. 
  */
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP); 
  
  pinMode(3, OUTPUT);

}

void checkInput(){
  // The variable names correspond to the keys on the keypad:
  int star = digitalRead(0);  // keypad pin 2
  int seven = digitalRead(2);  // keypad pin 3
  int four = digitalRead(4);  // keypad pin 4
  int one = digitalRead(5);  // keypad pin 5
  int zero = digitalRead(6);  // keypad pin 6
  int eight = digitalRead(7);  // keypad pin 7
  int five = digitalRead(8);  // keypad pin 8
  int two = digitalRead(9);  // keypad pin 9
  int pound = digitalRead(10);  // keypad pin 10
  int nine = digitalRead(11);  // keypad pin 11
  int six = digitalRead(12);  // keypad pin 12
  int three = digitalRead(13);  // keypad pin 13
  
  // When the digitalRead() of a pin returns 0 the corresponding 
  // key label is printed via Serial.
  int debounce = 400;
  if(!star){ Serial.println("*"); mysend.sendRC5(0x80C, 12); delay(debounce); } //Power. 2060 in decimal
  if(!seven){Serial.println(7); mysend.sendRC5(7, 12); delay(debounce); }
  if(!four){ Serial.println(4); mysend.sendRC5(4, 12); delay(debounce); }
  if(!one){ Serial.println(1); mysend.sendRC5(1, 12); delay(debounce); }
  if(!zero){ Serial.println(0); mysend.sendRC5(0, 12); delay(debounce); }
  if(!eight){ Serial.println(8); mysend.sendRC5(8, 12); delay(debounce); }
  if(!five){ Serial.println(5); mysend.sendRC5(5, 12); delay(debounce); }
  if(!two){ Serial.println(2); mysend.sendRC5(2, 12); delay(debounce); }
  if(!pound){ Serial.println("#"); mysend.sendRC5(56, 12); delay(debounce); }
  if(!nine){ Serial.println(9); mysend.sendRC5(9, 12); delay(debounce); }
  if(!six){ Serial.println(6); mysend.sendRC5(6, 12); delay(debounce); }
  if(!three){ Serial.println(3); mysend.sendRC5(3, 12); delay(debounce); }
}

void blink() {
  digitalWrite(3, HIGH);
  delay(40);
  digitalWrite(3, LOW);
  delay(40);
}  
  
void loop(){
  checkInput();
}



