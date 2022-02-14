#include "shell.h"
#include "stdio.h"
#include "stdlib.h"
#include "peachos.h"

int main(int argc, char **argv)
{
    print("Peachos v1.0.0\n");
    while (1)
    {
        print("> ");
        char buf[1024];
        peach_terminal_readline(buf, sizeof(buf), true);
        print("\n");
        print(buf);
        print("\n");
    }

    return 0;
}