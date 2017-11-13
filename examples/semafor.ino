/*
* Program na demonstraci semaforu
*
*/

void setup() {
  // pocatecni nastaveni IO bran
  pinMode (13, OUTPUT);
  pinMode (12, OUTPUT);
  Serial.begin(9600);
}

void blikni_LED_12 () {
  digitalWrite(12, HIGH); // rozsvitim, tj. nastavim uroven portu c. 13 na vysokou uroven, cca 5V
  delay(500);             // 500 ms nedelam vubec nic
  digitalWrite(12, LOW);  // zhasnu
  delay(500);
}

void blikni_LED_13 () {
  digitalWrite(13, HIGH); // rozsvitim, tj. nastavim uroven portu c. 12 na vysokou uroven, cca 5V
  delay(500);             // 500 ms nedelam vubec nic
  digitalWrite(13, LOW);  // zhasnu
  delay(500);
}

void blikni_LED (int LED, int CEKANI) {
  char msg[10];
  sprintf (msg, "LED %d t=%d", LED, CEKANI);
  Serial.println(msg);
  digitalWrite(LED, HIGH); // rozsvitim, tj. nastavim uroven portu c. 12 na vysokou uroven, cca 5V
  delay(CEKANI);           // 500 ms nedelam vubec nic
  digitalWrite(LED, LOW);  // zhasnu
  delay(CEKANI);
}

void loop() {
  // hlavni smycka, ktera opakuje sekvenci prikazu stale dokola
  if (Serial.available()) { // v bufferu k dispozici data
    char x = Serial.read();
    
    if (x == 'a') {
      blikni_LED (13,100);
      blikni_LED (13,200);
    }

    if (x == 'b') {
      blikni_LED (12, 200);
      blikni_LED (12, 100);
      blikni_LED (12, 100);
      blikni_LED (12, 100);
    }
  }
}
