#define LM1 10
#define LM2 11
#define RM1 6
#define RM2 9
#define s1 12
#define s2 2
#define s6 3
#define s3 4
#define s7 5
#define s4 7
#define s5 8


void setup() {
  // put your setup code here, to run once:
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);
  Serial.begin(9600);
}

void move_straight()
{
  analogWrite(LM1, 80);
  analogWrite(LM2, 0);
  analogWrite(RM1, 75);
  analogWrite(RM2, 0);
}
void left_turn_soft()
{
  analogWrite(LM1, 100);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 0);
}
void left_turn_hard()
{
  analogWrite(LM1, 100);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 100);
}
void right_turn_soft()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 0);
  analogWrite(RM1, 100);
  analogWrite(RM2, 0);
}
void right_turn_hard()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 100);
  analogWrite(RM1, 100);
  analogWrite(RM2, 0);
}
void ruko()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 0);
}
void reverse()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 100);
  analogWrite(RM1, 0);
  analogWrite(RM2, 100);
}

void loop() {
  move_straight();
//  if (digitalRead(s1) == LOW && digitalRead(s2) == LOW && digitalRead(s3) == HIGH && digitalRead(s4) == LOW && digitalRead(s5) == LOW && digitalRead(s6) == HIGH && digitalRead(s7) == HIGH) {
//    ruko();
//    //delay(100);
//    move_straight();
//    Serial.println("move straight");
//  }
//  else{
//    ruko();
//  }
  //if (digitalRead(s1) == LOW && digitalRead(s2) == LOW && digitalRead(s3) == HIGH && digitalRead(s4) == HIGH && digitalRead(s5) == HIGH && digitalRead(s6) == HIGH && digitalRead(s7) == HIGH)  {
    //move_straight();
    //right_turn_hard();
    //delay(15);
    //if (digitalRead(s1) == LOW && digitalRead(s2) == LOW && digitalRead(s3) == HIGH && digitalRead(s4) == LOW && digitalRead(s5) == LOW && digitalRead(s6) == HIGH && digitalRead(s7) == HIGH) {
      //move_straight();
      //Serial.println("right intersection, moving straight");
    //}
    //else if (digitalRead(s1) == LOW && digitalRead(s2) == LOW && digitalRead(s3) == LOW && digitalRead(s4) == LOW && digitalRead(s5) == LOW && digitalRead(s6) == LOW && digitalRead(s7) == LOW) {
      //right_turn_hard();
      //Serial.println("turning right hard");
    //}
    //One more condition for box, maybe there when all sensors are low.
  //}
}
