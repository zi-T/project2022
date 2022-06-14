.globl findPaymentsSum
findPaymentsSum:
  push %rbp
  mov %rsp, %rbp

  mov $0, %rax
  mov $0, %rcx
Top:
  cmp %rsi, %rcx
  jge Done
  add 8(%rdi, %rcx, 4),%rax
  inc %rcx
  jmp Top
Done:
  pop %rbp
  ret
