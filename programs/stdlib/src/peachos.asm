[BITS 32]

section .asm

global print:function
global peachos_getkey:function
global peachos_free:function
global peachos_malloc:function
global peachos_putchar:function
global peachos_process_load_start:function

; void print(const char* message)
print:
    push ebp
    mov ebp, esp
    push dword[ebp+8]
    mov eax, 0x1        ;command print
    int 0x80
    
    add esp, 4
    pop ebp
    ret

; int peachos_getkey()
peachos_getkey:
    push ebp
    mov ebp, esp
    mov eax, 0x2        ;command get key
    int 0x80

    pop ebp
    ret

; void peachos_putchar(char c)
peachos_putchar:
    push ebp
    mov ebp, esp
    mov eax, 0x3        ;command putchar
    push dword[ebp+8]   ; var c
    int 0x80

    add esp, 4
    pop ebp
    ret


; void* peachos_malloc(size_t size)
peachos_malloc:
    push ebp
    mov ebp, esp
    mov eax, 0x4        ;command malloc
    push dword[ebp+8]   ;var size
    int 0x80
    
    add esp, 4
    pop ebp
    ret

; void peachos_free(void* ptr)
peachos_free:
    push ebp
    mov ebp, esp
    mov eax, 0x5        ;command free
    push dword[ebp+8]   ;vat ptr
    int 0x80

    add esp, 4
    pop ebp
    ret


; void peachos_process_load_start(const char* filename)
peachos_process_load_start:
    push ebp
    mov ebp, esp
    mov eax, 0x6        ;command process load start
    push dword[ebp+8]   ;vat filename
    int 0x80

    add esp, 4
    pop ebp
    ret
