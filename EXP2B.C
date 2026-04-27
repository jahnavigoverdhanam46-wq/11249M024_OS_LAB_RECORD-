#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Parent Process Started\n");

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        
        printf("Child Process Executing 'ls -l'\n");

        execl("/bin/ls", "ls", "-l", NULL);

        
        printf("Exec failed\n");
        exit(1);
    }
    else
    {
        
        wait(NULL);
        printf("Parent Process Resumed\n");
    }

    return 0;
}
