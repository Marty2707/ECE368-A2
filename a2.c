#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node_t
{
    struct _Node_t* next;
    int window;
    
} Node_t;

static void printlist(Node_t* a_head)
{
    Node_t* current = a_head;

    while(current != NULL)
    {
        printf("| %d | -> ", current->window);
        current = current->next;
    }
    printf("NULL\n\n");
}

void openwindow(int windownum, Node_t** a_head)
{
    Node_t* new = malloc(sizeof(Node_t));
    new->window = windownum;
    new->next = *a_head;
    *a_head = new;
    printf("%d\n" , windownum);
}


void switchwindow(int windownum, Node_t** a_head)
{
    if(*a_head == NULL)
    {
        return;
    }

    else if ((*a_head)->next == NULL)
    {
        return;
    }
    Node_t* curr = (*a_head)->next;
    Node_t* prev = *a_head;
    while(windownum != curr -> window)
    {
        curr = curr->next;
        prev = prev->next;
    }
    prev-> next = curr->next;
    curr->next = *a_head;
    *a_head = curr;
    printf("%d\n", windownum);
}

void closewindow(int windownum, Node_t** a_head)
{
    if(*a_head == NULL)
    {
        return;
    }
    else if ((*a_head)->next == NULL) //work on it
    {
        free(*a_head);
        *a_head = NULL;
        return;
    }
    Node_t* prev = *a_head;
    Node_t* dummy = *a_head;
    Node_t* curr = (*a_head)->next;

    if ((*a_head) -> window == windownum)
    {
        (*a_head) -> next = prev->next;
        free(dummy);
    }

    while(windownum != curr -> window)
    {
        curr = curr->next;
        prev = prev->next;
    }

    prev->next = curr->next;
    free (curr);

    printf("%d\n", (*a_head)->window);
}

int main() 
{
    int windownum;
    char instruct[7];
    
    Node_t* head = NULL;

    while (scanf("%s %d", instruct, &windownum))
    { 
        if (strcmp(instruct, "open")==0)
        {
            openwindow(windownum, &head);
        }
        else if (strcmp(instruct, "switch")==0)
        {
            switchwindow(windownum, &head);
        }   
        else if ((strcmp(instruct, "close")==0))
        {
            closewindow(windownum, &head);
        }
        printlist(head);
    }
}

