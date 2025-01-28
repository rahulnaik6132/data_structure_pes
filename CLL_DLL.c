#include <stdio.h>
#include <stdlib.h>

typedef struct MyNode
{
    int data;
    struct MyNode *rptr, *lptr;
} *NODE;

NODE create_node(int data)
{
    NODE new_node = (NODE)malloc(sizeof(struct MyNode));
    if (new_node == NULL)
    {
        printf("Empty Memory");
    }
    new_node->data = data;
    new_node->rptr = new_node;
    new_node->lptr = new_node;
    return new_node;
}

NODE go_last(NODE HEADER)
{
    if (HEADER == NULL || HEADER->rptr == HEADER)
    {
        return HEADER;
    }
    NODE temp = HEADER;
    while (temp->rptr != HEADER)
    {
        temp = temp->rptr;
    }
    return temp;
}

void display(NODE HEADER)
{
    if (HEADER == NULL)
    {
        printf("empty list");
    }
    NODE temp = HEADER;
    printf("HEADER-> ");
    do
    {
        printf("%d-> ", temp->data);
        temp = temp->rptr;
    } while (temp != HEADER);
    printf(" HEADER\n");
}

NODE ins_front(NODE HEADER, int data)
{
    NODE new_node = create_node(data);
    if (new_node == NULL)
    {
        return HEADER;
    }
    if (HEADER == NULL)
    {
        HEADER = new_node;
    }
    else
    {
        //     NODE prev = go_last(HEADER);
        //     prev->rptr = new_node;
        //     new_node->lptr = prev;
        //     new_node->rptr = HEADER;
        //     HEADER->lptr = new_node;
        //     HEADER = new_node;
        NODE temp = HEADER;
        while (temp->rptr != HEADER)
        {
            temp = temp->rptr;
        }
        temp->rptr = new_node;
        new_node->lptr = temp->rptr;
        new_node->rptr = HEADER;
        HEADER->lptr = new_node;
        HEADER = new_node;
    }

    display(HEADER);
    return HEADER;
}

NODE ins_end(NODE HEADER, int data)
{
    NODE new_node = create_node(data);
    NODE temp = HEADER;
    while (temp->rptr != HEADER)
    {
        temp = temp->rptr;
    }
    HEADER->lptr = new_node->rptr;
    new_node->rptr = HEADER;
    new_node->lptr = temp->rptr;
    temp->rptr = new_node;
    display(HEADER);
    return HEADER;
}

int main()
{
    NODE HEADER = NULL;
    HEADER = ins_front(HEADER, 12);
    HEADER = ins_front(HEADER, 24);
    HEADER = ins_front(HEADER, 32);
    HEADER = ins_end(HEADER,1000);
}