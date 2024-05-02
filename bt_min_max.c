#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>


t_root *insert(t_root **root, int data);
int find_min_bt(t_root **root, int min);
int find_min_bt(t_root **root, int min)
{
    if (*root == NULL)
    {
        printf("no minimum value found");
        return min;
    }
    else if ((*root)->left == NULL)
        return (min);
    else if (min >= (*root)->left->data)
    {
        min = find_min_bt(&((*root)->left), (*root)->left->data);
    }
    return min;
}

int find_max_bt(t_root **root, int max)
{
    if (*root == NULL)
    {
        printf("no tree is found");
        return max;
    }
    if ((*root)->right == NULL)
        return (max);
    if (max <= (*root)->right->data)
    {
        max = find_max_bt(&((*root)->right), (*root)->right->data);
    }
    return max;
}
int main()
{
    t_root *root = NULL;
    insert(&root, 100);
    insert(&root, 10);
    insert(&root, 2);
    insert(&root, 2000);
    int min = find_min_bt(&root, root->data);
    //printf("min value is %d", min);
    int max = find_max_bt(&root, root->data);
    printf("max value is %d\n", max);
}