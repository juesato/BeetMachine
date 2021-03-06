//int threshold = 30;
//int thresholdS = 20;
//int thresholdE = 300;
int threshold = 3;
int thresholdS = 2;
int thresholdE = 20;

int retriggerDelay = 50;
//int retriggerS = 5;
//int retriggerE = 150;
int retriggerS = 2;
int retriggerE = 20;

int floorThreshold = 110;

long debounceDelay = 100;

long lastDebounceTimes[] = {0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,
                             0,0};

int buttonStates[]     = {0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0};
int buttonLastStates[] = {0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0};

void readThreshold() {
  int thresh = analogRead(0);
  threshold = map(thresh, 0, 1023, thresholdS, thresholdE);
}

void getThreshold() {
  threshold = 30; // seems like a good hardcoded cutoff for now 
}

void readRetrigger() {
  int rettr = analogRead(1);
  retriggerDelay = map(rettr, 0, 1023, retriggerS, retriggerE);
}


void peachRead(int number, int reading, int midiNote, int midiChannel){
//  Serial.println(reading);
  //Serial.println(number);
//  if(number == 3) {
//    if(reading > floorThreshold ) {
//       buttonStates[number] = 1;
//    }  else {
//       buttonStates[number] = 0;
//    }
//  } else {
//    if(reading > threshold ) {
//      //Serial.println("HELLO");
//       buttonStates[number] = 1;
//    }  else {
//       buttonStates[number] = 0;
//    }
//  }
//if (number == 0) Serial.println(reading);
//    if (reading > 1) {
//      Serial.print("thresh: ");
//      Serial.println(threshold);
//    }
    if(reading > threshold ) {
      //Serial.println("HELLO");
      //Serial.println(number);
       buttonStates[number] = 1;
    }  else {
       buttonStates[number] = 0;
    }
  
  if (buttonStates[number] != buttonLastStates[number]){
   if ((millis() - lastDebounceTimes[number]) < retriggerDelay && buttonStates[number] == 1) {
     return;
   }
   if(buttonStates[number] == 1) {
     Serial.print("play");
     Serial.println(number);
//     MIDI.sendNoteOn(midiNote,127,midiChannel);
    digitalWrite(13, HIGH);
   } else {
//     MIDI.sendNoteOff(midiNote,0,midiChannel);
    Serial.print("stop");
    Serial.println(number);
    digitalWrite(13, LOW);
     lastDebounceTimes[number] = millis();
   }
  }
  
  buttonLastStates[number] = buttonStates[number];
}

