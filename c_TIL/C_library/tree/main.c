#include <stdlib.h>
#include "fun.h"

t_btree *btree_create_node(void *item)
{
    t_btree * new = (t_btree *)malloc(sizeof(t_btree));
    new->item = item;
    new->left = 0;
    new->right = 0;
    return (new);
}



void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    if (!root)
        return;
    applyf(root->item);
    btree_apply_prefix(root->left,applyf);
    btree_apply_prefix(root->right,applyf);
}

void btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
    if (!root)
        return;
    btree_apply_infix(root->left,applyf);
    applyf(root);
    btree_apply_infix(root->right, applyf);
}

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (!root)
        return;
    btree_apply_suffix(root->left,applyf);
    btree_apply_suffix(root->right,applyf);
    applyf(root);
}
