
/*
   Sketching mit Hardware
  DMP - Vertiefung Medieninformatik 2 -  WS 23_24
  - millis function Demo. Termin 5
  This project demonstrates the usage of the millis function

  by: Marcos Martinez
*/

void setup()
{
  Serial.begin(9600);

}
void loop()
{
  Serial.println(millis());
}
