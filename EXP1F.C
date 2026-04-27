#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    int fd;
    char message[] = "hai Hello world";
    char buffer[100];

    
    fd = open("new2file.txt", O_RDWR | O_CREAT | O_EXCL, 0666);

    if (fd == -1)
    {
        perror("File already exists or cannot be opened");
        exit(1);
    }

    printf("new2file.txt opened for read/write access\n");


    write(fd, message, sizeof(message));

    
    lseek(fd, 0, SEEK_SET);

    if (read(fd, buffer, sizeof(message)) == sizeof(message))
    {
        printf("\"%s\" was written to new2file.txt\n", buffer);
    }
    else
    {
        printf("Error reading new2file.txt\n");
    }

    close(fd);

    return 0;
}
