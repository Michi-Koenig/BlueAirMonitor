int SensorPin = 5; // Der PWM-Pin des Sensors wird an Pin5 des Mikrocontrollers angeschlossen. Bei anderen Mikrocontrollern muss darauf geachtet werden, dass der Pin PWM-Fähig ist.
int Messbereich = 2000; // Der voreingestellte Messbereich (0-2000ppm). Der Sensor MH-Z19B kann auch auf einen Maximalwert von 2000ppm vorkonfiguriert sein.
unsigned long ZeitMikrosekunden; // Variable für die Dauer des PWM-Signalpegels in Mikrosenkunden
unsigned long ZeitMillisekunden; // Variable für die Dauer des PWM-Signalpegels in Millisekunden

int PPM = 0; // Variable für den CO2-Messwert in ppm (parts per million - Anteile pro Million)
float Prozent=0; // Variable für den prozentuale Länge des PWM-Signals


void setup() 
{
pinMode(SensorPin, INPUT); //Der Pin für die Sensorwerte (6) wird als Eingang definiert.
Serial.begin(9600); // Aufbau der seriellen Verbindung, um Messwerte am Seriellen Monitor anzeigen zu können
}

void loop() 
{  
ZeitMikrosekunden = pulseIn(SensorPin, HIGH, 2000000); // Der pulseIn Befehl misst die Zeit, ab der ein Signal am angegebenen Pin auf HIGH wechselt und in diesem Zustand verbleibt. Standartmäßig endet diese Messung nach maximal 1.000.000 Mikrosekunden (1000ms). Durch das Ahängen des letzten Wertes kann man diesen sogenannten "Timeout" verlängern. Da das Signal des CO2 Sensors bis zu 1004ms lang sein kann, müssen wir den Wert entsprechend hoch ansetzen.
ZeitMillisekunden = ZeitMikrosekunden/1000; // Umwandeln der Zeiteinheit von Mikrosekunden in Millisekunden.
float Prozent = ZeitMillisekunden / 1004.0; // Die maximale Länge des PWM-Signals ist laut Datenblatt des MH-Z19B 1004ms (Millisekunden) lang. Daher berechnen wir hier die gemessene PWM-Signaldauer durch die maximal mögliche Signaldauer und erhalten einen Prozentwert des aktiven (5V) Pegels im PWM-Signal. Dieser Prozentwert spiegelt einen PPM-Wert zwischen 0PPM und 5000PPM wieder.
PPM = Messbereich * Prozent; // PPM-Wert berechnen aus der prozentualen Signaldauer und dem maximalen Messbereich.
Serial.println("------------------------------");
Serial.println(ZeitMikrosekunden);
Serial.println(ZeitMillisekunden);
Serial.println(Prozent);
Serial.println("------------------------------");
Serial.print("CO2 Anteil in der Luft in PPM: "); // Ausgabe der Werte über den Seriellen Monitor
Serial.println(PPM);
delay(1000);  // Eine Sekunde Wartezeit bis zur Bestimmung des nächsten Messwertes.
}
