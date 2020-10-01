//Write a program to create a linkedList

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

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    printf("Hello there!!");
    printf("\nWant to create a linked list press Y.....\n\t\t");
    char c;
    scanf("%c", &c);
    if (c == 'Y' || c == 'y')
    {
        printf("Enter the value of head\n  ");
        int value;
        scanf("%d", &value);
        head->info = value;
        head->link = NULL;
        temp = head;
    }
    else
    {
        printf("Why did you ran this program if you did not wanted to make a linked list\n");
        printf("Program exited");
        goto end;  //can be directly replaces with "return 0", just a suggestion to reduce 1 step.
    }

    int ch;
    printf("Want to add more values to linked list press 1...\n  ");
    scanf("%d", &ch);
    if (ch == 1)
    {
    addNode:
        printf("Enter the next value\n  ");
        int value;
        scanf("%d", &value);
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->info = value;
        new->link = NULL;
        temp->link = new;
        temp = temp->link;
        printf("\nThe new List is:");
        printList(head);
    }
    else
    {
        printf("At last the linked list is..");
        printList(head);
        goto end;
    }
    printf("Want to add more values to linked list press 1...\n  ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        goto addNode;
    }
    else
    {
        printf("At last the linked list is..");
        printList(head);
    }

end:
    return 0;
}
void printList(struct node *head)
{
    struct node *temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}
