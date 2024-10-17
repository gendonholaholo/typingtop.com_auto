import pyautogui
import time

time.sleep(5)

with open('output.txt', 'r') as file:
    text = file.read()

pyautogui.typewrite(text, interval=0.05)

