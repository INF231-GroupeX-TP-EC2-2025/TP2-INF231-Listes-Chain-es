//insertion en tete et en queue dans une liste simplement chainee circulaire

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

Noeud* insererTeteCirculaire(Noeud* tete, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);
    
    if (tete == NULL) {
        nouveau->suivant = nouveau;
        return nouveau;
    }
    
    nouveau->suivant = tete;
    
    // Trouver le dernier nœud
    Noeud* actuel = tete;
    while (actuel->suivant != tete) {
        actuel = actuel->suivant;
    }
    
    actuel->suivant = nouveau;
    return nouveau;
}

Noeud* insererQueueCirculaire(Noeud* tete, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);
    
    if (tete == NULL) {
        nouveau->suivant = nouveau;
        return nouveau;
    }
    
    // Trouver le dernier nœud
    Noeud* actuel = tete;
    while (actuel->suivant != tete) {
        actuel = actuel->suivant;
    }
    
    actuel->suivant = nouveau;
    nouveau->suivant = tete;
    
    return tete;
}

void afficherListeCirculaire(Noeud* tete) {
    if (tete == NULL) return;
    
    Noeud* actuel = tete;
    do {
        printf("%d -> ", actuel->donnee);
        actuel = actuel->suivant;
    } while (actuel != tete);
    printf("[retour à %d]\n", tete->donnee);
}

int main() {
    Noeud* liste = NULL;
    
    liste = insererTeteCirculaire(liste, 30);
    liste = insererQueueCirculaire(liste, 40);
    liste = insererTeteCirculaire(liste, 20);
    liste = insererQueueCirculaire(liste, 50);
    
    printf("Liste circulaire simple: ");
    afficherListeCirculaire(liste);
    
    return 0;
}
