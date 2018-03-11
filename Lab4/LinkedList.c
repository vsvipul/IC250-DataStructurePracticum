#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char name[100];
	char roll[100];
	int marks;
    struct node *link;
};
typedef struct node NODE;

NODE *insert(NODE* start, char nam[], char rol[], int mark)
{
	NODE *tmp = (NODE*) malloc(sizeof(NODE));
	strcpy(tmp->name, nam);
	strcpy(tmp->roll, rol);
	tmp->marks=mark;
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

NODE *del(NODE *start, char rol[])
{
	if (start==NULL)
	{
        printf("Already empty!\n");
        return start;
    }
	NODE *tmp;
	if (strcmp(start->roll,rol)==0)
	{
		tmp=start;
		start=start->link;
		free(tmp);
		return start;
	}
	else
	{
        NODE *p=start;
		while (p->link!=NULL)
		{
			if (strcmp(p->link->roll,rol)==0)
			{
				tmp=p->link;
				p->link=tmp->link;
				free(tmp);
				return start;
			}
			p=p->link;
		}
	}
	printf("Record Not Found!\n");
    return start;
}

void ser(NODE* start, char rol[])
{
	NODE *p=start;
	while (p!=NULL)
	{
		if (strcmp(p->roll,rol)==0)
		{
			printf("%s %s %d\n",p->name,p->roll,p->marks);
			return;
		}
		p=p->link;
	}
	printf("Record Not Found\n");
}

int main()
{
	char t;
	char nam[100];
	char rol[100];
	int mark;
	NODE *start=NULL;
	while (scanf(" %c",&t)!=EOF)
	{
		if (t=='A')
		{
			scanf(" %s%s%d", nam, rol, &mark);
			start=insert(start,nam,rol,mark);
		}
		else if (t=='L')
		{
			count(start);
		}
		else if (t=='D')
		{
			scanf(" %s", rol);
			start=del(start,rol);
		}
		else if (t=='S')
		{
			scanf(" %s", rol);
			ser(start,rol);
		}
	}  	
    return 0;
}
