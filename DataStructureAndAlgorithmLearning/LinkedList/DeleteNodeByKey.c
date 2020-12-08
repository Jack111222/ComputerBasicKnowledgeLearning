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
void Delete_LinkList(LNode *L, int key)
{
    LNode *p = NULL, *q = NULL;

    p = L;
    q = L->next;
    while((q != NULL) && (q->data != key))
    {
        p = q;
        q = q->next;
    }
    if((q != NULL) && (q->data == key))
    {
        p->next = q->next;
        free(q);
        q = NULL;
    }
    else
    {
        printf("There is no node to delete!!\n");
    }
}

int main()
{
    LNode *head = NULL, *p = NULL;
    int key;

    head = Create_LinkList();
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    printf("key: ");
    scanf("%d", &key);
    Delete_LinkList(head, key);
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
