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

/*insert node*/
void Insert_Node(LNode *L, int i, int data)
{
    LNode *p = NULL, *q = NULL;
    int j = 0;

    p = L;
    while((p != NULL) && (j < i - 1))
    {
        p = p->next;
        j++;
    }
    if(j != i - 1)
    {
        printf("i is too large or i is 0!!\n");
    }
    else
    {
        q = (LNode *)malloc(sizeof(LNode));
        q->data = data;
        q->next = p->next;
        p->next = q;
    }
}

int main()
{
    LNode *head = NULL, *p = NULL;
    int i, data = 0;

    head = Create_LinkList();
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    printf("i: ");
    scanf("%d", &i);
    Insert_Node(head, i, data);
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");


    return 0;
}
