/*!\file free.c
 *
 * \brief Utilisée pour l'implémentation des fonctions de liberation de 
 * la mémoire.
 * \detail Ce fichier va avoir les fonctions nécissaire à la liberation et ou 
 * la suppression d'un champs ou d'un contact ou de répertoire. 
 * \author Groupe 14 Anis, Alycia, Kamel, Massi, Samy
 */


#include "opcontact.h"




/*!\detail Cette fonction permet de liberer un champs d'un contact en prenant 
 * un champ en parametre.
 * 
 *
 * \param Prend un champs.
 * \return Renvoie rien. 
 *
 */

int freeChamps(champs *champ){
  int libere = 0;
  if (champ->intitule != NULL){
    free(champ->intitule);
    champ->intitule = NULL;
    ++libere;
  }
  if(champ->donnees != NULL){
    free(champ->donnees);
    champ->donnees = NULL;
    ++libere;
  }
  if (libere > 0) return 1;
  else return 0;
  
}



/*!\brief Permet de liberer un contact.
 *\detail Cette fonction permet de liberer un contact passée en parametre ainsi que tout ces champs
 *
 * \param Prend un contact.
 * \return Renvoie rien. 
 *
 */

void freeContact(gcontact *contact){
  int i;
  int nbrchamp = contact->nbrChamps;
  if (contact->id != 0){
    for (i = 0; i < nbrchamp; ++i){
      
      if (contact->nbrChamps >= 0){
	contact->nbrChamps += freeChamps(&contact->chmps[i]);
      }
    }
    contact->id = 0;
    free(contact->chmps);
    contact->chmps = NULL;
  }
 
  
}




/*!\brief Permet de liberer tout les contacts.
 *\detail Cette fonction permet de liberer le tableau de contacts passée en parametre 
 * ainsi que tout les contacts et leurs champs.
 *
 * \param Prend un tableau de contacts.
 * \return Renvoie rien. 
 *
 */

void freeAll(tabcontact *tab){
  int i;
  
  for (i = 0; i < tab->utilisee; ++i){
    freeContact(&tab->contacttab[i]);
  }
  free(tab->contacttab);
  tab->contacttab = NULL;
  tab->utilisee = 0;
  tab->taille = 0;
  free(tab);
  tab = NULL;
}



