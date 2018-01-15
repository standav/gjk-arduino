#define STAV(x) (x-'0')
#define CERVENA 6
#define ZLUTA   5
#define ZELENA  4

void setup()
{
  Serial.begin(9600);
  pinMode(CERVENA, OUTPUT);
  pinMode(ZLUTA, OUTPUT);
  pinMode(ZELENA, OUTPUT);
}

// ctyrprvkove pole typu char
char cmd[4];
int i = 0;
int j = 0;  // bude signalizovat, ze se nacetly data do pole

void loop()
{
  while (Serial.available() > 0)
  {
    // pretypovanim na dat. typ char ziskam primo znak
    char a = Serial.read();
    if (a == 'x')
    {
      // doslo k ukonceni komunikace
      j = 1;
      break;
    }
    cmd[i++] = a;
  }
  if (j == 1)
  {
    // vyhodnoceni prikazu
    Serial.println(cmd);
      
    switch(cmd[1])
    {
      case '0': // vsechny LED
        digitalWrite(CERVENA, STAV(cmd[2]));
        digitalWrite(ZLUTA, STAV(cmd[2]));
        digitalWrite(ZELENA, STAV(cmd[2]));
      case '1': // prvni LED
        digitalWrite(CERVENA, STAV(cmd[2]));
        break;
      case '2': // druha LED
        digitalWrite(ZLUTA, STAV(cmd[2]));
        break;
      case '3': // treti LED
        digitalWrite(ZELENA, STAV(cmd[2]));
        break;  
    }
    
    j = 0; i = 0;
  }
}
