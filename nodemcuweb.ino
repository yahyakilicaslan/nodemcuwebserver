#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define ROLE  D0  // D1
#define ROLE1 D1  // D1
#define ROLE2 D4  // D1
#define ROLE3 D6  // D1

#define ANAHTAR D2 // D2
#define ANAHTAR1 D3 // D2
#define ANAHTAR2 D5 // D2
#define ANAHTAR3 D7 // D2
ESP8266WebServer server;

char* ssid = "okhan";
char* password = "atakan2009";
bool mevcutdurum = false;
bool sonANAHTARDurum = false;
bool ROLEDurum = false;
////
bool mevcutdurum1 = false;
bool sonANAHTARDurum1 = false;
bool ROLEDurum1 = false;
///
bool mevcutdurum2 = false;
bool sonANAHTARDurum2 = false;
bool ROLEDurum2 = false;
///
bool mevcutdurum3 = false;
bool sonANAHTARDurum3 = false;
bool ROLEDurum3 = false;

const bool bascekDurum = 0;     // 0 if bascek gives a low
const bool bascekDurum1 = 0;     // 0 if bascek gives a low
const bool bascekDurum2 = 0;     // 0 if bascek gives a low
const bool bascekDurum3 = 0;     // 0 if bascek gives a low
//====================================================
String HTML_Root = "<!doctype html><html><body>\<a href=\'toggle\'><ANAHTAR type=\"ANAHTAR\">ROLE1</ANAHTAR> <a href=\'role2\'><ANAHTAR type=\"ANAHTAR\">role2</ANAHTAR> <a href=\'role3\'><ANAHTAR type=\"ANAHTAR\">role3</ANAHTAR> <a href=\'role4\'><ANAHTAR type=\"ANAHTAR\">role4</ANAHTAR>\</body></html>";

//====================================================
void handleRoot() {
  server.send ( 200, "text/html", HTML_Root );
}

//====================================================
void bascekfzkANAHTAR() {// 1NOLU FİZİKSEL BUTON
  mevcutdurum = digitalRead(ANAHTAR);

  if (mevcutdurum != sonANAHTARDurum) {
    sonANAHTARDurum = mevcutdurum;

    if (mevcutdurum == bascekDurum)
    {
      ROLEDurum = !ROLEDurum;
    }
    digitalWrite(ROLE, ROLEDurum);
    Serial.print("RÖLE 1!\n");
  }
  delay(50);
}
//SONRAKI ROLELER

void bascekfzkANAHTAR1() { //// İKİ NOLU FİZİKSEL
  mevcutdurum1 = digitalRead(ANAHTAR1);

  if (mevcutdurum1 != sonANAHTARDurum1) {
    sonANAHTARDurum1 = mevcutdurum1;

    if (mevcutdurum1 == bascekDurum1)
    {
      ROLEDurum1 = !ROLEDurum1;
    }
    digitalWrite(ROLE1, ROLEDurum1);
    Serial.print("RÖLE2!\n");
  }
  delay(50);
}
//SONRAKI ROLE
//
//SONRAKI ROLE1
void bascekfzkANAHTAR2() { // 3 NOLU FİZİK
  mevcutdurum2 = digitalRead(ANAHTAR2);

  if (mevcutdurum2 != sonANAHTARDurum2) {
    sonANAHTARDurum2 = mevcutdurum2;

    if (mevcutdurum2 == bascekDurum2)
    {
      ROLEDurum2 = !ROLEDurum2;
    }
    digitalWrite(ROLE2, ROLEDurum2);
    Serial.print("RÖLE 3!\n");
  }
  delay(50);
}
//2
void bascekfzkANAHTAR3() {
  //4 NOLU FİZİKSEL BUTON
  mevcutdurum3 = digitalRead(ANAHTAR3);

  if (mevcutdurum3 != sonANAHTARDurum3) {
    sonANAHTARDurum3 = mevcutdurum3;

    if (mevcutdurum3 == bascekDurum3)
    {
      ROLEDurum3 = !ROLEDurum3;
    }
    digitalWrite(ROLE3, ROLEDurum3);
    Serial.print("RÖLE 4!\n");
  }
  delay(50);
}
//

//====================================================
void bascekWebANAHTAR() {
  ROLEDurum = !ROLEDurum;
  digitalWrite(ROLE, ROLEDurum);
  Serial.print("RÖLE1 WEB BUTON!\n");
  server.send(200, "text/html", HTML_Root);
}
// SONRAKİLER
void bascekWebANAHTAR1() {
  ROLEDurum1 = !ROLEDurum1;
  digitalWrite(ROLE1, ROLEDurum1);
  Serial.print("ROLE2 WEB BUTON!\n");
  server.send(200, "text/html", HTML_Root);
}
//
void bascekWebANAHTAR2() {
  ROLEDurum2 = !ROLEDurum2;
  digitalWrite(ROLE2, ROLEDurum2);
  Serial.print("ROLE3 WEB BUTON!\n");
  server.send(200, "text/html", HTML_Root);
}
//
void bascekWebANAHTAR3() {
  ROLEDurum3 = !ROLEDurum3;
  digitalWrite(ROLE3, ROLEDurum3);
  Serial.print("ROLE4 WEB BUTON!\n");
  server.send(200, "text/html", HTML_Root);
}

//====================================================
void setup() {
  Serial.begin(115200);
  pinMode(ANAHTAR, INPUT_PULLUP);
  pinMode(ANAHTAR1, INPUT_PULLUP);
  pinMode(ANAHTAR2, INPUT_PULLUP);
  pinMode(ANAHTAR3, INPUT_PULLUP);
  pinMode(ROLE, OUTPUT);
  pinMode(ROLE1, OUTPUT);
  pinMode(ROLE2, OUTPUT);
  pinMode(ROLE3, OUTPUT);
  // wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(WiFi.localIP());
  // webserver
  server.on ("/", handleRoot);
  server.on("/toggle", bascekWebANAHTAR);
  server.on("/role2", bascekWebANAHTAR1);
  server.on("/role3", bascekWebANAHTAR2);
  server.on("/role4", bascekWebANAHTAR3);
  server.begin();
}

//====================================================
void loop() {
  server.handleClient();
  bascekfzkANAHTAR();
    bascekfzkANAHTAR1();
      bascekfzkANAHTAR2();
        bascekfzkANAHTAR3();
}
