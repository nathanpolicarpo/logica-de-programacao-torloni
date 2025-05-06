// Variáveis
int ledVermelho = 5;
int ledVerde = 6;

float salario = 0.0;

void setup()
{
  pinMode(ledVermelho, OUTPUT); // LED vermelho como saída
  pinMode(ledVerde, OUTPUT);    // LED verde como saída
  Serial.begin(9600);           // Comunicação serial
}

void loop()
{
  // Entrada: pedir o salário
  Serial.println("Digite o salario do funcionario:");
  while (!Serial.available()) {}
  salario = Serial.parseFloat(); // Lê o salário
  Serial.read(); // limpa buffer
  delay(100);

  // Verificação e ação
  if (salario < 500) {
    salario = salario * 1.30; // Aplica 30% de aumento
    Serial.print("Novo salario com aumento: R$ ");
    Serial.println(salario, 2);
    digitalWrite(ledVerde, HIGH);     // Aumento: acende verde
    digitalWrite(ledVermelho, LOW);
  } else {
    Serial.println("Funcionario nao tem direito ao aumento.");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);  // Sem aumento: acende vermelho
  }

  Serial.println("-----------------------------");
  delay(5000); 
}
