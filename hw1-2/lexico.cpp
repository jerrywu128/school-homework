#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){

  int n;
  cout << "How many strings do you want to input? ";
  cin  >> n;

  char ** str = new char * [n];
   
  

  for(int i=0;i<n;i++){
    
    cout << "Input " << i+1 <<": ";
    
    cin.get();
   
    str[i] = new char[21];
    
    cin.get(str[i],21);
    
    for(int j=0;j<21;j++){
      
    str[i][j] = tolower(str[i][j]);

    } 
  }

  for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        
         if(!(lexicographical_compare(str[i],str[i]+21,str[j],str[j]+21))){
       			 char *temp = new char [21];
                         strncpy(temp,*(str+i),21);
                         strncpy(*(str+i),*(str+j),21);
                         strncpy(*(str+j),temp,21);
     
                         delete [] temp;
         }
   
         
      
      }
  }
   
  

  cout << "\nLexicographical Ordering...\n\n";

  for(int i=0;i<n;i++){
  
   cout << str[i] <<endl;


  }
  





 return 0;
}
