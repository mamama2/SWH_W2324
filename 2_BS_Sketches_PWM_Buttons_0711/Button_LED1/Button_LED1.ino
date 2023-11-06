//Sketching mit Hardware WS 23_24 - DMP
//Beispiel eines Tasters am Arduino (Üb.2.2)
//Martinez

int LEDblau = 6;       //Das Wort „LEDblau“ steht jetzt für den Wert 6.
int taster = 7;        //Das Wort „taster“ steht jetzt für den Wert 7.
int tasterstatus = 0;  //Das Wort „tasterstatus“ steht jetzt zunächst für den Wert 0. Später wird unter dieser Variable gespeichert, ob der Taster gedrückt ist oder nicht.

void setup()  //Hier beginnt das Setup.
{
  pinMode(LEDblau, OUTPUT);  //Der Pin mit der LED (Pin 6) ist jetzt ein Ausgang.
  pinMode(taster, INPUT);    //Der Pin mit dem Taster (Pin 7) ist jetzt ein Eingang.
}

void loop() {                          //Mit dieser Klammer wird der Loop-Teil geöffnet.
  tasterstatus = digitalRead(taster);  //Hier wird der Pin7 ausgelesen (Befehl:digitalRead). Das Ergebnis wird unter der Variable „tasterstatus“ mit dem Wert „HIGH“ für 5Volt oder „LOW“ für 0Volt gespeichert.
  if (tasterstatus == HIGH)            //Verarbeitung: Wenn der Taster gedrückt ist (Das Spannungssignal ist hoch)
  {                                    //Programmabschnitt des IF-Befehls öffnen.
    digitalWrite(LEDblau, HIGH);       //dann soll die LED leuchten
    delay(5000);                       //und zwar für für 5 Sekunden (5000 Millisekunden).
    digitalWrite(LEDblau, LOW);        //danach soll die LED aus sein.
  }                                    //Programmabschnitt des IF-Befehls schließen.
  else                                 //...ansonsten...
  {                                    //Programmabschnitt des else-Befehls öffnen.
    digitalWrite(LEDblau, LOW);        //...soll die LED aus sein.
  }                                    //Programmabschnitt des else-Befehls schließen.
}  //Mit dieser letzten Klammer wird der Loop-Teil geschlossen.