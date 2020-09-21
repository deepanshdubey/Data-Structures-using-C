#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
int searchValue(struct node *, int);
int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
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
            temp->link = new;
            temp = temp->link;
        }
        
    }
    int k;
    scanf("%d", &k);
    int position = searchValue(head, k);
    printf("%d", position);
    return 0;
}

int searchValue(struct node *head, int k)
{
    struct node *temp = head;
    int i = 1;
    while (temp != NULL)

    {
        if (temp->info > k)
        {
            return -1;
        }
        else if (temp->info == k)
        {
            return i;
        }
        temp = temp->link;
        i++;
    }
    return -1;
}
