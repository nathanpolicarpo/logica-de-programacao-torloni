// Programa que recebe a idade de uma pessoa em anos
// e imprime essa idade em meses, dias, horas e minutos

// Variáveis
int idade = 0; // inicia a idade
int meses = 0;
int dias = 0;
int horas = 0;
int minutos = 0;

void setup()
{
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop()
{
  // Entrada
  Serial.println("Digite a sua idade em anos:"); // Pergunta ao usuário

  // Espera o usuário digitar e apertar Enter
  while (!Serial.available()) {}

  // Lê a idade digitada
  idade = Serial.parseInt();

  // Processamento
  meses = idade * 12;         // Converte idade para meses
  dias = idade * 365;         // Converte idade para dias (sem considerar ano bissexto)
  horas = dias * 24;          // Converte dias em horas
  minutos = horas * 60;       // Converte horas em minutos

  // Saída
  Serial.println("Sua idade em diferentes unidades:");
  Serial.print("Meses: ");
  Serial.println(meses);

  Serial.print("Dias: ");
  Serial.println(dias);

  Serial.print("Horas: ");
  Serial.println(horas);

  Serial.print("Minutos: ");
  Serial.println(minutos);

  Serial.println("-----------------------------");

  delay(5000); // Aguarda 5 segundos antes de permitir nova entrada
}
