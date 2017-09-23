section .data
; by Matthias Altmann
; Define standard values
; general
	sys_exit        equ     60
	sys_read        equ     0
	sys_write       equ     1
	stdin           equ     0
	stdout          equ     1
	stderr          equ     2
        alphasize       equ     26 ; size of alphabet used for iteration
        bAsciiZero      equ     0x30
        wAsciiZero      equ     0x3030
        pCounter	db      "00"
        pAsciiSpace     db      " "

; program specific
	pPrompt 	db      "Enter string to decode (caesar):"
	promptsize 	equ	$-pPrompt 

section .bss
; Buffer to read input
	lpCipher        resb    255
	ciphersize      equ     $-lpCipher


section .text
    global _start

_start:
    nop ; for good old gdb 

; Output prompt to enter text
    mov    	rsi, pPrompt
    mov		rdx, promptsize
    call DisplayText
; Read text
    mov 	rsi, lpCipher
    mov		rdx, ciphersize
    call ReadText    

; Setup loop
    xor	 	rbx, rbx ; counter (all)
    xor 	r9,r9 ; counter (10) 
    inc         r9
    mov 	rsi, pCounter
    mov word 	[rsi],wAsciiZero   

; Start loop over alphabet
Alpha_Loop:
    mov         rsi, pCounter
    ;output     counter 
    mov		rdx,2
    call 	DisplayText
    ; update buffer counter
    call	IncCounterBuf
 
    ; output an empty space
    mov         rsi, pAsciiSpace
    mov         rdx,1
    call 	DisplayText

    ; output rotated cipher 
    mov 	rsi, lpCipher
    mov 	rdx, ciphersize
    call 	DisplayText
    ; update buffer rotated cipher
    call	IncCipherBuf

    ; increase counter
    inc rbx
    inc r9
    cmp rbx, alphasize
    jne Alpha_Loop

; Exit prog
    call Exit

ReadText:
    mov     rax, sys_read
    mov     rdi, stdin
    syscall
    ret

DisplayText:
    mov	 	rax, sys_write
    mov 	rdi, stdout
    syscall
    ret 

IncCounterBuf:
    inc byte    [rsi+1]
    cmp         r9,10
    jb          .noDecJump
    ; Decimal jump
    xor		r9,r9
    inc byte    [rsi]
    mov byte    [rsi+1],bAsciiZero       
.noDecJump:
    ret
 
IncCipherBuf:
    xor 	r11,r11
    mov 	rsi, lpCipher
    mov 	r10, rsi
    lodsb
.loopThroughBuf:
    cmp 	al,0x0A ; line feed '\n' ?
    je 		.endOfCipher
    cmp 	r11,ciphersize
    jae 	.endOfCipher
    ; check if empty space
    cmp byte   	[r10],0x20
    je          .toNextChar
    ; check if lower case
    cmp byte 	[r10],0x7A ; is z?
    jne 	.checkUpCase
    mov 	byte [r10],0x61 ; set a
    jmp 	.toNextChar
.checkUpCase:
    ; check if upper case
    cmp byte    [r10],0x5A ; is Z?
    jne      	.doNormalInc
    mov 	byte [r10],0x41; set A
    jmp 	.toNextChar
.doNormalInc:
    inc byte	[r10]
.toNextChar:
    lodsb
    inc r10
    inc r11
    jmp .loopThroughBuf
.endOfCipher:    
    ret

Exit:
    mov    rax, sys_exit
    mov    rdi, 0
    syscall
    ret

