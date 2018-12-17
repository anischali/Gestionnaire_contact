/*!\file file.c
 *
 * \brief Utilisée pour l'implémentation des fonctions de sauvegarde et de  
 * chargement a partir d'un fichier 
 * \detail Ce fichier va avoir les fonctions nécissaire à la sauvegarde et ou 
 * le chargement des contacts de répertoire. 
 * \author Groupe 14 Anis, Alycia, Kamel, Massi, Samy
 */


#include "opcontact.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>



/*!\detail Cette fonction permet d'ouvrir un fichier et renvoie son indice sur  
 * la table des fichier.
 * 
 *
 * \param Prend rien.
 * \return Renvoie rien. 
 *
 */



static int existe(const char *name){

  struct stat info;
  if (stat(name, &info) == 0)
    return 1;
  else return 0;

}



/*!\detail Cette fonction permet d'ouvrir un fichier et renvoie son indice sur  
 * la table des fichier.
 * 
 *
 * \param Prend un entier determinant le mode.
 * \return Renvoie un indice de fichier. 
 *
 */


static int ouvrirUnFichier(int mode){
  char *name = "./saveContact.save";
  int fd = 0;
  
  if (existe(name))
    fd = open(name, mode, 0777);
  else fd = open(name, O_CREAT | mode, 0777);
  return fd;
}


/*!\detail Cette fonction permet de charger les contacts d'un fichier  
 * et de les ajouter dans le repertoire.
 * 
 *
 * \param tabcontact * le tableau de contact.
 * \return Renvoie rien. 
 *
 */


extern void charger(tabcontact *contact){
  int fd = ouvrirUnFichier(O_RDONLY);
  char *line = NULL, *verif = NULL;
  ssize_t nbr;
  size_t len;
  FILE *stream = fdopen(fd,"r");
  while ((nbr = getline(&line, &len, stream)) != -1){
    if (line != NULL){
      verif = line;
      while(*verif++)
	if (*verif == '\n') *verif = '\0';
      ajouterContact(line, contact, FILE_READ);
    }
  }
  fclose(stream);
  free(line);
  close(fd);
  remove("./saveContact.save");
}


/*!\detail Cette fonction permet de sauvegarder tout les contacts de   
 * repertoire passeé en parametre.
 * 
 *
 * \param tabcontact * tableau de contacts.
 * \return Renvoie rien. 
 *
 */


extern void sauvegarder(const tabcontact *contact){
  int fd = 0, id = 1;
  FILE *stream = NULL;
  fd = ouvrirUnFichier(O_WRONLY);
  stream = fdopen(fd,"w");
  if (lseek(fd, 0, SEEK_SET) == 0){
    for (int i = 0; i < contact->utilisee; ++i){
      if (contact->contacttab[i].id != 0){
	fprintf(stream,"%d",id++);
	fputs(",", stream);
	fprintf(stream,"%d",contact->contacttab[i].nbrChamps);
	
	
	for (int j = 0; j < contact->contacttab[i].nbrChamps; ++j){
	  fputs(",", stream);
	  fputs(contact->contacttab[i].chmps[j].intitule, stream);
	  fputs(",", stream);
	  fputs(contact->contacttab[i].chmps[j].donnees, stream);
	  
	  
	}
	fputs("\n",stream);
      }
      
    }
  }
  
  
  fclose(stream);
  close(fd);
  
}



