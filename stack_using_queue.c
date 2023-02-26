#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} nodetype;

void enqueue(nodetype **f, int element)
{
    nodetype *t=(nodetype*) malloc (sizeof(nodetype)), *iter;
    t->info=element;
    t->next=NULL;
    if(*f==NULL)  //first node
        *f=t;
    else
    {
        iter=*f;
        while(iter->next!=NULL)
            iter=iter->next;
        iter->next=t;
    }
}

int dequeue(nodetype **f)
{
    int element=(*f)->info;
    nodetype *t=*f;
    *f=(*f)->next;
    free(t);
    return element;
}

void push(nodetype **f, int element)
{
    enqueue(f, element);
}

int pop(nodetype **f)
{
    int element;
    if((*f)->next==NULL)
    {
        element=(*f)->info;
        return dequeue(f);
    }
    return pop(&(*f)->next);
}

void display(nodetype *top)
{
    if(top==NULL)
        return;
    display(top->next);
    printf("%d\n",top->info);
}

void delete_all(nodetype **f)
{
    nodetype * t;
    while(*f!=NULL)
    {
        t=*f;
        *f=(*f)->next;
        free(t);
    }
}

int main()
{
    nodetype *top=NULL;
    int ch, element;
    char ch2;
    while(1)
    {
        printf("Enter:\n1 to push an element\n2 to pop an element\n3 to display the stack\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter element to be pushed: ");
            scanf("%d", &element);
            push(&top, element);
            break;
        case 2:
            if(top!=NULL)
                pop(&top);
            break;
        case 3:
            if(top!=NULL)
                display(top);
            break;
        }
        printf("Do you want to continue? Y/N: ");
        scanf("\n%c", &ch2);
        if(ch2=='n'||ch2=='N')
            break;
    }
    delete_all(&top);
    return 0;
}
