hutint piezo = 8;
int duration = 250;
int notes[] = {261, 293, 329, 349, 392, 440, 493, 523, 587, 659, 698, 783, 880};

void setup()
{
    pinMode(piezo, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 13; i++)
    {
        tone(piezo, notes[i], duration);
        delay(duration);
    }
    for (int i = 11; i > 0; --i)
    {
        tone(piezo, notes[i], duration);
        delay(duration);
    }
}
