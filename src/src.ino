#include "note.h"
#include "mario.h"

#define SPEAKER_PIN 4

//ne definim un vector unde punem pinii
int ledPins[] = { 2, 3, 6, 8, 9, 10, 11, 12 };



//marioMelody :  200 ... 2500 
//marioTempo  n  ... z

int maxMelodyFrecv;
int nrNote  = sizeof(marioMelody)/sizeof(int);
int nrLed = sizeof(ledPins)/sizeof(int);

void setup() {
  for(int i=0; i< nrLed; i++) pinMode(ledPins[i], OUTPUT);
  
  pinMode(SPEAKER_PIN, OUTPUT);

  maxMelodyFrecv = 0;
  
  for(int i=0; i< nrNote; i++){
    if (maxMelodyFrecv < marioMelody[i]) {
      maxMelodyFrecv = marioMelody[i];
    }
  }

  Serial.begin(9600);
  
}

void playNote(int frecv, int  tempo){
    tone(SPEAKER_PIN, frecv, tempo);
}

int lastLightLed;

// 3 leduri
// 8 leduri
void lightNote(int frecv, int maxFrecv){
     // maxFrev .... nrled
     // frecv .... x leduri -> x = frecv*nrled/maxFrecv
    ///int nrNewLight = frecv * nrLed / maxFrecv;
    
    int nrNewLight = map(frecv, 0, maxFrecv, 1, nrLed);
    //4, 5, 6, 7, 8
    Serial.print("On=");
    Serial.println(nrNewLight);
    
    for(int i=0; i< nrLed; i++){
      digitalWrite(ledPins[i], i<=nrNewLight ? HIGH : LOW);
      if (i<=nrNewLight) delay(50);
    }
}


void loop() {
//    for(int i=0; i< nrNote; i++){
//      playNote(marioMelody[i], marioTempo[i]);
//      lightNote(marioMelody[i]);
//    }
   if (Serial.available()){
      int val = Serial.parseInt();
      lightNote(val, 800);  
   }
  
}
