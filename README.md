# INF231-TP2
# Description Détaillée des Codes en C les Listes Chaînées
## 1. Suppression de toutes les occurrences d'un élément
### **Objectif** :
Supprimer toutes les occurrences d'une valeur donnée dans une liste simplement chaînée.
### **Fonctionnement** :
```c
Node* supprimerOccurrences(Node* head, int valeur)
```
- **Paramètres** :
- `head` : pointeur vers le premier élément de la liste
- `valeur` : élément à supprimer
- **Processus en 2 étapes** :
1. **Suppression des occurrences en tête** :
- Tant que le premier élément contient la valeur, on le supprime et on avance la tête
- Utilise un pointeur temporaire pour libérer la mémoire
2. **Suppression dans le reste de la liste** :
- Parcours la liste avec deux pointeurs : `current` et `prev`
- Quand `current->data == valeur`, on ajuste les liens et on libère le nœud
- Sinon, on avance simplement dans la liste
### **Cas particuliers gérés** :
- Liste vide
- Suppression en tête
- Suppression au milieu
- Suppression en queue
- Valeur absente de la liste
---
## 2. Insertion dans une liste simplement chaînée triée
### **Objectif** :
Insérer un élément dans une liste triée tout en maintenant l'ordre croissant.
### **Fonctionnement** :
```c
Node* insererListeTriee(Node* head, int valeur)
```
- **Trois cas de figure** :1. **Liste vide ou insertion en tête** :
```c
if (head == NULL || valeur <= head->data)
```
- Crée le nouveau nœud
- Le fait pointer vers l'ancienne tête
- Retourne le nouveau nœud comme nouvelle tête
2. **Insertion au milieu ou en fin** :
- Parcours la liste jusqu'à trouver la position correcte
- Insère entre `current` et `current->next`
### **Avantage** :
- Complexité : O(n) dans le pire cas
- Maintient l'ordre sans avoir à trier après insertion
---
## 3. Insertion dans une liste doublement chaînée triée
### **Objectif** :
Insérer un élément dans une liste doublement chaînée triée.
### **Spécificités de la liste double** :
Chaque nœud a deux pointeurs :
- `next` : vers l'élément suivant
- `prev` : vers l'élément précédent
### **Fonctionnement** :
```c
DNode* insererListeDoubleTriee(DNode* head, int valeur)
```
- **Trois cas traités** :
1. **Liste vide** :
- Crée le premier nœud qui pointe sur lui-même
2. **Insertion en tête** :
- Ajuste `nouveau->next` et `head->prev`
- Met à jour les pointeurs dans les deux directions
3. **Insertion au milieu ou en fin** :
- Trouve la position correcte
- Met à jour **quatre** pointeurs :
- `current->next`- `nouveau->prev`
- `nouveau->next`
- `current->next->prev` (si existe)
### **Avantage** :
- Permet un parcours dans les deux sens
- Insertion/Suppression plus efficaces
---
## 4. Liste simplement chaînée circulaire
### **Caractéristique principale** :
Le dernier élément pointe vers le premier :
```c
last->next = head;
```
### **Insertion en tête** :
```c
Node* insererTeteCirculaire(Node* head, int valeur)
```
1. **Liste vide** : le nœud pointe sur lui-même
2. **Liste non vide** :
- Trouve le dernier nœud (celui qui pointe vers `head`)
- Fait pointer le dernier vers le nouveau nœud
- Le nouveau nœud pointe vers l'ancienne tête
### **Insertion en queue** :
```c
Node* insererQueueCirculaire(Node* head, int valeur)
```
- Similaire à l'insertion en tête
- Mais on retourne `head` (pas de changement de tête)
### **Parcours circulaire** :
```c
do {
// traitement
current = current->next;
} while (current != head);
```
---
## 5. Liste doublement chaînée circulaire **Caractéristique** :
- Chaque nœud a `prev` et `next`
- Le premier `prev` pointe vers le dernier
- Le dernier `next` pointe vers le premier
### **Structure complète** :
```
head nœud1 nœud2 ... dernier head
```
### **Insertion en tête** :
```c
DNode* insererTeteDoubleCirculaire(DNode* head, int valeur)
```
- **Actions nécessaires** :
1. `nouveau->next = head`
2. `nouveau->prev = head->prev` (dernier nœud)
3. `head->prev->next = nouveau` (dernier vers nouveau)
4. `head->prev = nouveau` (ancienne tête vers nouveau)
### **Insertion en queue** :
Similaire mais on ne change pas la tête.
### **Avantages** :
- Parcours bidirectionnel circulaire
- Accès rapide au dernier élément via `head->prev`
