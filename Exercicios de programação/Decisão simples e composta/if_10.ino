// Variáveis dos LEDs
int ledVermelho = 5;
int ledVerde = 6;

// Variáveis para cálculo
float precoCompra = 0.0;
float percentualLucro = 0.0;
float precoVenda = 0.0;

void setup()
{
  pinMode(ledVermelho, OUTPUT); // LED vermelho = margem pequena
  pinMode(ledVerde, OUTPUT);    // LED verde = margem boa
  Serial.begin(9600);           // Inicializa a comunicação serial
}

void loop()
{
  // Entrada do preço de compra
  Serial.println("Digite o preco de compra do produto:");
  while (!Serial.available()) {}
  precoCompra = Serial.parseFloat();
  Serial.read(); // limpa o buffer

  // Entrada do percentual de lucro
  Serial.println("Digite o percentual de lucro desejado (%):");
  while (!Serial.available()) {}
  percentualLucro = Serial.parseFloat();
  Serial.read();
 
  // Cálculo do preço de venda
  precoVenda = precoCompra + (precoCompra * percentualLucro / 100);

  // Saída de informações
  Serial.println("-------------------------------");
  Serial.print("Preco de compra: R$ ");
  Serial.println(precoCompra, 2);

  Serial.print("Percentual de lucro: ");
  Serial.print(percentualLucro, 2);
  Serial.println(" %");

  Serial.print("Preco de venda: R$ ");
  Serial.println(precoVenda, 2);

  // Verificação da margem de lucro
  if (percentualLucro < 50) {
    Serial.println("ATENCAO: Margem de lucro muito pequena!");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
  }

  Serial.println("-------------------------------");
  delay(10000); 
}
