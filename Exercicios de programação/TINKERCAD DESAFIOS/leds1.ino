// Variáveis dos LEDs
int ledVermelho = 5;
int ledVerde = 6;
int ledAmarelo = 7;
int opcao;
int sair;

void setup()
{
  pinMode(ledVermelho, OUTPUT);  
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  Serial.begin(9600);            
}

void loop()
{
  Serial.println("Escolha uma opcao no menu abaixo:");
  Serial.println("   1 - Ligar LED Verde");
  Serial.println("   2 - Desligar LED Verde");
  Serial.println("   3 - Ligar LED Vermelho");
  Serial.println("   4 - Desligar LED Vermelho");
  Serial.println("   5 - Ligar LED Amarelo");
  Serial.println("   6 - Desligar LED Amarelo");
  Serial.println("   7 - Ligar Tdos os LEDS ");
  Serial.println("   8 - Desligar Todos os LEDS");
  Serial.println("   0 -  Sair");
  Serial.println();

  while(!Serial.available());
  opcao = Serial.parseInt();


  switch(opcao) {
    case 1:
    Serial.println("Voce escolheu Ligar LED Verde");
    digitalWrite(ledVerde, HIGH);
    break;
    case 2:
    Serial.println("Voce escolheu Desligar LED Verde");
    digitalWrite(ledVerde, LOW);
    break;
    case 3:
    Serial.println("Voce escolheu Ligar LED Vermelho");
    digitalWrite(ledVermelho, HIGH);
    break;
    case 4:
    Serial.println("Voce escolheu Desligar LED Vermelho");
    digitalWrite(ledVermelho, LOW);
    break;  
    case 5:
    Serial.println("Voce escolheu Ligar LED Amarelo");
    digitalWrite(ledAmarelo, HIGH);
    break;
    case 6:
    Serial.println("Voce escolheu Desligar LED Amarelo");
    digitalWrite(ledAmarelo, LOW);
    break;
    case 7:
    Serial.println("Voce escolheu Ligar Todos os LEDS ");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    break;
    case 8:
    Serial.println("Voce escolheu Desligar Todos os LEDS");
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    break;
    default :
    Serial.println("Nao temos o led escolhido");
  }

}
