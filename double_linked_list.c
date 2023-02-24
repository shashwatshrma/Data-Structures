#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
} nodetype;

int insert(nodetype **l, nodetype **r, int element, int pos)
{
    nodetype *iter=*l;
    nodetype *temp=(nodetype*) malloc (sizeof(nodetype));
    temp->info=element;
    if(pos==1)
    {
        temp->next=*l;
        temp->prev=NULL;
        *l=temp;
        if(*r==NULL)
            *r=*l;
    }
    else if(pos==-1)
    {
        if(*r==NULL)
            *l=temp;
        else
            (*r)->next=temp;
        temp->prev=*r;
        *r=temp;
        (*r)->next=NULL;
    }
    else
    {
        pos--;
        while(--pos && iter!=NULL)
        {
            iter=iter->next;
        }
        if(iter==NULL)
            return -1;
        temp->next=iter->next;
        temp->next->prev=temp;
        iter->next=temp;
        temp->prev=iter;
    }
    return 0;
}

int delete(nodetype **l, nodetype **r, int pos)
{
    nodetype *iter=*l;
    nodetype *temp;
    if(*l==NULL)
        return -1;
    if(pos==1)
    {
        temp=*l;
        *l=(*l)->next;
        (*l)->prev=NULL;
    }
    else if(pos==-1)
    {
        if(iter->next==NULL)
        {
            temp=iter;
            *l=NULL;
            *r=NULL;
        }
        else
        {
            while(iter->next->next!=NULL)
            {
                iter=iter->next;
            }
            temp=iter->next;
            iter->next=NULL;
            *r=iter;
        }
    }
    else
    {
        pos--;
        while(--pos && iter!=NULL)
        {
            iter=iter->next;
        }
        if(iter==NULL)
            return -1;
        temp=iter->next;
        iter->next=iter->next->next;
        iter->next->prev=iter;
    }
    free(temp);
    return 0;
}

int search(nodetype *l, int element)
{
    int index=0;
    while(l!=NULL)
    {
        if(l->info==element)
            return index;
        index++;
    }
    return -1; //returns -1 in case of the element not found
}

void display(nodetype *l)
{
    while(l!=NULL)
    {
        printf("%d ", l->info);
        l=l->next;
    }
    printf("\n");
}

void delete_all(nodetype **l)
{
    nodetype *temp;
    while(*l!=NULL)
    {
        temp=*l;
        *l=(*l)->next;
        free(temp);
    }
}

int main()
{
    nodetype *l=NULL, *r=NULL;
    int ch, pos, element;
    char ch2;
    while(1)
    {
        printf("Enter:\n1 to insert an element \n2 to delete an element\n3 to display the list\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert(&l, &r, element, pos);
            break;
        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete(&l, &r, pos);
            break;
        case 3:
            display(l);
            break;
        }
        printf("Do you want to continue? Y/N: ");
        scanf("\n%c", &ch2);
        if(ch2=='n'||ch2=='N')
            break;
    }
    delete_all(&l);
    return 0;
}
