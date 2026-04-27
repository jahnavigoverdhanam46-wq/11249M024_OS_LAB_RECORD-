#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dirp;
    struct dirent *dptr;
    char buff[256];

    printf("Enter directory name: ");
    scanf("%255s", buff);

    
    dirp = opendir(buff);
    if (dirp == NULL)
    {
        perror("Error opening directory");
        exit(1);
    }

    while ((dptr = readdir(dirp)) != NULL)
    {
        printf("%s\n", dptr->d_name);
    }

    closedir(dirp);

    return 0;
}
