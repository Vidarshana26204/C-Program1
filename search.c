/* Includes the function definitions for Search Algorithms */
#include <string.h>
#include "struct.h"

// Recursively search for a string within the given array using linear search algorithm and returns the 
//    index of the matching string IF FOUND !
//    or returns -1 IF NOT FOUND!
int linear_recursiveSearch(struct line *array, char check[], int indx)
{

    if(indx >= 9)
    {
        return -1;  // Base case : No match found!
    }
    else if (strcmp(check, array[indx].string) == 0)
    {
        return indx;   
    }
    else
    {
        return linear_recursiveSearch(array, check, indx+1);
    }

    
}

// Recursively search for a string within the given array using binary search algorithm and returns the 
//    * index of the matching string IF FOUND!
//    * or returns -1 IF NOT FOUND!
int binary_recursiveSearch(struct line *array, char check[], int left, int right)
{

    if(right >= left)
    {
        int middle = (left + right)/2;

        //strcmp returns 0 if the both strings match!
        int val = strcmp(check, array[middle].string);
        if(val == 0)
        {
            return middle;
        }
        //strcmp returns a value greater than 0 if the first string is greater than the second string
        else if (val > 0)
        {
            return binary_recursiveSearch(array, check, middle + 1, right);
        }
        //strcmp returns a value lesser than 0 if the first string is lesser than the second string
        else
        {
            return binary_recursiveSearch(array, check, left, middle - 1);
            
        }
        
    }
    else
        return -1;  // If no match is found!
    
}