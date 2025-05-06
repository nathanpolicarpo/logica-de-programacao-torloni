// Variáveis
String nome = "";
String cargo = "";
float salario = 0.0;

// Área de configuração do Arduino
void setup()
{
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop()
{
  // Pergunta o nome
  Serial.println("Digite o nome do funcionario:");
  while (!Serial.available()) {}
  nome = Serial.readString();
  // Remove espaços extras e quebras de linha
  delay(100);

  // Pergunta o cargo
  Serial.println("Digite o cargo do funcionario:");
  while (!Serial.available()) {}
  cargo = Serial.readString();
  delay(100);

  // Pergunta o salario
  Serial.println("Digite o salario do funcionario:");
  while (!Serial.available()) {}
  salario = Serial.parseFloat();
  Serial.read(); // limpa caractere extra como Enter
  delay(100);

  // Verifica se deve aplicar aumento
  if (salario < 1000) {
    salario = salario * 1.10; // Acrescenta 10%
  }

  // Exibe os dados finais
  Serial.println("---------- Dados do Funcionario ----------");
  Serial.println("Nome: " + nome);
  Serial.println("Cargo: " + cargo);
  Serial.print("Salario ajustado: R$ ");
  Serial.println(salario, 2); // Exibe com 2 casas decimais
  Serial.println("---------------------------------------------");

  // Aguarda um tempo antes de reiniciar
  delay(5000);
}
