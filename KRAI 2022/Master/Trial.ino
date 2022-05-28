void trialEncoder()
{
  serial.print("ENC_KAD: ");
  serial.print(EncKAD.pulseCnt);
  serial.print("\t");
  serial.print("ENC_KAB: ");
  serial.print(EncKAB.pulseCnt);
  serial.print("\t");
  serial.print("ENC_KID: ");
  serial.print(EncKID.pulseCnt);
  serial.print("\t");
  serial.print("ENC_KIB: ");
  serial.print(EncKIB.pulseCnt);
  serial.print("\t");
  serial.print("ENC_X: ");
  serial.print(EncX.pulseCnt);
  serial.print("\t");
  serial.print("ENC_Y: ");
  serial.println(EncY.pulseCnt);
}

void trialMotor(int pwm)
{
  digitalWrite(PW_L, LOW);
  analogWrite(PW_R, pwm);
  digitalWrite(KAD_Lpwm_PIN, LOW);    //BTS 1
  analogWrite(KAD_Rpwm_PIN, pwm);
  digitalWrite(KAB_Lpwm_PIN, LOW);
  analogWrite(KAB_Rpwm_PIN, pwm);
  digitalWrite(KID_Lpwm_PIN, LOW);
  analogWrite(KID_Rpwm_PIN, pwm);
  digitalWrite(KIB_Lpwm_PIN, LOW);
  analogWrite(KIB_Rpwm_PIN, pwm);
  delay(1000);
  digitalWrite(PW_R, LOW);
  analogWrite(PW_L, pwm);
  digitalWrite(KAD_Rpwm_PIN, LOW);      //bts 1
  analogWrite(KAD_Lpwm_PIN, pwm);
  digitalWrite(KAB_Rpwm_PIN, LOW);
  analogWrite(KAB_Lpwm_PIN, pwm);
  digitalWrite(KID_Rpwm_PIN, LOW);
  analogWrite(KID_Lpwm_PIN, pwm);
  digitalWrite(KIB_Rpwm_PIN, LOW);
  analogWrite(KIB_Lpwm_PIN, pwm);
  delay(1000);
}

void trialRPS(int Speed)
{
  RPSKAD(Speed, 0.01, 0.05);
  RPSKAB(Speed, 0.01, 0.05);
  RPSKID(Speed, 0.01, 0.05);
  RPSKIB(Speed, 0.01, 0.05);
}
