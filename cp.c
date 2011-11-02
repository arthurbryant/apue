#include <stdio.h>
#include <stdlib.h>

#define SIZE 4096

int main(int argc, char * argv[])
{
    int n;
    int buffer[SIZE];

    while((n = read(0, buffer, SIZE)) > 0)
        if(write(1, buffer, n) != n)
        {
            printf("write error\n");
            exit(-1);
        }
    if(n < 0)
        {
            printf("read error\n");
            exit(-1);
        }


    return 0;
}
