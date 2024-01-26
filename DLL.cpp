#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node;

    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void deleteFirstNode(struct Node** head_ref) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    *head_ref = (*head_ref)->next;

    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;

    free(temp);
}

void deleteLastNode(struct Node** head_ref) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head_ref = NULL;

    free(temp);
}

void appendList(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }

    if (*head2 == NULL)
        return;

    struct Node* last1 = *head1;
    while (last1->next != NULL)
        last1 = last1->next;

    struct Node* first2 = *head2;
    while (first2->prev != NULL)
        first2 = first2->prev;

    last1->next = first2;
    first2->prev = last1;
}

void copyList(struct Node* head, struct Node** head_copy) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    while (temp != NULL) {
        insertNode(head_copy, temp->data);
        temp = temp->next;
     }
}

int main() {
     struct Node* head1 = NULL;
     struct Node* head2 = NULL;
     struct Node* head_copy = NULL;

     insertNode(&head1, 5);
     insertNode(&head1, 4);
     insertNode(&head1, 3);

     insertNode(&head2, 8);
     insertNode(&head2, 7);
     insertNode(&head2, 6);

     printf("Double Linked List 1: ");
     for (struct Node* i = head1; i != NULL; i = i->next)
         printf("%d ", i->data);
     printf("\n");

     printf("Double Linked List 2: ");
     for (struct Node* i = head2; i != NULL; i = i->next)
         printf("%d ", i->data);
     printf("\n");

     deleteFirstNode(&head1);

     printf("Double Linked List 1 after deleting first node: ");
     for (struct Node* i = head1; i != NULL; i = i->next)
         printf("%d ", i->data);
     printf("\n");

     deleteLastNode(&head2);

     printf("Double Linked List 2 after deleting last node: ");
     for (struct Node* i = head2; i != NULL; i = i->next)
         printf("%d ", i->data);
     printf("\n");
}