typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insertion dans liste simplement chaînée triée
Node* insererListeTriee(Node* head, int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    nouveau->next = NULL;
    
    // Cas 1: liste vide ou insertion en tête
    if (head == NULL || valeur <= head->data) {
        nouveau->next = head;
        return nouveau;
    }
    
    // Cas 2: insertion au milieu ou en fin
    Node* current = head;
    while (current->next != NULL && current->next->data < valeur) {
        current = current->next;
    }
    
    nouveau->next = current->next;
    current->next = nouveau;
    
    return head;
}
