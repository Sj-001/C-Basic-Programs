#include <bits/stdc++.h>
#include <stdlib.h>

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* The function removes duplicates from a sorted list */
struct Node* removeDuplicates(struct Node* head)
{
    /* if head is null then return*/
    if (head == NULL)
        return NULL;

    /* Remove duplicates from list after head */
    head->next = removeDuplicates(head->next);

    // Check if head itself is duplicate
    if (head->next != NULL &&
        head->next->data == head->data) {

        Node* res = head->next;
        delete head;
        return res;
    }

    return head;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at
   the beginning of the linked list */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    /* Let us create a sorted linked list to test the functions
    Created linked list will be 11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    printf("\n Linked list before duplicate removal ");
    printList(head);

    /* Remove duplicates from linked list */
    struct Node* h = removeDuplicates(head);

    printf("\n Linked list after duplicate removal ");
    printList(h);

    return 0;
}
