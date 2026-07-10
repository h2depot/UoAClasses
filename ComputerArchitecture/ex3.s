	.data
	
A:	.word 0, 0, 0, 1
	.word 0, 2, 0, 0
	.word 0, 0, 3, 0
	.word 4, 0, 0, 0

B:	.word 0, 1, 2, 3
	.word 4, 5, 6, 7
	.word 8, 9, 10, 11
	.word 12, 13, 14, 15

C:	.space 64

	.text
main:
	or $16, $0, $0 
	or $17, $0, $0
	or $18, $0, $0
	or $19, $0, $0
	addi $19, $19, 4

	la $20, C
	
outer:
	beq $16, $19, outer_end
	or $17, $0, $0
	
	
inner:
	beq $17, $19, inner_end
	or $18, $0, $0
	or $21, $0, $0

calc:
	beq $18, $19, calc_end

	add $22, $16, $16
	add $22, $22, $22
	add $22, $22, $22
	add $22, $22, $22

	add $23, $18, $18
	add $23, $23, $23

	add $22, $22, $23
	la $23, A
	add $22, $22, $23
	lw $4,0($22)


	add $22, $18, $18
	add $22, $22, $22
	add $22, $22, $22
	add $22, $22, $22

	add $23, $17, $17
	add $23, $23, $23

	add $22, $22, $23
	la $23, B
	add $22, $22, $23
	lw $5,0($22)

	jal multiply
	add $21, $21, $2
	addi $18, 1
	j calc

calc_end:
	sw $21, 0($20)
	addi $20, $20, 4
	addi $17, $17, 1
	j inner
	
inner_end:
	addi $16, $16, 1
	j outer

outer_end:
	

exit:
	j exit


multiply:
        or $8, $0, $0
        addi $9,$0, 32

        or $2, $0, $0
        or $14, $0, $0
        addi $14, $14, 1
	or $10, $4, $0
	or $11, $5, $0

mul_loop:
        beq $8, $9, mul_loopend
        addi $8, $8, 1

        and $13, $11, $14

        beq $13, $0, skip

        add $2, $2, $10

skip:
        addu $10, $10, $10
        addu $14, $14, $14

        j mul_loop

mul_loopend: jr $31
