// Blick fara delay
// the setup function runs once when you press reset or power the board


long lastEvent;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  lastEvent = millis();
}

bool isOn = false;
void changeLedLight(){

  digitalWrite(LED_BUILTIN, isOn ? LOW : HIGH);
  isOn = !isOn;
  Serial.println(isOn);
}

void loop() {
  long now = millis();
  if (now - lastEvent > 1000) {
    changeLedLight();
    lastEvent = now;
    //Serial.println("x");
  }
  
  
}
