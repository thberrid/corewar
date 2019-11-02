.name "carry"
.comment "Carry tester"

# Setup
#	r1 = 0
#	r2 = 1
#	r3 = '1'
#	r4 = '0'
#	carry = 0
init:	ld %0, r1
		ld %1, r2
		ld %49, r3
		ld %48, r4

start:	and %0, %0, r16
		zjmp %:ok

# if zjump failed (carry == 0)
bad:	aff r4
		and %0, %0, r16
		zjmp %:end

# if zjump success (carry == 1)
ok:		aff r3

# infinite loop to kill the program quickly
end:	zjmp %:end

# label to void memory (zero for indirect val)
void:
