#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct         s_btree
{
    struct s_btree *left;
    struct s_btree *right;
    void    *item;
}t_btree;

#endif

