#include <iostream>
#include <cstring>
#include <string>
#include "name.h"
#include <algorithm>
using namespace std;
/*Past1-------------------------------------------------------*/
enum leval{
   Gold,
   Silver
};

struct members_data{
   Name *name; 
  
   string  phone_number;
  
   enum leval LV; 
  
   union members_benefit{
        double discount;
        int freeMinute;
   }benefit;

};
/*-----------------------------------define members_data struct*/

int main(){

/*Past2---------------------------------------------------*/  
     members_data * member = new members_data[5];
     char mleval[10];
     int a;

     for(int i=0;i<5;i++)
     {   
        char *names = new char[40];
        cin.get(names,40).get();
    
        member[i].name = setName(names);
        delete [] names;
        
        cin >> member[i].phone_number; cin.get();              
        cin.getline(mleval,10);
             
        if (strcmp(mleval,"Gold")==0) 
             a=0;
        else
             a=1;

              switch (a){
                   case 0:
                        member[i].LV = Gold;
                        break;    
                   case 1:
                        member[i].LV = Silver;
                        break;
              } 
       
               
        if (member[i].LV==0){
                cin >> member[i].benefit.discount; 
        }
        else{
                cin >> member[i].benefit.freeMinute;
        }     
                cin.get();
        
     };

/*-------------------------------------------Input members data 5 members*/

/*Past3------------------------------------------------------------------*/
     int b;
     members_data t;
     for(int i=0;i<5;i++){
           for(int j=i+1;j<5;j++){

                     a = strcmp(member[i].name->lastname,member[j].name->lastname);

                     if(a==0){
                      b = lexicographical_compare(member[i].name->firstname,member[i].name->firstname+21,
                                                  member[j].name->firstname,member[j].name->firstname+21);
                         if(!b){  
                                t = member[i];
                                member[i]=member[j];
                                member[j] = t;
                         }

                     } 
           }
     }
/*----------------------------------------------------------------lexicographical the data*/


/*Past4-----------------------------------------------------------------------------------*/
    bool quit = false;
    int count = 0;



 while(!quit){

    char * input = new char[10];
 
    cout << "Input: ";
    cin.get(input,10).get();
    cout << input <<endl;
   
    if (strcmp(input,"Quit")==0){
        cout << "Bye" <<endl;
        quit =true;
        break;
    }

    for(int i=0;i<5;i++){
        
         a = strcmp(input,member[i].name->lastname);
  
          if (a==0){
                  cout << member[i].name->firstname << " ("
                       << member[i].phone_number    << ") " ;
               
                  if(member[i].LV==0){
                        cout << "G/" << member[i].benefit.discount << endl;
                  }
  
                  else{
                        cout << "S/" << member[i].benefit.freeMinute << endl;           
	          }
   
                  count ++;
 
          }

    }
     
    if (count==0) {

          cout << "Member not found!\n" ;

    }
   
    count =0;
    cout << endl;
  
    delete [] input ;
     
 }
/*---------------------------------------------------------------------Output members data*/
  return 0;
} 
