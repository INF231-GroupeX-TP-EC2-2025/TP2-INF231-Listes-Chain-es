//  insertion en tete et en queue dans une liste doublement chainee circulaire

#include <stdio.h>
#include <stdlib.h>

typedef struct NoeudDouble {
    int donnee;
    struct NoeudDouble* precedent;
    struct NoeudDouble* suivant;
} NoeudDouble;

NoeudDouble* creerNoeudDouble(int donnee) {
    NoeudDouble* nouveau = (NoeudDouble*)malloc(sizeof(NoeudDouble));
    nouveau->donnee = donnee;
    nouveau->precedent = NULL;
    nouveau->suivant = NULL;
    return nouveau;
}

NoeudDouble* insererTeteDoubleCirculaire(NoeudDouble* tete, int valeur) {
    NoeudDouble* nouveau = creerNoeudDouble(valeur);
    
    if (tete == NULL) {
        nouveau->suivant = nouveau;
        nouveau->precedent = nouveau;
        return nouveau;
    }
    
    NoeudDouble* queue = tete->precedent;
    
    nouveau->suivant = tete;
    nouveau->precedent = queue;
    tete->precedent = nouveau;
    queue->suivant = nouveau;
    
    return nouveau;
}

NoeudDouble* insererQueueDoubleCirculaire(NoeudDouble* tete, int valeur) {
    NoeudDouble* nouveau = creerNoeudDouble(valeur);
    
    if (tete == NULL) {
        nouveau->suivant = nouveau;
        nouveau->precedent = nouveau;
        return nouveau;
    }
    
    NoeudDouble* queue = tete->precedent;
    
    nouveau->suivant = tete;
    nouveau->precedent = queue;
    queue->suivant = nouveau;
    tete->precedent = nouveau;
    
    return tete;
}

void afficherListeDoubleCirculaire(NoeudDouble* tete) {
    if (tete == NULL) return;
    
    NoeudDouble* actuel = tete;
    printf("... <-> ");
    do {
        printf("%d <-> ", actuel->donnee);
        actuel = actuel->suivant;
    } while (actuel != tete);
    printf("[retour] <-> ...\n");
}

int main() {
    NoeudDouble* liste = NULL;
    
    liste = insererTeteDoubleCirculaire(liste, 100);
    liste = insererQueueDoubleCirculaire(liste, 200);
    liste = insererTeteDoubleCirculaire(liste, 50);
    liste = insererQueueDoubleCirculaire(liste, 300);
    
    printf("Liste double circulaire: ");
    afficherListeDoubleCirculaire(liste);
    
    return 0;
}
