// Variáveis dos LEDs
int ledVermelho = 5;
int ledVerde = 6;

int numero = 0;

void setup()
{
  pinMode(ledVermelho, OUTPUT);  // LED vermelho = número ímpar
  pinMode(ledVerde, OUTPUT);     // LED verde = número par
  Serial.begin(9600);            // Inicializa a comunicação serial
}

void loop()
{
  Serial.println("Digite um numero:");
  while (!Serial.available()) {}
  numero = Serial.parseInt();
  Serial.read(); // limpa o buffer

  Serial.println("-------------------------------");
  Serial.print("Numero digitado: ");
  Serial.println(numero);

  if (numero % 2 == 0) {
    Serial.println("O numero e PAR.");
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    Serial.println("O numero e IMPAR.");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  Serial.println("-------------------------------");
  delay(5000);  
}
