/* Includes function definitions for the sort algorithms */

#include "struct.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

// When the array and size is given, this function sorts the array in ascending order using bubble sort algorithm
void bubble_sort(struct line array[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (strcmp(array[j].string, array[j+1].string) > 0)
            {
                struct line temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
            
        }
        
    }
    
}

// When the array and it's size is given, this function sorts the array in descending order using bubble sort algorithm
void bubble_sortDSC(struct line array[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (strcmp(array[j].string, array[j+1].string) < 0)
            {
                struct line temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
            
        }
        
    }
    
}


// When the array and it's size is given, this function sorts the array in ascending order using insertion sort algorithm
void insertion_sort(struct line v[], int n) {
    int i, j;

    for (i = 1; i < n; i++) {
        for (j = i; j > 0 && strcmp(v[j].string, v[j - 1].string) < 0; j--) {
            struct line copy = v[j - 1];
            v[j - 1] = v[j];
            v[j] = copy;
        }
    }
}

// When the array and it's size is given, this function sorts the array in descending order using insertion sort algorithm
void insertion_sortDSC(struct line v[], int n) 
{
    int i, j;

    for (i = 1; i < n; i++) {
        for (j = i; j > 0 && strcmp(v[j].string, v[j - 1].string) > 0; j--) {
            struct line copy = v[j - 1];
            v[j - 1] = v[j];
            v[j] = copy;
        }
    }
}

// This function writes the sorted array into a text file when the array and filename is given as parameters
int export(struct line array[], char name[])
{
    FILE *fptr = fopen(name, "w");

    if(!fptr)
    {
        printf("Error opening the textfile\n");
        return 1;
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        fprintf(fptr, "%s %d %d %fl\n", array[i].string, array[i].int_value1, array[i].int_value2, array[i].fl_value);
    }
    

    fclose(fptr);
    printf("Done.\n");
    return 0;
    
}
