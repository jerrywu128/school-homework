#include <iostream>
#include <string>
#include <cstring>
#include "initial.h"
#include  "name.h"

using namespace std;

char *initial(Name *n ){

  char *initial_name = new char[30];
  initial_name = n->lastname;
  strcat(initial_name,", "); 

  const  char * t,*a;
  t = strpbrk(n->firstname,"-");
  a = n->firstname;
  strncat(initial_name,a,1);
  strcat(initial_name,".");
  
  while(t!=NULL){
    strcat(initial_name,"-");
    strncat(initial_name,t+1,1);
    strcat(initial_name,"."); 
    t = strpbrk(t+1,"-");
  }
 
  


 return initial_name;
}
