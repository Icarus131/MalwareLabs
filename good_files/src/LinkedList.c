#include<stdio.h>
#include<stdlib.h>

#define llNULL -0x1a7e

typedef struct Node
{
    int val;
    struct Node* next;
}Node;


typedef struct LinkedList
{
    Node* start;
    Node* end;
    int length;
}LinkedList;

void init(LinkedList *self)
{
    self->start = (Node*)malloc(sizeof(Node));
    self->start->val = llNULL;
    self->end = self->start;
    self->length = 0;
}

void clear(LinkedList *self)
{
    Node* curr;
    for(curr=self->start; curr != self->end; curr = curr->next)
    {
        printf("freed (%x)\n", (unsigned int)curr);
        free(curr);
    }
    free(self->end);
    printf("freed (%x)\n", (unsigned int)self->end);
    init(self);
}

int insert(LinkedList *self, int value)
{
    if(self->start->val == llNULL)
    {
        self->start->val = value;
        // printf("Initialised value for %d", value);
        self->length = 1;
        return 0;
    }
    Node *new_loc = (Node*)malloc(sizeof(Node));
    self->end->next = new_loc;
    self->end = self->end->next;
    self->end->val = value;
    self->length += 1;
    // printf("\nset end value to %d", value);
    return 0;
}

void printLL(LinkedList *myll)
{
    Node *curr = myll->start;
    if(curr == myll->end)
    {
        printf("%d", curr->val);
        // printf("Ran this instead");
        return;
    }
    while(1){
        printf("%d", curr->val);
        curr = curr->next;
        if(curr == myll->end)
        {
            printf("%d", curr->val);
            break;
        }
    }
}

int get(LinkedList *l, int n)
{
    if(n+1 > l->length)
    {
        return llNULL;
    }
    Node* curr = l->start;
    for(int i=0; i<n; i++)
        curr = curr->next;
    return curr->val;

}


int main(int argc, char const *argv[])
{
    // testing my linked list
    LinkedList myll;
    init(&myll);
    insert(&myll, 2);
    insert(&myll, 5);
    insert(&myll, 6);
    clear(&myll);
    printf("%d", myll.start->val);
    return 0;
}
