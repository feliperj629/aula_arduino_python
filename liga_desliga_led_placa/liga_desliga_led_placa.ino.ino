/*
Pisca - Blink

Liga um LED por um segundo e depois desliga por um segundo, repetidamente.

A maioria dos Arduinos tem um LED on-board que você pode controlar. No UNO, MEGA e ZERO
ele é conectado ao pino digital 13.

Este código de exemplo é de domínio público.
https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// A função de configuração é executada uma vez quando você pressiona reset ou liga a placa
void setup() {
  // inicializa o pino digital LED_BUILTIN como uma saída.
  pinMode(LED_BUILTIN, OUTPUT);
}

// a função de loop é executada repetidamente para sempre
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // liga o LED (ALTO é o nível de tensão)
  delay(1000);                      // espere um segundo
  digitalWrite(LED_BUILTIN, LOW);   // desliga o LED deixando a tensão BAIXA
  delay(1000);                      // espere um segundo
}
