// Faça um programa que receba o ano de nascimento
// de uma pessoa e o ano atual. Calcule e imprima:
// a. A idade dessa pessoa
// b. Essa idade convertida em semanas

// Variáveis
int anoNascimento = 0;
int anoAtual = 0;
int idade = 0;
int idadeSemanas = 0;

void setup()
{
  Serial.begin(9600); // Inicia a comunicação Serial
}

void loop()
{
  // Entrada
  Serial.println("Digite o ano de nascimento:");
  while (!Serial.available()) {}         // Aguarda o usuário digitar
  anoNascimento = Serial.parseInt();     // Lê o ano de nascimento
  delay(500);                            // Pequena pausa para leitura correta

  Serial.println("Digite o ano atual:");
  while (!Serial.available()) {}         // Aguarda o usuário digitar
  anoAtual = Serial.parseInt();          // Lê o ano atual
  delay(500);

  // Processamento
  idade = anoAtual - anoNascimento;      // Calcula a idade
  idadeSemanas = idade * 52;             // Aproximadamente 52 semanas por ano

  // Saída
  Serial.println("Resultado:");
  Serial.print("Idade: ");
  Serial.println(idade);
  Serial.print("Idade em semanas: ");
  Serial.println(idadeSemanas);  

  delay(1000); // Aguarda 5 segundos antes de reiniciar
}
