#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char * argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2)
    {
        printf("Wrong paraments\n");
        exit(-1);
    }
    if((dp = opendir(argv[1])) == NULL)
    {
        printf("can not open %s\n", argv[1]);
        exit(-1);
    }
    while((dirp = readdir(dp)) != NULL)
        printf("%s\t", dirp->d_name);
    printf("\n");
    closedir(dp);

    return 0;
}
