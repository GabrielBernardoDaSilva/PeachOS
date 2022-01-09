section .asm

global idt_load

idt_load:                               ;load interrupt descriptor table
    push ebp
    mov ebp, esp
    mov ebx, [ebp + 8]
    lidt [ebx]
    pop ebp
    ret
