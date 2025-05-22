String frutas[6];
float precosFrutas;

  void setup()
{
  Serial.begin(9600);

  Serial.println("*** sacolao do zeh kjkj***");
  Serial.println();

  String frutas[6];//cria um vetor tamanho 6 (preenchendo as posições)

  Serial.println("oh ZEH, bora cadastrar as frutas!");
  Serial.println("");

  for(int i = 0; i <= 5; i++){
    Serial.println("informe la fruta" + String(i + 1) + "a fruta:");
    while(!Serial.available());
    String fruta = Serial.readString();

    frutas[i] = fruta;
  }

  Serial.println("");
  Serial.println("as frutas cadastradas foram:");
  for (int i = 0; i < 6; i++) {
    Serial.println("informe a " + String(i + 1) + "a fruta:");
    while(!Serial.available());
    String frutaDigitada = Serial.readString();

    Serial.println("Fruta " + String(i + 1) + ": " + frutas[i]);
    while(!Serial.available());
    float precoDigitado = Serial.readString();

    frutas[i] = frutaDigitada;
    precosFrutas[i] = precoDigitado;

  }//Fim do for

  Serial.println("Exibindo os valores cadastrados: ")
    Serial.println();

  for(int i = 0; i <= 5; i++)
  {
    Serial.println(String(i + 1) + "a fruta: " + frutas[i]);
    Serial.println("preco da fruta: " + String(precosFrutas[1]));
  }
}
//Desafio: crie um for para exibir as frutas cadastradas
void loop(){

}