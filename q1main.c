#include "q1.h"
#include "q1struct.c"
#include "search.c"
#include "sort.c"
#include <stdio.h>
#include "struct.h"

// Defines an array 10 of structs
struct line arr[ARRAY_SIZE];

int main(void)
{
    // Opens the text file to get data
    FILE *fptr = fopen("q1.txt", "r");

    if(!fptr)
    {
        printf("Error reading the textfile\n");
        return 1;
    }

    int i = 0;

    // Populate struct array with values
    while (fscanf(fptr, "%s %d %d %lf", arr[i].string, &arr[i].int_value1, &arr[i].int_value2, &arr[i].fl_value) == 4)
    {
        i++;
    }

    fclose(fptr);

    // Infinite loop : Keeps looping until 5(Quit) is entered. 
    while(1)
    {
        int c = print_options();
        if(c == 1)
        {
            // Loop over the struct array and prints each record to the terminal
            for(int j = 0; j < ARRAY_SIZE; j++)
            {
                printf("%s %d %d %lf\n", arr[j].string, arr[j].int_value1, arr[j].int_value2, arr[j].fl_value);
            }
        }
        else if(c == 2)
        {
            printf("How do you want to sort? \n (1) Ascending \n (2) Descending\n Enter your Option: ");
            int method, algo;
            scanf("%d", &method);
            printf("How do you want to sort? \n (1) Bubble Sort \n (2) Insertion Sort\n Enter your Option: ");
            scanf("%d", &algo);
            if(method == 1)
            {

                if (algo == 1)
                {
                    bubble_sort(arr, ARRAY_SIZE);
                    export(arr, "asc-bubble_sorted.txt");
                } 
                else if (algo == 2)
                {

                    insertion_sort(arr, ARRAY_SIZE);
                    export(arr, "asc-ins_sorted.txt");
                }

            }
            if(method == 2)
            {
                if (algo == 1)
                {
                    bubble_sortDSC(arr, ARRAY_SIZE);
                    export(arr, "dsc-bubble_sorted.txt");
                } 
                else if (algo == 2)
                {

                    insertion_sortDSC(arr, ARRAY_SIZE);
                    export(arr, "dsc-ins_sorted.txt");
                }
            }

            for(int j = 0; j < ARRAY_SIZE; j++)
            {
                // Prints the sorted array in to the terminal
                printf("%s and %lf\n", arr[j].string, arr[j].fl_value);
            }
            
        }
        else if (c == 3)
        {
            printf("Enter the string to search.. :");
            char search_str[MAX_STRLEN];
            int choice = 0;
            scanf("%s", search_str);
            printf("(1)Linear Search\n(2)Binary Search\nSelect your preferred search algorithm: ");
            scanf("%d", &choice);
            if(choice == 1)
            {
                int k = linear_recursiveSearch(arr, search_str, 0);
                if(k != -1)
                {
                    printf("Found!\n%s %d %d %fl\n", arr[k].string, arr[k].int_value1, arr[k].int_value2, arr[k].fl_value);
                }
                else
                {
                    printf("No results found :(\n");
                }
            }
            else if (choice == 2)
            {
                // Sort the array before using the Binary Search
                bubble_sort(arr, ARRAY_SIZE);

                int k = binary_recursiveSearch(arr, search_str, 0, 9);
                if(k != -1)
                {
                    printf("Found!\n%s %d %d %lf\n", arr[k].string, arr[k].int_value1, arr[k].int_value2, arr[k].fl_value);
                }
                else
                {
                    printf("No results found :(\n");
                }
            }
            

        }
        else if (c == 4)
        {
            node *root = NULL;
            for(int i = 0; i < ARRAY_SIZE; i++)
            {
                insert_data(&root, arr[i]);
            }
            print_nodes(root);

            int nc = free_nodes(&root);
        }
        else if (c == 5)
        {
            break;
        }
        else
        {
            // if user entered a number other than 1 to 5
            printf("Invalid input!\n");
        }
        
        
    }
    
    return 0;
}
