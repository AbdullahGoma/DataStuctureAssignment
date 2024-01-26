#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node;
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
    } else
        new_node->next = new_node;

    *head_ref = new_node;
}

void deleteFirstNode(struct Node** head_ref) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    if ((*head_ref)->next == *head_ref) {
        *head_ref = NULL;
        free(temp);
        return;
    }

    while (temp->next != *head_ref)
        temp = temp->next;

    temp->next = (*head_ref)->next;
    *head_ref = (*head_ref)->next;

    free(temp);
}

void deleteLastNode(struct Node** head_ref) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    if ((*head_ref)->next == *head_ref) {
        *head_ref = NULL;
        free(temp);
        return;
    }

    while (temp->next->next != *head_ref)
        temp = temp->next;

    free(temp->next);
    temp->next = *head_ref;
}

void appendList(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }

    if (*head2 == NULL)
        return;

    struct Node* last1 = (*head1)->next;
    while (last1->next != *head1)
        last1 = last1->next;

    struct Node* last2 = (*head2)->next;
    while (last2->next != *head2)
        last2 = last2->next;

    last1->next = (*head2);
    last2->next = (*head1);
}

void copyList(struct Node* head, struct Node** head_copy) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        insertNode(head_copy, temp->data);
        temp = temp->next;
    } while (temp != head);
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

    printf("Circular Linked List 1: ");
    for (struct Node* i = head1; i != NULL; i = i->next) {
        printf("%d ", i->data);
        if (i->next == head1)
            break;
     }
     printf("\n");

     printf("Circular Linked List 2: ");
     for (struct Node* i = head2; i != NULL; i = i->next) {
         printf("%d ", i->data);
         if (i->next == head2)
             break;
     }
     printf("\n");

     deleteFirstNode(&head1);

     printf("Circular Linked List 1 after deleting first node: ");
     for (struct Node* i = head1; i != NULL; i = i->next) {
         printf("%d ", i->data);
         if (i->next == head1)
             break;
     }
     printf("\n");

     deleteLastNode(&head2);

     printf("Circular Linked List 2 after deleting last node: ");
     for (struct Node* i = head2; i != NULL; i = i->next) {
         printf("%d ", i->data);
         if (i->next == head2)
             break;
     }
     printf("\n");
}