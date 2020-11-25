#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

/*creating linked list by head inserting method*/
LNode *Create_LinkList()
{
    int data;
    LNode *head = NULL, *p = NULL;

    //create head node
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;

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
            p->next = head->next;
            head->next = p;  //the new created node is always the first node
        }
    }

    return head;
}

int main()
{
    LNode *p;

    p = Create_LinkList();
    p = p->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");

    return 0;
}
