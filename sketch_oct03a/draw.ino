
void draw(int frame)
{

  GD.ClearColorRGB(0x103000);
  GD.Clear();
  
  GD.Begin(BITMAPS);

  GD.Vertex2ii(35, 0, MAP_HANDLE);

  if(dir == 1)
  {
    if(acc > 0)
      GD.Vertex2ii(xpos*x + between - x/3, ypos*y, 0, 6 + frame);
    else
      GD.Vertex2ii(xpos*x + between - x/3, ypos*y, 0, 4 + frame);
  }
  else
  {
    if(acc > 0)
      GD.Vertex2ii(xpos*x - x/3, ypos*y + between, 0, 0 + frame);
    else
      GD.Vertex2ii(xpos*x - x/3, ypos*y + between, 0, 2 + frame);
  }

  for(int i = 0; i < 4; i++)
  {
    if(ghostdir[i] == 1)
      if(!super && !taken[i])
        GD.Vertex2ii(ghostx[i]*x - x/3 + betweenghost[i], ghosty[i]*y, i+1, 0);
      else if(taken[i])
        GD.Vertex2ii(ghostx[i]*x - x/3 + betweenghost[i], ghosty[i]*y, 7, 0);
      else
        GD.Vertex2ii(ghostx[i]*x - x/3 + betweenghost[i], ghosty[i]*y, 6, 0 + frame);
    else
      if(!super && !taken[i])
        GD.Vertex2ii(ghostx[i]*x - x/3, ghosty[i]*y + betweenghost[i], i+1, 0);
      else if(taken[i])
        GD.Vertex2ii(ghostx[i]*x - x/3, ghosty[i]*y + betweenghost[i], 7, 0);
      else
        GD.Vertex2ii(ghostx[i]*x - x/3, ghosty[i]*y + betweenghost[i], 6, 0 + frame);
        
    if(xpos == ghostx[i] && ypos == ghosty[i] && !super && !taken[i])
      gameover = true;
    else if(xpos == ghostx[i] && ypos == ghosty[i] && super && !taken[i])
    {
      taken[i] = true;
      points+=5000;  
    }
  }
  
  GD.PointSize(16 * 5);
  
  GD.ColorRGB(0xffcccc);
  GD.Begin(POINTS);
  for(int i = 0; i < 36; i++)
  {
    for(int j = 0; j < 28; j++)
    {
      if(mapb[i][j] == 'p')
      {
        GD.Vertex2ii(i*x + x/2, j*y + y/2);
      }
    }    
  }

  GD.PointSize(8 * 5);
  
  GD.ColorRGB(0xffccff);
  for(int i = 0; i < 36; i++)
  {
    for(int j = 0; j < 28; j++)
    {
      if(mapb[i][j] == '.')
      {
        GD.Vertex2ii(i*x + x/2, j*y + y/2);
      }
    }    
  }
  
  GD.ColorRGB(0xffffff);
  
  GD.PointSize(16 * 5);

  GD.ColorRGB(0xffff00);

  String scoreStr = String(points);

  GD.cmd_text(380, 36, 28, OPT_CENTER, "Score:");
  GD.cmd_text(380, 76, 28, OPT_CENTER, scoreStr.c_str());
  
  GD.swap();
  
}
