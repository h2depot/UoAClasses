	.data
N:	.word 10
A:	.word 9
	.word 3
	.word 12
	.word 7
	.word 23
	.word 1
	.word 23
	.word 43
	.word 54
	.word 31
B:	.space 40

	.text
main:   or $8, $0, $0
	lw $9, N
	or $10, $0, $0

	la $11, A
	la $12, B

loop:	beq $8, $9, loopend
	addi $8, $8, 1

	lw $13, 0($11)
	sw $13, 0($12)

	addi $11, $11, 4
	addi $12, $12, 4
	j loop

loopend:

exit:	j exit
	
