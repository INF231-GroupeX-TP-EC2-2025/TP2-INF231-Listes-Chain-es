// insertion d'un element daans une liste doublement chainee triee

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

NoeudDouble* insererTriDouble(NoeudDouble* tete, int valeur) {
    NoeudDouble* nouveau = creerNoeudDouble(valeur);
    
    // Cas 1: liste vide
    if (tete == NULL) {
        return nouveau;
    }
    
    // Cas 2: insertion en tête
    if (valeur <= tete->donnee) {
        nouveau->suivant = tete;
        tete->precedent = nouveau;
        return nouveau;
    }
    
    // Cas 3: insertion au milieu ou en queue
    NoeudDouble* actuel = tete;
    while (actuel->suivant != NULL && actuel->suivant->donnee < valeur) {
        actuel = actuel->suivant;
    }
    
    nouveau->suivant = actuel->suivant;
    nouveau->precedent = actuel;
    
    if (actuel->suivant != NULL) {
        actuel->suivant->precedent = nouveau;
    }
    
    actuel->suivant = nouveau;
    
    return tete;
}

void afficherListeDouble(NoeudDouble* tete) {
    NoeudDouble* actuel = tete;
    printf("NULL <- ");
    while (actuel != NULL) {
        printf("%d", actuel->donnee);
        if (actuel->suivant != NULL) {
            printf(" <-> ");
        }
        actuel = actuel->suivant;
    }
    printf(" -> NULL\n");
}

int main() {
    NoeudDouble* liste = NULL;
    
    liste = insererTriDouble(liste, 10);
    liste = insererTriDouble(liste, 5);
    liste = insererTriDouble(liste, 15);
    liste = insererTriDouble(liste, 7);
    liste = insererTriDouble(liste, 12);
    
    printf("Liste double triée: ");
    afficherListeDouble(liste);
    
    return 0;
}
