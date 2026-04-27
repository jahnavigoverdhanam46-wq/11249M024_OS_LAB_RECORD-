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
        perror("Fork error");
        exit(1);
    }

    if (pid == 0)
    {
        // Child process
        sleep(1);
        printf("Child process\n");
        exit(0);
    }
    else
    {
        // Parent process
        printf("Parent process\n");

        if ((exitch = wait(&status)) == -1)
        {
            perror("Error during wait()");
            exit(1);
        }

        printf("Parent exiting\n");
    }

    return 0;
}
