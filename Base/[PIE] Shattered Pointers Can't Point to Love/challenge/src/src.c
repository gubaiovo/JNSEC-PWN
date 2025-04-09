#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void the_way_to_find_her(){
    system("echo flag");
}
void the_last_message(){
    asm("pop %rdi; ret");
}
void init(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    puts("<< PIE: Shattered Pointers Can't Point to Love >>");
    puts("");
    puts("> Every time the program restarts,");
    puts("> our story gets loaded into virtual memory at randomized offsets.");
    puts("> The once-fixed .text segment was filled with sweet functions of embrace,");
    puts("> now even call instructions are separated by the sighs of ASLR.");
    puts(" ");
    puts("> Leaked address flicker in the GOT table");
    puts("> like the uncooled moonlight in your eyes on that breakup night.");
    puts("> I use PLT to calculate when we'll relink,");
    puts("> only to find our distance randomized by PIE into astronomical numbers.");
    puts("");

}
void gift(){
    void *return_address = __builtin_return_address(0);
    puts("> Disassembling us in IDA'S pseudocode,");
    puts("> I simulate all possible endings with angr.");
    puts("> But when forked child processes inherit the same randomization seeds,");
    puts("> I realize some memory layouts are destined to never rerandomize.");
    puts("> Like in the address space from 0x000000 to 0xffffff,");
    puts("> our chance of collision is 1/2^64.");
    puts("> When the program segments fault again,");
    puts("> I'll let the core file forever preserve this crash context——");
    printf("%p\n", return_address);
}
    
void vuln(){
    char buf[0x20];
    puts("> May you find the true love belongs to you.");
    puts("> best wish");
    read(0, buf, 0x100);
}

int main() {
    init();
    gift();
    vuln();
    return 0;
}