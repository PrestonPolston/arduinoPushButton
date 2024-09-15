int buttonPin = 2;
int redPin = 3;
int buttonValue;
int br = 115200;
int dt = 250;
bool light = false;



void setup() {
Serial.begin(br);
pinMode(buttonPin, INPUT);
pinMode(redPin, OUTPUT);
}

void loop() {
buttonValue = digitalRead(buttonPin);
Serial.println(buttonValue);
while(buttonValue == 0){
  Serial.println("Light is "+light);
if(light == false){
  Serial.println("its now true");
  light = true;
  buttonValue = 1;
  delay(dt);
  while(buttonValue == 1){
  digitalWrite(redPin, HIGH);
  buttonValue = digitalRead(buttonPin);
  }
}
if(light == true){
  Serial.println("its now false");
  light = false;
  buttonValue = 1;
  delay(dt);
  while(buttonValue == 1){
  digitalWrite(redPin, LOW);
  buttonValue = digitalRead(buttonPin);
  }
}
}

}
