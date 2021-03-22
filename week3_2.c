/*
This program is not perfect and has a segmentation fault which I can not solve.
*/
#include <stdio.h>
#include <stdlib.h>

//create 2 structs;

typedef struct list
{
    int data;
    struct list *next;
}list;
typedef struct lista
{
    double data;
    struct lista *next;
}lista;

//create a node;

list *create()
{   
    list *origin=(list *)malloc(sizeof(list));
    origin->data=rand()%50;
    origin->next=NULL;
    return origin;
}

//generate a list of random number

list *generate()
{
    list *head=(list *)malloc(sizeof(list));
    head->next=NULL;
    list *ptr=(list *)malloc(sizeof(list));
    for(int i=0;i<200;i++)
    {
    ptr=create();
    ptr->next=head->next;
    head->next=ptr;
    }
    return head;
}

//convert int to double

lista *convert(list *origin)
{ 
    lista *head=(lista *)malloc(sizeof(lista));
    head->next=NULL;
    list *p=(list *)malloc(sizeof(list)),
    *pf=(list *)malloc(sizeof(list));
    p=origin;
    pf=origin;
    for(int i=0;i<200;i++)
    {
    lista *ptr=(lista *)malloc(sizeof(lista));
    p=pf->next;
    ptr->data=(double)p->data;
    ptr->next=head->next;
    head->next=ptr;
    pf=p;
    }
    return head;
}

//bubble sort

lista *bubblesort(lista *origin)
{
    int flag=0;
    double tem;
    lista *p=(lista *)malloc(sizeof(lista)),
    *head=(lista *)malloc(sizeof(lista)),
    *tail=(lista *)malloc(sizeof(lista));
    p=origin;
    head=origin;
    tail=origin;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    while(p->next!=tail)
    {
        flag=0;
        head=p->next;
        while(head->next!=tail)
        {
            if(head->data>head->next->data)
            {
                tem=head->data;
                head->data=head->next->data;
                head->next->data=tem;
                flag=1;
            }
            head=head->next;
        }
        if(head->data>tail->data)
        {
            tem=head->data;
            head->data=tail->data;
            tail->data=tem;
            flag=1;
        }
        tail=head;
        if(flag==0) break;
    }
    return head;
}

//remove the same number

lista *remove(lista *aforigin)
{
    lista *p=(lista *)malloc(sizeof(lista)),
    *ptr=(lista *)malloc(sizeof(lista)),
    *head=(lista *)malloc(sizeof(lista));
    head=aforigin->next;
    p=aforigin->next;
    ptr=aforigin->next;
    while(ptr->next!=NULL)
    {
        ptr=p->next;
        if(p->data==ptr->data)
        {   
            p->next=ptr->next;
            free(ptr);
            ptr=p->next;
        }
        else
        {
            head=p;
            p=head->next;
        }
    }
    if(ptr->next==NULL&&p->data==ptr->data)
    p->next=ptr->next;
    return aforigin;
}

//print the list

int main(void)
{
    lista *a=(lista *)malloc(sizeof(lista));
    a=remove(bubblesort(convert(generate())));
    a=a->next;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%.3lf\t",a->data);
            a=a->next;
        }
        printf("\n");
    }
    free(a);
    system("pause");
}