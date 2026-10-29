#include <stdio.h>

#define max 20

int a[max], top1 = -1, top2 = max;

void push1(int x)
{
    if (top1 + 1 == top2)
    {
        printf("\nStack Overflow");
    }
    else
    {
        a[++top1] = x;
    }
}

void push2(int x)
{
    if (top2 == top1 + 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        a[--top2] = x;
    }
}

void pop1()
{
    if (top1 == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nPopped element is: %d", a[top1--]);
    }
}

void pop2()
{
    if (top2 == max)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nPopped element is: %d", a[top2++]);
    }
}

int main()
{
    int choice, x;

    while (1)
    {
        
        printf("\n1. Push Left");
        printf("\n2. Push Right");
        printf("\n3. Pop Left");
        printf("\n4. Pop Right");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push1(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                push2(x);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                return 0;

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}