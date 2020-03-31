int main()
{
int a=1;
int b=2;
int c=(a==b);
    return c;
}

/*
	movl	$1, -12(%rbp)
	movl	$2, -8(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax 
*/

// CMPL = Set condition codes according to S​1​ - S​2
// SETE = Set if equal/zero
// SETNE = Set if not equal/nonzero

// MOVZBL = Others, such as ​movsand ​movz​ will use two suffixes, as they convert operands of the type of the first suffix to that ofthe second. Thus, assembly to convert the byte in ​%al​ to a doubleword in ​%ebx​ withzero-extension would be ​movzbl %al, %ebx​.



//Question : al = autre registre à ajouter dans IRInstr.h ?
