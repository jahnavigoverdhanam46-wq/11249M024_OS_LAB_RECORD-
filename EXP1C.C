#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("Process ID is %d\n", pid);

    pid = getppid();
    printf("Parent process ID is %d\n", pid);

    return 0;
}
