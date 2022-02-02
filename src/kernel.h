#pragma once


#define VGA_WIDTH 80
#define VGA_HEIGHT 20
#define PEACHOS_MAX_PATH 108

#define ERROR(value) (void*) (value)
#define ERROR_I(value) (int) (value)
#define ISERR(value) ((int)value) < 0

void kernel_registers();

void kernel_main();
void kernel_page();

void panic(const char* msg);
void print(const char* str);

