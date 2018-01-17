# include <EEPROM.h>
# include <SPI.h>
# include <GD2.h>

#include "assets.h"

int ledPin = 13;
int joyPin1 = 14;                 // slider variable connecetd to analog pin 0
int joyPin2 = 15;                 // slider variable connecetd to analog pin 1
int value1 = 0;                  // variable to read the value from the analog pin 0
int value2 = 0;   

int xpos = 1;
int ypos = 5;

int between = 0;

int speed = 2;

bool super = false;
int supertimer = 0;

int dir = 0;
int acc = 0;

int waka = 0;

int pellets = 241;

int ghostx[] = {5, 6, 7, 8};
int ghosty[] = {1, 1, 1, 1};

int targetx[] = {14, 14, 14, 14};
int targety[] = {14, 14, 14, 14};

int betweenghost[] = {0, 0, 0, 0};

int ghostspeed = 2;

int ghostdir[] = {0, 0, 0, 0};
int ghostacc[] = {0, 0, 0, 0};

bool taken[] = {false, false, false, false};

int points = 0;

int frame = 0;

int x = 10;
int y = 10;

bool gameover = false;

int timer = 0;

String mapa[] = { 
"0000000000000000000000000000", 
"0000000000000000000000000000", 
"0000000000000000000000000000", 
"1111111111111111111111111111", 
"1............11............1", 
"1.1111.11111.11.11111.1111.1", 
"1p1001.10001.11.10001.1001p1", 
"1.1111.11111.11.11111.1111.1", 
"1..........................1", 
"1.1111.11.11111111.11.1111.1",
"1.1111.11.11111111.11.1111.1",
"1......11....11....11......1",
"111111.11111011011111.111111",
"000001.11111011011111.100000",
"000001.11000CBIP00011.100000",
"000001.11011111111011.100000",
"111111.11010000001011.111111",
"000000.00010000001000.000000",
"111111.11010000001011.111111",
"000001.11011111111011.100000",
"000001.11000000000011.100000",
"000001.11011111111011.100000",
"111111.11011111111011.111111",
"1............11............1",
"1.1111.11111.11.11111.1111.1",
"1.1111.11111.11.11111.1111.1",
"1p..11........S.......11..p1",
"111.11.11.11111111.11.11.111",
"111.11.11.11111111.11.11.111",
"1......11....11....11......1",
"1.1111111111.11.1111111111.1",
"1.1111111111.11.1111111111.1",
"1..........................1",
"1111111111111111111111111111",
"0000000000000000000000000000",
"0000000000000000000000000000"
};

char mapb[36][28];

char *mapc[] = { 
"0000000000000000000000000000", 
"0000000000000000000000000000", 
"0000000000000000000000000000", 
"1111111111111111111111111111", 
"1x0000x00000x11x00000x0000x1", 
"1011110111110110111110111101", 
"1010010100010110100010100101", 
"1011110111110110111110111101", 
"1x0000x00x00x00x00x00x0000x1", 
"1011110110111111110110111101",
"1011110110111111110110111101",
"1x0000x11x00x11x00x11x0000x1",
"1111110111110110111110111111",
"0000010111110110111110100000",
"000001011x00x00x00x110100000",
"0000010110111111110110100000",
"11111101101x0000x10110111111",
"000000x00x1x0000x1x00x000000",
"11111101101xxxxxx10110111111",
"0000010110111111110110100000",
"000001011x00000000x110100000",
"0000010110111111110110100000",
"1111110110111111110110111111",
"1x0000x00x00x11x00x00x0000x1",
"1011110111110110111110111101",
"1011110111110110111110111101",
"1x0x11x00x00x00x00x00x11x0x1",
"1110110110111111110110110111",
"1110110110111111110110110111",
"1x0x00x11x00x11x00x11x00x0x1",
"1011111111110110111111111101",
"1011111111110110111111111101",
"1x0000000000x00x0000000000x1",
"1111111111111111111111111111",
"0000000000000000000000000000",
"0000000000000000000000000000"
};

void setup()
{
  GD.begin();
  LOAD_ASSETS();
  GD.BitmapHandle(PACMAN_HANDLE);
  GD.BitmapLayout(ARGB4, 2 * 16, 16);
  GD.BitmapHandle(SPOOKED_HANDLE);
  GD.BitmapLayout(ARGB4, 2 * 16, 16);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  reset();
}
void loop()
{
  int start = millis();
  timer++;
  if(super)
    supertimer--;

  if(super && supertimer == 0)
    super = false;
  //INPUTS

if(timer % 10 == 0)
  frame = !frame;
  
if(!gameover)
{
  waka+=33;
  if(waka > 790)
  {
    waka = 0;
    GD.sample(WAKA, WAKA_LENGTH, 8000, ADPCM_SAMPLES);
  }
  input();
  
  between+=acc;

  bool s = false;
  int where = between/abs(between);
  
  if(dir == 1)
  {
    if(mapc[xpos + where][ypos] == '1')
    {
      s = true;  
    }
  }

  if(dir == 0)
  {
    if(mapc[xpos][ypos + where] == '1')
    {
      s = true;  
    }
  }

  if(!s)
  {
    if(abs(between) == 10)
    {
      
      
      if(dir == 1)
      {
        if(mapc[xpos + where][ypos] == '1')
        {
          where = 0;
          acc = 0;
          between = 0;  
        }
        else
          xpos+=where;
      }
      else
      {
        if(mapc[xpos][ypos + where] == '1')
        {
          where = 0;
          acc = 0;
          between = 0;  
        }
        else
          ypos+=where;
      }
      between = 0;
    }
  } 
  else
  {
    between = 0;
  }
  //AI and whatnot

  update_ghosts();

  //DRAW

  draw(frame);

  if(mapb[xpos][ypos] == '.')
  {
    mapb[xpos][ypos] = '0';
    points+=100;
    pellets--;
  }
  
  if(mapb[xpos][ypos] == 'p')
  {
    mapb[xpos][ypos] = '0';
    super = true;
    supertimer = 200;
  }
  
  if(ypos == 0)
    ypos = 25;

  if(ypos == 27)
    ypos = 1;

  for(int i = 0; i < 4; i++)
  {
    if(ghosty[i] == 0)
      ghosty[i] = 25;

    if(ghosty[i] == 27)
      ghosty[i] = 1;
  }

  if(pellets == 0)
    gameover = true;

}
else
{
  GD.ClearColorRGB(0x103000);
  GD.Clear();

  GD.cmd_text(240, 136, 28, OPT_CENTER, "GAME OVER : TOUCH TO RESTART");
  
  GD.get_inputs();
  if (GD.inputs.x != -32768) {
    reset();
  }
  
  GD.swap();
}

int t = millis() - start;

if(t > 33)
  t = 33;

delay(33 - t);

}

void reset()
{
    //SETUP POSITIONS
  gameover = false;
  timer = 0;

  betweenghost[0] = 0;
  betweenghost[1] = 0;
  betweenghost[2] = 0;
  betweenghost[3] = 0;

  pellets = 241;
  
  ghostspeed = 2;

  ghostdir[0] = 0;
  ghostdir[1] = 0;
  ghostdir[2] = 0;
  ghostdir[3] = 0;
  
  ghostacc[0] = 0;
  ghostacc[1] = 0;
  ghostacc[2] = 0;
  ghostacc[3] = 0;

  taken[0] = false;
  taken[1] = false;
  taken[2] = false;
  taken[3] = false;
  
  points = 0;

  frame = 0;

  for(int i = 0; i < 36; i++)
  {
    for(int j = 0; j < 28; j++)
    {
      mapb[i][j] = mapa[i][j];
    }
  }
    
  for(int i = 0; i < 36; i++)
  {
    for(int j = 0; j < 28; j++)
    {
      if(mapb[i][j] == 'S')
      {
        
        xpos = i;
        ypos = j;
        //mapc[i][j] = '0';
      }
      if(mapb[i][j] == 'B')
      {
        ghostx[0] = i;
        ghosty[0] = j;
        targetx[0] = i;
        targety[0] = j;
        //mapc[i][j] = '0';
      }
      if(mapb[i][j] == 'P')
      {
        ghostx[1] = i;
        ghosty[1] = j;
        targetx[1] = i;
        targety[1] = j;
        //mapc[i][j] = '0';
      }
      if(mapb[i][j] == 'I')
      {
        ghostx[2] = i;
        ghosty[2] = j;
        targetx[2] = i;
        targety[2] = j;
        //mapc[i][j] = '0';
      }
      if(mapb[i][j] == 'C')
      {
        ghostx[3] = i;
        ghosty[3] = j;
        targetx[3] = i;
        targety[3] = j;
        //mapc[i][j] = '0';
      }
    }    
  }
}
