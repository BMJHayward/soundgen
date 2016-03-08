#define speakerPin 8

unsigned long lastClick;


void setup()
{
    pinMode(speakerPin, OUTPUT);
    lastClick = micros();
}


//init with a 32 bit unsigned long value, can't be zero
#define LFSR_INIT 0xfeedfaceUL


//use bits {32,30,26,24} OR {32,16,3,2}
#define LFSR_MASK ((unsigned long)(1UL<<31 | 1UL<<15 | 1UL<<2 | 1UL<<1))


//see: http://arduino.stackexchange.com/questions/6715/audio-frequency-white-noise-generation-using-arduino-mini-pro
void generateNoise_a()
{
    unsigned long int reg;
    unsigned long int newr;
    unsigned char lobit;
    unsigned char b31, b29, b25, b24;
    b31 = (reg & (1L << 31)) >> 31;
    b29 = (reg & (1L << 29)) >> 29;
    b25 = (reg & (1L << 25)) >> 25;
    b24 = (reg & (1L << 24)) >> 24;
    lobit = b31 ^ b29 ^ b25 ^ b24;
    newr = (reg << 1) | lobit;
    reg = newr;
    digitalWrite (speakerPin, reg & 1);
    delayMicroseconds (50); //changing this val changes frequency
}


unsigned int generateNoise_b()
{
    // see "linear feedback shift register, Galois LFSR"
    static unsigned long int lfsr = LFSR_INIT; //start with 32 bits, non-zero
    if(lfsr & 1)
    {
        lfsr = (lfsr>>1) ^ LFSR_MASK;
        return(1);
    }
    else
    {
        lfsr >>= 1;
        return(0);
    }
}


void loop()
{
    if ((micros() - lastClick) > 50)
    {
        lastClick = micros();
        digitalWrite (speakerPin, generateNoise_b());
    }
}

