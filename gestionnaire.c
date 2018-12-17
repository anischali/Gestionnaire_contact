#include "opcontact.h"



int main(void){
  tabcontact *cont = initContact();
  int choix=0, boolmodif = 0;
  charger(cont);
  while(1){
    
    choix=menu();
    executerChoix(choix, cont, &boolmodif);
  }
 


}
