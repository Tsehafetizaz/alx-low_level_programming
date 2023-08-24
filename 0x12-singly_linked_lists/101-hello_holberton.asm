section .data
    hello_string db "Hello, Holberton",10,0 ; 10 is the newline character, 0 is the null terminator

section .text
    extern printf ; This tells the assembler that printf is an external function

    global _start
_start:
    ; Prepare the arguments for printf
    ; rdi will contain the address of our string
    mov rdi, hello_string

    ; Call printf
    call printf

    ; Exit the program
    ; Instead of using an interrupt, we'll use the exit syscall
    mov rax, 60   ; syscall: exit
    xor rdi, rdi  ; status: 0
    syscall
