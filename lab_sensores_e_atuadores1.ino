//Atribui um "valor limite de disparo" para achar um valor adequando e 
//ligar e desligar o LED quando passar a mão sobre o fotoresistor (LDR)
int triggerLimit = 930;
 
// Ligue o LED ao pino digital 3
const int ledPin = 3;

// Ligue o Piezo no pino 8
const int buzzerPin = 8; 
 
// O fotoresistor (LDR) é conectado ao pino analógico 0
int sensor = A0;


// Armazena e inicializa o valor de leitura analógica
int sensorValue = 0;
 
void setup() {
   // Inicia a comunicação serial com uma taxa de transmissão de 9600 boud rate
  Serial.begin(9600);

  // Define o LED como uma saída
  pinMode(ledPin, OUTPUT);
  
  // Define o fotoresistor como uma entrada
  pinMode(sensor, INPUT);
}
 
 
void loop(){
  
  // Lê o valor atual do fotoresistor
  sensorValue = analogRead(sensor);
  
  // Se o valor da luminosidade estiver abaixo do valor "limite de disparo", 
  //então o LED liga, caso contrário o LED permanece desligado.
  if (sensorValue < triggerLimit) {
      digitalWrite(ledPin, HIGH);
      
    //Toca o alarme
    tone(buzzerPin,1000); // toca um tom de 1000 Hz do piezo
  }
  else {
      digitalWrite(ledPin,LOW);
      noTone(buzzerPin); 
  }
  
  // Imprime as leituras atuais no monitor serial da IDE do Arduino
  Serial.print ("Leitura atual do sensor: ");
  Serial.println(sensorValue);
  delay(130);
}

