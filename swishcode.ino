const int t1=1;
const int e1=2;
const int t2=3;
const int e2=4;
long time_taken;
int dist,distL,distR;

void setup() {
pinMode(t1,OUTPUT);
pinMode(e1,INPUT);
pinMode(t2,OUTPUT);
pinMode(e2,INPUT);
}

void cal_dist(int trigger,int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
}

void loop() {
cal_dist(t1,e1);
distL=dist;
cal_dist(t2,e2);
distR=dist;
if (distL==20)
{
  pinMode(5,HIGH);
}
if(distR==20)
{
  pinMode(6,HIGH);
}
if(distL==10)
{
  pinMode(5,LOW);
}
if(distR==10)
{
  pinMode(6,LOW);
}
}
