from pyfirmata import Arduino, util
import time

# Substitua com a porta correta do seu sistema
#board = Arduino('/dev/ttyUSB0')  # Para Linux
board = Arduino('COM4')  # Para Windows

# Configura o pino 13 como saída (LED embutido no Arduino Uno)
led = board.get_pin('d:13:o')

while True:
    led.write(1)  # Liga o LED
    time.sleep(2)
    led.write(0)  # Desliga o LED
    time.sleep(2)
