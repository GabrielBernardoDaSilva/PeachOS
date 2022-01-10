ORG 0x7c00
BITS 16

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

_start:
    jmp short start
    nop

times 33 db 0

start:
    jmp 0x0: step2

step2: 
    cli                             ;clear interrupts
    mov ax, 0x00
    mov ds, ax
    mov es, ax
    mov ss, ax                      ;mov ax value to stack segmentation 
    mov sp, 0x7c00                  ;init stack pointer register
    sti                             ;enable interrupts
                                    
.load_protected:
    cli
    lgdt[gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:load32

                                    ;GDT
gdt_start:
gdt_null:
    dd 0x0
    dd 0x0
                                    ;offset 0x8
gdt_code:                           ;cs should point to this
    dw 0xffff                       ;Segement limit first 0-15 bits 
    dw 0x0                          ;base first 0-15 bits
    db 0x0                          ;base 16-23 bits
    db 0x9a                         ;access byte
    db 11001111b                    ;high 4 bit flags and low 4 bit flags
    db 0x0                          ;base 24-31
                                    ;offset 0x10
gdt_data:
    dw 0xffff                       ;Segement limit first 0-15 bits 
    dw 0x0                          ;base first 0-15 bits
    db 0x0                          ;base 16-23 bits
    db 0x92                         ;access byte
    db 11001111b                    ;high 4 bit flags and low 4 bit flags
    db 0x0                          ;base 24-31

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

[BITS 32]
load32:
    mov eax, 0x01
    mov ecx, 0x64
    mov edi, 0x0100000
    call ata_lbl_read
    jmp CODE_SEG: 0x0100000

ata_lbl_read:
    mov ebx, eax                    ;backup the lba
    shr eax, 24                     ;send the highest 8 bits of lba to hard disk controller shr => bitwise right 24 bits of 32 result only left 8 bits
    or eax, 0xe0                    ;select master driver
    mov dx, 0x1f6
    out dx, al                      ;finished sending highest 8 bits of the lba


    mov eax, ecx                    ;send total sectors to read
    mov dx, 0x1f2
    out dx, al                      ;finish sending total sectors to read

    mov eax, ebx                    ;restore the backup lba
    mov dx, 0x1f3
    out dx, al                      ;finished sending more bits to lba

    mov dx, 0x1f4                   ;sending more bits of the lba
    mov eax, ebx                    ;restore the backup lba
    shr eax, 8
    out dx, al                      ;finished sending more bits to lba

    mov dx, 0x1f5                   ;send upper 16bits to lba
    mov eax, ebx
    shr eax, 16
    out dx, al                      ;finished sending upper 16bits to lba

    mov dx, 0x1f7
    mov al, 0x20
    out dx, al

.next_sector:                       ;read all sctors
    push ecx

.try_again:                         ;checkin if we need to read again
    mov dx, 0x1f7
    in al, dx
    test al, 8
    jz .try_again   
                                    ;we need to read 256 words
    mov ecx, 256
    mov dx, 0x1f0
    rep insw
    pop ecx
    loop .next_sector
                                    ;ending reading sectors
    ret 



times 510-($ - $$) db 0
dw 0xAA55 

