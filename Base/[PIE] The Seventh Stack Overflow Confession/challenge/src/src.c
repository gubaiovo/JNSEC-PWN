#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void vuln() {
    char buf[0x100];
    puts("> The last message for her: ");
    read(0, buf, 0x200);
}
void sub_11451(){
    puts("> Those carefully crafted ROP chains could never withstand your sudden PIE protection mode.");
    system("/bin/sh");
}
void init(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    puts("<< PIE: The Seventh Stack Overflow Confession >>");
    puts("");
    puts("> I press the gdb start key once more in the dead of night.");
    puts("> Your .text segment scatters across different quadrants after each reboot, ");
    puts("> mirroring the randomized heartbeat frequencies from when we first met.");
    puts("> That spring when I first discovered the PIE vulnerability, ");
    puts("> your .rodata still held unencrypted tenderness. ");
    puts("> All offsets were sweet absolute values, ");
    puts("> and what overflowed from segment registers weren't error codes, ");
    puts("> but overlapping coffee-stained fingerprints.");
}
void fin(){
    printf("> Now, as gdb breaks for the 1,024th time at %p, \n", (void*)puts);
    puts("> I stare at the forever-misaligned addresses in the rax register and laugh bitterly.");
    puts("> The cruelest exploit is realizing that when someone's memory layout is no longer fixed,");
    puts("> you can't even locate a return address to say goodbye.");
}
int main() {
    init();
    vuln();
    fin();
    return 0;
}