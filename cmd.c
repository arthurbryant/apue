#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 10 

int main(int argc, char * argv[])
{
    int n, status;
    char buffer[MAXLINE];
    pid_t pid;
    
    while(fgets(buffer, MAXLINE, stdin) != NULL)
    {
        n = strlen(buffer);
        if(buffer[n-1] == '\n')
            buffer[n-1] = '\0';
        if((pid = fork()) < 0)
        {
            printf("fork error\n");
            exit(-1);
        }
        if(pid == 0)
        {
            execlp(buffer, buffer, (char *)NULL);
            exit(127);
        }
        if((pid = waitpid(pid, &status, 0)) < 0)
        {
            printf("waitpid error\n");
            exit(-1);
        }
    }

    return 0;
}
