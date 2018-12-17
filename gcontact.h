/*!\file gcontact.h
 *
 * \brief Utilisée pour définir les fonctions concernant l'initialisation des structures contacts.
 * Ce fichier va avoir les structure nécissaire pour les contacts ainsi que
 * les fonctions d'initialisation des contacts.
 * 
 * \author Groupe 14 Anis, Alycia, Kamel, Massi, Samy
 */

#ifndef _GCONTACT_H
#define _GCONTACT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#ifdef __cplusplus
extern "C" {
  #endif
//Les structures:
  /**
   * \brief        Structure champs.
   */
  typedef struct champs champs;
 
  
  struct champs
  {
    char *intitule; /*!<L'intitulé de champs à ajouter*/
    char *donnees; /*!<Les données des champs*/
    
  };

  /**
   * \brief        Structure contact.
   */
  typedef struct gcontact gcontact;
 
  
  struct gcontact
  {
    unsigned int id; /*!<L'identifiant unique de contact*/
    int nbrChamps; /*!<Le nombres de champs que contient le contact*/
    int cmax;      /*!<indique le nombre de champs allouer*/
    champs *chmps;/*!<Un pointeur vers le tableau des champs*/
  };
/**
   * \brief        Structure pour le tableau de contact.
   */
  typedef struct tabcontact tabcontact;
 
  
  struct tabcontact
  {
    int utilisee; /*!<Nombre de contacts utiliseés*/
    int taille; /*!La taille actuelle de tableau*/
    gcontact *contacttab;/*!<Un tableau de pointeurs vers contact*/
  };


//Les fonctions:
  
/**
 * \brief        Fonction d'initialisation de tableau de contact.
 */
  
  extern tabcontact * initContact(void);
  
 /**
  * \brief        Fonction d'agrandissement de tableau de contact.
  */
  
  extern int agrandirTab(tabcontact *);
  /**
 * \brief        Fonction qui ajoute un contact dans le tableau de contact.
 */

  extern void ajouterContact(char *, tabcontact *,int);
  

 /**
 * \brief        Fonction qui affiche les contacts.
 */

  extern void afficher(const tabcontact *);	
/**
 * \brief        Fonction qui affiche le menu de programme.
 */

 extern int menu(void);
  
/**
 * \brief        Fonction qui récupère un contact saisie par l'utilisateur.
 */

 extern char * saisirContact(int);

/**
 * \brief  Permet d'effectuer les choix de l'utilisateur.
 */

  extern void executerChoix(const int,  tabcontact *, int *);



/**
*\brief Permet de liberer tout les contacts.
*/

 extern void freeAll(tabcontact *);

  
/**
*\brief Permet d'ajouter un champs a un contact.
*/

  extern int ajouterChamps(char *, gcontact *);

  
/**
 *\brief Permet de sauvegarder les contacts dans un fichier.
 */

extern void sauvegarder(const tabcontact *);

/**
 *\brief Permet de charger les contacts a partir d'un fichier.
 */
extern void charger(tabcontact *);
  

  


    
#ifdef __cplusplus
}
#endif
#endif
  
  
