#include <stdio.h>

#define max 20

int undo_stack[max], redo_stack[max];
int tu = -1, tr = -1;

void push_undo(int x);
void push_redo(int x);
void insert(int x);
void undo();
void redo();
void display();

void insert(int x)
{
    if (tu == max - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        push_undo(x);
        tr = -1;
    }
}

void undo()
{
    if (tu == -1)
    {
        printf("\nUndo not possible");
    }
    else
    {
        int x = undo_stack[tu];
        tu--;
        push_redo(x);

        printf("\nUndo: %d", x);
    }
}

void redo()
{
    if (tr == -1)
    {
        printf("\nRedo not possible");
    }
    else
    {
        int x = redo_stack[tr];
        tr--;
        push_undo(x);

        printf("\nRedo: %d", x);
    }
}

void push_undo(int x)
{
    if (tu == max - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        tu++;
        undo_stack[tu] = x;
    }
}

void push_redo(int x)
{
    if (tr == max - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        tr++;
        redo_stack[tr] = x;
    }
}

void display()
{
    int i;

    printf("\n\nUndo Stack: ");

    if (tu == -1)
    {
        printf("Empty");
    }
    else
    {
        for (i = tu; i >= 0; i--)
        {
            printf("%d ", undo_stack[i]);
        }
    }

    printf("\nRedo Stack: ");

    if (tr == -1)
    {
        printf("Empty");
    }
    else
    {
        for (i = tr; i >= 0; i--)
        {
            printf("%d ", redo_stack[i]);
        }
    }
}

int main()
{
    int choice, x;

    while (1)
    {
    
        printf("\n1. Insert");
        printf("\n2. Undo");
        printf("\n3. Redo");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                undo();
                break;

            case 3:
                redo();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}