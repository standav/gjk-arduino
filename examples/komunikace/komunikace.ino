#define STAV(x) (x-'0')

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
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
    Serial.println(STAV(cmd[2]));
    digitalWrite(LED_BUILTIN, HIGH); // prevod char -> int
    /*
    switch(cmd[1])
    {
      case '1': // prvni LED
        Serial.println((int)cmd[2]);
        // podle cmd[2] rozsvecim nebo zhasinam
        break;
      case '2': // druha LED
        break;

    }
    */
    j = 0; i = 0;
  }
}
