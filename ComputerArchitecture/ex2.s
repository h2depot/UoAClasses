	.data
A:	.word 32
B:	.word 112
N:	.word 32
S:	.word 0

	.text

main:
	or $8, $0, $0
	lw $9, N

	lw $4, A
	lw $5, B
	or $2, $0, $0
	or $14, $0, $0
	addi $14, $14, 1

loop:
	beq $8, $9, loopend
	addi $8, $8, 1

	and $13, $5, $14

	beq $13, $0, skip

	add $2, $2, $4

skip:
	add $4, $4, $4
	add $14, $14, $14	

	j loop

loopend: sw $2, S

exit:
	j exit
	
