/*!\file init.c
 *
 * \brief Utilisée pour initialisé toutes les structures de donnés de programme.
 * Ce fichier va avoir les fonctions nécissaire à l'initialisation de toutes les
 * structures de données utilisées dans le programme gcontact.
 *
 * \author Groupe 14 Anis, Alycia, Kamel, Massi, Samy
 */
#include "gcontact.h"


/*!\brief permet d'allouer le tableau de pointeurs vers gcontact
 * Cette fonction permet un tableu de pointeurs vers des contacts
 * avec une taille de départ de 64 éléments puis renvoie la mémoire allouée
 * dans un pointeur.
 *
 * \param Ne prend rien en parametres.
 * \return Renvoie un pointeur de type tabconatct. 
 *
 */

extern tabcontact * initContact(void){
  tabcontact *tableau=NULL;//tableau de pour les conatcts.
  tableau = malloc(sizeof *tableau);//allocation de la variable a renvoyer.
  tableau->contacttab = malloc((tableau->taille = 64) * sizeof *(tableau->contacttab));//allocation de tableau contenant des contacts.
  assert(tableau->contacttab);
  tableau->utilisee=0;
  return tableau;
}





/*!\brief Permet d'agrandir le tableau de contact dans le cas ou il est plein. 
 * Cette fonction permet d'agrandir le tableau contact en prenant comme entreé 
 * le pointeur vers le tableau existant puis double sa taille.
 *
 * \param Un pointeur de type tabcontact.
 * \return Renvoie 1 si l'opperation a échouer sinon 0. 
 *
 */

extern int agrandirTab(tabcontact *tab){
  tab->contacttab = realloc(tab->contacttab, (tab->taille *= 2) * sizeof *tab->contacttab);//l'opération de la reallocation
  if (tab->contacttab == NULL)
    return 1;
  return 0;
}

 
