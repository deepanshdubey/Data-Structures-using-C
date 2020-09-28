//Write a program to perform deletion from LinkedList

//Name-Sai Prashant Saxena
//Roll no-02220902719

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
void printList(struct node *);
struct node *insertValue(int);
struct node *deleteValue(struct node *, int);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->link = NULL;
    struct node *temp = head;

    printf("Hello there!!\nWant to create a Linked List press 1...\n ");
    int ask;
    scanf("%d", &ask);
    if (ask == 1)
    {
        printf("\nEnter the value of head\n ");
        int value;
        scanf("%d", &value);
        head->info = value;
        printList(head);
        temp = head;
    }
    else
    {
        printf("\nProgram exited");
        goto end;
    }

askAgain:
    printf("\nPress 1 for adding value\nPress 2 for deleting value\nPress any other key to exit\n ");
    scanf("%d", &ask);
    if (ask == 1)
    {
        printf("\nEnter the value to be added\n ");
        int value;
        scanf("%d", &value);
        if (head == NULL)
        {

            head = insertValue(value);
            temp = head;
        }
        else
        {

            temp->link = insertValue(value);
            temp = temp->link;
        }
        printf("Thus the new list is");
        printList(head);
    }
    else if (ask == 2)
    {
        printf("Enter the value to be deleted\n ");
        int value;
        scanf("%d", &value);
        head = deleteValue(head, value);
    }
    else
    {
        printf("The linked list is..");
        printList(head);
        goto end;
    }
    goto askAgain;

end:
    return 0;
}
struct node *insertValue(int value)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = value;
    new->link = NULL;
    return new;
}
struct node *deleteValue(struct node *head, int value)
{
    if (head == NULL)
    {
        printf("Linked is already empty!!!");
        return head;
    }
    struct node *current = head, *previous;
    if (head->info == value)
    {
        head = head->link;
        free(current);
        printf("Linked List after deletion is..");
        printList(head);
        return head;
    }
    while (current != NULL)
    {
        if (current->info == value)
        {
            previous->link = current->link;
            free(current);
            printf("Linked List after deletion is..");
            printList(head);
            return head;
        }
        previous = current;
        current = current->link;
    }

    printf("Value not found in Linked List!!\n");

    return head;
}
void printList(struct node *head)
{
    if (head == NULL)
    {
        printf(" Empty\n");
        return;
    }
    struct node *temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}