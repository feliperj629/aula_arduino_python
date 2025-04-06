import time
from pyfirmata import Arduino, util

# Substitua pela porta do seu Arduino (ex: "COM3" ou "/dev/ttyACM0")
board = Arduino('COM4')  # Altere conforme necessário

# Inicia leitura assíncrona
it = util.Iterator(board)
it.start()

# Configura o servo
servo_pin = board.get_pin('d:9:s')  # pino digital 9 como servo

# Ativa leitura analógica
sensor_pin = board.get_pin('a:2:i')  # pino analógico 2 como input

time.sleep(1)  # Aguarda o Arduino inicializar

try:
    while True:
        leitura = sensor_pin.read()  # Valor entre 0.0 e 1.0
        if leitura is not None:
            valor_0_1023 = int(leitura * 1023)
            angulo = int((1 - leitura) * 180)
            servo_pin.write(angulo)
            print(f"Sensor: {valor_0_1023}, Ângulo: {angulo}")
        time.sleep(0.01)

except KeyboardInterrupt:
    print("Encerrando...")
    board.exit()
