#include <stdio.h>

#define max 20

int stack[max], maxstack[max], minstack[max], top = -1;

void push(int x)
{
    if (top == max - 1)
    {
        printf("\nStack Overflow");
    }
    else if (top == -1)
    {
        top++;
        stack[top] = x;
        maxstack[top] = x;
        minstack[top] = x;
    }
    else
    {
        top++;
        stack[top] = x;

        if (x > maxstack[top - 1])
        {
            maxstack[top] = x;
            minstack[top] = minstack[top - 1];
        }
        else if (x < minstack[top - 1])
        {
            minstack[top] = x;
            maxstack[top] = maxstack[top - 1];
        }
        else
        {
            maxstack[top] = maxstack[top - 1];
            minstack[top] = minstack[top - 1];
        }
    }
}

int pop()
{
    int x;

    if (top == -1)
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
    {
        x = stack[top];
        top--;
        return x;
    }
}

int getMax()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return maxstack[top];
    }
}

int getMin()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return minstack[top];
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is empty");
        return;
    }

    printf("\nStack elements: ");

    i = top;

    while (i != -1)
    {
        printf("%d ", stack[i]);
        i--;
    }

    printf("\nMaximum = %d", getMax());
    printf("\nMinimum = %d", getMin());
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n\n===== STACK WITH MIN AND MAX =====");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Get Maximum");
        printf("\n4. Get Minimum");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                x = pop();

                if (x != -1)
                    printf("\nPopped element = %d", x);
                break;

            case 3:
                printf("\nMaximum = %d", getMax());
                break;

            case 4:
                printf("\nMinimum = %d", getMin());
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