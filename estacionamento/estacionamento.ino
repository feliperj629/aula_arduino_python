const int trigPin = 9;     // Define o pino de disparo (trigger)
const int echoPin = 10;    // Define o pino de eco (echo)
const int ledVerde = 4;    // Define o pino para o LED verde
const int ledAmarelo = 3;  // Define o pino para o LED amarelo
const int ledVermelho = 2; // Define o pino para o LED vermelho

long duration;             // Variável para armazenar o tempo do pulso
int distance;              // Variável para armazenar a distância calculada

void setup() {
  pinMode(trigPin, OUTPUT);  // Configura o pino trigPin como saída
  pinMode(echoPin, INPUT);   // Configura o pino echoPin como entrada
  pinMode(ledVerde, OUTPUT);   // Configura o pino para LED verde como saída 
  pinMode(ledAmarelo, OUTPUT); // Configura o pino para LED amarelo como saída
  pinMode(ledVermelho, OUTPUT); // Configura o pino para LED vermelho como saída
  
  Serial.begin(9600);        // Inicia a comunicação serial a 9600 bps
}

void loop() {
  // Limpa o pino trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Aguarda 2 microssegundos
  
  // Envia um pulso no trigPin para iniciar a medição
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Pulso de 10 microssegundos
  digitalWrite(trigPin, LOW);
  
  // Lê o tempo do pulso no echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância
  distance = duration * 0.034 / 2; // A fórmula é distância = (tempo * velocidade do som) / 2

  // Imprime a distância no monitor serial
  Serial.print("Distance: ");
  Serial.println(distance);

  // Lógica para acender os LEDs com base na distância
  if (distance < 10) {
    // A distância é menor que 10 cm, acende o LED vermelho
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  } else if (distance >= 10 && distance <= 20) {
    // A distância está entre 10 cm e 20 cm, desliga todos os LEDs
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);  // Acende o LED amarelo
    digitalWrite(ledVerde, LOW);
  } else if (distance > 20 && distance <= 30) {
    // A distância está entre 20 cm e 30 cm, acende o LED verde
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
  } else if (distance > 30) {
    // A distância é maior que 30 cm, desliga todos os LEDs
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  }

  delay(1000); // Aguarda 1 segundo antes de medir novamente
}
