#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

//void wordendcomparison();

using namespace std;

void wordcleanup(ifstream &ifs, ofstream &outstream, string filename);
void lastword(ifstream &ifs, string clean);

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
  lastword(ifs, clean);
}

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

void lastword(ifstream &ifs, string clean){
  ifs.open(clean);
  int count(0);
  string next;
  while(ifs >> next){
    count++;
  }
  ifs.close();
  cout << count;
  
}
    
  

    



