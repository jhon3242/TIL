#include <stdio.h>
#include <stdlib.h>
#include "node_function.h"



int main(){

    struct node *node1 = create_node(100);
    struct node *node2 = insert_node(200, node1);
    struct node *node3 = insert_node(300, node2);
    struct node *node4 = insert_node(400, node3);
    struct node *node5 = insert_node(500, node4);
    
    
    
    print_node(node1);
    //if (bool_has_node(node1, 700)) printf("I have\n");
    
    return 0;
}




