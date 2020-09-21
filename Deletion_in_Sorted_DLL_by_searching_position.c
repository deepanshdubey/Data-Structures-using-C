#include <stdio.h>
#include <stdlib.h>

struct node *deletionBySearchingPosition(struct node *, int);
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

    struct node *temp = head;
    // printf("\n");
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

struct node *deletionBySearchingPosition(struct node *head, int value)
{
    if(hasValue(head,value)){
        if(head->info==value){
            
        }


    }
    else{
        return NULL;
    }
}

int hasValue(struct node* head,int value){
    struct node* temp=head;
    while (temp!=NULL)
    {
        if(temp->info==value){
            return 1;
        }
    temp=temp->next;
    }
    
    return 0;
}