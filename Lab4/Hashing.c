#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int id;
	char fn[20],ln[20],dob[20],city[20],dep[20];
	struct node *link;
};
typedef struct node NODE;

NODE* hashtable[587];

NODE *insert(NODE *start, int idt, char fnt[], char lnt[], char dobt[], char cityt[], char dept[])
{
	NODE *tmp=(NODE *)malloc(sizeof(NODE));
	if (tmp==NULL)
	{
		printf("Segmentation Fault\n");
		exit(0);
	}
	tmp->id=idt;
	strcpy(tmp->fn,fnt);
	strcpy(tmp->ln,lnt);
	strcpy(tmp->dob,dobt);
	strcpy(tmp->city,cityt);
	strcpy(tmp->dep,dept);
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

void count(NODE *start)
{
    NODE *p;
    p=start;
    int res=0;
    while (p!=NULL)
    {
        res++;
        p=p->link;
    }
    printf("%d\n",res);
}

int main()
{
	int i;
	for (i=0;i<587;i++)
		hashtable[i]=NULL;
	int idt;
	char fnt[20],lnt[20],dobt[20],cityt[20],dept[20];
	while (scanf(" %d %s%s%s%s%s",&idt,fnt,lnt,dobt,cityt,dept)!=EOF)
	{
		hashtable[idt%587]=insert(hashtable[idt%587],idt,fnt,lnt,dobt,cityt,dept);
	}
	for (i=0;i<587;i++)
	{
        if (hashtable[i]!=NULL)
        {
		    printf("%d	",i);
            count(hashtable[i]);
        }
	}
    return 0;
}
