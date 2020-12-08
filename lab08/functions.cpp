// Place your member function and program function definitions here:
//  1. The 2 Constructors
//  2. Accessor member function
//  3. Mutator member function #1
//  4. Mutator member function #2
//  5. Program function
// See lab description for details
//
// Setting StringValue to a empty string
#include "headers.h"
#include <iostream>
using namespace std;


AString::AString(){
  StringValue = "";
}
// Initializing StringValue
AString::AString(string str){
  StringValue = str;
}
// Two cin statements for sentence1 and sentence 2... using getline so that spaces would be counted too.
void AString::getAString(){
  cout << "Enter string value: ";
  getline(cin, StringValue);
  
}
// Cleaning Up the sentence with no punctuation
void AString::cleanUp(){
  string clean = "";
  for(int i = 0; i < StringValue.size(); i++){
    if((StringValue[i]<=90)&&(StringValue[i]>=65)){
      clean += StringValue[i]+32;
    }
    else if((StringValue[i] <= 122) && (StringValue[i] >= 97)){
      clean += StringValue[i];
    }
  }
  StringValue = clean;
}

// While the in array is 0-25 = a-z, if there is letter a in the sentence, it would 0 position in the array would +1, which is counting the Letters within the cleanedup sentence.  
void AString::countLetters(int array[]){
  for(int i = 0; i < 26; i++){
    array[i] = 0; // create a array with 26 0's
  }
  for( int i = 0; i < 26; i++){
    for( int j = 0; j < StringValue.size(); j++){ 
      if(StringValue[j] == (i+97)){ // this had to be i + 97 because of ascii or else stringvalue[j] would never be = to i
	array[i]++;
      }
    }
  }
}

// This function compares the two arrays from sentence1 and sentence 2 and if the 2 arrays are the same it will return false. Otherwise it'll return true.
bool compareCounts(int ca1[], int ca2[]){
  for(int i=0; i<26; i++){
    if(ca1[i] != ca2[i]){
      return true;
    }
  }
  return false;
}


