 
const int buttonPinJump = 4;  
const int buttonPinRight = 6;  
const int buttonPinLeft = 5; 
const int led = 10; 
const int led2 = 11; 
char serialData; 



int buttonStateJump = 0;
int buttonStateRight = 0;
int buttonStateLeft = 0;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPinRight, INPUT);
  pinMode(buttonPinJump, INPUT);
  pinMode(buttonPinLeft, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  
  serialData = Serial.read(); 

  int buttonStateRight = digitalRead(buttonPinRight);
  int buttonStateJump = digitalRead(buttonPinJump);
  int buttonStateLeft = digitalRead(buttonPinLeft);

  if(serialData == '5'){
    digitalWrite(led, HIGH);
  }
  if(serialData == '6'){
    digitalWrite(led, LOW);
  }
   if(serialData == '7'){
    digitalWrite(led2, HIGH);
  }
  if(serialData == '8'){
    digitalWrite(led2, LOW);
  }
	
  if(buttonStateRight == HIGH){
    Serial.println("2");
  } else if(buttonStateJump == HIGH){
    Serial.println("3");
  } else if(buttonStateLeft == HIGH){
    Serial.println("1");
  }


  else {
    Serial.println("0");
  }
  Serial.flush();

  delay(1); 
}