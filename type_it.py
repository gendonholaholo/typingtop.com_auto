import pyautogui
import time

# Tunggu beberapa detik sebelum mulai mengetik
time.sleep(5)

# Baca teks dari output.txt
with open('output.txt', 'r') as file:
    text = file.read()

# Ketik teks secara otomatis
pyautogui.typewrite(text, interval=0.05)

