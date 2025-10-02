// insertiooon d'un element dans une liste simplement chaînée triée'

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

Noeud* insererTriSimple(Noeud* tete, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);
    
    // Cas 1: liste vide ou insertion en tête
    if (tete == NULL || valeur <= tete->donnee) {
        nouveau->suivant = tete;
        return nouveau;
    }
    
    // Cas 2: insertion au milieu ou en queue
    Noeud* actuel = tete;
    while (actuel->suivant != NULL && actuel->suivant->donnee < valeur) {
        actuel = actuel->suivant;
    }
    
    nouveau->suivant = actuel->suivant;
    actuel->suivant = nouveau;
    
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
    Noeud* liste = NULL;
    
    // Insertions dans l'ordre
    liste = insererTriSimple(liste, 5);
    liste = insererTriSimple(liste, 2);
    liste = insererTriSimple(liste, 8);
    liste = insererTriSimple(liste, 1);
    liste = insererTriSimple(liste, 4);
    
    printf("Liste triée: ");
    afficherListe(liste);
    
    return 0;
}
