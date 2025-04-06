const int trigPin = 9;  // Define o pino de disparo (trigger)
const int echoPin = 10; // Define o pino de eco (echo)
long duration;           // Variável para armazenar o tempo do pulso
int distance;            // Variável para armazenar a distância calculada

void setup() {
  pinMode(trigPin, OUTPUT); // Configura o pino trigPin como saída
  pinMode(echoPin, INPUT);  // Configura o pino echoPin como entrada
  Serial.begin(9600);       // Inicia a comunicação serial a 9600 bps
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

  delay(1000); // Aguarda 1 segundo antes de medir novamente
}
