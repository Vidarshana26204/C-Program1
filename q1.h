/* Includes some function declarations and Macros */

#ifndef HEADERS_H
#define HEADERS_H
#define MAX_STRLEN 20
#define ARRAY_SIZE 10

#include <stdio.h>
#include "struct.h"

// Function declarations related to the linked list
void insert_data(node **root, struct line x);
void print_nodes(node *root);
int free_nodes(node **root);


// Function declarations for search algorithms
int linear_recursiveSearch(struct line *array, char check[], int indx);
int binary_recursiveSearch(struct line *array, char check[], int left, int right);

// Function declarations for sort algorithms
void bubble_sort(struct line array[], int n);
void bubble_sortDSC(struct line array[], int n);
void insertion_sort(struct line array[], int n);
void insertion_sortDSC(struct line v[], int n) ;
int export(struct line array[], char name[]);

// This functions prints the menu to terminal and get the user-input and returns it.
int print_options(void)
{
    printf("(1) Display the details of the array\n(2) Sort the array\n(3) Search for strings\n(4) Insert the array into a linked list\n(5) Quit\n");
    printf("Select an Option : ");
    int choice;

    // This while loop makes sure that the user inputs a valid number(NOT a letter NOR a special character)
    while (1)
    {
        char buffer[3];
        fgets(buffer, 3, stdin);
        if ( sscanf(buffer, "%d", &choice) == 1 )
        {
            break;
        } 
    }
    return choice;
}

#endif /** HEADERS_H */