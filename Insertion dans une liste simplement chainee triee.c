#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* inserer_trie(Node* head, int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    nouveau->next = NULL;
    
    if (head == NULL || valeur <= head->data) {
        nouveau->next = head;
        return nouveau;
    }
    
    Node* current = head;
    while (current->next != NULL && current->next->data < valeur) {
        current = current->next;
    }
    
    nouveau->next = current->next;
    current->next = nouveau;
    return head;
}

// Fonction pour afficher la liste
void afficher_liste(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// POINT D'ENTRÉE PRINCIPAL
int main() {
    Node* head = NULL;
    
    // Test de la fonction
    head = inserer_trie(head, 5);
    head = inserer_trie(head, 2);
    head = inserer_trie(head, 8);
    head = inserer_trie(head, 3);
    
    printf("Liste triée : ");
    afficher_liste(head);
    
    return 0;
}
