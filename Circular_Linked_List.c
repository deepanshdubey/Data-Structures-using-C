#include <stdio.h>
#include <stdlib.h>

//Structure of node :-
struct node
{
    int info;
    struct node *link;
};

struct node *insertValue(struct node *, int);

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
    temp->link = head;
    int k;
    scanf("%d", &k);

    return 0;
}

struct node *insertValue(struct node *head, int k)
{
    struct node *new = (struct node *)malloc(sizeof(struct node *));
    new->info = k;
    new->link = NULL;

    if (head == NULL)
    {
        new->link = new;
        return new;
    }

    struct node* last=head;
    while(last->link!=head){
        last=last->link;
    }
    //Insertion in beginning
    
}
