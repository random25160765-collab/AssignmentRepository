#include <string.h>
#include <stdio.h>

int main()
{
    char buf[20] = "Hello world!\n";
    memmove(buf+6, buf, 14);
    puts(buf);
    return 0;
}



