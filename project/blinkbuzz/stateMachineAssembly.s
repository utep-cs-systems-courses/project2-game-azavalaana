	.arch msp430g2553

	.p2align 1,0
	.data
jt:
	.word default
	.word case1
	.word case2
	.word case3
	.word case4
	
	.text
	.global state_advance

state_advance:
	cmp #5, r12 		; compare switch to 5
	jc default 		; jump to default if there is a carry
	add r12, r12 		; make space
	mov jt(r12),r0 		; put r12 into counter

case1:
	call #errorTone
	call #greenLights
	jmp end
case2:
	call #superMarioTheme
	call #dimBlink
	jmp end
case3:
	call #starWarsTheme
	call #redLights
	call #starWarsTheme
	call #greenLights
	call #starWarsTheme
	jmp end
case4:
	call #starSong
	call #bothLights
	jmp end
default:
	jmp end
end:
	ret
