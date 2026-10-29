
#include <stdio.h>

#define max 10

int r = -1, f = -1;
int a[max];

void enqueue(int x)
{
    if ((r + 1) % max == f)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }

        r = (r + 1) % max;
        a[r] = x;
    }
}

void dequeue()
{
    if (f == -1)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        printf("\nDeleted element is %d", a[f]);

        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1) % max;
        }
    }
}

void display()
{
    int i;

    if (f == -1)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        i = f;

        while (i != r)
        {
            printf("%d ", a[i]);
            i = (i + 1) % max;
        }

        printf("%d", a[i]);
    }
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n\n--- CIRCULAR QUEUE ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                display();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}