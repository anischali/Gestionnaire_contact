/*!\file input_output.c
 *
 * \brief Utilisée pour l'implémentation des fonction d'affichage des contacts.
 * \detail Ce fichier va avoir les fonctions nécissaire à l'affichage des contacts et elle va s'occuper
 * de communiquer avec l'utilisateur.
 *
 * \author Groupe 14 Anis, Alycia, Kamel, Massi, Samy
 */


#include "opcontact.h"


/*!\detail Cette fonction permet d'afficher un champs d'un contact en prenant un champ en parametre
 * 
 *
 * \param Prend un champs.
 * \return Renvoie rien. 
 *
 */

static void afficherUnChamps(const champs champ){
  if (champ.intitule != NULL && champ.donnees != NULL){
    fprintf(stdout,"| %s | %s |\n", champ.intitule, champ.donnees);
    fprintf(stdout, "----------------------------------------------\n");
  }
}


/*!\brief Permet d'afficher un contact.
 *\detail Cette fonction permet d'afficher un contact en prenant un contact en parametre
 * un champ.
 *
 * \param Prend un contact.
 * \return Renvoie rien. 
 *
 */

static void afficherUnContact(const gcontact contact){
  int i;
  if (contact.id != 0){
    fprintf(stdout, "***********  %d  ***********\n",contact.id);
    for (i = 0; i < contact.nbrChamps; ++i)
      afficherUnChamps(contact.chmps[i]);
  }
}


/*!\detail Cette fonction permet d'afficher le répertoir des contacts en prenant un contact en parametre
 * un tableau de contact.
 *
 * \param Prend un tableau de contacts.
 * \return Renvoie rien. 
 *
 */

extern void afficher(const tabcontact *tab){
  int i;
  fprintf(stdout, "::::::: Répertoire :::::::\n");
  for (i = 0; i < tab->utilisee; ++i)
    afficherUnContact(tab->contacttab[i]);
  
}



/*!\detail Cette fonction permet d'afficher le menu pricipale de programme et
 * permet a l'utilisateur de faire son choix.
 * \param Prend rien.
 * \return Renvoie rien. 
 *
 */

extern int menu(void){
  int choix=0;

  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "....GGGG.EEEE..SSS.TTTTT.II..OOO..NN....N..AAA..II..RRR...EEEE...DDD...EEEE...\n");
  fprintf(stdout, "...G.....E....S......T...II.O...O.N.N...N.A...A.II..R..R..E......D..D..E......\n");
  fprintf(stdout, "...G.....EEEE..SSS...T...II.O...O.N..N..N.AAAAA.II..RRR...EEEE...D..D..EEEE...\n");
  fprintf(stdout, "...G...G.E........S..T...II.O...O.N...N.N.A...A.II..R..R..E......D..D..E......\n");
  fprintf(stdout, "....GGGG.EEEE.SSSS...T...II..OOO..N....NN.A...A.II..R...R.EEEE...DDD...EEEE...\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "................CCCC..OOO..NN....N.TTTTT..AAA...CCCC.TTTTT..SSS...............\n");
  fprintf(stdout, "...............C.....O...O.N.N...N...T...A...A.C.......T...S..................\n");
  fprintf(stdout, "...............C.....O...O.N..N..N...T...AAAAA.C.......T....SSS...............\n");
  fprintf(stdout, "...............C.....O...O.N...N.N...T...A...A.C.......T.......S..............\n");
  fprintf(stdout, "................CCCC..OOO..N....NN...T...A...A..CCCC...T...SSSS...............\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "Faite un choix d'opération dans le menu.......................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, ".1..Afficher le répertoire....................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, ".2..Ajouter un contact........................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, ".3..Modifier un contact.......................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, ".4..Supprimer un contacr......................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, ".5..Rechercher un contact.....................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, ".6..Quitter...................................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "..............................................................................\n");
  fprintf(stdout, "..............................................................................\n");
  while (!(choix > '0' && choix < '7'))choix = fgetc(stdin);
  return choix-48;
}


/*!\brief Permet de récuperer la saisie de l'utilistaeur.
 *\detail Cette fonction permet la récupération d'un contact saisie par l'utilisateur
 * puis retourne un pointeur vers la chaine de caractere
 * \param Prend rien.
 * \return Renvoie un pointeur vers une chaine de caractere. 
 *
 */


extern char * saisirContact(int call){
  char *vide = "Champs vide,";
  char string[1024] = {0};
 
  int indice = 0, c = 0,len = 0;
  fprintf(stdout, "Saisissez les noms des champs et leur contenu une fois terminé entrez le caractère '!' \n");
  if (call == 0)
    c = fgetc(stdin);
  
  while((c = fgetc(stdin))){
    
    if ( c == '!' )break;//fin d'un champs.
    else if (c != ',' && c != '\n'){//eviter le retour a la ligne et la virgule qu'est un separateur.
      string[indice++] = c;
      len++;
    }
    else if (c == '\n' && len == 0){ // le cas d'un champs laisser vide. 
      for (int i = 0; i < 12; ++i)
	string[indice++] = c = vide[i];
    }
    else if (c == '\n' && len > 0){ //la fin d'un champs et ces membre.
      string[indice++] = ',';
      len = 0;
    }
  }

  string[indice]='\0'; //la fin d'une chaine de caractere.
  return strndup(string, indice);
  
}




/*!\brief permet de selectionner un contact.
 * Cette fonction permet de trouver les contacts contenant une chaine de 
 * caractere donnée puis l'affiche.
 *
 * \param chaine de caractere et le tableau de contact.
 * \return Rien. 
 *
 */


static void trouverContact(tabcontact *tab){
  char *cont=NULL, atrouver[30] = {0};
  int eviterChariot = 2;
  
  fprintf(stdout, "Entrez un intitule ou les données d'un contact\n");
  while(eviterChariot-- > 0){
    fflush(stdin);
    cont = fgets( atrouver, 30, stdin);
  }
  cont=atrouver;
  while(*cont++ != '\0')
    if (*cont == 10){
      *cont = '\0';
    }
  for (int i = 0; i < tab->utilisee; ++i){
    for (int j = 0; j < tab->contacttab[i].nbrChamps; ++j){
      if (tab->contacttab[i].id  != 0){
	if (strcmp(tab->contacttab[i].chmps[j].intitule, atrouver) == 0 ||
	    strcmp(tab->contacttab[i].chmps[j].donnees, atrouver) == 0){
	  afficherUnContact(tab->contacttab[i]);
	  break;
	}
      }
    }
  }
  
}


/*!\brief Permet d'obtenir un pointeur vers un contact.
 *\detail Cette fonction permet la recupération d'un pointeur sur contact a 
 * d'un id données en entrée.
 * \param et un id le tableau de contacts.
 * \return gcontact * pointeur vers contact. 
 *
 */


static gcontact *getContact(unsigned int id, const tabcontact *contact){
  
  
  for (int i = 0; i < contact->utilisee; ++i){
    if (contact->contacttab[i].id == id){
      return &(contact->contacttab[i]);
    }
  }
  return NULL;
} 








/*!\brief Permet de definir le type de modification.
 *\detail Cette fonction permet la récupération de choix saisie par l'utilisateur
 * puis fait appel a la fonction qui exécute son choix de modification concernée.
 * \param le tableau de contacts.
 * \return rien. 
 *
 */

static void choixModification(tabcontact *contact){
  int choix1 = 0, choix2 = 0, vid = 0, id = 0, champnum = 0, data = 0;
  char idchar[10]={0}, *amodifier = NULL, *s1 = NULL;
  gcontact *modifier = NULL;
  
  
  while(!vid){
    fprintf(stdout, "[1] Vous aver l'[id]entifiant de contact.\n");
    fprintf(stdout, "[2] Chercher le contact pour trouver son [id].\n");
    
    while(!(choix1 > '0' && choix1 < '3'))
      choix1 = fgetc(stdin); 
    
    switch(choix1-48){
    case 1:
      while(!vid){
	while(id < 1 || id > contact->utilisee){
	  fprintf(stdout, "Entrez l'[id]: ");
	  fflush(stdin);
	  s1 = fgets(idchar, 10, stdin);
	  id=atoi(idchar);
	}
	vid = 1;
      }
      choix1 = 0;
      break;
    case 2:
      trouverContact(contact);
      choix1 = 0;
      break;
    default:
      choix1 = 0;
    }
  }
  modifier = getContact(id , contact);
  afficherUnContact(*modifier);

  
  fprintf(stdout, "\n\n[1] Ajouter un champs.\n");
  fprintf(stdout, "[2] Modifier un champs.\n");
  fprintf(stdout, "[3] Supprimer un champs.\n");
  fprintf(stdout, "[4] Retourner.\n");

  while(!(choix2 > '0' && choix2 < '5'))choix2 = fgetc(stdin);
  if (choix2-48 == 2 || choix2-48 == 3){
    vid = 0;
    while(!vid){
      fprintf(stdout,"Veuillez rentrez le numero de champs entre 1 et %d\n", modifier->nbrChamps);
      while(!vid && !champnum){
	fflush(stdin);
	s1 = fgets(idchar, 10, stdin);
	
	if (atoi(idchar) > 0 && atoi(idchar) <= modifier->nbrChamps){
	  vid = 1;
	  champnum = atoi(idchar);
	}
	
      }
    }
    afficherUnChamps(modifier->chmps[champnum-1]);
  }
 
  switch(choix2-48){
  case 1:
    ajouterChamps(saisirContact(0),modifier);
    break;
  case 2:
    vid = 0;
    while(!vid){
      fprintf(stdout,"Entrez ce que vous voulez modifier [1] donnees [2] intitulee [3] les deux\n");
      while(!vid && !data){
	fflush(stdin);
	s1 = fgets(idchar, 10, stdin);
	if (atoi(idchar) > 0 && atoi(idchar) < 4){
	  vid = 1;
	  data = atoi(idchar);
	}
      }
    }
    switch(data){
    case 1:
      free(modifier->chmps[champnum-1].donnees);
      amodifier=saisirContact(1);
      s1 = strtok(amodifier,",");
      modifier->chmps[champnum-1].donnees = strdup(s1);
      break;
    case 2:
      free(modifier->chmps[champnum-1].intitule);
      amodifier=saisirContact(1);
      s1 = strtok(amodifier,",");
      modifier->chmps[champnum-1].intitule = strdup(s1);
      break;
    case 3:
      modifier->nbrChamps -= freeChamps(&modifier->chmps[modifier->nbrChamps - 1]);
      ajouterChamps(saisirContact(0),modifier);
      break;
    }
    break;
  case 3:
    while(champnum - 1 < modifier->nbrChamps){
      modifier->chmps[champnum-1].intitule = modifier->chmps[champnum].intitule;
      modifier->chmps[champnum-1].donnees = modifier->chmps[champnum].donnees;
      champnum++;
    }
    
    modifier->nbrChamps -= freeChamps(&modifier->chmps[modifier->nbrChamps - 1]);
    printf("%d\n",  modifier->nbrChamps);
    break;
  case 4:
    return;
  }
 
}


/*!\brief Permet de supprimer un contact complet.
 *\detail Cette fonction permet la supprission d'un contact choisi par l'utilisateur
 *
 * \param le tableau de contacts.
 * \return rien. 
 *
 */


static void supprimeContact(tabcontact *contact){
  int choix1 = 0, choix2 = 0, vid = 0, id = 0;
  char idchar[10]={0}, *s1 = NULL;
  gcontact *modifier = NULL;
  
  
  while(!vid){
    fprintf(stdout, "[1] Vous aver l'[id]entifiant de contact.\n");
    fprintf(stdout, "[2] Chercher le contact pour trouver son [id].\n");
    
    while(!(choix1 > '0' && choix1 < '3'))
      choix1 = fgetc(stdin); 
    
    switch(choix1-48){
    case 1:
      while(!vid){
	while(id < 1 || id > contact->utilisee){
	  fprintf(stdout, "Entrez l'[id]: ");
	  fflush(stdin);
	  s1 = fgets(idchar, 10, stdin);
	  id=atoi(idchar);
	}
	vid = 1;
      }
      choix1 = 0;
      break;
    case 2:
      trouverContact(contact);
      choix1 = 0;
      break;
    default:
      choix1 = 0;
    }
  }
  modifier = getContact(id , contact);
  afficherUnContact(*modifier);
  for (int i = 0; i < contact->utilisee; ++i){
    if (contact->contacttab[i].id == modifier->id)
      id = i;
  }
  fprintf(stdout,"vous voullez supprimé ce contacte tapez Y/N ");
  choix2=fgetc(stdin);
  if(choix2 == 'Y' || choix2 == 'y'){
       freeContact(modifier);
      
  }
  
  else return;


}

/*!\brief Permet d'effectuer les choix de l'utilisateur.
 *\detail Cette fonction permet la récupération de choix saisie par l'utilisateur en entrée
 * puis fait appel a la fonction qui exécute son choix
 * \param int un entier en 1 et 5 correspondant au choix de l'utilisateur.
 * \return rien. 
 *
 */


extern void executerChoix(const int choix,  tabcontact *contact, int *boolmodif){

  char *cont=NULL;
  
  switch(choix){

  case 1:
    afficher(contact);
    break;
  case 2:
    cont = saisirContact(0);
    ajouterContact(cont,contact,USER_READ);
    free(cont);
    cont=NULL;
    *boolmodif = 1;
    break;
  case 3:
    choixModification(contact);
    *boolmodif = 1;
    break;
  case 4:
    supprimeContact(contact);
    *boolmodif = 1;
    break;
  case 5:
    trouverContact(contact);
    break;
  case 6:
    if (*boolmodif == 1)
      sauvegarder(contact);
    freeAll(contact);
    exit(0);
    break;
  default:
    return;
  }
  
}









