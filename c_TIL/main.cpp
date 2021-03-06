Node* CreateNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void AddNode(List **list, Node* node)
{
    if (!(*list) || !node) return;
    cout << "Add Node : " << node->data << endl;

    if ((*list)->count == 0)
    {
        (*list)->tail = node;
        node->next = node;
    }
    else
    {
        node->next = (*list)->head;

        (*list)->tail->next = node;
        (*list)->tail = node;
    }

    (*list)->count++;
}