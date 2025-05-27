// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for(int contador = 1; contador <=99; contador += 2){
    Serial.println("Contador" + String(contador));
    delay(500);
  
  }
}


