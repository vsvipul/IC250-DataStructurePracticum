#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char c;
    struct node* link;
};
typedef struct node NODE;

void display(NODE *start)
{
    NODE *p;
    if (start==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    p=start;
    while (p!=NULL)
    {
        printf("%c",p->c);
        p=p->link;
    }
}

NODE *insert(NODE *start, char data)
{
    NODE *tmp;
    tmp=(NODE *)malloc(sizeof(NODE));
    if (tmp==NULL)
    {
        printf("Segmentation Fault");
        exit(0);
    }
    tmp->c=data;
    tmp->link=NULL;
    if (start==NULL)
    {
        start=tmp;
    }
    else
    {
        NODE *p=start;
        while (p->link!=NULL)
            p=p->link;
        p->link=tmp;
    }
    return start;
}

NODE *reverse(NODE* start)
{
    NODE *prev,*next,*p;
    prev=NULL;
    p=start;
    while (p!=NULL)
    {
        next=p->link;
        p->link=prev;
        prev=p;
        p=next;
    }
    start=prev;
    return start;
}

int main()
{
    NODE* start=NULL;
    char str[100];
    int i;
    while (scanf(" %[^\n]",str) && strcmp(str,"END")!=0)
    {
        for (i=strlen(str)-1;i>=2;i--)
            start=insert(start, str[i]);
    }
    start=reverse(start);
    display(start);
    return 0;
}
