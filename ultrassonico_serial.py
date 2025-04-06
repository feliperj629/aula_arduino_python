import serial
import time

# Configure a porta serial - ajuste para sua porta
ser = serial.Serial('COM4', 9600, timeout=1)

try:
    while True:
        if ser.in_waiting > 0:
            distance = ser.readline().decode('utf-8').strip()
            print(f"Distance: {distance} cm")
        time.sleep(0.1)

except KeyboardInterrupt:
    ser.close()
    print("Programa encerrado")