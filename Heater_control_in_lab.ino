void setup() {
  pinMode(13, OUTPUT); //grzalka 1
  pinMode(6, OUTPUT); //grzalka 2
  Serial.begin(9600);
  
  Serial.println("***Remote heat controller by MM - Christmas Edition***");
  Serial.println();
  Serial.println("Instructions: send character 'A' or 'B' on Serial protocol ");
  Serial.println("A - switch OFF the heating process");
  Serial.println("B - switch ON the heating process");

  digitalWrite(13, HIGH);
  digitalWrite(6, HIGH);
}

void loop() {
  char inByte = Serial.read();

  if(inByte == 'A'){
    digitalWrite(13, HIGH);
    digitalWrite(6, HIGH);
    Serial.println("DEVICE SWITCHED OFF");
    
    Serial.println("***Remote heat controller by MM - Christmas Edition***");
    Serial.println("Instructions: send character 'A' or 'B' on Serial protocol ");
    Serial.println("A - switch OFF the heating process");
    Serial.println("B - switch ON the heating process");
  }

  if(inByte == 'B'){
    digitalWrite(13, LOW);
    digitalWrite(6, LOW);

    Serial.println("DEVICE SWITCHED ON. Send 'A' to turn it back OFF");
  }

}
