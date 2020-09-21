#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
    
};

struct node *deleteNode(struct node *, int);
int haveValue(struct node *, int);
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
    if (!haveValue(head, k))
    {
        printf("Value do not exist in linked list");
    }
    else
    {
        head = deleteNode(head, k);
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->link;
        }
    }

    return 0;
}

struct node *deleteNode(struct node *head, int k)
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

int haveValue(struct node *head, int k)
{
    struct node *temp = head;
    int i = 1;
    while (temp != NULL)

    {
        if (temp->info > k)
        {
            return 0;
        }
        else if (temp->info == k)
        {
            return 1;
        }
        temp = temp->link;
        i++;
    }
    return 0;
}
