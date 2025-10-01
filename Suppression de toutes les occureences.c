#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Ajouter en fin de liste
void ajouterFin(struct Node** head, int value) {
    struct Node* nouveau = (struct Node*)malloc(sizeof(struct Node));
    nouveau->data = value;
    nouveau->next = NULL;
    
    if (*head == NULL) {
        *head = nouveau;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nouveau;
}

// Supprimer toutes les occurrences
void supprimerOccurrences(struct Node** head, int key) {
    if (*head == NULL) return;
    
    struct Node *courant = *head;
    struct Node *precedent = NULL;
    struct Node *aSupprimer;
    
    while (courant != NULL) {
        if (courant->data == key) {
            aSupprimer = courant;
            
            if (precedent == NULL) {
                // Suppression en tête
                *head = courant->next;
                courant = *head;
            } else {
                // Suppression au milieu ou fin
                precedent->next = courant->next;
                courant = precedent->next;
            }
            
            free(aSupprimer);
        } else {
            precedent = courant;
            courant = courant->next;
        }
    }
}

// Afficher la liste
void afficherListe(struct Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Menu principal
int main() {
    struct Node* head = NULL;
    int choix, valeur;
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ajouter un élément\n");
        printf("2. Afficher la liste\n");
        printf("3. Supprimer toutes les occurrences d'un élément\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                printf("Entrez la valeur à ajouter : ");
                scanf("%d", &valeur);
                ajouterFin(&head, valeur);
                printf("Élément %d ajouté.\n", valeur);
                break;
                
            case 2:
                printf("Contenu de la liste : ");
                afficherListe(head);
                break;
                
            case 3:
                if (head == NULL) {
                    printf("La liste est vide.\n");
                } else {
                    printf("Entrez l'élément à supprimer : ");
                    scanf("%d", &valeur);
                    printf("Avant suppression : ");
                    afficherListe(head);
                    
                    supprimerOccurrences(&head, valeur);
                    
                    printf("Après suppression : ");
                    afficherListe(head);
                }
                break;
                
            case 4:
                printf("Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);
    
    // Libération mémoire
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
