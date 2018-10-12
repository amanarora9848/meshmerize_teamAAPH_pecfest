//First initializing everything.
int irSensor[5]={0, 0, 0, 0, 0}; //Defined an array of 5 elements, particularly sensors here.
int RightmostSensor = 0;
int LeftmostSensor = 0;
irSensor[0] = digitalRead(lineFollowSensor0);
irSensor[1] = digitalRead(lineFollowSensor1);
irSensor[2] = digitalRead(lineFollowSensor2);
irSensor[3] = digitalRead(lineFollowSensor3);
irSensor[4] = digitalRead(lineFollowSensor4);
RightmostSensor = analogRead(farRightSensorPin);
LeftmostSensor = analogRead(farLeftSensorPin);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
