#include <stdio.h>
#include <stdlib.h>

//Structure of nodes in list :-
struct node
{
    int info;
    struct node *link;
};
struct node *insertValue(struct node *, int);

int main()
{
    int n;
    int counter=0;
    scanf("%d", &n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->link=NULL;
    struct node *temp;
    for (int i = 0; i < n; i++)
    {
        counter++;
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
            new->link=NULL;
            temp->link = new;
            temp = temp->link;
        }
    }
    int k;
    scanf("%d", &k);
    head = insertValue(head, k);
    temp=head;
    // printf("%d",temp->info);
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp=temp->link;
    }
    
    printf("The no. of steps took to complete the insertion was %d", counter);
    return 0;
}

struct node *insertValue(struct node *head, int k)
{
    struct node *temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = k;
    new->link=NULL;
    if (head->info > k)
    {
        new->link = head;
        head = new;
        return head;
    }
    while (temp->link != NULL)
    {
        if (temp->link->info > k)
        {
            new->link = temp->link;
            temp->link = new;
            return head;
        }
        temp = temp->link;
    }
    temp->link=new;
    return head;
}
