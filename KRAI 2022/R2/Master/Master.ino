/* MASTER */
/*
   Motor Pelontar
*/
#define GamePad Serial3
#define Slave Serial2
 #define Enc Serial1

/*motor*/
#define Pe_Right_A 2
#define Pe_Right_B 3
#define Pe_Left_A 4
#define Pe_Left_B 5

#define encPE_CHA 33
#define encPE_CHB 31


#define Switch A11
#define Capit_BeA 6
#define Capit_BeB 7

struct ENC
{
  volatile long int pulseCnt;
  long int lastpulse;
} EncPE;

struct COM
{
  char data = 'Z';
} SLave, joyStick;

void LogData()
{
  if (GamePad.available())
  {
    joyStick.data = GamePad.read();
    Slave.print(joyStick.data);
    // Serial.println(joyStick.data);
  }
}

void setup() {
  Serial.begin(9600);
  GamePad.begin(9600);
  Slave.begin(9600);
  pinMode(encPE_CHA, INPUT_PULLUP);
  pinMode(encPE_CHB, INPUT_PULLUP);
  pinMode(Switch, INPUT_PULLUP);
  pinMode(Pe_Right_A, OUTPUT);
  pinMode(Pe_Right_B, OUTPUT);
  pinMode(Pe_Left_A, OUTPUT);
  pinMode(Pe_Left_B, OUTPUT);
  pinMode(Capit_BeA, OUTPUT);
  pinMode(Capit_BeB, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encPE_CHA), encPE_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encPE_CHB), encPE_INTT_B, CHANGE);
}

void loop() {
  LogData();
  CtrlManual();
//Serial.println(EncPE.pulseCnt);
}

void CtrlManual() {
  if (joyStick.data == 'I') {
    Pelontar(60);
  } if (joyStick.data == 'J') {
    Pelontar(0);
  } if (joyStick.data == 'O') {
    while (true) {
      if (!SWITCH()) {
        MTR_CAPIT_CCW(40);
      } else {
        MTR_CAPIT_CCW(0);
        EncPE.pulseCnt = 0;
        break;
      }
    }
  } if (joyStick.data == 'T') {
    while (true) {
      if (EncPE.pulseCnt <= 200) {
        MTR_CAPIT_CW(40);
      } else {
        MTR_CAPIT_CW(0);
        break;
      }
    }
  }

}

bool SWITCH() {
  return digitalRead(Switch);
}
