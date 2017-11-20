/*
	cilem prikladu je ukazat moznosti analogoveho vstupu
	budeme trimrem ovladat jas LED diody
*/

// promenna, do ktere budeme cist hodnotu na vstupu portu A5
int i = 0;
	
void setup() {	
	// inicializace serioveho portu 
	Serial.begin(9600);	
	// digitalni port 11 nastaven do vystupniho modu
	pinMode (11, OUTPUT);	
}	
	
void loop() {	
	// digitalni hodnota odpovidajici napeti na vstupu A5
	// cislo v rozsahu 0 - 1023 (10b reprezentace) odpovida napeti v rozsahu 0-5V
	i = analogRead(A5);	
	// protoze jas diody (ovladany pomoci PWM) je v rozsahu 0-255, je treba 
	// zmenit rozsah 
	i = (int)255*(i/1024.0);	
	// kontrola na seriovem potru
	Serial.println(i);		
}	
