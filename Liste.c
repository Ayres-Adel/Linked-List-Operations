#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"


void initialise(Liste * l)
{
  l->prem = NULL;
  l->last = NULL;
}




// int estVide(const Liste * l)
int estVide(const Liste *l) {
    if (l == NULL) {
        printf("Erreur : liste non initialisée.\n");
        exit(EXIT_FAILURE);
    }

    return (l->prem == NULL) ? 1 : 0;
}









// unsigned int nbElements(const Liste * l)
unsigned int nbElements(const Liste *l) {

    if (l == NULL) {
        printf("Erreur : liste non initialisée.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int count = 0;
    Cellule *temp = l->prem; 

    while (temp != NULL) {
        count++;
        temp = temp->suivant; 
    }

    return count;
}













 // void affichageListeGaucheDroite(const Liste * l)
void affichageListeGaucheDroite(const Liste *l) {

    if (l == NULL || l->prem == NULL) {
        printf("Liste vide ou non initialisée.\n");
        return;
    }

    Cellule *temp = l->prem; 

    printf("Contenu de la liste de gauche à droite : ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->suivant; 
    }
    printf("\n");
}










// void affichageListeDroiteGauche(const Liste * l)
void affichageListeDroiteGauche(const Liste *l) {

    if (l == NULL || l->last == NULL) {
        printf("Liste vide ou non initialisée.\n");
        return;
    }

    Cellule *temp = l->last; 

    printf("Contenu de la liste de droite à gauche : ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->precedent; 
    }
    printf("\n");
}

















// void ajoutEnTete(int e,Liste * l)
void ajoutEnTete(int e, Liste *l) {

    if (l == NULL) {
        printf("Erreur : liste non initialisée.\n");
        exit(EXIT_FAILURE);
    }


    Cellule *nouvelleCellule = (Cellule *)malloc(sizeof(Cellule));
    if (nouvelleCellule == NULL) {
        printf("Erreur : allocation de mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }
    nouvelleCellule->info = e;
    nouvelleCellule->suivant = l->prem; 

    if (l->prem != NULL) {
        l->prem->precedent = nouvelleCellule; 
    } else {
        l->last = nouvelleCellule; 
    }

    nouvelleCellule->precedent = NULL; 
    l->prem = nouvelleCellule; 
}







// void suppressionEnTete(Liste * l)
void suppressionEnTete(Liste *l) {
    if (l == NULL || l->prem == NULL) {
        printf("Erreur : liste vide ou non initialisée.\n");
        exit(EXIT_FAILURE);
    }

    Cellule *aSupprimer = l->prem;

    if (aSupprimer->suivant != NULL) {
        l->prem = aSupprimer->suivant;                   
        l->prem->precedent = NULL;
    } else {
        l->prem = NULL;
        l->last = NULL;
    }

    free(aSupprimer);
}
















// void videListe(Liste * l)
void videListe(Liste *l) {
    if (l == NULL) {
        printf("Erreur : liste non initialisée.\n");
        exit(EXIT_FAILURE);
    }
    Cellule *courant = l->prem;
    while (courant != NULL) {
        Cellule *suivant = courant->suivant;                  
        free(courant);
        courant = suivant;
    }
    l->prem = NULL;
    l->last = NULL;
}



//void ajoutEnQueue(int e, Liste * l)
void ajoutEnQueue(int e, Liste *l) {
    if (l == NULL) {
        printf("Erreur : liste non initialisée.\n");
        exit(EXIT_FAILURE);
    }
    Cellule *nouvelleCellule = (Cellule *)malloc(sizeof(Cellule));
    if (nouvelleCellule == NULL) {
        printf("Erreur : allocation de mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }
    nouvelleCellule->info = e;
    nouvelleCellule->suivant = NULL;
    nouvelleCellule->precedent = NULL;
    if (l->prem == NULL) {
        l->prem = nouvelleCellule;
        l->last = nouvelleCellule;
    } else {
        l->last->suivant = nouvelleCellule;
        nouvelleCellule->precedent = l->last;
        l->last = nouvelleCellule;
    }
}





















// void affectation(Liste * l1, const Liste * l2)
void affectation(Liste *l1, const Liste *l2) {
    if (l1 == NULL || l2 == NULL) {
        printf("Erreur : listes non initialisées.\n");
        exit(EXIT_FAILURE);
    }
    if (l2->prem == NULL) {
        l1->prem = NULL;
        l1->last = NULL;
        return;
    }
    Cellule *temp = l2->prem;
    l1->prem = (Cellule *)malloc(sizeof(Cellule));
    if (l1->prem == NULL) {
        printf("Erreur : allocation de mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }                                                                       
    l1->prem->info = temp->info;
    l1->prem->suivant = NULL;
    l1->prem->precedent = NULL;

    Cellule *courant = l1->prem;
    temp = temp->suivant;

    while (temp != NULL) {
        courant->suivant = (Cellule *)malloc(sizeof(Cellule));
        if (courant->suivant == NULL) {
            printf("Erreur : allocation de mémoire échouée.\n");
            exit(EXIT_FAILURE);
        }
        courant->suivant->info = temp->info;
        courant->suivant->suivant = NULL;
        courant->suivant->precedent = courant;

        temp = temp->suivant;
        courant = courant->suivant;
    }

    l1->last = courant; 
}




















// int rechercheElement(int e, const Liste *l)
int rechercheElement(int e, const Liste *l) {
    if (l==NULL||l->prem==NULL)
	{
        return -1; 
    }
    Cellule *courant = l->prem;
    int position = 0;
    while (courant != NULL)                                                         
	{
        if (courant->info==e)                        
		{
            return position;                                                                            
        }
        courant=courant->suivant;
        position++;
    }

    return -1; 
}




















// void insererElement(int e, Liste * l, unsigned int position)
void insererElement(int e, Liste *l, unsigned int position) {
    Cellule *nouvelleCellule = (Cellule *)malloc(sizeof(Cellule));
    if (nouvelleCellule == NULL) {
        printf("Erreur : allocation de mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }
    nouvelleCellule->info = e;
    nouvelleCellule->suivant = NULL;
    nouvelleCellule->precedent = NULL;

    if (l == NULL) {
        printf("Erreur : liste non initialisée.\n");
        exit(EXIT_FAILURE);
    }

    if (position == 0) {
        if (l->prem == NULL) {
            l->prem = nouvelleCellule;
            l->last = nouvelleCellule;                                     
        } else {
            nouvelleCellule->suivant = l->prem;
            l->prem->precedent = nouvelleCellule;
            l->prem = nouvelleCellule;
        }
    } else {
        Cellule *courant = l->prem;
        unsigned int currentPosition = 0;

        while (courant != NULL && currentPosition < position - 1) {
            courant = courant->suivant;
            currentPosition++;
        }
        if (courant == NULL) {
            printf("Erreur : position invalide pour l'insertion.\n");
            free(nouvelleCellule);
            exit(EXIT_FAILURE);
        }
        nouvelleCellule->suivant = courant->suivant;
        if (courant->suivant != NULL) {
            courant->suivant->precedent = nouvelleCellule;
        } else {
            l->last = nouvelleCellule;
        }
        courant->suivant = nouvelleCellule;
        nouvelleCellule->precedent = courant;
    }
}





















