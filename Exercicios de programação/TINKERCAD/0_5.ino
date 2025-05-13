void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // O 0 também conta
  int contadorwhile = 1; 

  while (contadorwhile <= 5) {
    Serial.println(contadorwhile);
    //contadorWhile
    contadorwhile++;
  }

  delay(1000); 
}
