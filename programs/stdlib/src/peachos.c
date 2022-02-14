#include "peachos.h"

int peachos_getkeyblock()
{
    int val = 0;
    do
    {
        val = peachos_getkey();
    } while (val == 0);

    return val;
}

void peach_termianl_readline(char *out, int max, bool output_while_typing)
{
    int i = 0;
    for (i = 0; i < max - 1; i++)
    {
        char key = peachos_getkeyblock();

        // carriage return
        if (key == 13)
            break;

        if (output_while_typing)
            peachos_putchar(key);

        // backspace

        if (key == 0x08 && i >= 1)
        {
            out[i - 1] = 0x00;
            // -2 because we will +1 when we go to the continue
            i -= 2;
        }
        out[i] = key;
    }

    out[i] = 0x00;
}