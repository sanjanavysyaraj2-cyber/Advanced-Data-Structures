// Priority Queue using Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data, pr;
    struct node *next;
};

struct node *f = NULL;

void enqueue(int x, int p)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    newnode->data = x;
    newnode->pr = p;
    newnode->next = NULL;

    if (f == NULL || p > f->pr)
    {
        newnode->next = f;
        f = newnode;
    }
    else
    {
        temp = f;

        while (temp->next != NULL && temp->next->pr >= p)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void dequeue()
{
    struct node *temp;

    if (f == NULL)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        temp = f;

        printf("\nDeleted element is %d", f->data);

        f = f->next;

        free(temp);
    }
}

void display()
{
    struct node *temp;

    if (f == NULL)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        temp = f;

        printf("\nPriority -> Element\n");

        while (temp != NULL)
        {
            printf("%d -> %d\n", temp->pr, temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, x, p;

    while (1)
    {
        printf("\n\n--- PRIORITY QUEUE USING LINKED LIST ---");
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