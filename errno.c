#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char * argv[])
{
    char *p = strerror(EACCES);  
    printf("%s\n", p);
    errno = ENOENT;
    perror(argv[0]);

    return 0;
}
