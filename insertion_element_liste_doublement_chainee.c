#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un noeud
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau noeud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée dans la liste doublement chaînée
void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    // Insertion en tête si nécessaire
    if (data <= current->data) {
        newNode->next = current;
        current->prev = newNode;
        *head = newNode;
        return;
    }
    // Recherche de la position d'insertion
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Affichage de la liste
void displayList(Node* head) {
    Node* temp = head;
    printf("Liste: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Libération de la mémoire
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int n, val, i;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Entrez la valeur de l'element %d: ", i + 1);
        scanf("%d", &val);
        insertSorted(&head, val);
    }

    displayList(head);
    freeList(head);
    return 0;
}