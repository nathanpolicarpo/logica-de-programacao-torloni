// Variáveis
int numero1 = 0;
int numero2 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Digite o primeiro numero:");
  while (!Serial.available()) {}
  numero1 = Serial.parseInt();
  Serial.read(); // limpa o buffer

  Serial.println("Digite o segundo numero:");
  while (!Serial.available()) {}
  numero2 = Serial.parseInt();
  Serial.read(); // limpa o buffer

  if (numero1 > numero2) {
    Serial.print("O maior numero eh: ");
    Serial.println(numero1);
  } else if (numero2 > numero1) {
    Serial.print("O maior numero eh: ");
    Serial.println(numero2);
  } else {
    Serial.println("Os numeros sao iguais.");
  }

  delay(5000);  // espera 5 segundos antes de repetir
}
