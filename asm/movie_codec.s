	.syntax unified
	.text

	.macro movie_codec_reg name
	.irp n, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	.ifc \name, r\n
	.set .Lreg, \n
	.endif
	.endr
	.ifc \name, sl
	.set .Lreg, 10
	.endif
	.ifc \name, fp
	.set .Lreg, 11
	.endif
	.ifc \name, ip
	.set .Lreg, 12
	.endif
	.endm

	.macro movie_codec_patch kind, rd, rn, row, col
	movie_codec_reg \rd
	.set .Lrd, .Lreg
	movie_codec_reg \rn
	.word 0xEF000000 | (\kind << 20) | (.Lrd << 16) | (.Lreg << 12) | (\row << 4) | \col
	.endm

	.macro str_row rd, rn, row, col
	movie_codec_patch 0, \rd, \rn, \row, \col
	.endm

	.macro ldr_row rd, rn, row, col
	movie_codec_patch 1, \rd, \rn, \row, \col
	.endm

	.macro add_row rd, rn, row, col
	movie_codec_patch 3, \rd, \rn, \row, \col
	.endm

	.macro sub_row rd, rn, row, col
	movie_codec_patch 4, \rd, \rn, \row, \col
	.endm

	.macro mov_blocks rd, dim
	.ifc \dim, width
	movie_codec_patch 2, \rd, r0, 0, 0
	.else
	movie_codec_patch 2, \rd, r0, 0, 1
	.endif
	.endm

	.align 2, 0
	.arm

	.global MovieVideoCodecStart
MovieVideoCodecStart:
	.global MovieVideoCodecConstants
	.type MovieVideoCodecConstants, %object
MovieVideoCodecConstants:
	.space 0x60
	.size MovieVideoCodecConstants, . - MovieVideoCodecConstants

	.global MovieVideoCodecKeyFrame
	.type MovieVideoCodecKeyFrame, %function
MovieVideoCodecKeyFrame:
	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	bl	.L0078
	bl	.L0484
	bl	.L0204
	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	bx	lr
.L0078:
	stmfd	sp!, {r0}
	mov	ip, #31
	mov	r4, #0
.L0084:
	push	{r0, r2, r4}
	mov	r4, #0
.L008C:
	push	{r0, r4}
	adr	r2, MovieVideoCodecConstants
	ldrh	r4, [r3]
	ldrh	r5, [r3, #2]
	and	r8, ip, r4, lsr #10
	and	r9, ip, r5, lsr #10
	add	sl, r9, r8, lsl #1
	add	fp, r8, r9, lsl #1
	ldrb	r6, [r2, sl]
	ldrb	r7, [r2, fp]
	and	r8, ip, r4, lsr #5
	and	r9, ip, r5, lsr #5
	add	sl, r9, r8, lsl #1
	add	fp, r8, r9, lsl #1
	ldrb	r8, [r2, sl]
	ldrb	r9, [r2, fp]
	add	r6, r8, r6, lsl #5
	add	r7, r9, r7, lsl #5
	and	r8, ip, r4
	and	r9, ip, r5
	add	sl, r9, r8, lsl #1
	add	fp, r8, r9, lsl #1
	ldrb	r8, [r2, sl]
	ldrb	r9, [r2, fp]
	add	r6, r8, r6, lsl #5
	add	r7, r9, r7, lsl #5
	ldr	r8, [r3, #4]
	strh	r6, [r3, #4]
	strh	r7, [r3, #6]
	mov	fp, #6
	and	r9, fp, r8, lsl #1
	ldrh	r4, [r3, r9]
	strh	r4, [r0]
	and	r9, fp, r8, lsr #1
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #8]
	and	r9, fp, r8, lsr #3
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #16]
	and	r9, fp, r8, lsr #5
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #24]
	add	r0, r0, r1, lsl #3
	and	r9, fp, r8, lsr #7
	ldrh	r4, [r3, r9]
	strh	r4, [r0]
	and	r9, fp, r8, lsr #9
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #8]
	and	r9, fp, r8, lsr #11
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #16]
	and	r9, fp, r8, lsr #13
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #24]
	add	r0, r0, r1, lsl #3
	and	r9, fp, r8, lsr #15
	ldrh	r4, [r3, r9]
	strh	r4, [r0]
	and	r9, fp, r8, lsr #17
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #8]
	and	r9, fp, r8, lsr #19
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #16]
	and	r9, fp, r8, lsr #21
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #24]
	add	r0, r0, r1, lsl #3
	and	r9, fp, r8, lsr #23
	ldrh	r4, [r3, r9]
	strh	r4, [r0]
	and	r9, fp, r8, lsr #25
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #8]
	and	r9, fp, r8, lsr #27
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #16]
	and	r9, fp, r8, lsr #29
	ldrh	r4, [r3, r9]
	strh	r4, [r0, #24]
	add	r3, r3, #8
	pop	{r0, r4}
	add	r0, r0, #32
	add	r4, r4, #16
	cmp	r4, r1
	bne	.L008C
	pop	{r0, r2, r4}
	add	r0, r0, r1, lsl #5
	add	r4, r4, #16
	cmp	r4, r2
	bne	.L0084
	ldmfd	sp!, {r0}
	mov	pc, lr
.L0204:
	stmfd	sp!, {r0}
	lsl	r4, r1, #2
	add	r4, r4, r1, lsl #1
	ldr	r8, .L06FC
	ldr	r7, .L0700
	mov	r3, #0
.L021C:
	push	{r0, r3}
	mov	r3, #16
	ldr	r9, [r0]
	and	r5, r9, r7
	and	r9, r9, r8
.L0230:
	stmfd	sp!, {r3}
	ldr	sl, [r0, r1, lsl #3]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	str	fp, [r0, r1, lsl #2]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	str	ip, [r0, r1, lsl #1]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	str	ip, [r0, r4]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, r1, lsl #3
	ldr	sl, [r0, r1, lsl #3]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	str	fp, [r0, r1, lsl #2]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	str	ip, [r0, r1, lsl #1]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	str	ip, [r0, r4]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, r1, lsl #3
	ldr	sl, [r0, r1, lsl #3]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	str	fp, [r0, r1, lsl #2]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	str	ip, [r0, r1, lsl #1]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	str	ip, [r0, r4]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, r1, lsl #3
	ldr	sl, [r0, r1, lsl #3]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	str	fp, [r0, r1, lsl #2]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	str	ip, [r0, r1, lsl #1]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	str	ip, [r0, r4]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, r1, lsl #3
	ldmfd	sp!, {r3}
	add	r3, r3, #16
	cmp	r3, r2
	bne	.L0230
	ldr	sl, [r0, r1, lsl #3]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	str	fp, [r0, r1, lsl #2]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	str	ip, [r0, r1, lsl #1]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	str	ip, [r0, r4]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, r1, lsl #3
	ldr	sl, [r0, r1, lsl #3]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	str	fp, [r0, r1, lsl #2]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	str	ip, [r0, r1, lsl #1]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	str	ip, [r0, r4]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, r1, lsl #3
	ldr	sl, [r0, r1, lsl #3]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	str	fp, [r0, r1, lsl #2]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	str	ip, [r0, r1, lsl #1]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	str	ip, [r0, r4]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, r1, lsl #3
	ldr	sl, [r0]
	str	sl, [r0, r1, lsl #1]
	str	sl, [r0, r1, lsl #2]
	str	sl, [r0, r4]
	pop	{r0, r3}
	add	r0, r0, #4
	add	r3, r3, #2
	cmp	r3, r1
	bne	.L021C
	ldmfd	sp!, {r0}
	mov	pc, lr
.L0484:
	stmfd	sp!, {r0}
	ldr	r8, .L06FC
	ldr	r7, .L0700
	mov	r3, #0
.L0494:
	push	{r0, r3}
	mov	r3, #16
	ldrh	r9, [r0]
	and	r5, r9, r7
	and	r9, r9, r8
.L04A8:
	stmfd	sp!, {r3}
	ldrh	sl, [r0, #8]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	strh	fp, [r0, #4]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	strh	ip, [r0, #2]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	strh	ip, [r0, #6]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, #8
	ldrh	sl, [r0, #8]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	strh	fp, [r0, #4]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	strh	ip, [r0, #2]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	strh	ip, [r0, #6]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, #8
	ldrh	sl, [r0, #8]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	strh	fp, [r0, #4]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	strh	ip, [r0, #2]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	strh	ip, [r0, #6]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, #8
	ldrh	sl, [r0, #8]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	strh	fp, [r0, #4]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	strh	ip, [r0, #2]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	strh	ip, [r0, #6]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, #8
	ldmfd	sp!, {r3}
	add	r3, r3, #16
	cmp	r3, r1
	bne	.L04A8
	ldrh	sl, [r0, #8]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	strh	fp, [r0, #4]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	strh	ip, [r0, #2]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	strh	ip, [r0, #6]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, #8
	ldrh	sl, [r0, #8]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	strh	fp, [r0, #4]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	strh	ip, [r0, #2]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	strh	ip, [r0, #6]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, #8
	ldrh	sl, [r0, #8]
	and	r6, sl, r7
	and	sl, sl, r8
	add	fp, r9, sl
	lsr	fp, fp, #1
	orr	fp, fp, r5
	strh	fp, [r0, #4]
	and	fp, fp, r8
	add	ip, r9, fp
	lsr	ip, ip, #1
	orr	ip, ip, r5
	strh	ip, [r0, #2]
	add	ip, fp, sl
	lsr	ip, ip, #1
	orr	ip, ip, r6
	strh	ip, [r0, #6]
	mov	r9, sl
	mov	r5, r6
	add	r0, r0, #8
	ldrh	sl, [r0]
	strh	sl, [r0, #2]
	strh	sl, [r0, #4]
	strh	sl, [r0, #6]
	pop	{r0, r3}
	add	r0, r0, r1, lsl #3
	add	r3, r3, #4
	cmp	r3, r2
	bne	.L0494
	ldmfd	sp!, {r0}
	mov	pc, lr
.L06FC:
	.word 0x7bdf7bdf
.L0700:
	.word 0x04200420
	.size MovieVideoCodecKeyFrame, . - MovieVideoCodecKeyFrame

	.global MovieVideoCodecPostProcess
	.type MovieVideoCodecPostProcess, %function
MovieVideoCodecPostProcess:
	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip}
	mov	r5, r0
	ldr	r8, .L06FC
	ldr	r9, .L0700
	mov	r6, r2
.L0718:
	mov	r3, r5
	sub	r4, r1, #8
.L0720:
	ldrh	sl, [r3, #14]
	ldrh	fp, [r3, #16]
	and	r7, fp, r9
	and	sl, sl, r8
	and	fp, fp, r8
	add	ip, sl, fp
	lsr	ip, ip, #1
	orr	ip, ip, r7
	strh	ip, [r3, #16]
	add	r3, r3, #16
	subs	r4, r4, #8
	bne	.L0720
	add	r5, r5, r1, lsl #1
	subs	r6, r6, #1
	bne	.L0718
	add	r5, r0, r1, lsl #4
	sub	r5, r5, r1, lsl #1
	ldr	r8, .L06FC
	ldr	r9, .L0700
	sub	r4, r2, #8
.L0770:
	mov	r3, r5
	mov	r6, r1
.L0778:
	ldr	sl, [r3]
	ldr	fp, [r3, r1, lsl #1]
	and	r7, fp, r9
	and	sl, sl, r8
	and	fp, fp, r8
	add	fp, sl, fp
	lsr	fp, fp, #1
	orr	fp, fp, r7
	str	fp, [r3, r1, lsl #1]
	add	r3, r3, #4
	subs	r6, r6, #2
	bne	.L0778
	add	r5, r5, r1, lsl #4
	subs	r4, r4, #8
	bne	.L0770
	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip}
	bx	lr
	.size MovieVideoCodecPostProcess, . - MovieVideoCodecPostProcess

	.global MovieVideoCodecEnd
MovieVideoCodecEnd:
	.global MovieDeltaCodecStart
	.type MovieDeltaCodecStart, %function
MovieDeltaCodecStart:
.LRefillBits:
	ldr	r6, [r3], #4
	adcs	r6, r6, r6
	mov	pc, lr
.L07C8:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L0C30
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L08F0
	add	r9, r0, r2
	add	sl, r1, r2
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 2, 2
	ldr_row	ip, r9, 2, 3
	str_row	fp, sl, 2, 2
	str_row	ip, sl, 2, 3
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 3, 2
	ldr_row	ip, r9, 3, 3
	str_row	fp, sl, 3, 2
	str_row	ip, sl, 3, 3
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 4, 1
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 4, 1
	ldr_row	fp, r9, 4, 2
	ldr_row	ip, r9, 4, 3
	str_row	fp, sl, 4, 2
	str_row	ip, sl, 4, 3
	ldr_row	fp, r9, 5, 0
	ldr_row	ip, r9, 5, 1
	str_row	fp, sl, 5, 0
	str_row	ip, sl, 5, 1
	ldr_row	fp, r9, 5, 2
	ldr_row	ip, r9, 5, 3
	str_row	fp, sl, 5, 2
	str_row	ip, sl, 5, 3
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 6, 1
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 6, 1
	ldr_row	fp, r9, 6, 2
	ldr_row	ip, r9, 6, 3
	str_row	fp, sl, 6, 2
	str_row	ip, sl, 6, 3
	ldr_row	fp, r9, 7, 0
	ldr_row	ip, r9, 7, 1
	str_row	fp, sl, 7, 0
	str_row	ip, sl, 7, 1
	ldr_row	fp, r9, 7, 2
	ldr_row	ip, r9, 7, 3
	str_row	fp, sl, 7, 2
	str_row	ip, sl, 7, 3
	ldmfd	sp!, {pc}
.L08F0:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L0A10
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 2, 2
	ldr_row	ip, r9, 2, 3
	str_row	fp, sl, 2, 2
	str_row	ip, sl, 2, 3
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 3, 2
	ldr_row	ip, r9, 3, 3
	str_row	fp, sl, 3, 2
	str_row	ip, sl, 3, 3
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 4, 1
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 4, 1
	ldr_row	fp, r9, 4, 2
	ldr_row	ip, r9, 4, 3
	str_row	fp, sl, 4, 2
	str_row	ip, sl, 4, 3
	ldr_row	fp, r9, 5, 0
	ldr_row	ip, r9, 5, 1
	str_row	fp, sl, 5, 0
	str_row	ip, sl, 5, 1
	ldr_row	fp, r9, 5, 2
	ldr_row	ip, r9, 5, 3
	str_row	fp, sl, 5, 2
	str_row	ip, sl, 5, 3
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 6, 1
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 6, 1
	ldr_row	fp, r9, 6, 2
	ldr_row	ip, r9, 6, 3
	str_row	fp, sl, 6, 2
	str_row	ip, sl, 6, 3
	ldr_row	fp, r9, 7, 0
	ldr_row	ip, r9, 7, 1
	str_row	fp, sl, 7, 0
	str_row	ip, sl, 7, 1
	ldr_row	fp, r9, 7, 2
	ldr_row	ip, r9, 7, 3
	str_row	fp, sl, 7, 2
	str_row	ip, sl, 7, 3
	ldmfd	sp!, {pc}
.L0A10:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 4, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 4, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 4, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 4, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 5, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 5, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 5, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 5, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 6, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 6, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 6, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 6, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 7, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 7, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 7, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 7, 3
	ldmfd	sp!, {pc}
.L0C30:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L0C70
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L0C5C
	bl	.L1154
	add_row	r2, r2, 4, 0
	bl	.L1154
	sub_row	r2, r2, 4, 0
	ldmfd	sp!, {pc}
.L0C5C:
	bl	.L1680
	add	r2, r2, #8
	bl	.L1680
	sub	r2, r2, #8
	ldmfd	sp!, {pc}
.L0C70:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L10C4
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L0E24
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 2, 2
	ldr_row	ip, r9, 2, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 2, 2
	str_row	ip, sl, 2, 3
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 3, 2
	ldr_row	ip, r9, 3, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 3, 2
	str_row	ip, sl, 3, 3
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 4, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 4, 1
	ldr_row	fp, r9, 4, 2
	ldr_row	ip, r9, 4, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 4, 2
	str_row	ip, sl, 4, 3
	ldr_row	fp, r9, 5, 0
	ldr_row	ip, r9, 5, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 5, 0
	str_row	ip, sl, 5, 1
	ldr_row	fp, r9, 5, 2
	ldr_row	ip, r9, 5, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 5, 2
	str_row	ip, sl, 5, 3
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 6, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 6, 1
	ldr_row	fp, r9, 6, 2
	ldr_row	ip, r9, 6, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 6, 2
	str_row	ip, sl, 6, 3
	ldr_row	fp, r9, 7, 0
	ldr_row	ip, r9, 7, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 7, 0
	str_row	ip, sl, 7, 1
	ldr_row	fp, r9, 7, 2
	ldr_row	ip, r9, 7, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 7, 2
	str_row	ip, sl, 7, 3
	ldmfd	sp!, {pc}
.L0E24:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 4, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 4, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 4, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 4, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 5, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 5, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 5, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 5, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 6, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 6, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 6, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 6, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 7, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 7, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 7, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 7, 3
	ldmfd	sp!, {pc}
.L10C4:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str_row	r8, sl, 0, 0
	str_row	r8, sl, 0, 1
	str_row	r8, sl, 0, 2
	str_row	r8, sl, 0, 3
	str_row	r8, sl, 1, 0
	str_row	r8, sl, 1, 1
	str_row	r8, sl, 1, 2
	str_row	r8, sl, 1, 3
	str_row	r8, sl, 2, 0
	str_row	r8, sl, 2, 1
	str_row	r8, sl, 2, 2
	str_row	r8, sl, 2, 3
	str_row	r8, sl, 3, 0
	str_row	r8, sl, 3, 1
	str_row	r8, sl, 3, 2
	str_row	r8, sl, 3, 3
	str_row	r8, sl, 4, 0
	str_row	r8, sl, 4, 1
	str_row	r8, sl, 4, 2
	str_row	r8, sl, 4, 3
	str_row	r8, sl, 5, 0
	str_row	r8, sl, 5, 1
	str_row	r8, sl, 5, 2
	str_row	r8, sl, 5, 3
	str_row	r8, sl, 6, 0
	str_row	r8, sl, 6, 1
	str_row	r8, sl, 6, 2
	str_row	r8, sl, 6, 3
	str_row	r8, sl, 7, 0
	str_row	r8, sl, 7, 1
	str_row	r8, sl, 7, 2
	str_row	r8, sl, 7, 3
	ldmfd	sp!, {pc}
.L1154:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L13AC
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L11FC
	add	r9, r0, r2
	add	sl, r1, r2
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 2, 2
	ldr_row	ip, r9, 2, 3
	str_row	fp, sl, 2, 2
	str_row	ip, sl, 2, 3
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 3, 2
	ldr_row	ip, r9, 3, 3
	str_row	fp, sl, 3, 2
	str_row	ip, sl, 3, 3
	ldmfd	sp!, {pc}
.L11FC:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L129C
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 2, 2
	ldr_row	ip, r9, 2, 3
	str_row	fp, sl, 2, 2
	str_row	ip, sl, 2, 3
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 3, 2
	ldr_row	ip, r9, 3, 3
	str_row	fp, sl, 3, 2
	str_row	ip, sl, 3, 3
	ldmfd	sp!, {pc}
.L129C:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 3
	ldmfd	sp!, {pc}
.L13AC:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L13EC
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L13D8
	bl	.L1BCC
	add_row	r2, r2, 2, 0
	bl	.L1BCC
	sub_row	r2, r2, 2, 0
	ldmfd	sp!, {pc}
.L13D8:
	bl	.L2624
	add	r2, r2, #8
	bl	.L2624
	sub	r2, r2, #8
	ldmfd	sp!, {pc}
.L13EC:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1630
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L14E0
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 2, 2
	ldr_row	ip, r9, 2, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 2, 2
	str_row	ip, sl, 2, 3
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 3, 2
	ldr_row	ip, r9, 3, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 3, 2
	str_row	ip, sl, 3, 3
	ldmfd	sp!, {pc}
.L14E0:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 3
	ldmfd	sp!, {pc}
.L1630:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str_row	r8, sl, 0, 0
	str_row	r8, sl, 0, 1
	str_row	r8, sl, 0, 2
	str_row	r8, sl, 0, 3
	str_row	r8, sl, 1, 0
	str_row	r8, sl, 1, 1
	str_row	r8, sl, 1, 2
	str_row	r8, sl, 1, 3
	str_row	r8, sl, 2, 0
	str_row	r8, sl, 2, 1
	str_row	r8, sl, 2, 2
	str_row	r8, sl, 2, 3
	str_row	r8, sl, 3, 0
	str_row	r8, sl, 3, 1
	str_row	r8, sl, 3, 2
	str_row	r8, sl, 3, 3
	ldmfd	sp!, {pc}
.L1680:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L18E8
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1728
	add	r9, r0, r2
	add	sl, r1, r2
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 4, 1
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 4, 1
	ldr_row	fp, r9, 5, 0
	ldr_row	ip, r9, 5, 1
	str_row	fp, sl, 5, 0
	str_row	ip, sl, 5, 1
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 6, 1
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 6, 1
	ldr_row	fp, r9, 7, 0
	ldr_row	ip, r9, 7, 1
	str_row	fp, sl, 7, 0
	str_row	ip, sl, 7, 1
	ldmfd	sp!, {pc}
.L1728:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L17C8
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 4, 1
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 4, 1
	ldr_row	fp, r9, 5, 0
	ldr_row	ip, r9, 5, 1
	str_row	fp, sl, 5, 0
	str_row	ip, sl, 5, 1
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 6, 1
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 6, 1
	ldr_row	fp, r9, 7, 0
	ldr_row	ip, r9, 7, 1
	str_row	fp, sl, 7, 0
	str_row	ip, sl, 7, 1
	ldmfd	sp!, {pc}
.L17C8:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 4, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 4, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 5, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 5, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 6, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 6, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 7, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 7, 1
	ldmfd	sp!, {pc}
.L18E8:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1928
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1914
	bl	.L2624
	add_row	r2, r2, 4, 0
	bl	.L2624
	sub_row	r2, r2, 4, 0
	ldmfd	sp!, {pc}
.L1914:
	bl	.L1EC8
	add	r2, r2, #4
	bl	.L1EC8
	sub	r2, r2, #4
	ldmfd	sp!, {pc}
.L1928:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1B7C
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L1A1C
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 4, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 4, 1
	ldr_row	fp, r9, 5, 0
	ldr_row	ip, r9, 5, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 5, 0
	str_row	ip, sl, 5, 1
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 6, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 6, 1
	ldr_row	fp, r9, 7, 0
	ldr_row	ip, r9, 7, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 7, 0
	str_row	ip, sl, 7, 1
	ldmfd	sp!, {pc}
.L1A1C:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 4, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 4, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 5, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 5, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 6, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 6, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 7, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 7, 1
	ldmfd	sp!, {pc}
.L1B7C:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str_row	r8, sl, 0, 0
	str_row	r8, sl, 0, 1
	str_row	r8, sl, 1, 0
	str_row	r8, sl, 1, 1
	str_row	r8, sl, 2, 0
	str_row	r8, sl, 2, 1
	str_row	r8, sl, 3, 0
	str_row	r8, sl, 3, 1
	str_row	r8, sl, 4, 0
	str_row	r8, sl, 4, 1
	str_row	r8, sl, 5, 0
	str_row	r8, sl, 5, 1
	str_row	r8, sl, 6, 0
	str_row	r8, sl, 6, 1
	str_row	r8, sl, 7, 0
	str_row	r8, sl, 7, 1
	ldmfd	sp!, {pc}
.L1BCC:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1D1C
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1C34
	add	r9, r0, r2
	add	sl, r1, r2
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldmfd	sp!, {pc}
.L1C34:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L1C94
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldmfd	sp!, {pc}
.L1C94:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 3
	ldmfd	sp!, {pc}
.L1D1C:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1D5C
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1D48
	bl	.L21F4
	add_row	r2, r2, 1, 0
	bl	.L21F4
	sub_row	r2, r2, 1, 0
	ldmfd	sp!, {pc}
.L1D48:
	bl	.L2930
	add	r2, r2, #8
	bl	.L2930
	sub	r2, r2, #8
	ldmfd	sp!, {pc}
.L1D5C:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1E98
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L1DF0
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 0, 2
	ldr_row	ip, r9, 0, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 2
	str_row	ip, sl, 0, 3
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 1, 2
	ldr_row	ip, r9, 1, 3
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 2
	str_row	ip, sl, 1, 3
	ldmfd	sp!, {pc}
.L1DF0:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 3
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 1
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 2
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 3
	ldmfd	sp!, {pc}
.L1E98:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str_row	r8, sl, 0, 0
	str_row	r8, sl, 0, 1
	str_row	r8, sl, 0, 2
	str_row	r8, sl, 0, 3
	str_row	r8, sl, 1, 0
	str_row	r8, sl, 1, 1
	str_row	r8, sl, 1, 2
	str_row	r8, sl, 1, 3
	ldmfd	sp!, {pc}
.L1EC8:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2030
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L1F30
	add	r9, r0, r2
	add	sl, r1, r2
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 1, 0
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 1, 0
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 3, 0
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 3, 0
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 5, 0
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 5, 0
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 7, 0
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 7, 0
	ldmfd	sp!, {pc}
.L1F30:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L1F90
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 1, 0
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 1, 0
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 3, 0
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 3, 0
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 5, 0
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 5, 0
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 7, 0
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 7, 0
	ldmfd	sp!, {pc}
.L1F90:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 4, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 5, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 6, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 7, 0
	ldmfd	sp!, {pc}
.L2030:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2070
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L205C
	bl	.L2B1C
	add_row	r2, r2, 4, 0
	bl	.L2B1C
	sub_row	r2, r2, 4, 0
	ldmfd	sp!, {pc}
.L205C:
	bl	.L23B8
	add	r2, r2, #2
	bl	.L23B8
	sub	r2, r2, #2
	ldmfd	sp!, {pc}
.L2070:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L21C4
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L2104
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 1, 0
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 3, 0
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 3, 0
	ldr_row	fp, r9, 4, 0
	ldr_row	ip, r9, 5, 0
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 4, 0
	str_row	ip, sl, 5, 0
	ldr_row	fp, r9, 6, 0
	ldr_row	ip, r9, 7, 0
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 6, 0
	str_row	ip, sl, 7, 0
	ldmfd	sp!, {pc}
.L2104:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 4, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 5, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 6, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 7, 0
	ldmfd	sp!, {pc}
.L21C4:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str_row	r8, sl, 0, 0
	str_row	r8, sl, 1, 0
	str_row	r8, sl, 2, 0
	str_row	r8, sl, 3, 0
	str_row	r8, sl, 4, 0
	str_row	r8, sl, 5, 0
	str_row	r8, sl, 6, 0
	str_row	r8, sl, 7, 0
	ldmfd	sp!, {pc}
.L21F4:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L22C0
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L223C
	add	r9, r0, r2
	add	sl, r1, r2
	ldr	fp, [r9]
	ldr	ip, [r9, #4]
	str	fp, [sl]
	str	ip, [sl, #4]
	ldr	fp, [r9, #8]
	ldr	ip, [r9, #12]
	str	fp, [sl, #8]
	str	ip, [sl, #12]
	ldmfd	sp!, {pc}
.L223C:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L227C
	ldr	fp, [r9]
	ldr	ip, [r9, #4]
	str	fp, [sl]
	str	ip, [sl, #4]
	ldr	fp, [r9, #8]
	ldr	ip, [r9, #12]
	str	fp, [sl, #8]
	str	ip, [sl, #12]
	ldmfd	sp!, {pc}
.L227C:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str	fp, [sl]
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str	fp, [sl, #4]
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	str	fp, [sl, #8]
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	str	fp, [sl, #12]
	ldmfd	sp!, {pc}
.L22C0:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L22E0
	bl	.L2D18
	add	r2, r2, #8
	bl	.L2D18
	sub	r2, r2, #8
	ldmfd	sp!, {pc}
.L22E0:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2398
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L2344
	ldr	fp, [r9]
	ldr	ip, [r9, #4]
	add	fp, fp, r8
	add	ip, ip, r8
	str	fp, [sl]
	str	ip, [sl, #4]
	ldr	fp, [r9, #8]
	ldr	ip, [r9, #12]
	add	fp, fp, r8
	add	ip, ip, r8
	str	fp, [sl, #8]
	str	ip, [sl, #12]
	ldmfd	sp!, {pc}
.L2344:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str	fp, [sl]
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str	fp, [sl, #4]
	ldrh	fp, [r9, #8]
	ldrh	ip, [r9, #10]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str	fp, [sl, #8]
	ldrh	fp, [r9, #12]
	ldrh	ip, [r9, #14]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str	fp, [sl, #12]
	ldmfd	sp!, {pc}
.L2398:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str	r8, [sl]
	str	r8, [sl, #4]
	str	r8, [sl, #8]
	str	r8, [sl, #12]
	ldmfd	sp!, {pc}
.L23B8:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L24F0
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L245C
	add	r9, r0, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L245C:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L24F0:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2510
	bl	.L2E54
	add_row	r2, r2, 4, 0
	bl	.L2E54
	sub_row	r2, r2, 4, 0
	ldmfd	sp!, {pc}
.L2510:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L25D8
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L25D8:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	ldmfd	sp!, {pc}
.L2624:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L277C
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L268C
	add	r9, r0, r2
	add	sl, r1, r2
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldmfd	sp!, {pc}
.L268C:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L26EC
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldmfd	sp!, {pc}
.L26EC:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 1
	ldmfd	sp!, {pc}
.L277C:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L27BC
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L27A8
	bl	.L2930
	add_row	r2, r2, 2, 0
	bl	.L2930
	sub_row	r2, r2, 2, 0
	ldmfd	sp!, {pc}
.L27A8:
	bl	.L2B1C
	add	r2, r2, #4
	bl	.L2B1C
	sub	r2, r2, #4
	ldmfd	sp!, {pc}
.L27BC:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2900
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L2850
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 2, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 2, 1
	ldr_row	fp, r9, 3, 0
	ldr_row	ip, r9, 3, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 3, 0
	str_row	ip, sl, 3, 1
	ldmfd	sp!, {pc}
.L2850:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 1
	ldmfd	sp!, {pc}
.L2900:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str_row	r8, sl, 0, 0
	str_row	r8, sl, 0, 1
	str_row	r8, sl, 1, 0
	str_row	r8, sl, 1, 1
	str_row	r8, sl, 2, 0
	str_row	r8, sl, 2, 1
	str_row	r8, sl, 3, 0
	str_row	r8, sl, 3, 1
	ldmfd	sp!, {pc}
.L2930:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2A00
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2978
	add	r9, r0, r2
	add	sl, r1, r2
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldmfd	sp!, {pc}
.L2978:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L29B8
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldmfd	sp!, {pc}
.L29B8:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 1
	ldmfd	sp!, {pc}
.L2A00:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2A40
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2A2C
	bl	.L2D18
	add_row	r2, r2, 1, 0
	bl	.L2D18
	sub_row	r2, r2, 1, 0
	ldmfd	sp!, {pc}
.L2A2C:
	bl	.L2FD0
	add	r2, r2, #4
	bl	.L2FD0
	sub	r2, r2, #4
	ldmfd	sp!, {pc}
.L2A40:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2AFC
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L2AA4
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 0, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 0, 1
	ldr_row	fp, r9, 1, 0
	ldr_row	ip, r9, 1, 1
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 1, 0
	str_row	ip, sl, 1, 1
	ldmfd	sp!, {pc}
.L2AA4:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 1
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 1
	ldmfd	sp!, {pc}
.L2AFC:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str_row	r8, sl, 0, 0
	str_row	r8, sl, 0, 1
	str_row	r8, sl, 1, 0
	str_row	r8, sl, 1, 1
	ldmfd	sp!, {pc}
.L2B1C:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2BF4
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2B64
	add	r9, r0, r2
	add	sl, r1, r2
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 1, 0
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 1, 0
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 3, 0
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 3, 0
	ldmfd	sp!, {pc}
.L2B64:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L2BA4
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 1, 0
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 1, 0
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 3, 0
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 3, 0
	ldmfd	sp!, {pc}
.L2BA4:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 2, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 3, 0
	ldmfd	sp!, {pc}
.L2BF4:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2C34
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2C20
	bl	.L2FD0
	add_row	r2, r2, 2, 0
	bl	.L2FD0
	sub_row	r2, r2, 2, 0
	ldmfd	sp!, {pc}
.L2C20:
	bl	.L2E54
	add	r2, r2, #2
	bl	.L2E54
	sub	r2, r2, #2
	ldmfd	sp!, {pc}
.L2C34:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2CF8
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L2C98
	ldr_row	fp, r9, 0, 0
	ldr_row	ip, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 0, 0
	str_row	ip, sl, 1, 0
	ldr_row	fp, r9, 2, 0
	ldr_row	ip, r9, 3, 0
	add	fp, fp, r8
	add	ip, ip, r8
	str_row	fp, sl, 2, 0
	str_row	ip, sl, 3, 0
	ldmfd	sp!, {pc}
.L2C98:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 2, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 3, 0
	ldmfd	sp!, {pc}
.L2CF8:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str_row	r8, sl, 0, 0
	str_row	r8, sl, 1, 0
	str_row	r8, sl, 2, 0
	str_row	r8, sl, 3, 0
	ldmfd	sp!, {pc}
.L2D18:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2DA4
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2D50
	add	r9, r0, r2
	add	sl, r1, r2
	ldr	fp, [r9]
	ldr	ip, [r9, #4]
	str	fp, [sl]
	str	ip, [sl, #4]
	ldmfd	sp!, {pc}
.L2D50:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L2D80
	ldr	fp, [r9]
	ldr	ip, [r9, #4]
	str	fp, [sl]
	str	ip, [sl, #4]
	ldmfd	sp!, {pc}
.L2D80:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str	fp, [sl]
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	str	fp, [sl, #4]
	ldmfd	sp!, {pc}
.L2DA4:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2DC4
	bl	.L3134
	add	r2, r2, #4
	bl	.L3134
	sub	r2, r2, #4
	ldmfd	sp!, {pc}
.L2DC4:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2E3C
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L2E10
	ldr	fp, [r9]
	ldr	ip, [r9, #4]
	add	fp, fp, r8
	add	ip, ip, r8
	str	fp, [sl]
	str	ip, [sl, #4]
	ldmfd	sp!, {pc}
.L2E10:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str	fp, [sl]
	ldrh	fp, [r9, #4]
	ldrh	ip, [r9, #6]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str	fp, [sl, #4]
	ldmfd	sp!, {pc}
.L2E3C:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str	r8, [sl]
	str	r8, [sl, #4]
	ldmfd	sp!, {pc}
.L2E54:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2F0C
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2EB8
	add	r9, r0, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L2EB8:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L2F0C:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2F2C
	bl	.L3230
	add_row	r2, r2, 2, 0
	bl	.L3230
	sub_row	r2, r2, 2, 0
	ldmfd	sp!, {pc}
.L2F2C:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L2FA4
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	add_row	sl, sl, 1, 0
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add_row	r9, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L2FA4:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	ldmfd	sp!, {pc}
.L2FD0:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L3060
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L3008
	add	r9, r0, r2
	add	sl, r1, r2
	ldr	fp, [r9]
	ldr_row	ip, r9, 1, 0
	str	fp, [sl]
	str_row	ip, sl, 1, 0
	ldmfd	sp!, {pc}
.L3008:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L3038
	ldr	fp, [r9]
	ldr_row	ip, r9, 1, 0
	str	fp, [sl]
	str_row	ip, sl, 1, 0
	ldmfd	sp!, {pc}
.L3038:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 0, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str_row	fp, sl, 1, 0
	ldmfd	sp!, {pc}
.L3060:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L30A0
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L308C
	bl	.L3134
	add_row	r2, r2, 1, 0
	bl	.L3134
	sub_row	r2, r2, 1, 0
	ldmfd	sp!, {pc}
.L308C:
	bl	.L3230
	add	r2, r2, #2
	bl	.L3230
	sub	r2, r2, #2
	ldmfd	sp!, {pc}
.L30A0:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L311C
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L30EC
	ldr	fp, [r9]
	ldr_row	ip, r9, 1, 0
	add	fp, fp, r8
	add	ip, ip, r8
	str	fp, [sl]
	str_row	ip, sl, 1, 0
	ldmfd	sp!, {pc}
.L30EC:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 0, 0
	add_row	r9, r9, 1, 0
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str_row	fp, sl, 1, 0
	ldmfd	sp!, {pc}
.L311C:
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str	r8, [sl]
	str_row	r8, sl, 1, 0
	ldmfd	sp!, {pc}
.L3134:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L31A0
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L3164
	add	r9, r0, r2
	add	sl, r1, r2
	ldr	fp, [r9]
	str	fp, [sl]
	ldmfd	sp!, {pc}
.L3164:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L318C
	ldr	fp, [r9]
	str	fp, [sl]
	ldmfd	sp!, {pc}
.L318C:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	str	fp, [sl]
	ldmfd	sp!, {pc}
.L31A0:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L31F8
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ands	fp, r9, #3
	bne	.L31E0
	ldr	fp, [r9]
	add	fp, fp, r8
	str	fp, [sl]
	ldmfd	sp!, {pc}
.L31E0:
	ldrh	fp, [r9]
	ldrh	ip, [r9, #2]
	orr	fp, fp, ip, lsl #16
	add	fp, fp, r8
	str	fp, [sl]
	ldmfd	sp!, {pc}
.L31F8:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L3218
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	str	r8, [sl]
	ldmfd	sp!, {pc}
.L3218:
	ldrh	r8, [r4], #2
	add	sl, r1, r2
	strh	r8, [sl]
	ldrh	r8, [r4], #2
	strh	r8, [sl, #2]
	ldmfd	sp!, {pc}
.L3230:
	stmfd	sp!, {lr}
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L32A0
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L3270
	add	r9, r0, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L3270:
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L32A0:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L32EC
	ldrb	r9, [r5], #1
	ldr	r9, [r7, r9, lsl #2]
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	r9, r9, r0
	add	r9, r9, r2
	add	sl, r1, r2
	ldrh	fp, [r9]
	add_row	r9, r9, 1, 0
	ldrh	ip, [r9]
	add	fp, fp, r8
	add	ip, ip, r8
	strh	fp, [sl]
	add_row	sl, sl, 1, 0
	strh	ip, [sl]
	ldmfd	sp!, {pc}
.L32EC:
	adds	r6, r6, r6
	bleq	.LRefillBits
	bcs	.L3314
	ldrh	r8, [r4], #2
	orr	r8, r8, r8, lsl #16
	add	sl, r1, r2
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	strh	r8, [sl]
	ldmfd	sp!, {pc}
.L3314:
	ldrh	r8, [r4], #2
	add	sl, r1, r2
	strh	r8, [sl]
	add_row	sl, sl, 1, 0
	ldrh	r8, [r4], #2
	strh	r8, [sl]
	ldmfd	sp!, {pc}
	.size MovieDeltaCodecStart, . - MovieDeltaCodecStart

	.global MovieDeltaCodecOffsets
	.type MovieDeltaCodecOffsets, %object
MovieDeltaCodecOffsets:
	.space 0x400
	.size MovieDeltaCodecOffsets, . - MovieDeltaCodecOffsets

	.global MovieDeltaCodecDecode
	.type MovieDeltaCodecDecode, %function
MovieDeltaCodecDecode:
	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	add	r3, r2, #4
	adr	r7, MovieDeltaCodecOffsets
	mov	r6, #-2147483648
	ldrh	r4, [r2]
	add	r4, r4, r3
	ldrh	r5, [r2, #2]
	add	r5, r5, r4
	mov	r2, #0
	mov_blocks	ip, height
.L3758:
	stmfd	sp!, {ip}
	mov_blocks	fp, width
.L3760:
	stmfd	sp!, {fp}
	bl	.L07C8
	ldmfd	sp!, {fp}
	add	r2, r2, #16
	subs	fp, fp, #1
	bne	.L3760
	add_row	r2, r2, 7, 0
	ldmfd	sp!, {ip}
	subs	ip, ip, #1
	bne	.L3758
	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	bx	lr
	.size MovieDeltaCodecDecode, . - MovieDeltaCodecDecode

	.global MovieAudioCodecStart
MovieAudioCodecStart:
	.global MovieAudioCodecAdpcmSteps
	.type MovieAudioCodecAdpcmSteps, %object
MovieAudioCodecAdpcmSteps:
	.space 0x2c8
	.size MovieAudioCodecAdpcmSteps, . - MovieAudioCodecAdpcmSteps

	.global MovieAudioCodecAdpcm
	.type MovieAudioCodecAdpcm, %function
MovieAudioCodecAdpcm:
	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip}
	ldrsh	r6, [r0], #2
	ldrh	r7, [r0], #2
	lsl	r7, r7, #2
	mov	r3, #16
	ldr	r4, [r0], #4
	adr	r8, MovieAudioCodecAdpcmSteps
.L3A74:
	and	r5, r4, #3
	add	r9, r5, r7
	add	r9, r8, r9, lsl #1
	ldrsh	sl, [r9]
	add	r6, r6, sl
	asr	r9, r6, #8
	strb	r9, [r1], #1
	ands	r5, r5, #1
	addne	r7, r7, #4
	subeq	r7, r7, #4
	cmp	r7, #0
	movmi	r7, #0
	cmp	r7, #352
	movgt	r7, #352
	subs	r3, r3, #1
	lsrne	r4, r4, #2
	moveq	r3, #16
	ldreq	r4, [r0], #4
	subeq	r2, r2, #32
	cmp	r2, #0
	bne	.L3A74
	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip}
	bx	lr
	.size MovieAudioCodecAdpcm, . - MovieAudioCodecAdpcm

	.global MovieAudioCodecPcm16
	.type MovieAudioCodecPcm16, %function
MovieAudioCodecPcm16:
	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip}
.L3AD4:
	ldrsh	r6, [r0], #2
	asr	r6, r6, #8
	strb	r6, [r1], #1
	subs	r2, r2, #2
	bne	.L3AD4
	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip}
	bx	lr
	.size MovieAudioCodecPcm16, . - MovieAudioCodecPcm16

	.global MovieAudioCodecNull
	.type MovieAudioCodecNull, %function
MovieAudioCodecNull:
	push	{r4, r5, r6, r7, r8, r9, sl, fp, ip}
	pop	{r4, r5, r6, r7, r8, r9, sl, fp, ip}
	bx	lr
	.size MovieAudioCodecNull, . - MovieAudioCodecNull

	.global MovieAudioCodecEnd
MovieAudioCodecEnd:
