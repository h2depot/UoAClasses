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
S:	.word 0

	.text
main:	or $8, $0, $0
	lw $9, N
	or $10, $0, $0

	la $11, A

loop:	beq $8, $9, loopend
	addi $8, $8, 1

	lw $12, 0($11)
	add $10, $10, $12
	addi $11, $11, 4
	j loop

loopend:	sw $10, S

exit:	j exit
