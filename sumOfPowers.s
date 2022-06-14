.globl sumOfPowers
sumOfPowers:
  push %rbp
  mov %rsp, %rbp

  mov $0, %rax
  mov $1, %rcx
  mov $1, %rdx
  
Top:
  cmp %rdi, %rcx
  jg Done
  imul %rcx,%rcx
  add %rcx,%rax
  mov %rdx,%rcx
  inc %rcx
  inc %rdx
  jmp Top

Done:
  pop %rbp
  ret
