#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
  int data;
  struct s_node *left;
  struct s_node *right;
}t_node;

t_node *insert(t_node **root, int data)
{
  if (*root == NULL)
  {
    (*root) = malloc(sizeof(t_node));
    (*root)->data = data;
    (*root)->left = NULL;
    (*root)->right = NULL;
    return (*root);
  }
  if (data > (*root)->data) /* traveling right*/
  {
    (*root)->right = insert(&((*root)->right), data);
  }
  else if (data < (*root)->data)
  {
    (*root)->left = insert(&((*root)->left), data);
  }
  return (*root);
}
int main()
{
  t_node *root = NULL;
  insert(&root, 5);
  insert(&root, 10);
  insert(&root, 2);
  insert(&root, 20);
  printf("%d", root->right->data);

} 
