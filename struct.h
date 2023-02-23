// Includes struct definitions

#ifndef STRUCT_H
#define STRUCT_H

struct line
{
    char string[10];
    int int_value1, int_value2;
    double fl_value;
};

typedef struct Node
{
    struct line data;
    struct Node* next;
}node;

#endif