const int pin2 = 2;
const int pin3 = 3;

volatile int pinState = 0;
volatile int pinState1 = 0;
int counter = 0;
int counter1 = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin2, INPUT_PULLUP);
  pinMode(pin3, INPUT_PULLUP);
  attachInterrupt(0, pin_ISR, CHANGE);
  attachInterrupt(1, pin_ISR1, CHANGE);
  Serial.begin(115200);
  Serial.print("Got Here");
}

void loop() {
  // put your main code here, to run repeatedly:

}

void pin_ISR() {
  pinState = digitalRead(pin2);
  Serial.println(pinState);
  Serial.println("ISR");
  /*counter++;
  Serial.println(counter);
  Serial.println(0);*/
}

void pin_ISR1() {
  pinState = digitalRead(pin3);
  Serial.println(pinState);
  Serial.println("ISR1");
  //counter1++;
  //Serial.println(counter1);
  //Serial.println(1);
}
