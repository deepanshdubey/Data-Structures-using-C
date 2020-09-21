#include <stdio.h>
#include <stdlib.h>

struct node *deleteFromLast(struct node *, int);

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    head->prev = NULL;
    struct node *current = head;
    // struct node* previous=NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        if (i == 0)
        {

            current->info = value;
            current->prev = NULL;
        }
        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->info = value;
            new->prev = current;
            new->next = NULL;
            current->next = new;
            current = current->next;
        }
    }
    int value;
    scanf("%d", &value);
    head = deleteFromLast(head, value);

    struct node *temp = head;

    while (temp->next != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("%d\n", temp->info);
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->prev;
    }

    return 0;
}

struct node *deleteFromLast(struct node *head, int value)
{
    struct node *last = head;
    if (head->info == value)
    {
        last = last->next;
        last->prev = NULL;
        free(head);
        return last;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    struct node *next = NULL;
    if (last->info == value)
    {
        next = last->prev;
        next->next = NULL;
        free(last);
        return head;
    }
    //Now last is the last node of the linked list
    while (last != NULL)
    {
        if (last->info == value)
        {
            next->prev = last->prev;
            last->prev->next = next;
            free(last);
            return head;
        }
        next = last;
        last = last->prev;
    }

    return head;
}