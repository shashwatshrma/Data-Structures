#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} nodetype;

void push(nodetype **top, int element)
{
    nodetype *temp=(nodetype*) malloc (sizeof(nodetype));
    temp->info=element;
    temp->next=*top;
    *top=temp;
}

int pop(nodetype **top)
{
    int element=(*top)->info;
    nodetype *temp=*top;
    *top=(*top)->next;
    free(temp);
    return element;
}

void enqueue(nodetype **st, int element)
{
    push(st,element);
}

int dequeue(nodetype **st1)
{
    if(*st1==NULL)
        return -1;
    int element;
    nodetype *st2=NULL;
    while((*st1)!=NULL)
        push(&st2, pop(st1));
    element=pop(&st2);
    while(st2!=NULL)
        push(st1, pop(&st2));
    return element;
}

void display(nodetype *queue)
{
    if(queue==NULL)
        return;
    display(queue->next);
    printf("%d ",queue->info);
}

void delete_all(nodetype **st)
{
    nodetype * t;
    while(*st!=NULL)
    {
        t=*st;
        *st=(*st)->next;
        free(t);
    }
}

int main()
{
    nodetype *queue=NULL;
    int ch, element;
    char ch2;
    while(1)
    {
        printf("Enter:\n1 to enqueue an element\n2 to dequeue an element\n3 to display the queue\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter element to be enqueued: ");
            scanf("%d", &element);
            enqueue(&queue, element);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            display(queue);
            printf("\n");
        }
        printf("Do you want to continue? Y/N: ");
        scanf("\n%c", &ch2);
        if(ch2=='n'||ch2=='N')
            break;
    }
    delete_all(&queue);
    return 0;
}
