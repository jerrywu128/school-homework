#include <iostream>
#include <cstring>
#include <string>
#include "name.h"

using namespace std;

Name *setName(const char *name)
 {

   Name *somebody = new Name;
   
   const char *t;
   t = strpbrk(name,",");
   
   

 
   if(t!=NULL){

      strcpy(somebody->firstname,t+2);
      strncpy(somebody->lastname,name,t-name);
   }
   else{
    t = strpbrk(name," ");
      strncpy(somebody->firstname,name,t-name);
      strcpy(somebody->lastname,t+1);
   } 

   return somebody;
}
