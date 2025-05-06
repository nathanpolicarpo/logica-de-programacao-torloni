// Variáveis dos LEDs
int ledVermelho = 5;
int ledVerde = 6;

int numero = 0;

void setup()
{
  pinMode(ledVermelho, OUTPUT);  // LED vermelho = número negativo
  pinMode(ledVerde, OUTPUT);     // LED verde = número positivo
  Serial.begin(9600);            // Inicializa a comunicação serial
}

void loop()
{
  Serial.println("Digite um numero inteiro:");
  while (!Serial.available()) {}
  numero = Serial.parseInt();
  Serial.read(); // limpa o buffer

  Serial.println("-------------------------------");
  Serial.print("Numero digitado: ");
  Serial.println(numero);

  if (numero >= 0) {
    Serial.println("O numero e positivo.");
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    Serial.println("O numero e negativo.");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  Serial.println("-------------------------------");
  delay(5000);  
}
