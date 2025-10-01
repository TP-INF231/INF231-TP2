typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// Insertion en tête dans liste doublement circulaire
DNode* insererTeteDoubleCirculaire(DNode* head, int valeur) {
    DNode* nouveau = (DNode*)malloc(sizeof(DNode));
    nouveau->data = valeur;
    
    if (head == NULL) {
        nouveau->next = nouveau;
        nouveau->prev = nouveau;
        return nouveau;
    }
    
    DNode* last = head->prev; // Dernier nœud
    
    nouveau->next = head;
    nouveau->prev = last;
    
    head->prev = nouveau;
    last->next = nouveau;
    
    return nouveau;
}

// Insertion en queue dans liste doublement circulaire
DNode* insererQueueDoubleCirculaire(DNode* head, int valeur) {
    DNode* nouveau = (DNode*)malloc(sizeof(DNode));
    nouveau->data = valeur;
    
    if (head == NULL) {
        nouveau->next = nouveau;
        nouveau->prev = nouveau;
        return nouveau;
    }
    
    DNode* last = head->prev; // Dernier nœud
    
    nouveau->next = head;
    nouveau->prev = last;
    
    last->next = nouveau;
    head->prev = nouveau;
    
    return head;
}
