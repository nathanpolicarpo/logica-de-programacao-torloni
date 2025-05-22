// 
//
int palpite = 0;
int qtdRodadas;
  
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
  randomSeed(analogRead(0));//inicia e normaliza a porta randomica para evitar pega o mesmo numero.
}

void loop()
{
  desenhaCabecalho();//desenha o cabecalho na tela.
  
  Serial.println("quantas vezes vc quer jogar?");
  while(!Serial.available());
  int qtdRodadas = Serial.parseInt();

  int vetPalpites[qtdRodadas];//qual o tamanho do vetor/array.
  int vetResultados[qtdRodadas];//mesmo tamanho.

  for(int r = 0; r < qtdRodadas; r++){    
    //solicitar o palpite do usuario - 3 comandos.
    Serial.println("Digite seu palpite entre 1 e 7 ");
    while(!Serial.available());//espera o usuario digitar.
    int palpite = Serial.parseInt();//guarda o palpite do usuario.

    //jogar o dado - sorteia um numero randomico/aleatorio de 1 ate 7 - 1, ou seja, 6.
    int numeroSorteado = random(1, 7);//numero entre 1 a 6.

    //guarda os dados para estatisticas
    vetPalpites[r] = palpite;
    vetResultados[r] = numeroSorteado;

    Serial.print("jogando o dado");
    for(int i = 0; i < 5; i++){
      Serial.print(".");
      delay(700);
    }
    //exibir o palpite do usuario.
    Serial.println("seu palpite:" + String(palpite));
    Serial.println("Numero sorteado:" + String(numeroSorteado));

    if( palpite == numeroSorteado){
      Serial.println("Parabens, voce acertou!!");
    } else {    
      Serial.println("Que pena, tente outra vez!!");  
    }
    Serial.println("--------------------------------");
    delay(500);
  }
  
  Serial.println("ESTATISTICAS DO JOGO");
  Serial.println();
  for(int i = 0; i < qtdRodadas; i++){
    Serial.println("Rodada" + String(i + 1) + ":");
    Serial.println("Seu palpite: " + String(vetPalpites[i]));
    Serial.println("Resultado: " + String (vetResultados[i]));
    Serial.println("-------------");
    Serial.println();
    
  }
  //ao finalizar.
  Serial.println("FIM DE JOGO, REINICIANDO O SISTEMA");
  delay(3000);
}



