// C++ code
//

int palpite = 0;

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

  //solicitar o palpite do usuario - 3 comandos.
  Serial.println("Digite seu palpite entre 1 e 7 ");
  while(!Serial.available());//espera o usuario digitar.
  int palpite = Serial.parseInt();//guarda o palpite do usuario.

  //jogar o dado - sorteia um numero randomico/aleatorio de 1 ate 7 - 1, ou seja, 6.
  int numeroSorteado = random(1, 7);//numero entre 1 a 6. 

  Serial.print("jogando o dado");
  for(int i = 1; i <= 5; i++){
    Serial.print(".");
    delay(700);

  }

  //exibir o palpite do usuario.
  Serial.println("seu palpite:" + String(palpite));
  Serial.println("Numero sorteado:" + String(numeroSorteado));



  if( palpite == numeroSorteado)
  {
    Serial.println("Parabens, voce acertou!!");
  } else {
    Serial.println("Que pena, tente outra vez!!");  
  }

  Serial.println("Reiniciando o programa...");
  Serial.println();
  delay(700);
}

//exibir o numero sorteado.

