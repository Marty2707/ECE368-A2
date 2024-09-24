#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node* next;
    int window;
    
};


void openwindow(int windownum, struct node** a_head)
{
    struct node* new = malloc(sizeof(struct node));
    new->window = windownum;
    new->next = *a_head;
    *a_head = new;
    printf("%d\n" , windownum);
}


void switchwindow(int windownum, struct node** a_head)
{
    if(*a_head == NULL)
    {
        return;
    }

    else if ((*a_head)->next == NULL)
    {
        return;
    }
    struct node* curr = (*a_head)->next;
    struct node* prev = *a_head;
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

void closewindow(int windownum, struct node** a_head)
{
    if(*a_head == NULL)
    {
        return;
    }
    else if ((*a_head)->next == NULL) //work on it
    {
        return;
    }
    struct node* prev = *a_head;
    struct node* dummy = *a_head;
    struct node* curr = (*a_head)->next;

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
    
    struct node* head = NULL;

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
    }
}

