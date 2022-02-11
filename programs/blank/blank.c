#include "peachos.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char** argv)
{
    print("Hello How are you!\n");
    print(itoa(356));

    putchar('Z');

    void* ptr = malloc(512);
    free(ptr);
    while (1)
    {

        if (getkey()!= 0)
            print("key was pressed!\n");
    }
    
    return 0;
}