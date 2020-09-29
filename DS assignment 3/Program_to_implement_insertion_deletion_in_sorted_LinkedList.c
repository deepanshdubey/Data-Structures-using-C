//Write a program to implement deletion,insertion and display LinkedList

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
struct node *insertValue(struct node *, int);
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
    printf("\nPress 1 for adding value\nPress 2 for deleting value\nPress 0 to exit\n ");
    scanf("%d", &ask);
    if (ask == 1)
    {
        printf("\nEnter the value to be added\n ");
        int value;
        scanf("%d", &value);
        head = insertValue(head, value);
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
struct node *insertValue(struct node *head, int value)
{

    struct node *temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = value;
    new->link = NULL;
    if (head == NULL)
    {
        return new;
    }
    if (head->info > value)
    {
        new->link = head;
        head = new;
        return head;
    }
    while (temp->link != NULL)
    {
        if (temp->link->info > value)
        {
            new->link = temp->link;
            temp->link = new;
            return head;
        }
        temp = temp->link;
    }
    temp->link = new;
    return head;
}
struct node *deleteValue(struct node *head, int value)
{
    if (head == NULL)
    {
        printf("Linked is already empty!!!");
        return head;
    }
    struct node *current = head, *previous;
    if (head->info > value)
    {
        current = NULL;
    }
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
        if (current->info > value)
        {
            break;
        }
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