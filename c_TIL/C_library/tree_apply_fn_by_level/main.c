#include "fun.h"
#include <stdlib.h>

t_list *    creat_list(int level)
{
    t_list *    new;
    
    new->level = level;
    new->next = 0;
    new->node = 0;
    return (new);
}

void enqu(t_list ** head, t_btree *node, int level)
{
    t_list *    tmp;
    if (!*head)
    {
        *head = creat_list(0);
        (*head)->node = node;
    }
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = creat_list(level);
    tmp->next->node = node;
}

void  dequ(t_list ** head)
{
    t_list *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}



void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
    t_list *    start;
    t_list *    tmp;
    int     level;
    
    
    if (root)
    {
        start = creat_list(0);
        start->node = root;
    }
    
    level = -1;
    while (start)
    {
        tmp = start;
        if (tmp->node->left)
            enqu(&start, tmp->node->left, tmp->level + 1);
        if (tmp->node->right)
            enqu(&start, tmp->node->right, tmp->level + 1);
        if (level != tmp->level)
            applyf(tmp->node->item, ++level,1);
        else
            applyf(tmp->node->item,level,0);
        dequ(&start);
    }
}
