#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;


    last->next = new_node;
    return;
}

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    Node* head = NULL;

    append(&head, 20);
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    append(&head, 25);

    cout<<"Created Linked list is: ";

     printList(head);

    return 0;
}
