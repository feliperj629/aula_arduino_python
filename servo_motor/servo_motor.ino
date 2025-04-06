// C++ code
// Inclusão da biblioteca Servo, que permite controlar servomotores
#include <Servo.h>

// Definindo a variável que armazenará a posição do sensor
int PosicaoSensor = 0;

// Variável que armazenará o ângulo calculado para o servo
int Angulo = 0;

// Criação de um objeto Servo chamado "servo_8"
Servo servo_8;

void setup() {
  // Configura o pino A2 como entrada para o sensor
  pinMode(A2, INPUT);

  // Anexa o servo ao pino 9 com um intervalo de sinal PWM entre 500 e 2500 microsegundos
  servo_8.attach(9, 500, 2500);
}

void loop() {
  // Lê o valor analógico do sensor no pino A2 (vai de 0 a 1023)
  PosicaoSensor = analogRead(A2);

  // Mapeia o valor lido (0 a 1023) para um valor de ângulo (180 a 0 graus)
  Angulo = map(PosicaoSensor, 0, 1023, 180, 0);

  // Envia o valor do ângulo calculado para o servo, movendo-o
  servo_8.write(Angulo);

  // Aguarda 10 milissegundos antes de repetir o loop
  delay(10); // Delay um pouco para melhorar o desempenho da simulação
}
