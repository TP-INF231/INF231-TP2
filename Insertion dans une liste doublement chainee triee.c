typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// Insertion dans liste doublement chaînée triée
DNode* insererListeDoubleTriee(DNode* head, int valeur) {
    DNode* nouveau = (DNode*)malloc(sizeof(DNode));
    nouveau->data = valeur;
    nouveau->prev = NULL;
    nouveau->next = NULL;
    
    // Cas 1: liste vide
    if (head == NULL) {
        return nouveau;
    }
    
    // Cas 2: insertion en tête
    if (valeur <= head->data) {
        nouveau->next = head;
        head->prev = nouveau;
        return nouveau;
    }
    
    // Cas 3: insertion au milieu ou en fin
    DNode* current = head;
    while (current->next != NULL && current->next->data < valeur) {
        current = current->next;
    }
    
    nouveau->next = current->next;
    nouveau->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = nouveau;
    }
    
    current->next = nouveau;
    
    return head;
}
