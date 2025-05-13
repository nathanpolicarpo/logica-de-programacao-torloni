float soma;
float resultado;

int escolhaDaOperacao;
int contador = 0;

float somar( float numero1, float numero2, float numero3 = 10) {
  return (numero1 + numero2 + numero3);
}

void subtrair(float numero1, float numero2){
  resultado = numero1 - numero2;
  Serial.println("WOW!!! O resultado foi: " + String(resultado));
}

void multiplicar(float numero1, float numero2){
  resultado = numero1 * numero2;
  Serial.println("WOW!!! O resultado foi: " + String(resultado));
}

void dividir(float numero1, float numero2){
  resultado = numero1 / numero2;
  Serial.println("WOW!!! O resultado foi: " + String(resultado));

}



void setup()
{
  Serial.begin(9600);
  
  float n1 = 0.0;
  float n2 = 0.0;
  
  do{
    Serial.println("Bem-Vindo(a)");
    Serial.println("Escolha uma opcao");
    Serial.println("1 - somar");
    Serial.println("2 - subtrair");
    Serial.println("3 - multiplicar");
    Serial.println("4 - dividir");

    while(!Serial.available()){}

    escolhaDaOperacao = Serial.parseInt();

    Serial.println("Digite o primeiro numero:");
    while (!Serial.available()); 
    n1 = Serial.parseFloat();


    Serial.println("Digite o segundo numero:");
    while (!Serial.available()); 
    n2 = Serial.parseFloat(); 
 
    switch(escolhaDaOperacao){
      case 1:  
      resultado = somar(n1,n2);
      Serial.println("WOW!!! O resultado foi: " + String(resultado));
      
      break;
      
       case 2:
      subtrair(n1, n2);
      break;
      
       case 3:
      multiplicar(n1, n2);     
      break;
      
       case 4:
      dividir(n1, n2);
      break;
      
      default:
      Serial.println("opcao invalidade");
    
    
    }
    
    Serial.println("Voce deseja continuar? Se sim, digite [s], Se nao digite [n]");
    while (!Serial.available());{}
    
    if (Serial.readString() == "s"){
      contador++;
    }
    else{
      contador = 0;
      
      Serial.println("Ate nunca mais, se vc voltar vc tera cancer!!!");
      
    }
          
  }
  while(contador != 0);
} 

void loop()
{
  
  
} 
