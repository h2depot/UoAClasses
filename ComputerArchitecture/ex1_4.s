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

	.text
main:
	or $8, $0, $0
	lw $9, N

outer_loop:
	addi $10, $9, -1
	beq $10, $8, outer_loopend

	sub $11, $9, 2
	la $13, A

inner_loop:
	slt $16, $11, $8
	beq $16, $0, cont
	j inner_loopend

cont:
	lw $14, 0($13)
	lw $15, 4($13)
	
	slt $16, $15, $14
	beq $16, $0, skip
	
	sw $15, 0($13)
	sw $14, 4($13)

skip:
	addi $13, $13, 4
	addi $11, $11, -1
	j inner_loop
	
inner_loopend:
	addi $8, $8, 1
	j outer_loop

outer_loopend:

exit:	j exit
		

	
	
