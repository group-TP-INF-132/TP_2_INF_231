#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un noeud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau noeud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée dans la liste simplement chaînée
void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);

    // Cas où la liste est vide ou l'élément doit être inséré en tête
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Recherche de la position d'insertion
    Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Affichage de la liste
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Libération de la mémoire
void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Exemple d'utilisation
int main() {
    Node* head = NULL;
    int n, val;
    printf("Combien de valeurs voulez-vous insérer ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &val);
        insertSorted(&head, val);
    }
    printf("\nListe chaînée triée : ");
    printList(head);
    freeList(head);
    return 0;
}