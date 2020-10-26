// calculate.cpp
// By: Henry Lin
// Created on: 10/25/2020
#include <iostream>
#include <cstdlib>
using namespace std;

int main( int argc, char *argv[]){
  if(argc!=4){ // The number of elements that is passing in
    cerr << "Number of arguments is incorrect.\n";
    return 0;
  }
  if(argc==4){
    int input1 = atoi(argv[1]); // holds the first argument from the command line
    int input2 = atoi(argv[3]); // holds the third argument from the command line
    string signs = argv[2]; // The numeric signs % * + - is between position 1 and 3... such that input1 signs input2
    if((signs == "%") && (input2 == 0)){
      cerr << "Cannot divide by zero.\n"; //checking for illegal operation
    }
    if(signs == "-"){
      cerr << "Bad operation choice.\n";
    }
    if((signs == "%") && (input2 != 0)){ //division of int
      cout << input1 % input2 << endl;
    }
    if(signs == "x"){ // since the lab require multiplication to be x 
      cout << input1 * input2 << endl;
    }
    if(signs == "+"){  // addition 
      cout << input1 + input2 << endl;
    }
	
  }
  return 0;
}
    
    
   
    
    

















