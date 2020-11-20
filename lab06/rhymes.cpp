#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

//void wordendcomparison();

using namespace std;

void wordcleanup(ifstream &ifs, ofstream &outstream, string filename);
void cleanuptostring(ifstream &ifs, string clean, string &lines);
void lastword(string lines, string &previousWord, string &LastWord);
bool WordComparison(string previousWord, string LastWord);

int main(){
  // should output 2 decimal points for rhym line density.
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  // Ask User for inputFile Name
  string filename;
  cout << "Enter file name: ";
  cin >> filename;
  // ifstream open file and reads new lines for line count
  ifstream ifs;
  ofstream outstream; //creating an outstream to copy code over later...
  ifs.open(filename);
  // Cerr message if input file fails.
  if(ifs.fail()){
    cerr << "Input file opening failed.";
    exit(1);
  }
  
  ifs.close();

  wordcleanup(ifs, outstream, filename);
  string clean = "clean.txt"; // the new file for cleaned poem
  string lines;
  cleanuptostring(ifs, clean, lines);
  string previousWord = " ";
  string LastWord = " ";
  lastword(lines, previousWord, LastWord);
}





// This function I want to clean up the poem with no punctuation
void wordcleanup(ifstream &ifs, ofstream &outstream, string filename){
  ifs.open(filename);
  outstream.open("clean.txt");
  // inspired by hw06 Q3
  char c;
  ifs.get(c);
  while(!ifs.eof()){
    if ((c!= '?')&&(c != '!')&&(c != ',')&&(c!='.')&&(c!='"')){
      outstream << c;
    }
    ifs.get(c);
  }
  ifs.close();
  outstream.close();
}

void cleanuptostring(ifstream &ifs, string clean, string &lines){
  ifs.open(clean);
  string cleanuplines;
  char c;
  ifs.get(c);
  char lastchar;
  // converting the cleaned up file to string for lastword...
  // I'm adding all the characters including \n into string line
  while(!ifs.eof()){
    if( c== '\n' && lastchar == '\n'){
      lastchar = '\n';
    }
    else{
      cleanuplines += c;
      if( c== '\n'){
	lastchar = '\n';
      }
    }
    
    lastchar = c;
    ifs.get(c);
  }
  lines = cleanuplines;
    
  ifs.close(); 
}
// This Function, I will extract the last words from each line, using last index and counts backwards until
// space
void lastword(string lines, string &previousWord, string &LastWord){
  int LastIndex;
  int indexLine(1);
  int pairs(0);
  int count(0);
  for(int i = 0; i < lines.length(); i++){
    if((lines[i] == '\n')||(i==lines.length()-1)){
      LastIndex = i;
      // Need to find the word before every end line
      while((lines[LastIndex] == ' ')||(lines[LastIndex]== '\n')){
	LastIndex--;
      }
      LastWord = " ";
      // To get the LastWord, this goes backwards until a space character is found.
      while(lines[LastIndex] != ' '){
	LastWord = lines[LastIndex] + LastWord;
	LastIndex--;
      }
      // This will run the boolean wordcomparison and checks if the last two character of the words are
      // the same, if it is, then the boolean will return true and cout the rhyme words/
      if(previousWord != " "){
	if(WordComparison(LastWord, previousWord)){
	  pairs++;
	  cout << previousWord << "and " << LastWord << endl;
	}
      }
      previousWord = LastWord;
      count++;
      indexLine++;
    }
  }
  // Calculating the rhyme density of the text.
  double doublepairs;
  double doubleindexline;
  double density;
  doublepairs = pairs;
  doubleindexline = indexLine;
  density = doublepairs/(doubleindexline-1.00);
  if(pairs==1){
    cout << "There is " << pairs << " pair of rhyming words." << endl;
    cout << "There are " << indexLine-1 << " lines in this poem, so the rhyme-line density is: " << density;
  }
  else if(pairs > 1){
    cout << "There are " << pairs << " pairs of rhyming words." << endl;
    cout << "There are " << indexLine-1 << " lines in this poem, so the rhyme-line density is: " << density;
  }
  else{
    cout << "No rhymes found." << endl;
    cout << "There are " << indexLine-1 << " lines in this poem.";
  }
}

bool WordComparison(string previousWord, string LastWord){
  if(previousWord.substr(previousWord.length()-2)==LastWord.substr(LastWord.length()-2)){
    return true;
  }
  else{
    return false;
  }
}

    
  
      
      
  

    



