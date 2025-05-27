void setup()
{
  Serial.begin(9600);
}
void loop()
{
  for(int contador = 60; contador <= 80; contador += 2){
    Serial.println("Contando pares " + String(contador));
    delay(500);
    Serial.println("------------------------------");
  }
  for(int contador = 81; contador <= 101; contador += 2){
    Serial.println("Contando pares " + String(contador));
    delay(500);
    Serial.println("------------------------------");
  
  }
}