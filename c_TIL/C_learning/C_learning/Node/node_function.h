struct node* insert_node(int data, struct node *before);
struct node* create_node(int data);
void print_node(struct node *from);
void delete_node(struct node *delecte, struct node *head);
void count_node(struct node *head);
int bool_has_node(struct node *head, int data);
void tail_to_head(struct node *head);


struct node{
    int data;
    struct node *next_node;
    struct node *prev_node;
};
