/*********** RPS MOTOR ***********/

void RPSKAD(int RPS, float kp, float kd)
{
  float
  Kp = kp,
  Kd = kd, TS = 1.0;

  float P, I, D, error, lError = 0;
  int cRPS;
  DE.RPS = RPS;

  if ((millis() - DE.Time) > 10)
  {
    cRPS = abs(EncKAD.pulseCnt) - abs(EncKAD.lastpulse);
    if (DE.RPS > 0)
    {
      MotorKAD(maju);
    }
    else if (DE.RPS < 0)
    {
      MotorKAD(mundur);
    }
    else
    {
      MotorKAD(berhenti);
      DE.pwm = 0;
    }

    error = abs(DE.RPS) - abs(cRPS);
    P = Kp * error;
    D = ((Kd / TS) * (error - lError));
    DE.PID = P + D;
    DE.pwm = DE.pwm + DE.PID;

    DE.Time = millis();
    lError = error;
    EncKAD.lastpulse = EncKAD.pulseCnt;

    if (DE.pwm > 255)
      DE.pwm = 255;
    else if (DE.pwm < 0)
      DE.pwm = 0;
  }
}

void MotorKAD(int dir)
{
  switch (dir)
  {
    case maju:
      analogWrite(KAD_Rpwm_PIN, DE.pwm);
      analogWrite(KAD_Lpwm_PIN, LOW);
      break;
    case mundur:
      analogWrite(KAD_Lpwm_PIN, DE.pwm);
      analogWrite(KAD_Rpwm_PIN, LOW);
      break;
    case berhenti:
      analogWrite(KAD_Rpwm_PIN, LOW);
      analogWrite(KAD_Rpwm_PIN, LOW);
      break;
  }
}

void RPSKAB(int RPS, float kp, float kd)
{
  float
  Kp = kp,
  Kd = kd, TS = 1.0;

  float P, I, D, error, lError = 0;
  int cRPS;
  BE.RPS = RPS;

  if ((millis() - BE.Time) > 10)
  {
    cRPS = abs(EncKAB.pulseCnt) - abs(EncKAB.lastpulse);
    if (BE.RPS > 0)
    {
      MotorKAB(maju);
    }
    else if (BE.RPS < 0)
    {
      MotorKAB(mundur);
    }
    else
    {
      MotorKAB(berhenti);
      BE.pwm = 0;
    }

    error = abs(BE.RPS) - abs(cRPS);
    P = Kp * error;
    D = ((Kd / TS) * (error - lError));
    BE.PID = P + D;
    BE.pwm = BE.pwm + BE.PID;

    BE.Time = millis();
    lError = error;
    EncKAB.lastpulse = EncKAB.pulseCnt;

    if (BE.pwm > 255)
      BE.pwm = 255;
    else if (BE.pwm < 0)
      BE.pwm = 0;
  }
}

void MotorKAB(int dir)
{
  switch (dir)
  {
    case maju:
      analogWrite(KAB_Rpwm_PIN, BE.pwm);
      analogWrite(KAB_Lpwm_PIN, LOW);
      break;
    case mundur:
      analogWrite(KAB_Lpwm_PIN, BE.pwm);
      analogWrite(KAB_Rpwm_PIN, LOW);
      break;
    case berhenti:
      analogWrite(KAB_Rpwm_PIN, LOW);
      analogWrite(KAB_Rpwm_PIN, LOW);
      break;
  }
}

void RPSKID(int RPS, float kp, float kd)
{
  float
  Kp = kp,
  Kd = kd, TS = 1.0;

  float P, I, D, error, lError = 0;
  int cRPS;
  KA.RPS = RPS;

  if ((millis() - KA.Time) > 10)
  {
    cRPS = abs(EncKID.pulseCnt) - abs(EncKID.lastpulse);
    if (KA.RPS > 0)
    {
      MotorKID(maju);
    }
    else if (KA.RPS < 0)
    {
      MotorKID(mundur);
    }
    else
    {
      MotorKID(berhenti);
      KA.pwm = 0;
    }

    error = abs(KA.RPS) - abs(cRPS);
    P = Kp * error;
    D = ((Kd / TS) * (error - lError));
    KA.PID = P + D;
    KA.pwm = KA.pwm + KA.PID;

    KA.Time = millis();
    lError = error;
    EncKID.lastpulse = EncKID.pulseCnt;

    if (KA.pwm > 255)
      KA.pwm = 255;
    else if (KA.pwm < 0)
      KA.pwm = 0;
  }
}

void MotorKID(int dir)
{
  switch (dir)
  {
    case maju:
      analogWrite(KID_Rpwm_PIN, KA.pwm);
      analogWrite(KID_Lpwm_PIN, LOW);
      break;
    case mundur:
      analogWrite(KID_Lpwm_PIN, KA.pwm);
      analogWrite(KID_Rpwm_PIN, LOW);
      break;
    case berhenti:
      analogWrite(KID_Rpwm_PIN, LOW);
      analogWrite(KID_Rpwm_PIN, LOW);
      break;
  }
}

void RPSKIB(int RPS, float kp, float kd)
{
  float
  Kp = kp,
  Kd = kd, TS = 1.0;

  float P, I, D, error, lError = 0;
  int cRPS;
  KI.RPS = RPS;

  if ((millis() - KI.Time) > 10)
  {
    cRPS = abs(EncKIB.pulseCnt) - abs(EncKIB.lastpulse);
    if (KI.RPS > 0)
    {
      MotorKIB(maju);
    }
    else if (KI.RPS < 0)
    {
      MotorKIB(mundur);
    }
    else
    {
      MotorKIB(berhenti);
      KI.pwm = 0;
    }

    error = abs(KI.RPS) - abs(cRPS);
    P = Kp * error;
    D = ((Kd / TS) * (error - lError));
    KI.PID = P + D;
    KI.pwm = KI.pwm + KI.PID;

    KI.Time = millis();
    lError = error;
    EncKIB.lastpulse = EncKIB.pulseCnt;

    if (KI.pwm > 255)
      KI.pwm = 255;
    else if (KI.pwm < 0)
      KI.pwm = 0;
  }
}

void MotorKIB(int dir)
{
  switch (dir)
  {
    case maju:
      analogWrite(KIB_Rpwm_PIN, KI.pwm);
      analogWrite(KIB_Lpwm_PIN, LOW);
      break;
    case mundur:
      analogWrite(KIB_Lpwm_PIN, KI.pwm);
      analogWrite(KIB_Rpwm_PIN, LOW);
      break;
    case berhenti:
      analogWrite(KIB_Rpwm_PIN, LOW);
      analogWrite(KIB_Rpwm_PIN, LOW);
      break;
  }
}


/*********** ENC COUNT ***********/
void encKAD_INTT_A()
{
  if (digitalRead(encKAD_CHA) == HIGH)
  {
    if (digitalRead(encKAD_CHB) == LOW)
    {
      EncKAD.pulseCnt++;
    }
    else
    {
      EncKAD.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encKAD_CHB) == HIGH)
    {
      EncKAD.pulseCnt++;
    }
    else
    {
      EncKAD.pulseCnt--;
    }
  }
}

void encKAD_INTT_B()
{
  if (digitalRead(encKAD_CHA) == HIGH)
  {
    if (digitalRead(encKAD_CHB) == HIGH)
    {
      EncKAD.pulseCnt++;
    }
    else
    {
      EncKAD.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encKAD_CHB) == LOW)
    {
      EncKAD.pulseCnt++;
    }
    else
    {
      EncKAD.pulseCnt--;
    }
  }
}

void encKAB_INTT_A()
{
  if (digitalRead(encKAB_CHA) == HIGH)
  {
    if (digitalRead(encKAB_CHB) == LOW)
    {
      EncKAB.pulseCnt++;
    }
    else
    {
      EncKAB.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encKAB_CHB) == HIGH)
    {
      EncKAB.pulseCnt++;
    }
    else
    {
      EncKAB.pulseCnt--;
    }
  }
}

void encKAB_INTT_B()
{
  if (digitalRead(encKAB_CHA) == HIGH)
  {
    if (digitalRead(encKAB_CHB) == HIGH)
    {
      EncKAB.pulseCnt++;
    }
    else
    {
      EncKAB.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encKAB_CHB) == LOW)
    {
      EncKAB.pulseCnt++;
    }
    else
    {
      EncKAB.pulseCnt--;
    }
  }
}

void encKID_INTT_A()
{
  if (digitalRead(encKID_CHA) == HIGH)
  {
    if (digitalRead(encKID_CHB) == LOW)
    {
      EncKID.pulseCnt++;
    }
    else
    {
      EncKID.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encKID_CHB) == HIGH)
    {
      EncKID.pulseCnt++;
    }
    else
    {
      EncKID.pulseCnt--;
    }
  }
}

void encKID_INTT_B()
{
  if (digitalRead(encKID_CHA) == HIGH)
  {
    if (digitalRead(encKID_CHB) == HIGH)
    {
      EncKID.pulseCnt++;
    }
    else
    {
      EncKID.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encKID_CHB) == LOW)
    {
      EncKID.pulseCnt++;
    }
    else
    {
      EncKID.pulseCnt--;
    }
  }
}

void encKIB_INTT_A()
{
  if (digitalRead(encKIB_CHA) == HIGH)
  {
    if (digitalRead(encKIB_CHB) == LOW)
    {
      EncKIB.pulseCnt++;
    }
    else
    {
      EncKIB.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encKIB_CHB) == HIGH)
    {
      EncKIB.pulseCnt++;
    }
    else
    {
      EncKIB.pulseCnt--;
    }
  }
}

void encKIB_INTT_B()
{
  if (digitalRead(encKIB_CHA) == HIGH)
  {
    if (digitalRead(encKIB_CHB) == HIGH)
    {
      EncKIB.pulseCnt++;
    }
    else
    {
      EncKIB.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encKIB_CHB) == LOW)
    {
      EncKIB.pulseCnt++;
    }
    else
    {
      EncKIB.pulseCnt--;
    }
  }
}
