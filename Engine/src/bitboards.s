	.file	"bitboards.c"
	.text
	.globl	__occupied45R_shift__
	.data
	.align 32
	.type	__occupied45R_shift__, @object
	.size	__occupied45R_shift__, 64
__occupied45R_shift__:
	.string	"#\033\024\016\t\005\002"
	.ascii	"*\"\032\023\r\b\004\0010)!\031\022\f\007\0035/( \030\021\013"
	.ascii	"\00694.'\037\027\020\n<83-&\036\026\017>;72,%\035\025?=:61+$"
	.ascii	"\034"
	.globl	__occupied45R_diagonalLength__
	.section	.rodata
	.align 32
	.type	__occupied45R_diagonalLength__, @object
	.size	__occupied45R_diagonalLength__, 64
__occupied45R_diagonalLength__:
	.ascii	"\b\007\006\005\004\003\002\001\007\b\007\006\005\004\003\002"
	.ascii	"\006\007\b\007\006\005\004\003\005\006\007\b\007\006\005\004"
	.ascii	"\004\005\006\007\b\007\006\005\003\004\005\006\007\b\007\006"
	.ascii	"\002\003\004\005\006\007\b\007\001\002\003\004\005\006\007\b"
	.globl	__occupied45R_skip__
	.align 32
	.type	__occupied45R_skip__, @object
	.size	__occupied45R_skip__, 64
__occupied45R_skip__:
	.string	"\034\025\017\n\006\003\001"
	.ascii	"$\034\025\017\n\006\003\001+$\034\025\017\n\006\0031+$\034\025"
	.ascii	"\017\n\00661+$\034\025\017\n:61+$\034\025\017=:61+$\034\025?"
	.ascii	"=:61+$\034"
	.globl	__occupied45L_shift__
	.data
	.align 32
	.type	__occupied45L_shift__, @object
	.size	__occupied45L_shift__, 64
__occupied45L_shift__:
	.string	""
	.ascii	"\002\005\t\016\024\033#\001\004\b\r\023\032\"*\003\007\f\022"
	.ascii	"\031!)0\006\013\021\030 (/5\n\020\027\037'.49\017\026\036&-3"
	.ascii	"8<\025\035%,27;>\034$+16:=?"
	.globl	__occupied45L_diagonalLength__
	.section	.rodata
	.align 32
	.type	__occupied45L_diagonalLength__, @object
	.size	__occupied45L_diagonalLength__, 64
__occupied45L_diagonalLength__:
	.ascii	"\001\002\003\004\005\006\007\b\002\003\004\005\006\007\b\007"
	.ascii	"\003\004\005\006\007\b\007\006\004\005\006\007\b\007\006\005"
	.ascii	"\005\006\007\b\007\006\005\004\006\007\b\007\006\005\004\003"
	.ascii	"\007\b\007\006\005\004\003\002\b\007\006\005\004\003\002\001"
	.globl	__occupied45L_skip__
	.data
	.align 32
	.type	__occupied45L_skip__, @object
	.size	__occupied45L_skip__, 64
__occupied45L_skip__:
	.string	""
	.ascii	"\001\003\006\n\017\025\034\001\003\006\n\017\025\034$\003\006"
	.ascii	"\n\017\025\034$+\006\n\017\025\034$+1\n\017\025\034$+16\017\025"
	.ascii	"\034$+16:\025\034$+16:=\034$+16:=?"
	.globl	__occupied90L_shift__
	.section	.rodata
	.align 32
	.type	__occupied90L_shift__, @object
	.size	__occupied90L_shift__, 64
__occupied90L_shift__:
	.string	"\007\017\027\037'/7?\006\016\026\036&.6>\005\r\025\035%-5=\004\f\024\034$,4<\003\013\023\033#+3;\002\n\022\032\"*2:\001\t\021\031!)19"
	.ascii	"\b\020\030 (08"
	.globl	__occupied90L_skip__
	.data
	.align 32
	.type	__occupied90L_skip__, @object
	.size	__occupied90L_skip__, 64
__occupied90L_skip__:
	.string	""
	.string	"\b\020\030 (08"
	.string	"\b\020\030 (08"
	.string	"\b\020\030 (08"
	.string	"\b\020\030 (08"
	.string	"\b\020\030 (08"
	.string	"\b\020\030 (08"
	.string	"\b\020\030 (08"
	.ascii	"\b\020\030 (08"
	.globl	__occupied_skip__
	.align 32
	.type	__occupied_skip__, @object
	.size	__occupied_skip__, 64
__occupied_skip__:
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.ascii	"\b\b\b\b\b\b\b\b\020\020\020\020\020\020\020\020\030\030\030"
	.ascii	"\030\030\030\030\030        ((((((((0000000088888888"
	.globl	__kingAttack__
	.bss
	.align 32
	.type	__kingAttack__, @object
	.size	__kingAttack__, 512
__kingAttack__:
	.zero	512
	.globl	__knightAttack__
	.align 32
	.type	__knightAttack__, @object
	.size	__knightAttack__, 512
__knightAttack__:
	.zero	512
	.globl	__pawnAttack__
	.align 32
	.type	__pawnAttack__, @object
	.size	__pawnAttack__, 1024
__pawnAttack__:
	.zero	1024
	.globl	__attackRank__
	.align 32
	.type	__attackRank__, @object
	.size	__attackRank__, 131072
__attackRank__:
	.zero	131072
	.globl	__attackFile__
	.align 32
	.type	__attackFile__, @object
	.size	__attackFile__, 131072
__attackFile__:
	.zero	131072
	.globl	__attackRightDiagonal__
	.align 32
	.type	__attackRightDiagonal__, @object
	.size	__attackRightDiagonal__, 131072
__attackRightDiagonal__:
	.zero	131072
	.globl	__attackLeftDiagonal__
	.align 32
	.type	__attackLeftDiagonal__, @object
	.size	__attackLeftDiagonal__, 131072
__attackLeftDiagonal__:
	.zero	131072
	.globl	__ranks__
	.align 32
	.type	__ranks__, @object
	.size	__ranks__, 64
__ranks__:
	.zero	64
	.globl	__files__
	.align 32
	.type	__files__, @object
	.size	__files__, 64
__files__:
	.zero	64
	.text
	.globl	getBitboardForPiece
	.type	getBitboardForPiece, @function
getBitboardForPiece:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	subl	$66, %eax
	cmpl	$48, %eax
	ja	.L2
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L4(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L4(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L15-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L14-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L13-.L4
	.long	.L2-.L4
	.long	.L12-.L4
	.long	.L11-.L4
	.long	.L10-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L9-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L8-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L7-.L4
	.long	.L2-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L14:
	movq	-8(%rbp), %rax
	addq	$80, %rax
	jmp	.L16
.L11:
	movq	-8(%rbp), %rax
	addq	$64, %rax
	jmp	.L16
.L10:
	movq	-8(%rbp), %rax
	addq	$48, %rax
	jmp	.L16
.L15:
	movq	-8(%rbp), %rax
	addq	$32, %rax
	jmp	.L16
.L13:
	movq	-8(%rbp), %rax
	addq	$40, %rax
	jmp	.L16
.L12:
	movq	-8(%rbp), %rax
	jmp	.L16
.L8:
	movq	-8(%rbp), %rax
	addq	$88, %rax
	jmp	.L16
.L5:
	movq	-8(%rbp), %rax
	addq	$72, %rax
	jmp	.L16
.L3:
	movq	-8(%rbp), %rax
	addq	$56, %rax
	jmp	.L16
.L9:
	movq	-8(%rbp), %rax
	addq	$40, %rax
	jmp	.L16
.L7:
	movq	-8(%rbp), %rax
	addq	$40, %rax
	jmp	.L16
.L6:
	movq	-8(%rbp), %rax
	addq	$8, %rax
	jmp	.L16
.L2:
	movl	$0, %eax
.L16:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	getBitboardForPiece, .-getBitboardForPiece
	.globl	firstBit
	.type	firstBit, @function
firstBit:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	rep bsfq	%rax, %rax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	movl	$1, %esi
	movl	%eax, %ecx
	salq	%cl, %rsi
	movq	%rsi, %rax
	notq	%rax
	andq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	firstBit, .-firstBit
	.globl	parsePiece
	.type	parsePiece, @function
parsePiece:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	movsbl	-4(%rbp), %eax
	subl	$66, %eax
	cmpl	$48, %eax
	ja	.L20
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L22(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L22(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L22:
	.long	.L33-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L32-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L31-.L22
	.long	.L20-.L22
	.long	.L30-.L22
	.long	.L29-.L22
	.long	.L28-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L27-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L26-.L22
	.long	.L20-.L22
	.long	.L20-.L22
	.long	.L25-.L22
	.long	.L20-.L22
	.long	.L24-.L22
	.long	.L23-.L22
	.long	.L21-.L22
	.text
.L32:
	movl	$75, %eax
	jmp	.L34
.L29:
	movl	$81, %eax
	jmp	.L34
.L28:
	movl	$82, %eax
	jmp	.L34
.L33:
	movl	$66, %eax
	jmp	.L34
.L31:
	movl	$78, %eax
	jmp	.L34
.L30:
	movl	$80, %eax
	jmp	.L34
.L26:
	movl	$107, %eax
	jmp	.L34
.L23:
	movl	$113, %eax
	jmp	.L34
.L21:
	movl	$114, %eax
	jmp	.L34
.L27:
	movl	$98, %eax
	jmp	.L34
.L25:
	movl	$110, %eax
	jmp	.L34
.L24:
	movl	$112, %eax
	jmp	.L34
.L20:
	movl	$32, %eax
.L34:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	parsePiece, .-parsePiece
	.globl	getColorByPiece
	.type	getColorByPiece, @function
getColorByPiece:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$32, -4(%rbp)
	jne	.L36
	movl	$2, %eax
	jmp	.L37
.L36:
	cmpl	$80, -4(%rbp)
	jbe	.L38
	movl	$0, %eax
	jmp	.L37
.L38:
	movl	$1, %eax
.L37:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	getColorByPiece, .-getColorByPiece
	.globl	initBitboards
	.type	initBitboards, @function
initBitboards:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 24(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 32(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 40(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 48(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 56(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 64(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 72(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 80(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 88(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 96(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 104(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 112(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 120(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 128(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 136(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	initBitboards, .-initBitboards
	.globl	setBitOnBitboard
	.type	setBitOnBitboard, @function
setBitOnBitboard:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	orq	-8(%rbp), %rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	setBitOnBitboard, .-setBitOnBitboard
	.globl	clearBitOnBitboard
	.type	clearBitOnBitboard, @function
clearBitOnBitboard:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	notq	%rax
	andq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	clearBitOnBitboard, .-clearBitOnBitboard
	.globl	playMoveOnBitboards
	.type	playMoveOnBitboards, @function
playMoveOnBitboards:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$72, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movl	%edx, -68(%rbp)
	movl	-68(%rbp), %edx
	movq	-56(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	getBitboardForPiece
	movq	%rax, -40(%rbp)
	movq	-64(%rbp), %rax
	movl	(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	setBitOnBitboard
	movq	-64(%rbp), %rax
	movl	4(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	clearBitOnBitboard
	movl	-68(%rbp), %eax
	movl	%eax, %edi
	call	getColorByPiece
	cmpl	$1, %eax
	jne	.L43
	movq	-56(%rbp), %rax
	addq	$104, %rax
	jmp	.L44
.L43:
	movq	-56(%rbp), %rax
	addq	$96, %rax
.L44:
	movq	%rax, -32(%rbp)
	movq	-64(%rbp), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	setBitOnBitboard
	movq	-64(%rbp), %rax
	movl	4(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	clearBitOnBitboard
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	__occupied90L_shift__(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, %edx
	leaq	__occupied90L_shift__(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -44(%rbp)
	movq	-56(%rbp), %rax
	addq	$120, %rax
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	setBitOnBitboard
	movq	-64(%rbp), %rax
	movl	4(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	clearBitOnBitboard
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	__occupied45L_shift__(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, %edx
	leaq	__occupied45L_shift__(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -44(%rbp)
	movq	-56(%rbp), %rax
	subq	$-128, %rax
	movq	%rax, -16(%rbp)
	movl	-44(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	setBitOnBitboard
	movl	-48(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	clearBitOnBitboard
	movq	-64(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	__occupied45R_shift__(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, %edx
	leaq	__occupied45R_shift__(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, -44(%rbp)
	movq	-56(%rbp), %rax
	addq	$136, %rax
	movq	%rax, -8(%rbp)
	movl	-44(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	setBitOnBitboard
	movl	-48(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	clearBitOnBitboard
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	playMoveOnBitboards, .-playMoveOnBitboards
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
