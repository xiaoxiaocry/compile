.data
	_ret: .asciiz "\n"
	a: .word 0
	.globl main
.text
read:
	li $v0, 5
	syscall
	jr $ra

write:
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, _ret
	syscall
	move $v0, $0
	jr $ra


main:
la $t6,a




li $t0, 0
sw $t0 44($t6)


label0:

lw $t0 44($t6)
li $t2, 10
blt $t0, $t2, label1

j label2

label1:

lw $t2 44($t6)
li $t1 10
sub $t0, $t1, $t2
sw $t0 48($t6)


lw $t1 48($t6)
li $t2 2
mul $t0, $t1, $t2
sw $t0 52($t6)


lw $t1 44($t6)
li $t2 1
mul $t0, $t1, $t2
sw $t0 56($t6)


lw $t2 56($t6)
addi $t0, $t2, 0
sw $t0 60($t6)


lw $t1 60($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 60($t6)


addi $t1,$t6,4
lw $t2 60($t6)
add $t0, $t1, $t2
sw $t0 60($t6)


lw $t0 60($t6)
lw $t1 52($t6)
sw $t1, 0($t0)

lw $t1 44($t6)
addi $t0, $t1, 1
sw $t0 44($t6)


j label0

label2:

li $t0, 5
sw $t0 64($t6)


li $t0, 2
sw $t0 68($t6)


lw $t1 68($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 68($t6)


addi $t1,$t6,4
lw $t2 68($t6)
add $t0, $t1, $t2
sw $t0 68($t6)


lw $t0 68($t6)
lw $t1 64($t6)
sw $t1, 0($t0)

li $t0, 16
sw $t0 72($t6)


li $t0, 7
sw $t0 76($t6)


lw $t1 76($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 76($t6)


addi $t1,$t6,4
lw $t2 76($t6)
add $t0, $t1, $t2
sw $t0 76($t6)


lw $t0 76($t6)
lw $t1 72($t6)
sw $t1, 0($t0)

li $t0, 15
sw $t0 80($t6)


li $t0, 9
sw $t0 84($t6)


lw $t1 84($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 84($t6)


addi $t1,$t6,4
lw $t2 84($t6)
add $t0, $t1, $t2
sw $t0 84($t6)


lw $t0 84($t6)
lw $t1 80($t6)
sw $t1, 0($t0)

li $t0, 1
sw $t0 88($t6)


label3:

lw $t0 88($t6)
li $t2, 10
blt $t0, $t2, label4

j label5

label4:

lw $t1 88($t6)
li $t2 1
mul $t0, $t1, $t2
sw $t0 92($t6)


lw $t2 92($t6)
addi $t0, $t2, 0
sw $t0 96($t6)


lw $t1 96($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 96($t6)


addi $t1,$t6,4
lw $t2 96($t6)
add $t0, $t1, $t2
sw $t0 96($t6)


lw $t1 96($t6)
lw $t0, 0($t1)
sw $t0 100($t6)


lw $t1 88($t6)
addi $t0, $t1, -1
sw $t0 104($t6)


label6:

lw $t0 104($t6)
li $t2, 0
bge $t0, $t2, label9

j label8

label9:

lw $t1 104($t6)
li $t2 1
mul $t0, $t1, $t2
sw $t0 108($t6)


lw $t2 108($t6)
addi $t0, $t2, 0
sw $t0 112($t6)


lw $t1 112($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 112($t6)


addi $t1,$t6,4
lw $t2 112($t6)
add $t0, $t1, $t2
sw $t0 112($t6)


lw $t1 112($t6)
lw $t0, 0($t1)
sw $t0 116($t6)


lw $t0 116($t6)
lw $t1 100($t6)
bgt $t0, $t1, label7

j label8

label7:

lw $t1 104($t6)
li $t2 1
mul $t0, $t1, $t2
sw $t0 120($t6)


lw $t2 120($t6)
addi $t0, $t2, 0
sw $t0 124($t6)


lw $t1 124($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 124($t6)


addi $t1,$t6,4
lw $t2 124($t6)
add $t0, $t1, $t2
sw $t0 124($t6)


lw $t1 124($t6)
lw $t0, 0($t1)
sw $t0 128($t6)


lw $t1 104($t6)
addi $t0, $t1, 1
sw $t0 132($t6)


lw $t1 132($t6)
li $t2 1
mul $t0, $t1, $t2
sw $t0 136($t6)


lw $t2 136($t6)
addi $t0, $t2, 0
sw $t0 140($t6)


lw $t1 140($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 140($t6)


addi $t1,$t6,4
lw $t2 140($t6)
add $t0, $t1, $t2
sw $t0 140($t6)


lw $t0 140($t6)
lw $t1 128($t6)
sw $t1, 0($t0)

lw $t1 104($t6)
addi $t0, $t1, -1
sw $t0 104($t6)


j label6

label8:

lw $t1 88($t6)
addi $t0, $t1, -1
sw $t0 144($t6)


lw $t0 104($t6)
lw $t1 144($t6)
bne $t0, $t1, label10

j label11

label10:

lw $t1 100($t6)
move $t0, $t1
sw $t0 148($t6)


lw $t1 104($t6)
addi $t0, $t1, 1
sw $t0 152($t6)


lw $t1 152($t6)
li $t2 1
mul $t0, $t1, $t2
sw $t0 156($t6)


lw $t2 156($t6)
addi $t0, $t2, 0
sw $t0 160($t6)


lw $t1 160($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 160($t6)


addi $t1,$t6,4
lw $t2 160($t6)
add $t0, $t1, $t2
sw $t0 160($t6)


lw $t0 160($t6)
lw $t1 148($t6)
sw $t1, 0($t0)

label11:

lw $t1 88($t6)
addi $t0, $t1, 1
sw $t0 88($t6)


j label3

label5:

li $t0, 0
sw $t0 88($t6)


label12:

lw $t0 88($t6)
li $t2, 10
blt $t0, $t2, label13

j label14

label13:

lw $t1 88($t6)
li $t2 1
mul $t0, $t1, $t2
sw $t0 164($t6)


lw $t2 164($t6)
addi $t0, $t2, 0
sw $t0 168($t6)


lw $t1 168($t6)
li $t2 4
mul $t0, $t1, $t2
sw $t0 168($t6)


addi $t1,$t6,4
lw $t2 168($t6)
add $t0, $t1, $t2
sw $t0 168($t6)


lw $t1 168($t6)
lw $t0, 0($t1)
sw $t0 172($t6)


lw $t0,172($t6)
move $a0, $t0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, 4

lw $t1 88($t6)
addi $t0, $t1, 1
sw $t0 88($t6)


j label12

label14:

li $t2, 0
move $v0, $t2
jr $ra

