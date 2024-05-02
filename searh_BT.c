#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchBinary(t_root **root, int data)
{
    if (*root == NULL)
    {
        printf("NOT FOUND");
        return ;
    }
    else if ((*root)->data == data)
    {
        printf("FOUND!");
        exit(0);
    }
    else if ((*root)->data < data)
        searchBinary(&((*root)->right), data);
    else if ((*root)->data > data)
        searchBinary(&((*root)->left), data);
}
t_root *insert(t_root **root, int data)
{
  if (*root == NULL)
  {
    (*root) = malloc(sizeof(t_root));
    (*root)->data = data;
    (*root)->left = NULL;
    (*root)->right = NULL;
    return (*root);
  }
  if (data > (*root)->data) /* traveling right*/
  {
    (*root)->right = insert(&((*root)->right), data);
  }
  else if (data <= (*root)->data)
  {
    (*root)->left = insert(&((*root)->left), data);
  }
  return (*root);
}
int main(int ac, char **av)
{
  t_root *root = NULL;
  insert(&root, 5);
  insert(&root, 10);
  insert(&root, 2);
  insert(&root, 20);
  searchBinary(&root, atoi(av[1]));
}