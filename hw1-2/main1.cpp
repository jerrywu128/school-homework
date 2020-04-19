using namespace std; 
#include <iostream>  
#include <cstring>   
#include "name.h"
#include "initial.h"
 
int main()
{
  Name *someone = new Name;
  char *name = new char[LenFN+LenLN+1];
 
  cout << "Please input your name: ";
  for(int i=0;i<(LenFN+LenLN);i++)
    cout << "_";
  for(int i=0;i<(LenFN+LenLN);i++)
    cout << "\b";
 
  cin.getline(name, LenFN+LenLN+1);
 
  someone = setName(name);
 
  cout << "Your first name is " << someone->firstname << "." << endl;
  cout << "Your last name is " << someone->lastname << "." << endl;
  cout << "The initial of your name is " << initial(someone) << endl;
 
  return 0;
}
