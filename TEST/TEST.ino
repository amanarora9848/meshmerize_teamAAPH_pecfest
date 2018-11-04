#define LM1 6
#define LM2 9
#define RM1 10
#define RM2 11
#define s1 12
#define s2 2
#define s6 3
#define s3 4
#define s7 5
#define s4 7
#define s5 8
int f = 0;
int fin = 0;


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
  analogWrite(LM1, 75);
  analogWrite(LM2, 0);
  analogWrite(RM1, 75);
  analogWrite(RM2, 0);
}
void left_turn_soft()
{
  analogWrite(LM1, 75);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 0);
}
void left_turn_hard()
{
  analogWrite(LM1, 75);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 75);
}
void right_turn_soft()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 0);
  analogWrite(RM1, 75);
  analogWrite(RM2, 0);
}
void right_turn_hard()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 75);
  analogWrite(RM1, 75);
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
  analogWrite(LM2, 75);
  analogWrite(RM1, 0);
  analogWrite(RM2, 75);
}


void loop() {
  if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 1 && digitalRead(s7) == 1) {
    move_straight();
    Serial.println("move straight");
  }
  //    if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 0 && digitalRead(s7) == 0 && f==0) {
  //    left_turn_hard();
  //    Serial.println("all black - turn left");
  //    delay(15);
  //  }
  //  if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1 && digitalRead(s5) == 1 && digitalRead(s6) == 1 && digitalRead(s7) == 1)  {
  //    move_straight();
  //    delay(15);
  //    f=1;
  //    Serial.println("f = "+f);
  //    ruko();
  //    //One more condition for box, maybe there when all sensors are low.
  //  }
  //  if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 0 && digitalRead(s7) == 0 && f==1) {
  //    // reverse();
  //     delay(15);
  //     f=0;
  //     right_turn_hard();
  //     Serial.println("turning right hard");
  //  }
  //  if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 1 && digitalRead(s7) == 1) {
  //    left_turn_hard();
  //    Serial.println("turning left hard");
  //  }
  //
  //  if ((digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 1 && digitalRead(s7) == 0) || (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 1 && digitalRead(s7) == 0) || (digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 1 && digitalRead(s7) == 0) || (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 1 && digitalRead(s7) == 0)) {
  //    left_turn_soft();
  //    Serial.println("turning left soft");
  //  }
  //  if ((digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1 && digitalRead(s5) == 0 && digitalRead(s6) == 0 && digitalRead(s7) == 1) || (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 0 && digitalRead(s7) == 1) || (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1 && digitalRead(s5) == 1 && digitalRead(s6) == 0 && digitalRead(s7) == 1) || (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 1 && digitalRead(s5) == 0 && digitalRead(s6) == 0 && digitalRead(s7) == 1)) {
  //    right_turn_soft();
  //    Serial.println("turning right soft");
  //  }
  //  if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 0 && digitalRead(s7) == 0 && f==0) {
  //    left_turn_hard();
  //    Serial.println("all black - turn left");
  //    delay(15);
  //  }
  //  if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 1 && digitalRead(s5) == 1 && digitalRead(s6) == 1 && digitalRead(s7) == 1 && fin==0) {
  //    move_straight();
  //    fin=1;
  //    delay(15);
  //    Serial.println("Straight for white");
  //  }
  //
  //  if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 1 && digitalRead(s5) == 1 && digitalRead(s6) == 1 && digitalRead(s7) == 1 && fin==1) {
  //    ruko();
  //    digitalWrite(13,1);
  //    Serial.println("Please be the end");
  //  }
  //  if (digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0 && digitalRead(s6) == 1 && digitalRead(s7) == 1 && fin==1) {
  //   // reverse();
  //    delay(15);
  //    left_turn_hard();
  //    fin=0;
  //    Serial.println("Left turn");
  //  }
}

