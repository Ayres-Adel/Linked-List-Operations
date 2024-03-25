#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Liste.h"
#include "Liste.c"
/* 
member of group:
Laidoui adil
Koceir Mehdi
Merah lotfi youcef
Tahri soheyb
KERFI GUETIB SAYEH
kaouther boutheldja
 */
int main()
{
  int i, alea,A,j,max;
  Liste lili, lala;
  printf("input number for insererElement: ");
  scanf("%d",&i);
  printf("input number rechercheElement: ");
  scanf("%d",&A);

  srand(time(NULL));


  initialise(&lili);

  /* Remplissage de lili : test de ajoutEnTete et AjoutEnQueue */
  printf("max: ");
  scanf("%d",&max);
  for(j=0;j<max;j++)
  {
  	printf("elment %d: ",j);
  	scanf("%d",&alea);
  	ajoutEnTete(alea,&lili);
    ajoutEnQueue(alea,&lili);
  }
  












  /* Creation d'une copie de lili */
  affectation(&lala,&lili);






  /* Modification de lili, lala ne doit pas etre affectee */
     /* insertion en tete */
     ajoutEnTete(i,&lili);

     /* insertion en queue */
     ajoutEnQueue(i,&lili);

     /* insertion en position 3 (num. en partant de 0) */
     insererElement(i,&lili,2);

     /* Printing LiLi after insertion */
     printf("lili: ");
     affichageListeGaucheDroite(&lili);
    /* Printing LaLa  */
    printf("lala: ");
    affichageListeGaucheDroite(&lala);




  /* Recherches dans lili */
  
  printf("rechercheElement:%d",rechercheElement(A,&lili));
  









  // return 0;
}
