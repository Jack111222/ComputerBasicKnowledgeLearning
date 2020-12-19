#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

/*creating linked list by tail inserting method*/
LNode *Create_LinkList()
{
    int data;
    LNode *head = NULL, *tail = NULL, *p = NULL;

    //create head node
    head = tail = (LNode *)malloc(sizeof(LNode));
    tail->next = NULL;

    //create linked list
    while(1)
    {
        scanf("%d", &data);
        if(data == 0)
        {
            break;
        }
        else
        {
            p = (LNode *)malloc(sizeof(LNode));
            p->data = data;  //data field assigment
            p->next = NULL;
            tail->next = p;
            tail = p;  //the new created node is always the last node
        }
    }

    return head;
}

LNode *Merge_LinkList(LNode *La, LNode *Lb)
{
    LNode *pa = La->next, *pb = Lb->next, *ptr = NULL;
    LNode *Lc = NULL, *pc = NULL;
    Lc = (LNode *)malloc(sizeof(LNode));
    Lc->next =NULL;
    pc = Lc;

    printf("111\n");
    while((pa != NULL) && (pb != NULL))
    {
        if(pa->data < pb->data)
        {
            printf("333\n");
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        if(pa->data > pb->data)
        {
            printf("444\n");
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        if(pa->data == pb->data)
        {
            printf("555\n");
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            ptr = pb;
            pb = pb->next;
            free(ptr);
        }
    }
    printf("222\n");
    if(pa != NULL)
    {
        pc->next = pa;
    }
    else
    {
        pc->next = pb;
    }
    free(Lb);

    return Lc;
}

int main()
{
    LNode *La = NULL, *Lb = NULL, *Lc = NULL, *p = NULL;

    printf("La:\n");
    La = Create_LinkList();
    printf("La:\n");
    p = La->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    printf("Lb:\n");
    Lb = Create_LinkList();
    printf("Lb:\n");
    p = Lb->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    Lc = Merge_LinkList(La, Lb);
    printf("Lc:\n");
    p = Lc->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
    }
    printf("\n");

    return 0;
}
