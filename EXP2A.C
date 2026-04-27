#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t value;

    value = fork();

    if (value < 0)
    {
        printf("Fork failed\n");
    }
    else if (value == 0)
    {
    
        printf("Child process: value = %d\n", value);
    }
    else
    {
        printf("Parent process: value = %d\n", value);
    }

    return 0;
}
