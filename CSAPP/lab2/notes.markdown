## Hints
If you’re still having trouble figuring out what your bomb is doing, here are some hints for what to think about at each stage: (1) comparison, (2) loops, (3) switch statements, (4) recursion, (5) pointers and arrays, (6) sorting linked lists.

## phase_1
### ASM
```
Dump of assembler code for function phase_1:
=> 0x0000000000400e70 <+0>:	sub    $0x8,%rsp
   0x0000000000400e74 <+4>:	mov    $0x401af8,%esi
   0x0000000000400e79 <+9>:	callq  0x40123d <strings_not_equal>
   0x0000000000400e7e <+14>:	test   %eax,%eax
   0x0000000000400e80 <+16>:	je     0x400e87 <phase_1+23>
   0x0000000000400e82 <+18>:	callq  0x40163d <explode_bomb>
   0x0000000000400e87 <+23>:	add    $0x8,%rsp
   0x0000000000400e8b <+27>:	retq   
End of assembler dump.
```
```
Dump of assembler code for function strings_not_equal:
   0x000000000040123d <+0>:	mov    %rbx,-0x18(%rsp)
   0x0000000000401242 <+5>:	mov    %rbp,-0x10(%rsp)
   0x0000000000401247 <+10>:	mov    %r12,-0x8(%rsp)
   0x000000000040124c <+15>:	sub    $0x18,%rsp
   0x0000000000401250 <+19>:	mov    %rdi,%rbx
=> 0x0000000000401253 <+22>:	mov    %rsi,%rbp
   0x0000000000401256 <+25>:	callq  0x401221 <string_length>
   0x000000000040125b <+30>:	mov    %eax,%r12d
   0x000000000040125e <+33>:	mov    %rbp,%rdi
   0x0000000000401261 <+36>:	callq  0x401221 <string_length>
   0x0000000000401266 <+41>:	mov    $0x1,%edx
   0x000000000040126b <+46>:	cmp    %eax,%r12d
   0x000000000040126e <+49>:	jne    0x4012a6 <strings_not_equal+105>
   0x0000000000401270 <+51>:	movzbl (%rbx),%eax
   0x0000000000401273 <+54>:	mov    $0x0,%dl
   0x0000000000401275 <+56>:	test   %al,%al
   0x0000000000401277 <+58>:	je     0x4012a6 <strings_not_equal+105>
   0x0000000000401279 <+60>:	mov    $0x1,%dl
   0x000000000040127b <+62>:	cmp    0x0(%rbp),%al
   0x000000000040127e <+65>:	jne    0x4012a6 <strings_not_equal+105>
   0x0000000000401280 <+67>:	mov    $0x0,%eax
   0x0000000000401285 <+72>:	jmp    0x401291 <strings_not_equal+84>
   0x0000000000401287 <+74>:	add    $0x1,%rax
   0x000000000040128b <+78>:	cmp    0x0(%rbp,%rax,1),%dl
   0x000000000040128f <+82>:	jne    0x4012a1 <strings_not_equal+100>
   0x0000000000401291 <+84>:	movzbl 0x1(%rbx,%rax,1),%edx
   0x0000000000401296 <+89>:	test   %dl,%dl
   0x0000000000401298 <+91>:	jne    0x401287 <strings_not_equal+74>
   0x000000000040129a <+93>:	mov    $0x0,%edx
   0x000000000040129f <+98>:	jmp    0x4012a6 <strings_not_equal+105>
   0x00000000004012a1 <+100>:	mov    $0x1,%edx
   0x00000000004012a6 <+105>:	mov    %edx,%eax
---Type <return> to continue, or q <return> to quit---
   0x00000000004012a8 <+107>:	mov    (%rsp),%rbx
   0x00000000004012ac <+111>:	mov    0x8(%rsp),%rbp
   0x00000000004012b1 <+116>:	mov    0x10(%rsp),%r12
   0x00000000004012b6 <+121>:	add    $0x18,%rsp
   0x00000000004012ba <+125>:	retq  
```
```
Dump of assembler code for function string_length:
=> 0x0000000000401221 <+0>:	mov    $0x0,%eax
   0x0000000000401226 <+5>:	cmpb   $0x0,(%rdi)
   0x0000000000401229 <+8>:	je     0x40123b <string_length+26>
   0x000000000040122b <+10>:	mov    %rdi,%rdx
   0x000000000040122e <+13>:	add    $0x1,%rdx
   0x0000000000401232 <+17>:	mov    %edx,%eax
   0x0000000000401234 <+19>:	sub    %edi,%eax
   0x0000000000401236 <+21>:	cmpb   $0x0,(%rdx)
   0x0000000000401239 <+24>:	jne    0x40122e <string_length+13>
   0x000000000040123b <+26>:	repz retq 
End of assembler dump.
```
```
(gdb) x /s $rsi
0x401af8 <__dso_handle+496>:	 "Science isn't about why, it's about why not?"
```
## phase_2
### ASM
```
Dump of assembler code for function phase_2:
=> 0x0000000000400e8c <+0>:	mov    %rbx,-0x20(%rsp) //save rbx, rbp, r12, r13
   0x0000000000400e91 <+5>:	mov    %rbp,-0x18(%rsp)
   0x0000000000400e96 <+10>:	mov    %r12,-0x10(%rsp)
   0x0000000000400e9b <+15>:	mov    %r13,-0x8(%rsp)
   0x0000000000400ea0 <+20>:	sub    $0x48,%rsp
   0x0000000000400ea4 <+24>:	mov    %rsp,%rsi
   0x0000000000400ea7 <+27>:	callq  0x401743 <read_six_numbers> //test whether input num is more than 5
   0x0000000000400eac <+32>:	mov    %rsp,%rbp
   0x0000000000400eaf <+35>:	lea    0xc(%rsp),%r13 //r13 stores the address of the 4th num
   0x0000000000400eb4 <+40>:	mov    $0x0,%r12d //clear r12
   0x0000000000400eba <+46>:	mov    %rbp,%rbx //store rbp into rbx
   0x0000000000400ebd <+49>:	mov    0xc(%rbp),%eax //fetch the 3rd num after the num in (%rbp) into eax
   0x0000000000400ec0 <+52>:	cmp    %eax,0x0(%rbp) //compare the 3rd num after the num in (%rbp) with the num in (%rbp)
   0x0000000000400ec3 <+55>:	je     0x400eca <phase_2+62> 
   0x0000000000400ec5 <+57>:	callq  0x40163d <explode_bomb> //if not equal, BOOM!
   0x0000000000400eca <+62>:	add    (%rbx),%r12d //if equal, add this num to r12
   0x0000000000400ecd <+65>:	add    $0x4,%rbp //rbp point to the next num on stack
   0x0000000000400ed1 <+69>:	cmp    %r13,%rbp //compare to test whether have test the 3 pair nums 
   0x0000000000400ed4 <+72>:	jne    0x400eba <phase_2+46> //go back to test the next pair of num
   0x0000000000400ed6 <+74>:	test   %r12d,%r12d //test to ensure sum of inputs is not zero
   0x0000000000400ed9 <+77>:	jne    0x400ee0 <phase_2+84>
   0x0000000000400edb <+79>:	callq  0x40163d <explode_bomb>
   0x0000000000400ee0 <+84>:	mov    0x28(%rsp),%rbx //restore rbx, rbp, r12, r13
   0x0000000000400ee5 <+89>:	mov    0x30(%rsp),%rbp
   0x0000000000400eea <+94>:	mov    0x38(%rsp),%r12
   0x0000000000400eef <+99>:	mov    0x40(%rsp),%r13
   0x0000000000400ef4 <+104>:	add    $0x48,%rsp
   0x0000000000400ef8 <+108>:	retq
End of assembler dump.
```

```
(gdb) x /72wx $rsp
0x7fffffffe5e0:	0x00000001	0x00000002	0x00000003	0x00000001
0x7fffffffe5f0:	0x00000002	0x00000004	0x00602f90	0x00000000
0x7fffffffe600:	0x00000000	0x00000000	0xffffe718	0x00007fff
0x7fffffffe610:	0x00000000	0x00000000	0x00400c40	0x00000000
0x7fffffffe620:	0xffffe710	0x00007fff	0x00400dd5	0x00000000
0x7fffffffe630:	0x00000000	0x00000000	0x5a021735	0x00000035
0x7fffffffe640:	0x00000000	0x00000000	0xffffe718	0x00007fff
0x7fffffffe650:	0x00000000	0x00000001	0x00400d24	0x00000000
0x7fffffffe660:	0x00000000	0x00000000	0x719ebdd9	0x0dfebf2c
0x7fffffffe670:	0x00400c40	0x00000000	0xffffe710	0x00007fff
0x7fffffffe680:	0x00000000	0x00000000	0x00000000	0x00000000
0x7fffffffe690:	0xbd1ebdd9	0xf20140d3	0x5c44bdd9	0x0d940b28
0x7fffffffe6a0:	0x00000000	0x00000000	0x00000000	0x00000000
0x7fffffffe6b0:	0x00000000	0x00000000	0x00401800	0x00000000
0x7fffffffe6c0:	0xffffe718	0x00007fff	0x00000001	0x00000000
0x7fffffffe6d0:	0x00000000	0x00000000	0x00000000	0x00000000
0x7fffffffe6e0:	0x00400c40	0x00000000	0xffffe710	0x00007fff
0x7fffffffe6f0:	0x00000000	0x00000000	0x00400c69	0x00000000
```

```
Dump of assembler code for function read_six_numbers:
=> 0x0000000000401743 <+0>:	sub    $0x18,%rsp
   0x0000000000401747 <+4>:	mov    %rsi,%rdx
   0x000000000040174a <+7>:	lea    0x4(%rsi),%rcx
   0x000000000040174e <+11>:	lea    0x14(%rsi),%rax
   0x0000000000401752 <+15>:	mov    %rax,0x8(%rsp)
   0x0000000000401757 <+20>:	lea    0x10(%rsi),%rax
   0x000000000040175b <+24>:	mov    %rax,(%rsp)
   0x000000000040175f <+28>:	lea    0xc(%rsi),%r9
   0x0000000000401763 <+32>:	lea    0x8(%rsi),%r8
   0x0000000000401767 <+36>:	mov    $0x401eb2,%esi
   0x000000000040176c <+41>:	mov    $0x0,%eax
   0x0000000000401771 <+46>:	callq  0x400ab0 <__isoc99_sscanf@plt> //return the number of input numbers into eax 
   0x0000000000401776 <+51>:	cmp    $0x5,%eax //compare eax to 5
   0x0000000000401779 <+54>:	jg     0x401780 <read_six_numbers+61> //if > 5, safe
   0x000000000040177b <+56>:	callq  0x40163d <explode_bomb> 
   0x0000000000401780 <+61>:	add    $0x18,%rsp
   0x0000000000401784 <+65>:	retq   
End of assembler dump.
```
The answer is 6 numbers, the 1st equals to the 4th, the 2nd equals to the 5th, the 3rd equals to the 6th, And the sum of the 1st, 2ed, 3rd number is not 0. 


## phase_3
### ASM
```
Dump of assembler code for function phase_3:
   0x0000000000400ef9 <+0>:	sub    $0x18,%rsp
   0x0000000000400efd <+4>:	lea    0x8(%rsp),%rcx
   0x0000000000400f02 <+9>:	lea    0xc(%rsp),%rdx
   0x0000000000400f07 <+14>:	mov    $0x401ebe,%esi
   0x0000000000400f0c <+19>:	mov    $0x0,%eax
   0x0000000000400f11 <+24>:	callq  0x400ab0 <__isoc99_sscanf@plt> //sscanf returns num of inputs to eax 
   0x0000000000400f16 <+29>:	cmp    $0x1,%eax
   0x0000000000400f19 <+32>:	jg     0x400f20 <phase_3+39>
   0x0000000000400f1b <+34>:	callq  0x40163d <explode_bomb>
=> 0x0000000000400f20 <+39>:	cmpl   $0x7,0xc(%rsp) 		      //the second input
   0x0000000000400f25 <+44>:	ja     0x400f63 <phase_3+106>
   0x0000000000400f27 <+46>:	mov    0xc(%rsp),%eax
   0x0000000000400f2b <+50>:	jmpq   *0x401b60(,%rax,8)
   0x0000000000400f32 <+57>:	mov    $0x217,%eax
   0x0000000000400f37 <+62>:	jmp    0x400f74 <phase_3+123>
   0x0000000000400f39 <+64>:	mov    $0xd6,%eax
   0x0000000000400f3e <+69>:	jmp    0x400f74 <phase_3+123>
   0x0000000000400f40 <+71>:	mov    $0x153,%eax
   0x0000000000400f45 <+76>:	jmp    0x400f74 <phase_3+123>
   0x0000000000400f47 <+78>:	mov    $0x77,%eax
   0x0000000000400f4c <+83>:	jmp    0x400f74 <phase_3+123>
   0x0000000000400f4e <+85>:	mov    $0x160,%eax
   0x0000000000400f53 <+90>:	jmp    0x400f74 <phase_3+123>
   0x0000000000400f55 <+92>:	mov    $0x397,%eax
   0x0000000000400f5a <+97>:	jmp    0x400f74 <phase_3+123>
   0x0000000000400f5c <+99>:	mov    $0x19c,%eax
   0x0000000000400f61 <+104>:	jmp    0x400f74 <phase_3+123>
   0x0000000000400f63 <+106>:	callq  0x40163d <explode_bomb>
   0x0000000000400f68 <+111>:	mov    $0x0,%eax
   0x0000000000400f6d <+116>:	jmp    0x400f74 <phase_3+123>
   0x0000000000400f6f <+118>:	mov    $0x39e,%eax
   0x0000000000400f74 <+123>:	cmp    0x8(%rsp),%eax
---Type <return> to continue, or q <return> to quit---
   0x0000000000400f78 <+127>:	je     0x400f7f <phase_3+134>
   0x0000000000400f7a <+129>:	callq  0x40163d <explode_bomb>
   0x0000000000400f7f <+134>:	add    $0x18,%rsp
   0x0000000000400f83 <+138>:	retq  
```

### The Jump Table
```
(gdb) x /8gx 0x401b60
0x401b60 <__dso_handle+600>:	0x0000000000400f32	0x0000000000400f6f
0x401b70 <__dso_handle+616>:	0x0000000000400f39	0x0000000000400f40
0x401b80 <__dso_handle+632>:	0x0000000000400f47	0x0000000000400f4e
0x401b90 <__dso_handle+648>:	0x0000000000400f55	0x0000000000400f5c
```
### Function
function sscanf put return in eax
### Input
If you input tow numbers, the first num is in 0xC(%rsp), the second num is in 0x8(%rsp)

## phase_4
### ASM
```
Dump of assembler code for function phase_4:
=> 0x0000000000400fc1 <+0>:	sub    $0x18,%rsp
   0x0000000000400fc5 <+4>:	lea    0xc(%rsp),%rdx
   0x0000000000400fca <+9>:	mov    $0x401ec1,%esi
   0x0000000000400fcf <+14>:	mov    $0x0,%eax
   0x0000000000400fd4 <+19>:	callq  0x400ab0 <__isoc99_sscanf@plt>
   0x0000000000400fd9 <+24>:	cmp    $0x1,%eax                      // one input
   0x0000000000400fdc <+27>:	jne    0x400fe5 <phase_4+36>
   0x0000000000400fde <+29>:	cmpl   $0x0,0xc(%rsp)
   0x0000000000400fe3 <+34>:	jg     0x400fea <phase_4+41>          // great than 0
   0x0000000000400fe5 <+36>:	callq  0x40163d <explode_bomb>
   0x0000000000400fea <+41>:	mov    0xc(%rsp),%edi
   0x0000000000400fee <+45>:	callq  0x400f84 <func4>
   0x0000000000400ff3 <+50>:	cmp    $0x37,%eax                     // eax needs to equal 0x37 = 55
   0x0000000000400ff6 <+53>:	je     0x400ffd <phase_4+60>
   0x0000000000400ff8 <+55>:	callq  0x40163d <explode_bomb>
   0x0000000000400ffd <+60>:	add    $0x18,%rsp
   0x0000000000401001 <+64>:	retq   
```
```
Dump of assembler code for function func4:
=> 0x0000000000400f84 <+0>:	mov    %rbx,-0x10(%rsp)
   0x0000000000400f89 <+5>:	mov    %rbp,-0x8(%rsp)
   0x0000000000400f8e <+10>:	sub    $0x18,%rsp
   0x0000000000400f92 <+14>:	mov    %edi,%ebx                       // input to ebx
   0x0000000000400f94 <+16>:	mov    $0x1,%eax                       // eax = 1
   0x0000000000400f99 <+21>:	cmp    $0x1,%edi 
   0x0000000000400f9c <+24>:	jle    0x400fb2 <func4+46>             // input <= 1
   0x0000000000400f9e <+26>:	lea    -0x1(%rbx),%edi                 // input--
   0x0000000000400fa1 <+29>:	callq  0x400f84 <func4>
   0x0000000000400fa6 <+34>:	mov    %eax,%ebp                       // ebp = 1
   0x0000000000400fa8 <+36>:	lea    -0x2(%rbx),%edi                 // 
   0x0000000000400fab <+39>:	callq  0x400f84 <func4>
   0x0000000000400fb0 <+44>:	add    %ebp,%eax
   0x0000000000400fb2 <+46>:	mov    0x8(%rsp),%rbx                  // caller function's rbx
   0x0000000000400fb7 <+51>:	mov    0x10(%rsp),%rbp
   0x0000000000400fbc <+56>:	add    $0x18,%rsp
   0x0000000000400fc0 <+60>:	retq   
End of assembler dump.
``` 

## phase_5
### ASM
```
Dump of assembler code for function phase_5:
=> 0x0000000000401002 <+0>:	sub    $0x18,%rsp
   0x0000000000401006 <+4>:	lea    0x8(%rsp),%rcx
   0x000000000040100b <+9>:	lea    0xc(%rsp),%rdx
   0x0000000000401010 <+14>:	mov    $0x401ebe,%esi
   0x0000000000401015 <+19>:	mov    $0x0,%eax
   0x000000000040101a <+24>:	callq  0x400ab0 <__isoc99_sscanf@plt>
   0x000000000040101f <+29>:	cmp    $0x1,%eax
   0x0000000000401022 <+32>:	jg     0x401029 <phase_5+39> // input more than 1 num
   0x0000000000401024 <+34>:	callq  0x40163d <explode_bomb>
   0x0000000000401029 <+39>:	mov    0xc(%rsp),%eax // first input into eax
   0x000000000040102d <+43>:	and    $0xf,%eax  // rest 4 bit of eax
   0x0000000000401030 <+46>:	mov    %eax,0xc(%rsp) // put back
   0x0000000000401034 <+50>:	cmp    $0xf,%eax    // first input not equals 0x...f
   0x0000000000401037 <+53>:	je     0x401065 <phase_5+99> 
   0x0000000000401039 <+55>:	mov    $0x0,%ecx 
   0x000000000040103e <+60>:	mov    $0x0,%edx
   0x0000000000401043 <+65>:	add    $0x1,%edx  //edx += 1
   0x0000000000401046 <+68>:	cltq   
   0x0000000000401048 <+70>:	mov    0x401ba0(,%rax,4),%eax
   0x000000000040104f <+77>:	add    %eax,%ecx
   0x0000000000401051 <+79>:	cmp    $0xf,%eax
   0x0000000000401054 <+82>:	jne    0x401043 <phase_5+65>
   0x0000000000401056 <+84>:	mov    %eax,0xc(%rsp)
   0x000000000040105a <+88>:	cmp    $0xc,%edx
   0x000000000040105d <+91>:	jne    0x401065 <phase_5+99>
   0x000000000040105f <+93>:	cmp    0x8(%rsp),%ecx
   0x0000000000401063 <+97>:	je     0x40106a <phase_5+104>
   0x0000000000401065 <+99>:	callq  0x40163d <explode_bomb>
   0x000000000040106a <+104>:	add    $0x18,%rsp
   0x000000000040106e <+108>:	retq   
End of assembler dump.
```

### Array
```
(gdb) x /64wd 0x401ba0
0x401ba0 <array.3014>:	10	2	14	7
0x401bb0 <array.3014+16>:	8	12	15	11
0x401bc0 <array.3014+32>:	0	4	1	13
0x401bd0 <array.3014+48>:	3	9	6	5
0x401be0:	2032168787	1948284271	1802398056	1970239776
0x401bf0:	1851876128	1869902624	1752440944	1868701797
0x401c00:	1998611053	543716457	1819440227	539779885
0x401c10:	2032168804	4158831	1701736302	1953720696
0x401c20:	1752460901	779383663	1999532899	1768452961
0x401c30:	1869899630	1684352622	117	0
0x401c40:	1936880963	539784037	662007673	1713399158
0x401c50:	1684960623	1701344288	1667592992	544499058
0x401c60:	1935763568	8549	544503106	1684957542
0x401c70:	543649385	1629516905	1931502702	1769368687
0x401c80:	1763731310	1918967924	1970348133	543519849
0x401c90:	1717987684	1852142181	774778484	0
```
* array[6] = 0xf, ending is 6;
* total 0xc (12) num, from index 6, backtrack 11 times, got start index 7

```
10, 02, 14, 07, 08, 12, 15, 11, 00, 04, 01, 13, 03, 09, 06, 05  //array content
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  //array index
7   9   10      5       12  1   6   4   8   2       3   11      //array travel order, starts from index 7
sum_of_travel = 93
```

## phase_6
### ASM
```
Dump of assembler code for function phase_6:
=> 0x00000000004010d9 <+0>:	sub    $0x8,%rsp
   0x00000000004010dd <+4>:	mov    $0xa,%edx
   0x00000000004010e2 <+9>:	mov    $0x0,%esi
   0x00000000004010e7 <+14>:	callq  0x400b80 <strtol@plt>      //input to long
   0x00000000004010ec <+19>:	mov    %eax,0x20168e(%rip)        # 0x602780 <node0> // eax = input to long, store input
   0x00000000004010f2 <+25>:	mov    $0x602780,%edi  //store input's address
   0x00000000004010f7 <+30>:	callq  0x40106f <fun6>
   0x00000000004010fc <+35>:	mov    0x8(%rax),%rax //jump on the linked list, *rax is the value, rax+8 is the next address
   0x0000000000401100 <+39>:	mov    0x8(%rax),%rax
   0x0000000000401104 <+43>:	mov    0x8(%rax),%rax
   0x0000000000401108 <+47>:	mov    0x201672(%rip),%edx        # 0x602780 <node0> // edx = input
   0x000000000040110e <+53>:	cmp    %edx,(%rax)  // compare the input with the 4th node in list start with rax(phase_6+35)
                                                    // now %(rax) is 34359738968
   0x0000000000401110 <+55>:	je     0x401117 <phase_6+62>
   0x0000000000401112 <+57>:	callq  0x40163d <explode_bomb>
   0x0000000000401117 <+62>:	add    $0x8,%rsp
   0x000000000040111b <+66>:	retq   
End of assembler dump.
```
