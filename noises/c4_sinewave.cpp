/* It's a C4 tone fading from left to right for 2.5 seconds. You can see in the code how all these numbers work.
 *
 * The wave file generated is a standard PCM, 16-bit, stereo file. (Everything that claims to play wave files should be able to play that.)
 *
 * The waveform itself is a simple sine wave.
 * Source: cplusplus.com/forum/beginner/166954 accessed:20161503
 */

#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;


namespace little_endian_io
{
    template <typename Word>
    std::ostream& write_word(std::ostream& outstrm, Word value, unsigned size = sizeof(Word))
    {
        for( ; size; --size, value >>= 8)
        {
            outstrm.put(static_cast<char> (value &0xFF));
        };

        return outstrm;
    }
}

using namespace little_endian_io;


int main()
{
    ofstream newfile("testexample.wav", ios::binary);

    //writing the file headers
    newfile << "RIFF----WAVEfmt ";     //chunk size, to be filled in later
    write_word(newfile,     16, 4);    //no extension data
    write_word(newfile,      1, 2);    //PCM - integer samples
    write_word(newfile,      2, 2);    //two channels for stereo mode
    write_word(newfile,  44100, 4);    //samples per second in Hz
    write_word(newfile, 176400, 4);    //(sample rate * bits/sample * channels ) / 8
    write_word(newfile,      4, 2);    //datablock size, size of 2 int samples in bytes, one per channel
    write_word(newfile,     16, 2);    //

    //write data to chunk header
    size_t data_chunk_pos = newfile.tellp();
    newfile << "data----"; //chunk size to fill in later
    
    //write audio samples, a C4 note sine wave with L to R fade
    constexpr double two_pi = 6.283185307179586476925286766559;
    constexpr double max_amplitude = 32760; //volume 

    double hz        = 44100;   //samples/second
    double frequency = 261.626; //middle C C4
    double seconds   = 10;      //time

    int N = hz * seconds; //number of samples
    for(int n=0; n<N; ++n)
    {
        double amplitude = (double)n / N * max_amplitude;
        double value = sin((two_pi * n * frequency) / hz);
        write_word(newfile, (int)(                amplitude * value), 2);
        write_word(newfile, (int)((max_amplitude - amplitude) * value), 2);
    }

    //need final file size to fill chunk sizes above
    size_t file_length = newfile.tellp();

    //fix data chunk header to contain data size
    newfile.seekp(data_chunk_pos + 4);
    write_word(newfile, file_length - data_chunk_pos + 8);

    //fix file header to contain correct RIFF chunk size: (file size - 8) bytes in total
    newfile.seekp(0 + 4);
    write_word(newfile, file_length - 8, 4);
}

