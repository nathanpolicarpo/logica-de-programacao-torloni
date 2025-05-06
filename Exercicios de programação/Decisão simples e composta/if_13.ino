// Variável
int numero = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Digite um numero:");
  while (!Serial.available()) {}
  numero = Serial.parseInt();
  Serial.read(); // limpa o buffer

  if (numero % 2 == 0) {
    Serial.print("O numero eh par: ");
    Serial.println(numero);
  } else {
    Serial.println("O numero digitado nao eh par.");
  }

  delay(5000); 
}
