import numpy as np
from scipy import signal as signal
import matplotlib.pyplot as plt
import seaborn

baseline = np.arange(1024)
incoming = signal.chirp(baseline,0,baseline[511],3)
if input('would you like to see the graph?').lower() == 'yes':
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

def runsignal():
    for data in channel1:
        print('Channel 1: ', data)
    for data in channel2:
        print('Channel 2: ',data)

while True:
    runsignal()
