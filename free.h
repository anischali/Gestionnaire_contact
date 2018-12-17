/*!\file free.h
 *
 * \brief Utilisée pour définir les fonctions de la liberation de la mémoire.
 * Ce fichier va avoir les fonction  pour liberer les contacts ainsi que
 * les fonctions de suppression.
 * 
 * \author Groupe 14 Anis, Alycia, Kamel, Massi, Samy
 */

#ifndef _FREE_H
#define _FREE_H
#include "gcontact.h"
#ifdef __cplusplus
extern "C" {
  #endif
  /**
   * \brief  Cette fonction permet de liberer un champs .
   */
  
  int freeChamps(champs *);
  
  
  /**
   * \brief  Cette fonction permet de liberer un contact et tout ces champs .
   */
  
  void freeContact(gcontact *);



  /**
   * \brief  Cette fonction permet de liberer tout les contact.
   */
  
  void freeAll(tabcontact *);





  
  #ifdef __cplusplus
}
#endif
#endif
  
