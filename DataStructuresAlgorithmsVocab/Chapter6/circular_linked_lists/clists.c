#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

Node *make_node(int data)
{
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->val = data;
    new->next = NULL;

    return new;
}

char *print_clist(Node *head)
{
    char *result = malloc(1024);

    int index = 0;
    Node *node = head;
    if (node == NULL)
    {
        result[0] = '\0';
        return result;
    }
    while (node != head || index == 0)
    {
        int num_len = snprintf(NULL, 0, "%d", node->val);
        snprintf(result + index, 8, "%d", node->val);
        index += num_len - 1;
        if (node->next != head)
        {
            result[++index] = ' ';
            result[++index] = '-';
            result[++index] = '>';
            result[++index] = ' ';
        }
        index++;

        node = node->next;
    }
    result[index] = '\0';

    return result;
}

void clist_insert_in_order(Node **list, Node **newnode)
{
    // empty list
    if (*list == NULL)
    {
        (*newnode)->next = *newnode;
        (*list) = *newnode;
        return;
    }

    // beginning insertion
    if ((*list)->val > (*newnode)->val)
    {
        (*newnode)->next = *list;
        Node *last = *list;
        while (last->next != *list)
        {
            last = last->next;
        }
        last->next = *newnode;
        (*list) = *newnode;
        return;
    }

    // otherwise, loop through and insert
    Node *cur = (*list)->next;
    Node *prev = *list;

    while (cur != *list && cur->val > (*newnode)->val)
    {
        prev = cur;
        cur = cur->next;
    }
    // insert newnode between previous and current (or at end)
    (*newnode)->next = cur;
    prev->next = *newnode;
}

// input a starting node and then the value you want to find
// it will go through the circular list and check each node
// it also returns the index, relative to the starting node, of the piece of data
//this can be changed to return different value simply signifying that it is in the circular linked list

int find_in_clist(Node *start, int value)
{

    Node *node = start;
    int index = 0;
    while (node != start)
    {
        if (node->val == value)
        {
            printf("%d is in index %d", value, index);
            return index;
        }
        else
        {
            index++;
            node = node->next;
        }
    }
}
