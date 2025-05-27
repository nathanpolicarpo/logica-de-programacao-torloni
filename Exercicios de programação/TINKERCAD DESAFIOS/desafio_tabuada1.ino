// Desafio da tabuada
//

int tabuadaEscolhida;
int resultado;


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Digite o numero da tabuada que deseja que apareça");
  while (!Serial.available()) {}
  tabuadaEscolhida = Serial.parseInt();
  
  for(int contador = 1;contador <= 10; contador++){
    resultado = tabuadaEscolhida * contador;
    
    // Exibir assim: 2 X 1 = 2
    Serial.println(String(tabuadaEscolhida) + " X " + String(contador) + " = " + String(resultado));
  
  }
  
  }
