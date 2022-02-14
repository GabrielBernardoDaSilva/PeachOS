#include "peachos.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char **argv)
{
    printf("My age is %i\n", 98);
    print("Hello How are you!\n");
    print(itoa(356));

    putchar('Z');

    void *ptr = malloc(512);
    free(ptr);
    peachos_getkeyblock();
    printf("Hello world!");

    char buf[1024];
    peach_termianl_readline(buf, sizeof(buf), true);
    print(buf);
    while (1)
    {
    }

    return 0;
}