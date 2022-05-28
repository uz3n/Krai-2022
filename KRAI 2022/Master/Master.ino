/* SERIAL */
#define Gamepad      Serial3
#define serial       Serial

/* ENCODER */
#define encKAD_CHA 33
#define encKAD_CHB 31
#define encKIB_CHA 41
#define encKIB_CHB 39
#define encKAB_CHA 37
#define encKAB_CHB 35
#define encKID_CHA 45
#define encKID_CHB 43

/* MOTOR*/
#define KAD_Rpwm_PIN 3
#define KAD_Lpwm_PIN 2
#define KAB_Rpwm_PIN 4
#define KAB_Lpwm_PIN 5

#define KIB_Rpwm_PIN 6
#define KIB_Lpwm_PIN 7
#define KID_Rpwm_PIN 9
#define KID_Lpwm_PIN 8
#define PW_R  10
#define PW_L  11

#define maju 1
#define mundur 2
#define berhenti 3

struct ENC
{
  volatile long int pulseCnt;
  long int lastpulse;
} EncKAD, EncKAB, EncKID, EncKIB, EncX, EncY;

struct Motor
{
  float PID, pwm, RPS;
  long Time;
} DE, BE, KA, KI;

struct COM
{
  char Data = 'Z';
} Slave, Joystik;

int vrps1 = 0, vrps2 = 0,
    vrps3 = 0, vrps4 = 0;


void pinConfig() {
  pinMode(encKAD_CHA, INPUT_PULLUP);
  pinMode(encKAD_CHB, INPUT_PULLUP);
  pinMode(encKAB_CHA, INPUT_PULLUP);
  pinMode(encKAB_CHB, INPUT_PULLUP);
  pinMode(encKID_CHA, INPUT_PULLUP);
  pinMode(encKID_CHB, INPUT_PULLUP);
  pinMode(encKIB_CHA, INPUT_PULLUP);
  pinMode(encKIB_CHB, INPUT_PULLUP);
  pinMode(KAD_Rpwm_PIN, OUTPUT);
  pinMode(KAD_Lpwm_PIN, OUTPUT);
  pinMode(KID_Rpwm_PIN, OUTPUT);
  pinMode(KID_Lpwm_PIN, OUTPUT);
  pinMode(KIB_Rpwm_PIN, OUTPUT);
  pinMode(KIB_Lpwm_PIN, OUTPUT);
  pinMode(KAB_Rpwm_PIN, OUTPUT);
  pinMode(KAB_Lpwm_PIN, OUTPUT);
  pinMode(PW_R, OUTPUT);
  pinMode(PW_L, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encKAD_CHA), encKAD_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKAD_CHB), encKAD_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKAB_CHA), encKAB_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKAB_CHB), encKAB_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKID_CHA), encKID_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKID_CHB), encKID_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKIB_CHA), encKIB_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKIB_CHB), encKIB_INTT_B, CHANGE);
  analogWrite(KAD_Lpwm_PIN, LOW);
  analogWrite(KAD_Rpwm_PIN, LOW);
  analogWrite(KID_Lpwm_PIN, LOW);
  analogWrite(KID_Rpwm_PIN, LOW);
  analogWrite(KIB_Lpwm_PIN, LOW);
  analogWrite(KIB_Rpwm_PIN, LOW);
  analogWrite(KAB_Lpwm_PIN, LOW);
  analogWrite(KAB_Rpwm_PIN, LOW);
  DE.Time = millis();
  BE.Time = millis();
  KA.Time = millis();
  KI.Time = millis();
}
void LogData()
{
  if (Gamepad.available())
  {
    Joystik.Data = Gamepad.read();
  }
}

void CtrlManual() {
  LogData();
  if (Joystik.Data == 'A') {

  } if (Joystik.Data == 'B') {

  } if (Joystik.Data == 'C') {

  } if (Joystik.Data == 'D') {

  } if (Joystik.Data == 'E') {

  } if (Joystik.Data == 'F') {

  } if (Joystik.Data == 'G') {

  } if (Joystik.Data == 'H') {

  } if (Joystik.Data == 'I') {

  } if (Joystik.Data == 'Z') {

  }
}

void setup() {
  serial.begin(9600);
  Gamepad.begin(9600);
  pinConfig();
}

void loop() {
  // trialMotor(70);
  trialEncoder();
}
