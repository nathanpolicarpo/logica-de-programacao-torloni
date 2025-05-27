// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
 for(int contador = 0; contador <= 100; contador += 5){
    Serial.println("Contando pares" + String(contador));
    delay(500);
  
  }
}