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

int Get_Data(LNode *L, int i)
{
    LNode * p = NULL;
    int j = 1;

    p = L->next;
    while((p != NULL) && (j < i))
    {
        p = p->next;
        j++;
    }
    if(j!=i)
    {
        return (-1);
    }
    else
    {
        return (p->data);
    }
}

int main()
{
    LNode *head = NULL, *p = NULL;
    int data;
    int position;

    head = Create_LinkList();
    p = head->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
    printf("position: ");
    scanf("%d", &position);
    data = Get_Data(head, 3);
    printf("%d\n", data);

    return 0;
}
