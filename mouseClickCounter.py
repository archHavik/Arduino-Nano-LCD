import serial
from pynput import mouse

ser = serial.Serial('COM3', 9600)

def on_move(x, y):
    pass

def on_click(x, y, button, pressed):
    if (pressed):
        if (button == button.left):
            ser.write(bytes([1]))
        # Stop listener

def on_scroll(x, y, dx, dy):
    #return False
    pass

# Collect events until released
with mouse.Listener(
        on_move=on_move,
        on_click=on_click,
        on_scroll=on_scroll) as listener:
    listener.join()

# ...or, in a non-blocking fashion:
listener = mouse.Listener(
    on_move=on_move,
    on_click=on_click,
    on_scroll=on_scroll)
listener.start()
