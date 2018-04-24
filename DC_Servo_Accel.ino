long previousTime1 = 0;
long previousTime2 = 0;
bool toggle1 = false;
bool toggle2 = false;
// Setup Pins
int pulPin = 4;
// Time
int Time = 1;
// Acceleration
int accel = 1;

void setup(){
  pinMode(pulPin, OUTPUT);
}

void loop(){
  // Accel Timer
  if((millis() - previousTime1) > 100){
    if(toggle1){
      Time = Time + accel;
      if(Time <= 1 || Time >= 30){
        accel = -accel;
      }
      
    }else{
    }

    toggle1 = !toggle1;
    previousTime1 = millis();
  }

  // DC_Servo Timer
  if((micros() - previousTime2) > Time){
    if(toggle2){
      digitalWrite(pulPin, HIGH);
    }else{
      digitalWrite(pulPin, LOW);
    }

    toggle2 = !toggle2;
    previousTime2 = micros();
  }
}

