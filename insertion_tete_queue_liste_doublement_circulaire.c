#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memorry error!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void insertHead(int val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Insert at head done.\n");
}

void insertTail(int val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
    printf("Insert at tail done.\n");
}

void displayList() {
    if (head == NULL) {
        printf("List is emty.\n");
        return;
    }
    Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void freeList() {
    if (head == NULL) return;
    Node* temp = head->next;
    while (temp != head) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(head);
}

int main() {
    int ch, val;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choise: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to insert at head: ");
                scanf("%d", &val);
                insertHead(val);
                break;
            case 2:
                printf("Enter value to insert at tail: ");
                scanf("%d", &val);
                insertTail(val);
                break;
            case 3:
                displayList();
                break;
            case 4:
                freeList();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalide choise!\n");
        }
    }
    return 0;
}