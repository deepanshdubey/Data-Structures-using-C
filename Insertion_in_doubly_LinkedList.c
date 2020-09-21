#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *insertValue(struct node *, int, int);

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
    int index;
    scanf("%d %d", &value, &index);
    head = insertValue(head, value, index);
    current = head;
    while (current->next != NULL)
    {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("%d\n", current->info);

    while (current != NULL)
    {
        printf("%d ", current->info);
        current = current->prev;
    }

    return 0;
}

struct node *insertValue(struct node *head, int value, int index)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = value;
    new->prev = NULL;
    new->next = NULL;
    if (index == 0)
    {
        new->next = head;
        head->prev = new;
        return new;
    }
    int i = 0;
    struct node *current = head;
    struct node *previous;

    while (current != NULL)
    {
        if (i == index)
        {
            previous->next = new;
            new->prev = previous;
            new->next = current;
            current->prev = new;
            return head;
        }
        i++;
        previous = current;
        current = current->next;
    }
    previous->next = new;
    new->prev = previous;

    return head;
}
