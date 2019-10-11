void setup() {
  int c_first_input_pin1 = A0;
  int c_last_input_pin1 = A2;
  
  for (int i = c_first_input_pin1; i <= c_last_input_pin1; i++) {
    pinMode(i, INPUT);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.println(analogRead(A1));
  delay(200);
}

