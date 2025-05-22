// C++ code
//
/*
     cria cada vetor tamanho 4,
     fazendo parte do mesmo cadastro.

*/

String convidados[4];//cria um vetor tamanho 4
int idadeConvidados[4];
String emailConvidados[4];

//FUNÇÕES

void desenhaCabecalho()
{
  Serial.println("\\--------------------------/");
  Serial.println("\\         Entrada          /");
  Serial.println("\\--------------------------/");
  Serial.println("                             ");
  
}


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // fazer um cabeçalho 

  desenhaCabecalho();//Chama a função pra desenhar o cabeçalho
  
  //cadastrar os dados
  for(int i = 0; i < 4; i++)
  {
    //solicitar nome de usuario
    Serial.println("informe " + String(i + 1)+ "o Nome para cadastro:");
    while(!Serial.available());
    convidados[i] = Serial.readString();
    
    //solicitar a idade do usuario
    Serial.println("informe a idade de " + convidados[i]);
    while(!Serial.available());
    idadeConvidados[i] = Serial.parseInt();
    
    //solicitar i email do usuario
    Serial.println("informe o Email para cadastro:");
    while(!Serial.available());
    emailConvidados[i] = Serial.readString();
    
    Serial.println();
  }//Fim do for
  
  
  //Exibir a lista de convidados
  //obs: So vai na festa quem for maior de idade >18
  Serial.println("Lista de convidados aprovados para a festa:");
  for (int i = 0; i < 3; i++)
  {
    if (idadeConvidados[i] > 18)
    {//apenas maiores de 18
      Serial.println("------------------------------");
      Serial.println("Nome: " + convidados[i]);
      Serial.println("Idade: " + String(idadeConvidados[i]));
      Serial.println("Email: " + emailConvidados[i]);  
      Serial.println("Permissao para a festa:" + String(idadeConvidados[i] >= 18 ? "OK" : "Menor de Idade"));
      Serial.println("---------");
      Serial.println();
    }
  }
  //criar um for 
  //exibir com print cada  um dos arrays
  //pular uma linhar
 
}//fim do loop