#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert_head(Node* tail, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    if (!tail) {
        new_node->next = new_node;
        return new_node;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    return tail;
}

Node* insert_tail(Node* tail, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    if (!tail) {
        new_node->next = new_node;
        return new_node;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    return new_node;
}

void display(Node* tail) {
    if (!tail) {
        printf("Liste vide\n");
        return;
    }
    Node* curr = tail->next;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != tail->next);
    printf("\n");
}

void free_list(Node* tail) {
    if (!tail) return;
    Node* curr = tail->next;
    Node* next;
    do {
        next = curr->next;
        free(curr);
        curr = next;
    } while (curr != tail->next);
}

int main() {
    Node* tail = NULL;
    int choix, val;
    do {
        printf("\n1. Insertion en tete\n2. Insertion en queue\n3. Afficher\n0. Quitter\nVotre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Entrer la valeur: ");
                scanf("%d", &val);
                tail = insert_head(tail, val);
                break;
            case 2:
                printf("Entrer la valeur: ");
                scanf("%d", &val);
                tail = insert_tail(tail, val);
                break;
            case 3:
                display(tail);
                break;
            case 0:
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (choix != 0);
    free_list(tail);
    return 0;
}