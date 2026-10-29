// Priority Queue using Array
#include <stdio.h>
#define max 20

int a[max], pr[max];
int r = -1, f = 0;

void enqueue(int x, int p)
{
    if (r == max - 1)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        r++;
        a[r] = x;
        pr[r] = p;
    }
}

void dequeue()
{
    if (r < f)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        int i, max_pr = 0;

        for (i = 1; i <= r; i++)
        {
            if (pr[i] > pr[max_pr])
            {
                max_pr = i;
            }
        }

        printf("\nDeleted element is %d", a[max_pr]);

        for (i = max_pr; i < r; i++)
        {
            a[i] = a[i + 1];
            pr[i] = pr[i + 1];
        }

        r--;
    }
}

void display()
{
    int i;

    if (r < f)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        printf("\nPriority -> Element\n");

        for (i = f; i <= r; i++)
        {
            printf("%d -> %d\n", pr[i], a[i]);
        }
    }
}

int main()
{
    int choice, x, p;

    while (1)
    {
        printf("\n\n--- PRIORITY QUEUE ---");
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

                printf("Enter priority: ");
                scanf("%d", &p);

                enqueue(x, p);
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