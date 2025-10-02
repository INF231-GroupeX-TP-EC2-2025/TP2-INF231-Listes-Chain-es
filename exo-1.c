#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
} Noeud;

Noeud* creerNoeud(int donnee) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->donnee = donnee;
    nouveau->suivant = NULL;
    return nouveau;
}

Noeud* supprimerOccurrences(Noeud* tete, int valeur) {
    Noeud* actuel = tete;
    Noeud* precedent = NULL;
    Noeud* aSupprimer;
    
    // Supprimer toutes les occurrences en tête
    while (actuel != NULL && actuel->donnee == valeur) {
        aSupprimer = actuel;
        actuel = actuel->suivant;
        free(aSupprimer);
    }
    tete = actuel;
    
    // Supprimer les occurrences dans le reste de la liste
    while (actuel != NULL) {
        if (actuel->donnee == valeur) {
            if (precedent != NULL) {
                precedent->suivant = actuel->suivant;
            }
            aSupprimer = actuel;
            actuel = actuel->suivant;
            free(aSupprimer);
        } else {
            precedent = actuel;
            actuel = actuel->suivant;
        }
    }
    
    return tete;
}

void afficherListe(Noeud* tete) {
    Noeud* actuel = tete;
    while (actuel != NULL) {
        printf("%d -> ", actuel->donnee);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

int main() {
    // Création : 1 -> 2 -> 1 -> 3 -> 1 -> 4
    Noeud* liste = creerNoeud(1);
    liste->suivant = creerNoeud(2);
    liste->suivant->suivant = creerNoeud(1);
    liste->suivant->suivant->suivant = creerNoeud(3);
    liste->suivant->suivant->suivant->suivant = creerNoeud(1);
    liste->suivant->suivant->suivant->suivant->suivant = creerNoeud(4);
    
    printf("Avant suppression: ");
    afficherListe(liste);
    
    liste = supprimerOccurrences(liste, 1);
    
    printf("Après suppression: ");
    afficherListe(liste);
    
    return 0;
}
