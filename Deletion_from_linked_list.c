#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *removeValue(struct node *, int);

int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->link = NULL;
    struct node *temp;
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        if (i == 0)
        {
            head->info = value;
            temp = head;
        }
        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->info = value;
            new->link = NULL;
            temp->link = new;
            temp = temp->link;
        }
    }
    int k;
    scanf("%d", &k);
    head = removeValue(head, k);
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }

    return 0;
}
struct node *removeValue(struct node *head, int k)
{
    struct node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }

    if (k == 1)
    {
        head = head->link;
        free(temp);
        return head;
    }
    struct node *prev = head;
    temp = head->link;
    while (temp != NULL)
    {
        if (temp->info == k)
        {
            prev->link = temp->link;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->link;
    }

    return head;
}

