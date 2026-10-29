// Priority Queue using Max Heap
#include <stdio.h>
#define max 10

int h[max], size = 0;

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void heapifyup(int index)
{
    int p;

    while (index > 0)
    {
        p = (index - 1) / 2;

        if (h[p] > h[index])
        {
            break;
        }

        swap(&h[p], &h[index]);
        index = p;
    }
}

void insert(int x)
{
    if (size == max)
    {
        printf("\nArray is full");
    }
    else
    {
        h[size] = x;
        size++;
        heapifyup(size - 1);
    }
}

void heapifydown(int index)
{
    int l, left, right;

    while (1)
    {
        l = index;
        left = 2 * index + 1;
        right = 2 * index + 2;

        if (left < size && h[left] > h[l])
        {
            l = left;
        }

        if (right < size && h[right] > h[l])
        {
            l = right; 
        }

        if (index == l)
        {
            break;
        }

        swap(&h[index], &h[l]);
        index = l;
    }
}

void del()
{
    if (size == 0)
    {
        printf("\nPriority Queue Underflow");
    }
    else
    {
        printf("\nDeleted element is %d", h[0]);

        h[0] = h[size - 1];
        size--;

        if (size > 0)
        {
            heapifydown(0);
        }
    }
}

void display()
{
    int i;

    if (size == 0)
    {
        printf("\nPriority Queue is empty");
    }
    else
    {
        printf("\nMax Heap elements: ");

        for (i = 0; i < size; i++)
        {
            printf("%d ", h[i]);
        }
    }
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n\n--- PRIORITY QUEUE USING MAX HEAP ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                del();
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