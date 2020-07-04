
./a.out：     文件格式 elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 e2 2f 00 00    	pushq  0x2fe2(%rip)        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmpq   *0x2fe4(%rip)        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <__cxa_atexit@plt>:
    1030:	ff 25 e2 2f 00 00    	jmpq   *0x2fe2(%rip)        # 4018 <__cxa_atexit@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	pushq  $0x0
    103b:	e9 e0 ff ff ff       	jmpq   1020 <.plt>

0000000000001040 <__stack_chk_fail@plt>:
    1040:	ff 25 da 2f 00 00    	jmpq   *0x2fda(%rip)        # 4020 <__stack_chk_fail@GLIBC_2.4>
    1046:	68 01 00 00 00       	pushq  $0x1
    104b:	e9 d0 ff ff ff       	jmpq   1020 <.plt>

0000000000001050 <_ZNSt8ios_base4InitC1Ev@plt>:
    1050:	ff 25 d2 2f 00 00    	jmpq   *0x2fd2(%rip)        # 4028 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    1056:	68 02 00 00 00       	pushq  $0x2
    105b:	e9 c0 ff ff ff       	jmpq   1020 <.plt>

Disassembly of section .text:

0000000000001060 <_start>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	31 ed                	xor    %ebp,%ebp
    1066:	49 89 d1             	mov    %rdx,%r9
    1069:	5e                   	pop    %rsi
    106a:	48 89 e2             	mov    %rsp,%rdx
    106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1071:	50                   	push   %rax
    1072:	54                   	push   %rsp
    1073:	4c 8d 05 f6 01 00 00 	lea    0x1f6(%rip),%r8        # 1270 <__libc_csu_fini>
    107a:	48 8d 0d 7f 01 00 00 	lea    0x17f(%rip),%rcx        # 1200 <__libc_csu_init>
    1081:	48 8d 3d d1 00 00 00 	lea    0xd1(%rip),%rdi        # 1159 <main>
    1088:	ff 15 52 2f 00 00    	callq  *0x2f52(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    108e:	f4                   	hlt    
    108f:	90                   	nop

0000000000001090 <deregister_tm_clones>:
    1090:	48 8d 3d a9 2f 00 00 	lea    0x2fa9(%rip),%rdi        # 4040 <__TMC_END__>
    1097:	48 8d 05 a2 2f 00 00 	lea    0x2fa2(%rip),%rax        # 4040 <__TMC_END__>
    109e:	48 39 f8             	cmp    %rdi,%rax
    10a1:	74 15                	je     10b8 <deregister_tm_clones+0x28>
    10a3:	48 8b 05 2e 2f 00 00 	mov    0x2f2e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10aa:	48 85 c0             	test   %rax,%rax
    10ad:	74 09                	je     10b8 <deregister_tm_clones+0x28>
    10af:	ff e0                	jmpq   *%rax
    10b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10b8:	c3                   	retq   
    10b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010c0 <register_tm_clones>:
    10c0:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4040 <__TMC_END__>
    10c7:	48 8d 35 72 2f 00 00 	lea    0x2f72(%rip),%rsi        # 4040 <__TMC_END__>
    10ce:	48 29 fe             	sub    %rdi,%rsi
    10d1:	48 89 f0             	mov    %rsi,%rax
    10d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10d8:	48 c1 f8 03          	sar    $0x3,%rax
    10dc:	48 01 c6             	add    %rax,%rsi
    10df:	48 d1 fe             	sar    %rsi
    10e2:	74 14                	je     10f8 <register_tm_clones+0x38>
    10e4:	48 8b 05 05 2f 00 00 	mov    0x2f05(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    10eb:	48 85 c0             	test   %rax,%rax
    10ee:	74 08                	je     10f8 <register_tm_clones+0x38>
    10f0:	ff e0                	jmpq   *%rax
    10f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10f8:	c3                   	retq   
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <__do_global_dtors_aux>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	80 3d 35 2f 00 00 00 	cmpb   $0x0,0x2f35(%rip)        # 4040 <__TMC_END__>
    110b:	75 33                	jne    1140 <__do_global_dtors_aux+0x40>
    110d:	55                   	push   %rbp
    110e:	48 83 3d ba 2e 00 00 	cmpq   $0x0,0x2eba(%rip)        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    1115:	00 
    1116:	48 89 e5             	mov    %rsp,%rbp
    1119:	74 0d                	je     1128 <__do_global_dtors_aux+0x28>
    111b:	48 8b 3d 16 2f 00 00 	mov    0x2f16(%rip),%rdi        # 4038 <__dso_handle>
    1122:	ff 15 a8 2e 00 00    	callq  *0x2ea8(%rip)        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    1128:	e8 63 ff ff ff       	callq  1090 <deregister_tm_clones>
    112d:	c6 05 0c 2f 00 00 01 	movb   $0x1,0x2f0c(%rip)        # 4040 <__TMC_END__>
    1134:	5d                   	pop    %rbp
    1135:	c3                   	retq   
    1136:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    113d:	00 00 00 
    1140:	c3                   	retq   
    1141:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1148:	00 00 00 00 
    114c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001150 <frame_dummy>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	e9 67 ff ff ff       	jmpq   10c0 <register_tm_clones>

0000000000001159 <main>:
#include <iostream>
using namespace std;


int main()
{
    1159:	55                   	push   %rbp
    115a:	48 89 e5             	mov    %rsp,%rbp
    115d:	48 83 ec 20          	sub    $0x20,%rsp
    1161:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1168:	00 00 
    116a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    116e:	31 c0                	xor    %eax,%eax
    int a = 1;
    1170:	c7 45 ec 01 00 00 00 	movl   $0x1,-0x14(%rbp)
    int *b = &a;
    1177:	48 8d 45 ec          	lea    -0x14(%rbp),%rax
    117b:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    return 0;
    117f:	b8 00 00 00 00       	mov    $0x0,%eax
}
    1184:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    1188:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    118f:	00 00 
    1191:	74 05                	je     1198 <main+0x3f>
    1193:	e8 a8 fe ff ff       	callq  1040 <__stack_chk_fail@plt>
    1198:	c9                   	leaveq 
    1199:	c3                   	retq   

000000000000119a <_Z41__static_initialization_and_destruction_0ii>:
    119a:	55                   	push   %rbp
    119b:	48 89 e5             	mov    %rsp,%rbp
    119e:	48 83 ec 10          	sub    $0x10,%rsp
    11a2:	89 7d fc             	mov    %edi,-0x4(%rbp)
    11a5:	89 75 f8             	mov    %esi,-0x8(%rbp)
    11a8:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    11ac:	75 32                	jne    11e0 <_Z41__static_initialization_and_destruction_0ii+0x46>
    11ae:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    11b5:	75 29                	jne    11e0 <_Z41__static_initialization_and_destruction_0ii+0x46>
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  //@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
    11b7:	48 8d 3d 83 2e 00 00 	lea    0x2e83(%rip),%rdi        # 4041 <_ZStL8__ioinit>
    11be:	e8 8d fe ff ff       	callq  1050 <_ZNSt8ios_base4InitC1Ev@plt>
    11c3:	48 8d 15 6e 2e 00 00 	lea    0x2e6e(%rip),%rdx        # 4038 <__dso_handle>
    11ca:	48 8d 35 70 2e 00 00 	lea    0x2e70(%rip),%rsi        # 4041 <_ZStL8__ioinit>
    11d1:	48 8b 05 20 2e 00 00 	mov    0x2e20(%rip),%rax        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    11d8:	48 89 c7             	mov    %rax,%rdi
    11db:	e8 50 fe ff ff       	callq  1030 <__cxa_atexit@plt>
    11e0:	90                   	nop
    11e1:	c9                   	leaveq 
    11e2:	c3                   	retq   

00000000000011e3 <_GLOBAL__sub_I_main>:
    11e3:	55                   	push   %rbp
    11e4:	48 89 e5             	mov    %rsp,%rbp
    11e7:	be ff ff 00 00       	mov    $0xffff,%esi
    11ec:	bf 01 00 00 00       	mov    $0x1,%edi
    11f1:	e8 a4 ff ff ff       	callq  119a <_Z41__static_initialization_and_destruction_0ii>
    11f6:	5d                   	pop    %rbp
    11f7:	c3                   	retq   
    11f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    11ff:	00 

0000000000001200 <__libc_csu_init>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	41 57                	push   %r15
    1206:	4c 8d 3d 9b 2b 00 00 	lea    0x2b9b(%rip),%r15        # 3da8 <__frame_dummy_init_array_entry>
    120d:	41 56                	push   %r14
    120f:	49 89 d6             	mov    %rdx,%r14
    1212:	41 55                	push   %r13
    1214:	49 89 f5             	mov    %rsi,%r13
    1217:	41 54                	push   %r12
    1219:	41 89 fc             	mov    %edi,%r12d
    121c:	55                   	push   %rbp
    121d:	48 8d 2d 94 2b 00 00 	lea    0x2b94(%rip),%rbp        # 3db8 <__do_global_dtors_aux_fini_array_entry>
    1224:	53                   	push   %rbx
    1225:	4c 29 fd             	sub    %r15,%rbp
    1228:	48 83 ec 08          	sub    $0x8,%rsp
    122c:	e8 cf fd ff ff       	callq  1000 <_init>
    1231:	48 c1 fd 03          	sar    $0x3,%rbp
    1235:	74 1f                	je     1256 <__libc_csu_init+0x56>
    1237:	31 db                	xor    %ebx,%ebx
    1239:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1240:	4c 89 f2             	mov    %r14,%rdx
    1243:	4c 89 ee             	mov    %r13,%rsi
    1246:	44 89 e7             	mov    %r12d,%edi
    1249:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    124d:	48 83 c3 01          	add    $0x1,%rbx
    1251:	48 39 dd             	cmp    %rbx,%rbp
    1254:	75 ea                	jne    1240 <__libc_csu_init+0x40>
    1256:	48 83 c4 08          	add    $0x8,%rsp
    125a:	5b                   	pop    %rbx
    125b:	5d                   	pop    %rbp
    125c:	41 5c                	pop    %r12
    125e:	41 5d                	pop    %r13
    1260:	41 5e                	pop    %r14
    1262:	41 5f                	pop    %r15
    1264:	c3                   	retq   
    1265:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    126c:	00 00 00 00 

0000000000001270 <__libc_csu_fini>:
    1270:	f3 0f 1e fa          	endbr64 
    1274:	c3                   	retq   

Disassembly of section .fini:

0000000000001278 <_fini>:
    1278:	f3 0f 1e fa          	endbr64 
    127c:	48 83 ec 08          	sub    $0x8,%rsp
    1280:	48 83 c4 08          	add    $0x8,%rsp
    1284:	c3                   	retq   
