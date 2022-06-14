.globl compareAges
compareAges:
  push %rbp
  mov %rsp, %rbp

  mov 4(%rdi),%rax
  mov 4(%rsi),%rcx
  cmp %rax,%rcx
  je Eq
  jg Neq
  jl Neq
Eq:
  mov $1, %rax
  jmp Done
Neq:
  mov $0, %rax
  jmp Done

Done:
  pop %rbp
  ret
