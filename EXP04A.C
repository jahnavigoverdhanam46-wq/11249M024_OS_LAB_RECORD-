#include <stdio.h>

int buffersize, currentsize = 0;

void producer()
{
    int n;
    printf("\nEnter number of elements to produce: ");
    scanf("%d", &n);

    if (currentsize + n <= buffersize)
    {
        currentsize += n;
        printf("\n%d elements produced.", n);
        printf("\nCurrent buffer size: %d / %d\n", currentsize, buffersize);
    }
    else
    {
        printf("\nBuffer overflow! Not enough space.\n");
    }
}

void consumer()
{
    int n;
    printf("\nEnter number of elements to consume: ");
    scanf("%d", &n);

    if (n <= currentsize)
    {
        currentsize -= n;
        printf("\n%d elements consumed.", n);
        printf("\nRemaining buffer size: %d / %d\n", currentsize, buffersize);
    }
    else
    {
        printf("\nBuffer underflow! Not enough elements.\n");
    }
}

int main()
{
    int choice;

    printf("Enter maximum buffer size: ");
    scanf("%d", &buffersize);

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (currentsize == buffersize)
                printf("\nBuffer is full! Cannot produce.\n");
            else
                producer();
            break;

        case 2:
            if (currentsize == 0)
                printf("\nBuffer is empty! Cannot consume.\n");
            else
                consumer();
            break;

        case 3:
            printf("\nExiting...\n");
            break;

        default:
            printf("\nInvalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
