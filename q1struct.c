/* Includes functions related to the linked list */

#include <stdio.h>
#include <string.h> // For strcmp
#include <stdlib.h> // For malloc, free etc..
#include "q1.h"


// Allocate, Initialise, and insert a new node at the end of the list head.
void insert_data(node **root, struct line x)
{
    node *tmp = NULL;
    
    tmp = malloc(sizeof(*tmp));
    if(NULL == tmp)
    {
        printf("Error allocating memory! \n");
    }
    // Adding data to the new node
    tmp->data = x;

    // Link this node to the list as the new head node
    tmp->next = *root;
    *root = tmp;

}

// Print the data of the each node
void print_nodes(node *root)
{
    node *tmp = root;
    int count = 0;

    while(tmp)
    {
        count++;
        printf("%s, %d, %d, %fl\n", tmp->data.string, tmp->data.int_value1, tmp->data.int_value2, tmp->data.fl_value);
        tmp = tmp->next;
    }
}

// Destroys the linked list by freeing the nodes
int free_nodes(node **root)
{
    int count = 0;
    while (*root)
    {
        node *freeNode = *root;
        *root = (*root)->next;
        free(freeNode);
        count++;
    }
    return count;
    
}