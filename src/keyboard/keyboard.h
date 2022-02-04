#ifndef KEYBOARD_H
#define KEYBOARD_H

typedef int (*KEYBOARD_INIT_FUNC)();

struct process;
struct keyboard
{
    KEYBOARD_INIT_FUNC init;
    char name[20];
    struct keyboard *next;
};

void keyboard_init();
void keyboard_backspace(struct process *process);
void keyboard_push(char c);
char keyboard_pop();
#endif