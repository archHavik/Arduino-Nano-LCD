
//Creating variables to set each segment to the correct pin
int counter = 0;
int segA = 12;
int segB = 10;
int segC = 8;
int segD = 6;
int segE = 5;
int segF = 11;
int segG = 9;
int segDot = 7;
int digit1 = 13;
int digit2 = 2;
int digit3 = 3;
int digit4 = 4;


void setup() {
  //Setting all the pins to outputs
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDot, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);

  //clear the screen and then display a zero.
  clear();
  digitalWrite(digit1, LOW);
  zero();
  
  Serial.begin(9600);
}

void loop() {
  int output = 0;
  if(Serial.available()) {
  int ch = Serial.read();
  Serial.println(ch);
  counter += ch;
  }
  
  if (counter > 9 && counter <= 99) {
    output = intAt(counter, 1);
    clear();
    digitalWrite(digit1, LOW);
    selection(output);
    delay(5);
    output = intAt(counter, 0);
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, LOW);
    selection(output);
    delay(5);
  }
  else if (counter > 99 && counter <= 999) {
    output = intAt(counter, 2);
    clear();
    digitalWrite(digit1, LOW);
    selection(output);
    delay(5);
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, LOW);
    output = intAt(counter, 1);
    selection(output);
    delay(5);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit3, LOW);
    output = intAt(counter, 0);
    selection(output);
    delay(5);
  }
  else if (counter > 999) {
    output = intAt(counter, 3);
    clear();
    digitalWrite(digit1, LOW);
    selection(output);
    delay(5);
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, LOW);
    output = intAt(counter, 2);
    selection(output);
    delay(5);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit3, LOW);
    output = intAt(counter, 1);
    selection(output);
    delay(5);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit4, LOW);
    output = intAt(counter, 0);
    selection(output);
    delay(5);
  }
  else {
    selection(counter);
  }
}

//This method clears the display, making it completely blank.
void clear() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDot, LOW);
  //The display that I have is common cathode, so I set each of them high unless I want to light up the digit,
  //then I set them to low.
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, HIGH);
}

//methods for each number on the display
void one() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDot, LOW);
}

void two() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segDot, LOW);
}

void three() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
  digitalWrite(segDot, LOW);
}

void four() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDot, LOW);
}

void five() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDot, LOW);
}

void six() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDot, LOW);
}

void seven() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  digitalWrite(segDot, LOW);
}

void eight() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDot, LOW);
}

void nine() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
  digitalWrite(segDot, LOW);
}

void zero() {
   digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
  digitalWrite(segDot, LOW);
}

void selection(int num) {
  switch(num) {
      case 0:
        zero();
        break;
      case 1:
        one();
        break;
      case 2:
        two();
        break;
      case 3:
        three();
        break;
      case 4:
        four();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
      case 8:
        eight();
        break;
      case 9:
        nine();
        break;
      default:
        Serial.write("Error");
  }
}

int intAt(int num, int index)
{
  String s = String(num);
  s = s.substring(index, index+1);
  int r = s.toInt();
  return r;
}
