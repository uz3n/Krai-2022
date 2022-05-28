void Pelontar(int pwm) {
  digitalWrite(Pe_Right_A, LOW);
  analogWrite(Pe_Right_B, pwm);
  digitalWrite(Pe_Left_B, LOW);
  analogWrite(Pe_Left_A, pwm);
}

void MTR_CAPIT_CW(int pwm) {
  digitalWrite(Capit_BeA, LOW);
  analogWrite(Capit_BeB, pwm);
}

void MTR_CAPIT_CCW(int pwm) {
  digitalWrite(Capit_BeB, LOW);
  analogWrite(Capit_BeA, pwm);
}
