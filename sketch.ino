int counter = 0;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  DDRB = 0b00001111; 
  PORTB = (1 << PORTB4); 
}

void loop() {
  bool currentButtonState = (PINB & (1 << PINB4));

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    delay(50); 
    counter++;
    if (counter > 15) {
      counter = 0;
    }

    Serial.print("Binary Counter: ");
    Serial.println(counter);

    PORTB = (counter & 0x0F) | (1 << PORTB4);
    while (!(PINB & (1 << PINB4)));
    delay(50);
  }
  
  lastButtonState = currentButtonState;
}