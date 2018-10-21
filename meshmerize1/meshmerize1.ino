//PID controls the robot and aligns it according to the line.
//PID - Proportional Integral Derivative
//Two path/'s, one is the path running on by bot, and one is the desired one. Error b/w them is controlled by adjusting PID constants. How much you need to turn to come to setpoint, desired line. (Motors may not be well tuned). D is the parameter goint to make it damp such that it comes to setpoint.
//Hence, three constants, Kp, Ki and Kd : proportional, integral and Derivative.
//position records position of bot.
//On line
//Code for black line following maze solving bot, without memory.
#define l1 2
#define l2 3
#define r1 4
#define r2 5
#define power 13
#define enl 6
#define enr 9
int irpin[5] = {11, 7, 8, 12, 10};
int a[5];


int last_proportional = 0;
int integral = 0;


char select_turn(unsigned char found_left, unsigned char found_right, unsigned char found_straight);
int mod(int v); //Absolute value
int set_motors(int a, int b);
void turn(char dir);
void PID();

int right = 0;
int left = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(enl, OUTPUT);
  pinMode(enr, OUTPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(irpin[i], INPUT);
  }
  pinMode(power, OUTPUT);
  pinMode(power, HIGH);
  pinMode(enl, OUTPUT);
  pinMode(enr, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  PID();
  set_motors(100, 100);
  delay(15); //Let the bot move a bit forward so as to facilitate the motors to turn the bot properly.
  //Whether the bot has found any left, right or straight turn. Turn parameters.
  unsigned char found_left, found_right, found_straight;
  unsigned char fount_left = 0;
  unsigned char fount_right = 0;
  unsigned char fount_straight = 0;
  //Whenever intersections at right angles.
  readline();
  if (a[0] == HIGH) {
    found_left = 1;
  }
  if (a[4] == HIGH) {
    found_right = 1;
  }
  if (a[2] == HIGH) { //found path ahead.
    fount_straight = 1;
  }
  unsigned char dir;
  dir = select_turn(found_left, found_right, found_straight);
  turn(dir);


}
void PID() {
  int i; //Control function
  int power_difference = 0;
  float Kp, Kd, Ki;
  unsigned int position;
  int derivative, proportional;
  while (true) {
    position = readline();
    Serial.println(position);
    proportional = ((int)position - 3500);

    derivative = proportional - last_proportional; //See derivative as difference of a number from a very small number in loop.
    integral = integral + proportional; //See integral as summation of a number and a very small number in loop.

    last_proportional = proportional;
    Kp = 0.09;
    Ki = 0.001;
    Kd = 1.0;
    //(The control parameters)

    power_difference = proportional * Kp + integral * Ki + derivative * Kd;
    //Kd almost the same as Ki, 10% of it, and Ki is 0.1% of it.
    const int max = 250; //max speed of motor.
    if (power_difference > max) {
      power_difference = max;
    }
    if (power_difference < -max) {
      power_difference = -1 * max;
    }
    if (power_difference < 0) {
      //left turn
      set_motors(max + power_difference, max);
      //Here the parameter for left turn will be stored in the array.

      
    }
    else {
      //right turn
      set_motors(max, max - power_difference);
      //Here the parameter for right turn will be stored in the array.

      
    }
    readline();
    if (a[0] == LOW && a[1] == LOW && a[2] == LOW && a[3] == LOW && a[4] == LOW) {
      return;
    }
    else if (a[0] == LOW || a[4] == LOW) {
      return;
    }
  }
}

int readline() {
  //It stores the value of ir sensor into an array a[5];
  //int v is a value which stores weighted mean of all values in array, defines a central line from which we are giving a weightage of 1000, line is from a[4], rightmost, each sensor's value os multiplied by 1000, continuous till leftmost end, and this is divided by the total sum value of the 5 inputs, returned by readline function.
  for (int i = 0; i < 5; i++) {
    a[i] = digitalRead(6 + i);
  }
  int v;
  v = (0 * a[0] + 1000 * a[1] + 2000 * a[2] + 3000 * a[3] + 4000 * a[4]) / (a[0] + a[1] + a[2] + a[3] + a[4]);
  Serial.println(a[4]);
  return v;
}

int stop() {
  analogWrite(enl, 255);
  analogWrite(enr, 255);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, HIGH);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
}

char select_turn(unsigned char found_left, unsigned char found_right, unsigned char found_straight) {
  //Left first Algorithm.
  if (found_left = 1) {
    return 'L';
  }
  else if (found_straight == 1) {
    return 'R';
  }
  else if (found_right == 1) {
    return 'R';
  }
  else {
    return 'B';
  }
}

void turn(char dir) {
  switch (dir) {
    case 'L':
      set_motors(-250, 250);
      delay(200); //Align it to the line perpendicular to it, subject to change, all of these. Will depend on testing.
      break;
    case 'R':
      set_motors(250, -250);
      delay(200);
      break;
    case 'B':
      set_motors(250, -250);
      delay(420);
      break;
    case 'S':
      break;
  }
}

int set_motors(int l, int r) {
  //Without this function, there is no significance of PID.
  //Motor setup.
  Serial.println(r);
  Serial.println(l);
  if (l > 0 && r > 0) {
    analogWrite(enl, mod(l));
    analogWrite(enr, mod(r));
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    //Go straight
  }
  else if (l < 0 && r > 0) {
    analogWrite(enl, mod(l));
    analogWrite(enr, mod(r));
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    //Go backward.
  }
  else if (l > 0 && r < 0) {
    analogWrite(enl, mod(l));
    analogWrite(enr, mod(r));
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    //Go backward.
  }
  else if (l == 0 && r == 0) {
    analogWrite(enl, mod(l));
    analogWrite(enr, mod(r));
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
  }
}

int mod(int v) {
  if (v < 0) {
    return -1 * v;
  }
  else if (v > 0) {
    return v;
  }
}
