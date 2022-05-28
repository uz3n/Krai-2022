void encPE_INTT_A()
{
  if (digitalRead(encPE_CHA) == HIGH)
  {
    if (digitalRead(encPE_CHB) == LOW)
    {
      EncPE.pulseCnt++;
    }
    else
    {
      EncPE.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encPE_CHB) == HIGH)
    {
      EncPE.pulseCnt++;
    }
    else
    {
      EncPE.pulseCnt--;
    }
  }
}

void encPE_INTT_B()
{
  if (digitalRead(encPE_CHA) == HIGH)
  {
    if (digitalRead(encPE_CHB) == HIGH)
    {
      EncPE.pulseCnt++;
    }
    else
    {
      EncPE.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(encPE_CHB) == LOW)
    {
      EncPE.pulseCnt++;
    }
    else
    {
      EncPE.pulseCnt--;
    }
  }
}
