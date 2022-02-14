#ifndef PEACHOS_H
#define PEACHOS_H
#include <stddef.h>
#include <stdbool.h>

void print(const char *message);
int peachos_getkey();
void *peachos_malloc(size_t size);
void peachos_free(void *ptr);
void peachos_putchar(char c);
int peachos_getkeyblock();
void peach_terminal_readline(char *out, int max, bool output_while_typing);

#endif