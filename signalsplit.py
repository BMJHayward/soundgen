import numpy as np
from scipy import signal as signal
import matplotlib.pyplot as plt
import seaborn

baseline = np.arange(1024)
incoming = signal.chirp(baseline,0,baseline[511],3)
plt.plot(baseline,incoming)
plt.show()
channel1 = []
channel2 = []
threshold = 0.25

for point in incoming:
    if abs(point) < threshold:
        channel1.append(point)
    else:
        channel2.append(point)

for data in channel1:
    print(data)
for data in channel2:
    print(data)
