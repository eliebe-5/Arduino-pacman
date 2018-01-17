
void input()
{
  value1 = analogRead(joyPin1);  
  value2 = analogRead(joyPin2); 
  if(value1 > 540)
  {
    
    if(mapc[xpos][ypos - 1] != '1')
    {
      if(!(dir == 0 && acc == -speed))
      {
        dir = 0;
        acc = -speed;
        between = 0;
      }
    }
  }
  else if(value1 < 486)
  {
    if(mapc[xpos][ypos + 1] != '1')
    {
      if(!(dir == 0 && acc == speed))
      {
        dir = 0;
        acc = speed;
        between = 0;
      }
    }
  }

  if(value2 > 540)
  {
    if(mapc[xpos + 1][ypos] != '1')
    {
      if(!(dir == 1 && acc == speed))
      {
        dir = 1;
        acc = speed;
        between = 0;
      }
    }
  }
  else if(value2 < 486)
  {
    if(mapc[xpos - 1][ypos] != '1')
    {
      if(!(dir == 1 && acc == -speed))
      {
        dir = 1;
        acc = -speed;
        between = 0;
      }
    }
  }
}
