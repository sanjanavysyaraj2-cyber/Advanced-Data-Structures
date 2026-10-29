#include <stdio.h>
#define max 10
int a[max], r = -1, f = -1;
void enqueuerear(int x)
{
    if ((f == 0 && r == max - 1) || (f == r + 1))
    {
        printf("\nQueue Overflow");
    }
    else
    {
        if (f == -1)
        {
            r = 0;
            f = 0;
        }
        else if (r == max - 1)
        {
            r = 0;
        }
        else
        {
            r++;
        }

        a[r] = x;
    }
}

void enqueuefront(int x)
{
    if ((f == 0 && r == max - 1) || (f == r + 1))
    {
        printf("\nQueue Overflow");
    }
    else
    {
        if (f == -1)
        {
            r = 0;
            f = 0;
        }
        else if (f == 0)
        {
            f = max - 1;
        }
        else
        {
            f--;
        }

        a[f] = x;
    }
}

void dequeuerear()
{
    if (f == -1)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        printf("\nDeleted element is %d", a[r]);

        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else if (r == 0)
        {
            r = max - 1;
        }
        else
        {
            r--;
        }
    }
}

void dequeuefront()
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
        else if (f == max - 1)
        {
            f = 0;
        }
        else
        {
            f++;
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
        printf("\n\n--- DOUBLE ENDED QUEUE ---");
        printf("\n1. Insert at Rear");
        printf("\n2. Insert at Front");
        printf("\n3. Delete from Rear");
        printf("\n4. Delete from Front");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueuerear(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueuefront(x);
                break;

            case 3:
                dequeuerear();
                break;

            case 4:
                dequeuefront();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}