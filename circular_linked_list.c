#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} nodetype;

int insert(nodetype **l, nodetype **r, int element, int pos)
{
    nodetype *iter;
    nodetype *temp=(nodetype*) malloc (sizeof(nodetype));
    temp->info=element;
    if(pos==1)
    {
        temp->next=*l;
        *l=temp;
        if(*r==NULL)
            *r=*l;
        (*r)->next=*l;
    }
    else if(pos==-1)
    {
        if(*r==NULL)
            *l=temp;
        else
            (*r)->next=temp;
        *r=temp;
        (*r)->next=*l;
    }
    else
    {
        iter=*l;
        pos--;
        if(iter==NULL)
            return -1;
        while(--pos)
        {
            iter=iter->next;
            if(iter==*l)
                return -1;
        }
        temp->next=iter->next;
        iter->next=temp;
        if(temp->next==*l)
            *r=temp;
    }
    return 0;
}

int delete(nodetype **l, nodetype **r, int pos)
{
    nodetype *iter;
    nodetype *temp;
    if(*l==NULL)
        return -1;
    if(pos==1)
    {
        temp=*l;
        if((*l)->next!=*l)
        {
            *l=(*l)->next;
            (*r)->next=*l;
        }
        else
        {
            *l=NULL;
            *r=NULL;
        }
    }
    else if(pos==-1)
    {
        iter=*l;
        if((*l)->next!=*l)
        {
            while(iter->next->next!=*l)
            {
                iter=iter->next;
            }
            temp=iter->next;
            iter->next=*l;
            *r=iter;
        }
        else
        {
            *l=NULL;
            *r=NULL;
        }
    }
    else
    {
        iter=*l;
        pos--;
        if(iter==NULL)
            return -1;
        while(--pos)
        {
            iter=iter->next;
            if(iter==*l)
                return -1;
        }
        temp=iter->next;
        iter->next=iter->next->next;
        if(iter->next==*l)
            *r=iter;
    }
    free(temp);
    return 0;
}

int search(nodetype *l, int element)
{
    int index=0;
    nodetype *iter=l;
    if(iter!=NULL)
    {
        do
        {
            if(iter->info==element)
                return index;
            index++;
            iter=iter->next;
        }while(iter!=l);
    }
    return -1; //returns -1 in case of the element not found
}

void display(nodetype *l)
{
    nodetype *iter=l;
    if(l==NULL)
        return;
    do
    {
        printf("%d ", iter->info);
        iter=iter->next;
    }while(iter!=l);
    printf("\n");
}

void delete_all(nodetype **l, nodetype **r)
{
    if(*l==NULL)
        return;
    nodetype *t;
    (*r)->next=NULL;
    while(*l!=NULL)
    {
        t=*l;
        *l=(*l)->next;
        free(t);
    }
}


int main()
{
    nodetype *l=NULL, *r=NULL;
    int ch, pos, element, ind;
    char ch2;
    while(1)
    {
        printf("Enter:\n1 to insert an element \n2 to delete an element\n3 to display the list\n4 to search an element\nEnter choice: ");
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
        case 4:
            printf("Enter element: ");
            scanf("%d", &element);
            ind=search(l,element);
            if(ind==-1)
                printf("Element not found!\n");
            else
                printf("Element found at index %d\n", ind);
        }
        printf("Do you want to continue? Y/N: ");
        scanf("\n%c", &ch2);
        if(ch2=='n'||ch2=='N')
            break;
    }
    delete_all(&l, &r);
    return 0;
}
