import matplotlib
matplotlib.use("TkAgg")  # Use TkAgg to block the script until the plot window is closed

import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import time

# ---------- SERIAL ----------
ser = serial.Serial("COM7", 9600, timeout=1)
time.sleep(2)

# ---------- DATA ----------
x = []
y = []
start_time = time.time()

# ---------- PLOT ----------
fig, ax = plt.subplots()
line, = ax.plot([], [], lw=2)

ax.set_xlabel("Time (s)")
ax.set_ylabel("Temperature (°C)")
ax.set_title("ESP32 Live Temperature")

ax.set_autoscale_on(True)

# ---------- UPDATE ----------
def update(frame):
    data = ser.readline().decode(errors="ignore").strip()
    if data:
        try:
            temp = float(data)
            t = time.time() - start_time

            x.append(t)
            y.append(temp)

            line.set_data(x, y)

            ax.relim()
            ax.autoscale_view()

        except ValueError:
            pass

    return line,

ani = FuncAnimation(
    fig,
    update,
    interval=1000,
    cache_frame_data=False
)

plt.show()
ser.close()
