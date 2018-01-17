
void update_ghosts()
{
  if(timer > 40)
  {
    update_ghost(0);
  }
  if(timer > 200)
  {
    update_ghost(1);
  }
  if(timer > 500)
  {
    update_ghost(2);
  }
  if(timer > 800)
  {
    update_ghost(3);
  }  

  for(int i = 0; i < 4; i++)
  {
    if(!super || taken[i])
      betweenghost[i] += ghostacc[i];
    else
      betweenghost[i] += ghostacc[i]/2;
    if(abs(betweenghost[i]) >= 10)
    {
      int where = betweenghost[i]*0.1;
      
      if(ghostdir[i] == 1)
      {
        ghostx[i]+=where;
      }
      else
      {
        ghosty[i]+=where;
      }
      betweenghost[i] = 0;
    }
  }
}

void update_ghost(int index)
{
  if(timer % (index + 1)*20 == 0 && !taken[index])
  {
    targetx[index] = xpos;
    targety[index] = ypos;
  }
  else if(taken[index] && ghostx[index] == 14 && ghosty[index] == 13)
  {
    taken[index] = false;
  }
  else
  {
    targetx[index] = 14;
    targety[index] = 13;
  }
  if((ghostacc[index] == 0 || mapc[ghostx[index]][ghosty[index]] == 'x') && betweenghost[index] == 0)
  {
    int xdiff = targetx[index] - ghostx[index];
    int ydiff = targety[index] - ghosty[index];

    float squares[4] = {10000, 10000, 10000, 10000};
    if(!super || taken[index])
    {
      squares[0] = 0;  
      squares[1] = 0;  
      squares[2] = 0;  
      squares[3] = 0;  
    }

  
    if(mapc[ghostx[index] + 1][ghosty[index]] != '1')
    {
      int tempx = abs(targetx[index] - ghostx[index] + 1);
      int tempy = abs(targety[index] - ghosty[index]);
      squares[0] = sqrt(tempx*tempx + tempy*tempy);
    }
  
    if(mapc[ghostx[index] - 1][ghosty[index]] != '1')
    {
      int tempx = abs(targetx[index] - ghostx[index] - 1);
      int tempy = abs(targety[index] - ghosty[index]);
      squares[1] = sqrt(tempx*tempx + tempy*tempy);
    }

    if(mapc[ghostx[index]][ghosty[index] + 1] != '1')
    {
      int tempx = abs(targetx[index] - ghostx[index]);
      int tempy = abs(targety[index] - ghosty[index] + 1);
      squares[2] = sqrt(tempx*tempx + tempy*tempy);
    }
  
    if(mapc[ghostx[index]][ghosty[index]  - 1] != '1')
    {
      int tempx = abs(targetx[index] - ghostx[index]);
      int tempy = abs(targety[index] - ghosty[index] - 1);
      squares[3] = sqrt(tempx*tempx + tempy*tempy);
    }

    if(!super || taken[index])
    {
      if(ghostdir[index] == 1)
      {
        if(ghostacc[index] > 0)
          squares[1] = 1;
        else if(ghostacc[index] < 0)  
          squares[0] = 1;
      }
      else
      {
        if(ghostacc[index] > 0)
          squares[3] = 1;
        else if(ghostacc[index] < 0)
          squares[2] = 1;
      }
    }
    int lowest = 0;

    if(!super || taken[index])
    {
      for(int i = 0; i < 4; i++)
      {
        for(int j = 0; j < 4; j++)
        {
          if(squares[j] > squares[lowest])
            lowest = j;
        }
      }
    }
    else
    {
      for(int i = 0; i < 4; i++)
      { 
        for(int j = 0; j < 4; j++)
        {
          if(squares[j] < squares[lowest])
            lowest = i;
        }
      }
    }
    
    switch(lowest)
    {
      case(0):
        ghostdir[index] = 1;
        ghostacc[index] = ghostspeed;
        break;
      case(1):
        ghostdir[index] = 1;
        ghostacc[index] = -ghostspeed;
        break;
      case(2):
        ghostdir[index] = 0;
        ghostacc[index] = ghostspeed;
        break;
      case(3):
        ghostdir[index] = 0;
        ghostacc[index] = -ghostspeed;
        break;
    }
  } 
}
