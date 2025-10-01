typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insertion en tête dans liste circulaire
Node* insererTeteCirculaire(Node* head, int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    
    if (head == NULL) {
        nouveau->next = nouveau; // Pointe sur lui-même
        return nouveau;
    }
    
    // Trouver le dernier nœud
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    nouveau->next = head;
    last->next = nouveau;
    
    return nouveau;
}

// Insertion en queue dans liste circulaire
Node* insererQueueCirculaire(Node* head, int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    
    if (head == NULL) {
        nouveau->next = nouveau;
        return nouveau;
    }
    
    // Trouver le dernier nœud
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    last->next = nouveau;
    nouveau->next = head;
    
    return head;
}
