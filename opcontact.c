/*!\file opcontact.c
 *
 * \brief Utilisée pour l'implémentation des fonction de manipulations des contacts.
 * Ce fichier va avoir les fonctions nécissaire à l'ajout, modification et supression des contacts,
 * champs  de pour le programme gcontact.
 *
 * \author Groupe 14 Anis, Alycia, Kamel, Massi, Samy
 */

#include "opcontact.h"

/**
 * \brief  Le maximum de champs au départ.
 */
#define MAX_CHAMPS 32


/*!\brief permet d'ajouter un champs.
 * Cette fonction permet un ajout de champs a partir d'une chaine
 * dans un tableau de contact passé également en argument.
 *
 * \param Prend une chaine de caractère et un tableau de type tabcontact.
 * \return Renvoie 1 cas d'echec sinon 0. 
 *
 */


extern int ajouterChamps(char *str, gcontact *contact){
  int reussi = 0;
  char *s1 =NULL;
  s1 = strtok(str, ",");

  while(s1){
    
    if (!(contact->nbrChamps < contact->cmax))
      contact->chmps = realloc(contact->chmps,(contact->cmax *= 2) * sizeof *(contact->chmps));
    
    contact->chmps[contact->nbrChamps].intitule = strdup(s1);
    if (contact->chmps[contact->nbrChamps].intitule != NULL)
      reussi++;
    s1 = strtok(NULL, ",");
    contact->chmps[contact->nbrChamps].donnees = strdup(s1);
    if (contact->chmps[contact->nbrChamps].donnees != NULL)
      reussi++;
    s1 = strtok(NULL, ",");
    contact->nbrChamps++;
  }
  return (reussi > 0)? 1 : 0;
}


/*!\brief permet d'ajouter un contact a partir d'une chaine de caractère.
 * Cette fonction permet un ajout de contact a partir d'une chaine de caractère passés en argument
 * dans un tableau de contact passé également en argument.
 *
 * \param Prend une chaine de caractère et un tableau de type tabcontact.
 * \return Renvoie 1 cas d'echec sinon 0. 
 *
 */


extern void ajouterContact(char *str, tabcontact *tab,int mode){
  int indice = 0 ;
  char *s1=NULL;

  if (tab->utilisee+1 < tab->taille){
    s1 = strtok(str,",/");
    if (mode == FILE_READ){
      tab->contacttab[tab->utilisee].id = atoi(s1);
      s1 = strtok(NULL,",/");
      tab->contacttab[tab->utilisee].nbrChamps = atoi(s1);
      s1 = strtok(NULL,",/");
    } 
    else{
      tab->contacttab[tab->utilisee].id = tab->utilisee + 1; 
    }
    tab->contacttab[tab->utilisee].chmps = malloc((tab->contacttab[tab->utilisee].cmax = MAX_CHAMPS) * sizeof *(tab->contacttab[tab->utilisee].chmps));
    
    while (s1){
      
      tab->contacttab[tab->utilisee].chmps[indice].intitule = (s1 != NULL) ? strdup(s1) : strdup("Champs vide");
      s1 = strtok(NULL, ",/");
      tab->contacttab[tab->utilisee].chmps[indice].donnees = (s1 != NULL) ? strdup(s1) : strdup("Champs vide");
      s1 = strtok(NULL, ",/");
      ++indice;
      if (!(indice < tab->contacttab[tab->utilisee].cmax))
	tab->contacttab[tab->utilisee].chmps = realloc(tab->contacttab[tab->utilisee].chmps,(tab->contacttab[tab->utilisee].cmax *= 2) * sizeof *(tab->contacttab[tab->utilisee].chmps));
    }
    tab->contacttab[tab->utilisee].nbrChamps = indice;
    tab->utilisee++;
  }
  
}




/*/*!\brief permet de selectionner un contact.
 * Cette fonction permet de selectionner un contact a partir d'une chaine de 
 * caractere donnée puis renvoie son indice
 *
 * \param chaine de caractere et le tableau de contact.
 * \return Renvoie l'indice de contact. 
 *
 */

/*
extern int *trouverContact(char *str, tabcontact *tab){
  int taille= 0, n = 1, *t=malloc((taille = 10) * sizeof *t);
 
  for (int i = 0; i < tab->utilisee; ++i){
    for (int j = 0; j < tab->contacttab[i].nbrChamps; ++j){
      if (strcmp(tab->contacttab[i].chmps[j].intitule,str) == 0 ||
	  strcmp(tab->contacttab[i].chmps[j].donnees,str) == 0){
	 
	t[(n++)] = tab->contacttab[i].id;
	if(n == taille)
	  t = realloc(t, (taille *= 2)*sizeof *t);
	
      }
    }
  }
  t[0]=n;
  return t;
  
}
*/
