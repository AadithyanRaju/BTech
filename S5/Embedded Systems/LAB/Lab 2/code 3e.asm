;Multiplying 2 numbers 12H and 03H
	MVI A,12H
	MOV B,A
	MVI C,03H
	MVI A,00H
Label1: ADD B
	DCR C
	JNZ Label1
	STA 2001H
	HLT