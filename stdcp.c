#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    char c;
    while((c = getc(stdin)) != EOF)
        if(putc(c, stdout) == EOF)
        {
            printf("stdout error\n");
            exit(-1);
        }
    if(ferror(stdin))
        {
            printf("stdin error\n");
            exit(-1);
        }
    

    return 0;
}
