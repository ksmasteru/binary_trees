#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_queue{
    t_root *addr;
    struct s_queue *next;
}t_queue;



t_root *insert(t_root **root, int data)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(t_root));
        if (*root == NULL)
            return (NULL);
        (*root)->data = data;
        (*root)->right = NULL;
        (*root)->left = NULL;
        //printf("adress of %d is %p\n", data, *root);
        return (*root);
    }
    
    if (data > (*root)->data)
    {
        (*root)->right = insert(&((*root)->right), data);
    }
    else if (data < (*root)->data)
    {
        (*root)->left = insert(&((*root)->left), data);
    }
    return (*root);

}

t_queue *new_follower(t_queue **head, t_queue **prev, t_root *addr)
{
    t_queue *new;

    if (*head == NULL)
    {
        new = malloc(sizeof(t_queue));
        if (!new)
            return (NULL);
        new->addr = addr;
        new->next = NULL;
        *head = new;
        *prev = new;
        return (new);
    }
    new = malloc(sizeof(t_queue));
    if (!new)
        return (NULL);
    (*prev)->next = new;
    new->addr = addr;
    new->next = NULL;
    *prev = new;
    return (new);
}
t_queue *pop(t_queue **head)
{
    t_queue *tmp;

    if (*head == NULL)
        return (NULL);
    tmp = (*head);
    (*head) = (*head)->next;
    return (tmp);
}


void bfs(t_root **root)
{
    t_queue *head;
    t_queue *current;
    t_queue *prev;
    t_queue *new;
    t_root *tmp;

    prev = NULL;
    head = NULL;
    if ((*root) != NULL)
    {
        new_follower(&head, &prev, *root);
        prev = head;
    }
    while (head != NULL)
    {
        current = pop(&head);
        if (current == NULL) 
            break;
        *root = current->addr;
        if (*root != NULL)
        {
            printf("%d\n", (*root)->data);
            new = new_follower(&head, &prev, (*root)->left);
            new = new_follower(&head, &prev, (*root)->right);
        }
    }
}
int main(int ac, char **av)
{
    // print values
    t_root *root;
    int i;

    i = 0;
    root = NULL;
    if (ac < 2)
        return (0);
    while ( i++ < ac - 1)
        insert(&root, atoi(av[i]));
    printf("breadth first seatch \n");
    bfs(&root);
    // now print all data in the nodes using breadth first search
    //printf("deepth first search preorder\n");
    //pre_order_traversal(&root);   
}