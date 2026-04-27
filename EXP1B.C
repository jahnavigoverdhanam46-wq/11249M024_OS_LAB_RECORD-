#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;
    int status, exitch;

    pid = fork();

    if (pid == -1)
    {
        perror("fork error");
        exit(1);
    }

    if (pid == 0)
    {
        
        sleep(1);
        printf("Child process\n");
        exit(0);
    }
    else
    {
    
        printf("Parent process\n");

        if ((exitch = wait(&status)) == -1)
        {
            perror("Error during wait()");
            exit(1);
        }

        printf("Parent exiting\n");
        exit(0);
    }
}
