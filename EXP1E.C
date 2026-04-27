#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      
#include <unistd.h>     

int main(void)
{
    int fd;

    fd = open("file1.dat", O_RDWR | O_CREAT, 0666);

    if (fd == -1)
    {
        perror("Error opening file");
        exit(1);
    }
    else
    {
        printf("file1.dat opened for read/write access\n");
    }

    printf("file1.dat is currently empty\n");

    close(fd);

    return 0;
}
