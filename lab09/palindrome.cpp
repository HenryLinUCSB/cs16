// Your Name Here
// henry Lin

// PLACE THE NECESSARY include, etc... STATEMENTS HERE
//
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
// DECLARE THE FUNCTIONS HERE:
//
void cleanUp(string& p);
bool isPalindrome(string p);

int main() {
  string p;
  cout << "Enter sentence:\n";
  getline(cin, p);

  cleanUp(p);
  bool answer = isPalindrome(p);

  if (answer) {
    cout << "It is a palindrome.\n";
  } else {
    cout << "It is not a palindrome.\n";
  }

  return 0;
}

// DEFINE THE FUNCTIONS HERE:
// clean up function would only leave the alphabets
// I used the same method I used on the previous lab
void cleanUp(string& p){
  string cleaned = "";
  //ascii for upper case (adding uppercase letters to cleaned)
  for(int i = 0; i < p.size(); i++){
    if((p[i] <=90)&&(p[i] >=65)){
      cleaned += p[i];
    }
    // ascii for lower case (adding lowecase letters to cleaned)
    else if((p[i] <= 122) && (p[i] >= 97)){
      cleaned += p[i]+32;
    }
  }
  //set p = cleaned, which is the cleaned up string which only contains letters
  p = cleaned;

}
// this bool ispalindrome will return true if the letters counted forward is the same as the letters counte backwards
bool isPalindrome(string p){
  // If the size of P is 1 or 0 (also wouldn't be negative), it will be a Palindrome because 0 backw is 0, 1 letter backw is the same
  if(p.size() <= 1){
    return true;
  }
  //if position 0 is different than the last character, then it is not a Palindrome
  if(p[0] != p[p.size()-1]){
    return false;
  }
  // here is the recursed statement where the string starts conting from 1 forward, and second to the last backwards
  return isPalindrome(p.substr(1, p.size()-2));
  
}

