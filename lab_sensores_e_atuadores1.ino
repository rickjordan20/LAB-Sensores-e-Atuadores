//Atribui um "valor limite de disparo" para achar um valor adequado, 
//ligando e desligando o LED quando passar a mão sobre o fotoresistor (LDR).
int triggerLimit = 930;
 
// Ligue o LED ao pino digital 3
const int ledPin = 3;

// Ligue o Piezo no pino 8
const int buzzerPin = 8; 
 
// Altera a frequência do tom
const int freq=5;

// O fotoresistor (LDR) é conectado ao pino analógico A0
int ldrPin = A0;

// Armazena e inicializa o valor de leitura analógica
int ldrValue = 0;
 
void setup() {
   // Inicia a comunicação serial com uma taxa de transmissão de 9600 boud rate
  Serial.begin(9600);
  
  // Define o fotoresistor como uma entrada
  pinMode(ldrPin, INPUT);
  
  // Define o LED como uma saída
  pinMode(ledPin, OUTPUT);
  
  // Define o Piezo como uma saída
  pinMode(buzzerPin, OUTPUT);

}
 
 
void loop(){
  
  // Lê o valor atual do fotoresistor
  ldrValue = analogRead(ldrPin);
  
  // Se o valor da luminosidade estiver abaixo do valor "limite de disparo", 
  //então o LED liga, caso contrário o LED permanece desligado.
  if (ldrValue < triggerLimit) {
      digitalWrite(ledPin, HIGH);
      
    //Toca o alarme
    tone(buzzerPin,300); // toca um tom de 300 Hz do piezo
    delay(30); // espera alguns segundos
    noTone(buzzerPin); // interrpompe o tom do buzzer
    digitalWrite(ledPin,LOW); // apaga a led
    delay(ldrValue/freq); /* espera agora a quantidade de milisegundos 
    em idrValue */
  }
  else {
      digitalWrite(ledPin,LOW); // apaga a led
      noTone(buzzerPin); // interrompe o tom do buzzer
  }
  
  // Imprime as leituras do sensor no monitor serial da IDE do Arduino
  Serial.print ("Leitura atual do sensor: ");
  Serial.println(ldrValue);
  delay(130);
}

