#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un élément de la liste chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour ajouter un élément en tête de liste
Node* ajouter_en_tete(Node* head, int data) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    if (!nouveau) return head;
    nouveau->data = data;
    nouveau->next = head;
    return nouveau;
}

// Fonction pour supprimer toutes les occurrences d'une valeur dans la liste
Node* supprimer_occurrences(Node* head, int valeur) {
    Node* courant = head;
    Node* precedent = NULL;

    while (courant != NULL) {
        if (courant->data == valeur) {
            Node* temp = courant;
            if (precedent == NULL) {
                head = courant->next;
                courant = head;
            } else {
                precedent->next = courant->next;
                courant = courant->next;
            }
            free(temp);
        } else {
            precedent = courant;
            courant = courant->next;
        }
    }
    return head;
}

// Fonction pour afficher la liste
void afficher_liste(Node* head) {
    Node* courant = head;
    while (courant != NULL) {
        printf("%d ", courant->data);
        courant = courant->next;
    }
    printf("\n");
}

// Fonction principale
int main() {
    Node* liste = NULL;
    int n, val, i, a_supprimer;

    printf("Combien d'elements dans la liste ? ");
    scanf("%d", &n);

    printf("Entrez les elements :\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        liste = ajouter_en_tete(liste, val);
    }

    printf("Liste initiale : ");
    afficher_liste(liste);

    printf("Entrez la valeur a supprimer : ");
    scanf("%d", &a_supprimer);

    liste = supprimer_occurrences(liste, a_supprimer);

    printf("Liste apres suppression : ");
    afficher_liste(liste);

    // Libération de la mémoire
    while (liste != NULL) {
        Node* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}