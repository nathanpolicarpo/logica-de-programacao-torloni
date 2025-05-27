#include <Servo.h>
Servo meuServo;
Servo motor;  


int ledAzul1 = 4;
int ledAzul2 = 3;
int ledAzul3 = 2;

int ledVermelho = 7;
int ledVerde = 10;
int palpite = 0;
int qtdRodadas;
int pontos;

void desenhaCabecalho()
{
  Serial.println("\\-----------------------------------------/");
  Serial.println("\\         PROGRAMA JOGO DE DADOS          /");
  Serial.println("\\-----------------------------------------/");
  Serial.println("                                            ");
  delay(500);
}

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));   

  meuServo.attach(6);
  motor.attach(2);
  motor.write(0); 

  pinMode(ledAzul1, OUTPUT);
  pinMode(ledAzul2, OUTPUT);
  pinMode(ledAzul3, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);

}

void loop()
{
  desenhaCabecalho();
  pontos = 0;

  Serial.println("Quantas vezes voce quer jogar?");
  while (!Serial.available());
  qtdRodadas = Serial.parseInt();

  int vetPalpites[qtdRodadas];
  int vetResultados[qtdRodadas];

  for (int r = 0; r < qtdRodadas; r++) {
    Serial.println("Digite seu palpite entre 1 e 7:");
    while (!Serial.available());
    palpite = Serial.parseInt();

    int numeroSorteado = random(1, 1);

    vetPalpites[r] = palpite;
    vetResultados[r] = numeroSorteado;

    Serial.print("Jogando o dado");
    for (int i = 0; i < 5; i++) {
      Serial.print(".");
      delay(700);
    }
    Serial.println();
    Serial.println("Seu palpite: " + String(palpite));
    Serial.println("Numero sorteado: " + String(numeroSorteado));

    if (palpite == numeroSorteado) {
      Serial.println("Parabens, voce acertou!!");
      digitalWrite(ledVerde, HIGH);
      delay(1000);
      digitalWrite(ledVerde, LOW);
      delay(1000);

      pontos += 1;


      if (pontos == 1) {
        digitalWrite(ledAzul1, HIGH);
      } else if (pontos == 2) {
        digitalWrite(ledAzul2, HIGH);
      } else if (pontos == 3) {
        digitalWrite(ledAzul3, HIGH);
      }

    } else {
      Serial.println("Que pena, tente outra vez!!");
      digitalWrite(ledVermelho, HIGH);
      delay(1000);
      digitalWrite(ledVermelho, LOW);
      delay(1000);
    }
  }

  if (pontos == qtdRodadas) {
    Serial.println("Todos os palpites corretos! Abrindo o portao...");
    
    motor.write(0);
    delay(1500);
    motor.write(90);
    delay(1500);
    
    digitalWrite(ledAzul1, HIGH);
    digitalWrite(ledAzul2, HIGH);
    digitalWrite(ledAzul3, HIGH);


  }

  Serial.println("--------------------------------");
  delay(500);

  Serial.println("ESTATISTICAS DO JOGO");
  Serial.println();
  for (int i = 0; i < qtdRodadas; i++) {
    Serial.println("Rodada " + String(i + 1) + ":");
    Serial.println("Seu palpite: " + String(vetPalpites[i]));
    Serial.println("Resultado: " + String(vetResultados[i]));
    Serial.println("-------------");
    Serial.println();
  }

  Serial.println("FIM DE JOGO, REINICIANDO O SISTEMA");
  delay(3000);
}
