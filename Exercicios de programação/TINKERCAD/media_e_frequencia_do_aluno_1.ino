// Media dos Alunos
//
float nota1, nota2, nota3, nota4, media;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
 //Entrada
  
 Serial.println("Digite a primeira nota!");
  while (! Serial.available()) {}
  nota1 = Serial.parseFloat();
 
  Serial.println("Digite a segunda nota!");
  while (! Serial.available()) {}
  nota2 = Serial.parseFloat();
  
  Serial.println("Digite a terceira nota!");
  while (! Serial.available()) {}
  nota3 = Serial.parseFloat();
  
  Serial.println("Digite a quarta nota!");
  while (! Serial.available()) {}
  nota4 = Serial.parseFloat(); 
 
//Processamento
media = (nota1 + nota2 + nota3 + nota4) / 4.0;

//Exiba a media
Serial.print("Media: ");
Serial.println(media, 2);

//Vericar a situacao das media e declara o resultado final.
if (media >= 7.0) {
  Serial.println("APROVADO");
} else if (media > 5.0) {
  Serial.println("RECUPERACAO");
} else {
  Serial.println("REPROVADO");
}

Serial.println("---------------------------------------");

delay(6000);
}