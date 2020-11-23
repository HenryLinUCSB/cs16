#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
string convertFromDec( unsigned int decnum, unsigned int base);

int main(){
  cout << "Enter positive decimal number (anything else quits): ";
  string enteredvalue;
  cin >> enteredvalue;
  int decnum;
  int base(0);
  decnum = stoi(enteredvalue); // learned in class when we did the string to integer conversion
  if(decnum >0){
    convertFromDec(decnum, base);
  }
  else{
    return 0;
  }
  
}
string convertFromDec(unsigned int decnum, unsigned int base){
  // binary...inspired by https://www.geeksforgeeks.org/program-decimal-binary-conversion/
  base = 2;
  int decnumOctal = decnum;
  int decnumHex = decnum;
  int binout[32];
  int i(0);
  cout << decnum << " in binary is: ";
  // The while function would run until decnum is 0
  // using the % would get the remainder and we store it to array i, then i++ to the next element of the aray
  while (decnum > 0){
    binout[i] = decnum % base;
    decnum = decnum / base;
    i++;
  }
  for(int x = i - 1; x >= 0; x--){
    cout << binout[x];
  }
    
  //octal... same as above but with 8 since it's octal
  base = 8;  // re-valued the base
  int octout[50]; // gave a random maximum elements for this array
  i = 0; //revalued the i
  cout << "\n" << decnumOctal << " in octal is: ";
  while (decnumOctal > 0){
    octout[i] = decnumOctal % base;
    decnumOctal = decnumOctal / base;
    i++;
  }
  for(int y = i -1; y >= 0; y--){
    cout << octout[y];
  }
  // Hexa: inspired by https://www.w3resource.com/cpp-exercises/for-loop/cpp-for-loop-exercise-71.php
  base = 16;
  char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  string hexaresult = "";
  int integer = 0;
  cout << "\n" << decnumHex << " in hex is: ";
  while(decnumHex > 0){
    integer = decnumHex%16;
    hexaresult = hex[integer] + hexaresult;
    decnumHex = decnumHex / base;
  }
  return 0;
}
    
 
