#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// MISSING FUNCTION DECLARATIONS HERE (you can remove these comments)
bool isAnagrams(string input1, string input2);
string clean_sentence(string sentence);

int main()
{
  // MISSING CODE HERE (you can remove these comments)
  // Get strings from user
  string input1, input2;
  cout << "Enter first string: " << endl;
  getline(cin, input1);
  cout << "\nEnter second string: " << endl;
  getline(cin, input2);
  input1 = clean_sentence(input1);
  input2 = clean_sentence(input2);
  bool anagram = isAnagrams(input1, input2);
  if(anagram){
    cout << "The strings are anagrams." << endl;
  }
  else{
    cout << "The strings are not anagrams." << endl;
  }
  
  // Clean strings
  // Check to see if they are anagrams
  // Report if they are or not anagrams

  return 0;
}

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
string clean_sentence(string sentence){
  string space = "";
  for(int i = 0; i < sentence.size(); i++){
    if(((sentence[i] <= 90)&&(sentence[i]>=65))){
      space += sentence[i]+32; // upper case to lower case using ASCII table Decimal 90 --> 65
    }
    else if((sentence[i] <= 122) && (sentence[i] >= 97)){ // lower case from ASCII table 122 --> 97
      space += sentence[i];
    }
  }
  return space;
}

bool isAnagrams(string input1, string input2){
  if(input1.size() != input2.size()){
    return false;
  }
  char space;
  for(int i = 0; i < input1.size()-1; i++){
    for(int j=0; j<input1.size()-1-i; j++){
      
      if(input1[j] > input1[j+1]){
        space = input1[j];
        input1[j] = input1[j+1];
        input1[j+1] = space;
      }
      if(input2[j] > input2[j+1]){
	space = input2[j];
	input2[j] = input2[j+1];
	input2[j+1] = space;
      }
    }
  }
  for( int i = 0; i <input2.size();i++){
    if(input1[i] != input2[i]){
      return false;
    }
  }
  return true;
}
      
