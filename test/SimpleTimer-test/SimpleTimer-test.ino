#include <SimpleTimer.h>

// the timer object
SimpleTimer xx;

// a function to be executed periodically

int timerID;

int nrApeluri = 0;
void lola() {
    Serial.print("Uptime (s): ");
    Serial.println(millis() / 1000);

    nrApeluri ++;
    
    if (nrApeluri> 10) {
      xx.deleteTimer(timerID);
      Serial.println("Timer stop");
    }
}

void setup() {
    Serial.begin(9600);
    timerID = xx.setInterval(1000, lola);
}

void loop() {
    xx.run();
}
