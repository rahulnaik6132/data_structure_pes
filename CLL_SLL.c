// #include <stdio.h>
// #include <stdlib.h>
// typedef struct myNODE
// {
//     int data;
//     struct myNODE *link;
// } *NODE;

// NODE create_node(int data)
// {
//     NODE new_node = (NODE)malloc(sizeof(struct myNODE));
//     if (new_node == NULL)
//     {
//         printf("No Memory");
//         return NULL;
//     }
//     new_node->data = data;
//     new_node->link = new_node;
//     printf("%d is created\n", data);
//     return new_node;
// }

// NODE display(NODE HEADER)
// {
//     NODE temp = HEADER;    if (HEADER == NULL)
//     {
//         printf("Empty list");
//     }
//     printf("HEADER-> ");
//     do
//     {
//         printf("%d-> ", temp->data);
//         temp = temp->link;
//     } while (temp != HEADER);
//     printf("HEADER\n\n");
// }

// NODE go_last(NODE HEADER)
// {
//     if (HEADER == NULL || HEADER->link == HEADER)
//     {
//         return HEADER;
//     }
//     NODE temp = HEADER;
//     while (temp->link != HEADER)
//     {
//         temp = temp->link;
//     }
//     return temp;
// }

// NODE ins_front(NODE HEADER, int data)
// {
//     NODE new_node = create_node(data);
//     if (HEADER == NULL)
//     {
//         return new_node;
//     }
//     if (new_node == NULL)
//     {
//         return HEADER;
//     }
//     (go_last(HEADER))->link = new_node;
//     new_node->link = HEADER;
//     HEADER = new_node;
//     display(HEADER);
//     return HEADER;
// }

// NODE ins_end(NODE HEADER, int data)
// {
//     NODE new_node = create_node(data);
//     go_last(HEADER)->link = new_node;
//     new_node->link = HEADER;
//     display(HEADER);
//     return HEADER;
// }

// NODE del_front(NODE HEADER)
// {
//     NODE temp = HEADER;
//     go_last(HEADER)->link = HEADER->link;
//     printf("%d is deleted\n", temp->data);
//     HEADER = HEADER->link;
//     free(temp);
//     display(HEADER);
// }

// NODE del_last(NODE HEADER)
// {
//     NODE temp = HEADER;
//     while (temp->link != HEADER)
//     {
//         temp = temp->link;
//     }
//     NODE ptr = go_last(HEADER)->link;
//     ptr->link = HEADER;
//     free(temp);
//     display(HEADER);
// }

// NODE ins_pos(NODE HEADER, int pos, int data)
// {
//     int i = 1;
//     NODE temp = HEADER;
//     if (pos <= 1)
//     {
//         return ins_front(HEADER, data);
//     }
//     printf("\n%d Pos\n", pos);
//     while (temp->link != HEADER && i < pos - 1)
//     {
//         temp = temp->link;
//         i++;
//     }
//     if (temp->link == HEADER && i < pos - 1)
//     {
//         printf("\nWrong Position\n");
//         return NULL;
//     }
//     NODE new_node = create_node(data);
//     if (new_node == NULL)
//     {
//         printf("\nNo Memory\n");
//     }
//     else
//     {
//         new_node->link = temp->link;
//         temp->link = new_node;
//     }
//     display(HEADER);
// }

// NODE del_pos(NODE HEADER, int pos)
// {
//     NODE curr = HEADER;
//     int i = 1;
//     if (pos <= 1)
//     {
//         return del_front(HEADER);
//     }
//     while (curr->link != HEADER && i < pos - 1)
//     {
//         // prev = curr;
//         curr = curr->link;
//         i++;
//     }
//     if (curr->link == HEADER)
//     {
//         printf("\nOut of range");
//         return NULL;
//     }
//     NODE prev = curr->link;
//     curr->link = prev->link;
//     printf("\n%d pos and %d data\n", pos, prev->data);
//     free(prev);
//     prev = NULL;
//     display(HEADER);
// }

// NODE ins_order(NODE HEADER, int data)
// {
//     NODE new_node = create_node(data);
//     int key = new_node->data;
//     NODE temp = HEADER;
//     if (temp->data >= key)
//     {
//         return ins_front(HEADER, data);
//     }
//     while (temp->link != HEADER && temp->link->data < key)
//     {
//         temp = temp->link;
//     }
//     new_node->link = temp->link;
//     temp->link = new_node;
//     display(HEADER);
// }

// NODE rev_list(NODE HEADER)
// {
//     if (HEADER == NULL)
//     {
//         printf("Empty List");
//         return HEADER;
//     }
//     NODE prev = NULL;
//     NODE curr = HEADER;
//     NODE next = NULL;
//     do
//     {
//         next = curr->link;
//         curr->link = prev;
//         prev = curr;
//         curr = next;
//     } while (curr != HEADER);
//     HEADER->link = prev;
//     HEADER = prev;
//     display(HEADER);
//     return HEADER;
// }

// int main()
// {
//     NODE HEADER = NULL;
//     HEADER = ins_front(HEADER, 30);
//     HEADER = ins_front(HEADER, 20);
//     HEADER = ins_front(HEADER, 10);
//     // printf("\nEnd NODE\n");
//     // HEADER = ins_end(HEADER, 5000);
//     // printf("\nDeletion\n");
//     // HEADER = del_front(HEADER);
//     // HEADER = del_last(HEADER);
//     // HEADER = del_pos(HEADER, 2);
//     // printf("\nPosition Method\n");
//     // HEADER = ins_pos(HEADER, 1, 1000);
//     // printf("\nOrder\n");
//     // HEADER = ins_order(HEADER, 32);
//     printf("\nReverse list\n");
//     HEADER = rev_list(HEADER);
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct myNode
{
    int data;
    struct myNode *link;
} *NODE;

NODE create_node(int data)
{
    NODE new_node = (NODE)malloc(sizeof(struct myNode));
    if (new_node == NULL)
    {
        printf("No Memory");
    }
    new_node->data = data;
    new_node->link = new_node;
    printf("\n%d is created", data);
    return new_node;
}

void display(NODE HEADER)
{
    if (HEADER == NULL)
    {
        printf("List is Empty");
    }
    NODE temp = HEADER;
    printf("\nHEADER-> ");
    do
    {
        printf("%d-> ", temp->data);
        temp = temp->link;
    } while (temp != HEADER);
    printf("HEADER\n\n");
}

NODE go_last(NODE HEADER)
{
    if (HEADER == NULL || HEADER->link == HEADER)
    {
        return HEADER;
    }
    NODE temp = HEADER;
    while (temp->link != HEADER)
    {
        temp = temp->link;
    }
    return temp;
}

NODE ins_front(NODE HEADER, int data)
{
    NODE new_node = create_node(data);
    if (HEADER == NULL)
    {
        return new_node;
    }
    if (new_node == NULL)
    {
        return HEADER;
    }
    (go_last(HEADER))->link = new_node;
    new_node->link = HEADER;
    HEADER = new_node;
    display(HEADER);
    return HEADER;
}

NODE ins_end(NODE HEADER, int data)
{
    NODE new_node = create_node(data);
    if (new_node == NULL)
    {
        printf("No Memory;");
    }
    go_last(HEADER)->link = new_node;
    new_node->link = HEADER;
    display(HEADER);
    return HEADER;
}

NODE ins_pos(NODE HEADER, int pos, int data)
{
    NODE temp = HEADER;
    int i = 1;
    if (pos <= 1)
    {
        return ins_front(HEADER, data);
    }
    while (temp->link != HEADER && i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    if (temp->link == HEADER && i < pos - 1)
    {
        printf("\nOut of range");
    }
    NODE new_node = create_node(data);
    if (new_node == NULL)
    {
        printf("NO MEMORY");
    }
    else
    {
        new_node->link = temp->link;
        temp->link = new_node;
    }
    display(HEADER);
}

NODE ins_order(NODE HEADER, int data)
{
    NODE new_node = create_node(data);
    if (new_node == NULL)
    {
        printf("\nList Is Empty\n");
    }
    NODE temp = HEADER;
    int key = new_node->data;
    if (temp->data >= key)
    {
        return ins_front(HEADER, data);
    }
    while (temp->link != HEADER && temp->link->data < key)
    {
        temp = temp->link;
    }
    new_node->link = temp->link;
    temp->link = new_node;
    display(HEADER);
}

NODE del_front(NODE HEADER)
{
    if (HEADER == NULL)
    {
        printf("Emptylist can't delete");
    }
    NODE temp = HEADER;
    go_last(HEADER)->link = HEADER->link;
    printf("\n%d is deleted\n", temp->data);
    HEADER = HEADER->link;
    free(temp);
    display(HEADER);
}

NODE del_last(NODE HEADER)
{
    if (HEADER == NULL || HEADER->link == HEADER)
    {
        free(HEADER);
        return NULL;
    }
    NODE temp = HEADER;
    while (temp->link->link != HEADER)
    {
        temp = temp->link;
    }
    printf("\n%d is deleted from last\n", temp->link->data);
    free(temp->link);
    temp->link = HEADER;
    display(HEADER);
}

NODE del_val(NODE HEADER, int key)
{
    NODE temp = HEADER;
    NODE curr = NULL;
    if (temp->data == key)
    {
        return del_front(HEADER);
    }
    if (temp->data != key)
    {
        printf("Value not found\n");
        return NULL;
    }
    while (temp->link != HEADER && temp->data != key)
    {
        curr = temp;
        temp = temp->link;
    }
    printf("\n%d is deleted ", temp->data);
    curr->link = temp->link;
    display(HEADER);
    return HEADER;
}

NODE del_pos(NODE HEADER, int pos)
{
    if (HEADER == NULL || HEADER->link == HEADER)
    {
        free(HEADER);
        return NULL;
    }
    NODE temp = HEADER;
    int i = 1;
    while (temp->link != HEADER && i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    NODE prev = temp->link;
    temp->link = prev->link;
    printf("%d",prev->data);
    free(prev);
    prev = NULL;
    display(HEADER);
}

int main()
{
    NODE HEADER = NULL;
    HEADER = ins_front(HEADER, 50);
    HEADER = ins_front(HEADER, 40);
    HEADER = ins_front(HEADER, 30);
    HEADER = ins_front(HEADER, 20);
    HEADER = ins_front(HEADER, 10);
    display(HEADER);
    printf("\nINSERT END\n");
    // HEADER = ins_end(HEADER, 500);
    printf("\nPOSITION\n");
    // HEADER = ins_pos(HEADER, 4, 1500);
    printf("\nORDER\n");
    // HEADER = ins_order(HEADER, 22);
    // HEADER = ins_order(HEADER, 9);
    printf("\nDELETION\n");
    // HEADER = del_front(HEADER);
    // HEADER = del_last(HEADER);
    // HEADER = del_val(HEADER, 60);1
    HEADER = del_pos(HEADER, 3);
}