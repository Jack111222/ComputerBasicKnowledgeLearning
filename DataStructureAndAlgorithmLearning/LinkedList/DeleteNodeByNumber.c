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

/*delete node by number*/
void Delete_LinkList(LNode *L, int i)
{
    LNode *p = NULL, *q = NULL;
    int j = 1;

    p = L;
    q = L->next;
    while((q != NULL) && (j < i))
    {
        p = q;
        q = q->next;
        j++;
    }
    if(j != i)
    {
        printf("i is too large or i is 0!!\n");
    }
    else
    {
        p->next = q->next;
        free(q);
    }
}

int main()
{
    LNode *head = NULL, *p = NULL;
    int i;

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
    Delete_LinkList(head, i);
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
