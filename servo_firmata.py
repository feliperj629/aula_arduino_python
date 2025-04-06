import time
from pyfirmata import Arduino, util

# Substitua pela porta do seu Arduino (ex: "COM3" ou "/dev/ttyACM0")
board = Arduino('COM4')  # Altere conforme necessário

# Observação:
# Se você estiver usando Python 3.11 ou superior e receber o erro:
# "AttributeError: module 'inspect' has no attribute 'getargspec'"
# Vá até o arquivo pyfirmata.py (no site-packages) e substitua:
# Geralmente dentro de C:\Users\NOMEUSUARIO\AppData\Roaming\Python\PythonXXX\site-packages\pyfirmata\pyfirmata.py
#
# procurar por:
#    len_args = len(inspect.getargspec(func)[0])
# por:
#    len_args = len(inspect.getfullargspec(func).args)

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
