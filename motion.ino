const int pingpin=7;
const int echopin=6;
int red=11; //red pin
int green=10;//green pin
int blue=10;// blue pin

int buzzer=8;
void rgb(int v1,int v2,int v3){
  int a=v1;
  int b=v2;
  int c=v3;
  analogWrite(red,a);
  analogWrite(green,b);
  analogWrite(blue,c);
  
  }
void setup()
{
  pinMode(pingpin,OUTPUT);
  pinMode(echopin,INPUT);
 

  Serial.begin(9000);
  
  
  }

void loop()
{
 digitalWrite(pingpin,LOW);
 delayMicroseconds(20);
 digitalWrite(pingpin,HIGH);
 delayMicroseconds(100);
 digitalWrite(pingpin,LOW);

 int distance=pulseIn(echopin,HIGH);
 int inch= microsecondsToInches(distance);
 Serial.println(inch);
  Serial.println("");
   Serial.println("mtr");
  if(inch<10){
    rgb(255,0,0);//for red 
    tone(buzzer,4000,500);
    
    
    }else{
        rgb(22, 183, 255);
      }
}

 long microsecondsToInches(long microseconds)
 {
  return microseconds / 74 / 2;


   
}
  
  
 
  
 
