#pragma once
#include <stdbool.h>


int strlen(const char* ptr);
int strnlen(const char* ptr, int max);
bool isdigit(char c);
int tonumericdigit(char c);
char* strcpy(char* dest, const char* src);

char tolower(char c);
int strncmp(const char* str1, const char* str2, int n);
int strnlen_terminator(const char* str, int max, char terminator );
int istrncmp(const char* str1, const char* str2, int n);
