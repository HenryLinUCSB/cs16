#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void sort_string(string& sentence, int size);
void print_freq(string sentence, int size);
string clean(string sentence);
// Missing Function Declarations here (you can remove these comments)

int main()
{
  string sentence;
  cout << "Enter Sentence: ";
  getline(cin,sentence);
  // MISSING (short) CODE HERE TO GET SENTENCE FROM USER (you can remove these comments)
  sentence = clean(sentence);
  cout << "Sorted and cleaned-up sentence:";
  int size = sentence.size();
  sort_string(sentence, size);
  cout << sentence << endl;
  print_freq(sentence, size);

  return 0;
}
// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
void sort_string(string& sentence, int size){ // Sentence will change outside of this function in alphabetical order ascii
  for(int i = 0; i < size - 1; i++){ // counting the characters until the element before the last
    for(int j = 0; j< size - 1 - i; j++){ 
      if(sentence[j] > sentence[j+1]){
	char letter = sentence[j];
	sentence[j] = sentence[j+1];
	sentence[j+1] = letter;
      }
    }
  }
}
void print_freq(string sentence, int size){
  int count(1);
  while(true){
    if(sentence[0] !=sentence[1]){
      cout << sentence[0] << ": " << count << endl;
      count = 1;
    }
    else{
      count++;
    }
    sentence = sentence.substr(1);
    if(sentence.size() == 2){
      if(sentence[0] == sentence[1]){
	count++;
	cout << sentence[0] << ": " << count << endl;
      }
      else{
	cout << sentence[1] << ": 1" << endl;
      }
      break;
    }
  }
}

string clean(string sentence){
  string space = "";
  for(int i = 0; i < sentence.size(); i++){
    if((sentence[i] <= 90 && sentence[i] >= 65) || (sentence[i] <= 122 && sentence[i] >= 97)){
      space += sentence[i];
      }
  }
  return space;
}
      
  
