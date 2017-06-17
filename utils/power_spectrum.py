from matplotlib import pyplot as plt
import numpy as np
import soundfile as sf
data = np.random.random(1000000)

def make_file(data):
    with sf.SoundFile('soundtest.wav', 'x+', 64000, 2) as noisefile:
        noisefile.write(np.array([data, data]).transpose())

def plot_power_spectrum(data):
    pwr_spec = np.abs(np.fft.fft(data))**2
    time_step = 1
    freqs = np.fft.fftfreq(data.size, time_step)
    index = np.argsort(freqs)
    plt.plot(freqs[index], pwr_spec[index])
    plt.show()  # may want to do this in calling scope

def main():
    plot_power_spectrum(data)

if __name__ == '__main__':
    main()