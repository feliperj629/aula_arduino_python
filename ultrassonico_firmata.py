from pyfirmata import Arduino, util
import time

# Solução 1: Usando um sketch customizado no Arduino
    # A melhor abordagem é criar um sketch Arduino que faz a medição e envia o resultado via serial:
# Solução 2: Alternativa usando apenas PyFirmata (menos precisa)
# Por que a primeira solução é melhor?
# Precisão: O Arduino nativo pode medir microssegundos com precisão#
# Confiabilidade: A comunicação serial é mais estável para este caso#
# Performance: O Firmata não foi projetado para medições de tempo precisas

# Conectar ao Arduino (substitua com a porta correta do seu sistema)
board = Arduino('COM4')  # Para Windows

# Configura os pinos como saída (Trigger, LEDs e Buzzer) e entrada (Echo)
trigPin = board.get_pin('d:9:o')  # Pino de disparo (Trigger) no pino digital 9
echoPin = board.get_pin('d:10:i')  # Pino de eco (Echo) no pino digital 10
ledAmarelo = board.get_pin('d:3:o')  # LED amarelo no pino digital 3
ledVerde = board.get_pin('d:4:o')  # LED verde no pino digital 4
ledVermelho = board.get_pin('d:2:o')  # LED vermelho no pino digital 2
buzzerPin = board.get_pin('d:11:o')  # Buzzer no pino digital 11

# Função para calcular a distância
def get_distance():
    # Envia um pulso no trigPin
    trigPin.write(0)  # Desliga o trigger
    time.sleep(0.000002)  # Espera 2 microssegundos
    trigPin.write(1)  # Ativa o trigger por 10 microssegundos
    time.sleep(0.00001)
    trigPin.write(0)  # Desliga o trigger

    # Aguardar o sinal de Echo começar
    while echoPin.read() == 0:
        pass  # Aguarda o início do pulso

    pulse_start = time.time()  # Marca o tempo de início da leitura

    # Aguardar o fim do sinal de Echo
    while echoPin.read() == 1:
        pass  # Aguarda até o sinal de Eco retornar

    pulse_end = time.time()  # Marca o tempo de fim da leitura

    # Calculando a duração do pulso
    duration = pulse_end - pulse_start

    # A distância é dada pela fórmula: distância = (tempo * velocidade do som) / 2
    distance = (duration * 34300) / 2  # Velocidade do som = 34300 cm/s
    return distance

# Função para controle dos LEDs
def control_leds(distance):
    if distance < 10:
        ledVermelho.write(1)  # Acende o LED vermelho
        ledAmarelo.write(0)
        ledVerde.write(0)
    elif 10 <= distance <= 20:
        ledVermelho.write(0)
        ledAmarelo.write(1)  # Acende o LED amarelo
        ledVerde.write(0)
    elif 20 < distance <= 30:
        ledVermelho.write(0)
        ledAmarelo.write(0)
        ledVerde.write(1)  # Acende o LED verde
    else:
        ledVermelho.write(0)
        ledAmarelo.write(0)
        ledVerde.write(0)  # Desliga todos os LEDs

# Função para controle do buzzer
def control_buzzer(distance):
    if distance < 30:
        beep_duration = map_distance_to_beep_duration(distance)
        buzzerPin.write(1)  # Liga o buzzer
        time.sleep(beep_duration / 1000)  # Duração do beep (em segundos)
        buzzerPin.write(0)  # Desliga o buzzer
    else:
        buzzerPin.write(0)  # Desliga o buzzer

# Função para mapear a distância para duração do beep
def map_distance_to_beep_duration(distance):
    return (30 - distance) * 5  # Mapeia a distância para uma duração proporcional

# Loop principal
while True:
    distance = get_distance()  # Mede a distância
    print(f"Distance: {distance:.2f} cm")

    # Controle dos LEDs e buzzer
    control_leds(distance)
    control_buzzer(distance)

    time.sleep(0.1)  # Aguarda 100 milissegundos antes de medir novamente
