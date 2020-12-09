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

/*delete all nodes with the same value*/
void Delete_Node_Value(LNode *L)
{
    LNode *p = L->next, *q = NULL, *ptr = NULL;

    while(p != NULL)
    {
        q = p;
        ptr = p->next;
        while(ptr != NULL)
        {
            if(p->data == ptr->data)
            {
                q->next = ptr->next;
                free(ptr);
                ptr = q->next;
            }
            else
            {
                q = ptr;
                ptr = ptr->next;
            }
        }
        p = p->next;
    }
}

int main()
{
    LNode *head = NULL, *p = NULL;

    head = Create_LinkList();
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    Delete_Node_Value(head);
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
