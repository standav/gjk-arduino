# Weather Client

## ArduinoJson
### Instalace
1. Stáhněte si ArduinoJson, https://github.com/bblanchon/ArduinoJson/archive/master.zip.
2. Rozbalte .zip balíček
3. Přejmenujte adresář z ArduinoJson-master na ArduinoJson
4. Přesuňte adresář ArduinoJson do adresáře, kde jsou umístěny knihovny Arduino IDE
5. Restartujte Arduino IDE

### Použití
Import knihovny
```
#include <ArduinoJson.h>
```
Alokace místa v paměti pro deserializovaný JSON řetězec
```
StaticJsonBuffer<200> jsonBuffer;
```
Vytvoření řetězce, který budeme deserializovat
```
char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
```
Deserializace
```
JsonObject& root = jsonBuffer.parseObject(json);
```
Test, jestli deserializace proběhla úspěšně
```
if(!root.success()) {
  Serial.println("parseObject() failed");
  return false;
}
```
Deserializace nemusí proběhnout z několika důvodů:
1. JSON řetězec není validní - https://jsonlint.com/ 
2. Místo alokované pro deserializaci je moc malé - https://arduinojson.org/v5/assistant/

Výsledek deserializace
```
const char* sensor = root["sensor"];
long time = root["time"];
double latitude = root["data"][0];
double longitude = root["data"][1];
```
