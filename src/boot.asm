[BITS 16]
[ORG 0x7C00]

start:
    ; Set up the stack
    mov ax, 0x9000
    mov ss, ax
    mov sp, 0xFFFF

    ; Load the kernel
    mov bx, 0x1000
    mov dh, 0x00
    mov dl, 0x80
    mov ah, 0x02
    mov al, 0x01
    mov ch, 0x00
    mov cl, 0x02
    int 0x13

    ; Jump to the kernel
    jmp 0x1000:0x0000

times 510-($-$$) db 0
dw 0xAA55
