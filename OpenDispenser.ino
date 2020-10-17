int valveOrange = 2;
int valveYellow = 3;
int valveGreen = 4;

int buttonRed = 11;
int buttonYellow = 12;
int buttonGreen = 13;

boolean buttonRedPressed = false;
boolean buttonYellowPressed = false;
boolean buttonGreenPressed = false;

boolean dispense = false;
int pushedButton = 0;

void setup() {
  dispense = false;
  pushedButton = 0;
  
  pinMode(valveOrange, OUTPUT);
  pinMode(valveYellow, OUTPUT);
  pinMode(valveGreen, OUTPUT);
  
  pinMode(buttonRed, INPUT);
  pinMode(buttonYellow, INPUT);
  pinMode(buttonGreen, INPUT);

  buttonRedPressed = false;
  buttonYellowPressed = false; 
  buttonGreenPressed = false;
  
  closeAllValve();
  delay(1000);
  Serial.begin(9600);
}
 
void loop() {
  Serial.println("NewLoop");
  pushedButton = buttonInput();
  
  if (pushedButton != 0){
    if(dispense){
      closeAllValve();
    }
    else {
      openValve(pushedButton);
    }
  }
  
  delay(100);
}

int buttonInput() {
  int buttonStateRed = 0;
  int buttonStateYellow = 0;
  int buttonStateGreen = 0;
  
  buttonStateRed = digitalRead(buttonRed);
  Serial.print("buttonInputRed: ");
  Serial.print(buttonStateRed);
  Serial.println();
  if (buttonStateRed == 1 && !buttonRedPressed) {
    buttonRedPressed = true;
  } else if (buttonStateRed == 0 && buttonRedPressed){
    buttonRedPressed = false;
    return valveOrange;
  }
  
  buttonStateYellow = digitalRead(buttonYellow);
  Serial.print("buttonInputYellow: ");
  Serial.print(buttonStateYellow);
  Serial.println();
  if (buttonStateYellow == 1 && !buttonYellowPressed) {
    buttonYellowPressed = true;
  } else if (buttonStateYellow == 0 && buttonYellowPressed){
    buttonYellowPressed = false;
    return valveYellow;
  }

  buttonStateGreen = digitalRead(buttonGreen);
  Serial.print("buttonInputGreen: ");
  Serial.print(buttonStateGreen);
  Serial.println();
  if (buttonStateGreen == 1 && !buttonGreenPressed) {
    buttonGreenPressed = true;
  } else if (buttonStateGreen == 0 && buttonGreenPressed){
    buttonGreenPressed = false;
    return valveGreen;
  }
  
  Serial.print("buttonInputDefault: ");
  Serial.print(0);
  Serial.println();
  return 0;
}

void closeAllValve() {
  Serial.print("closeAllValve");
  digitalWrite(valveOrange, LOW);
  digitalWrite(valveYellow, LOW);
  digitalWrite(valveGreen, LOW);
  dispense = false;
}

void openValve(int code){
  Serial.print("openValve: ");
  Serial.print(code);
  Serial.println();
  dispense = true;
  digitalWrite(code, HIGH);
  
}


