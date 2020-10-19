#include <iostream>

using namespace std;
// Worked with Daniel Kang
int main() {
  int row, column;
  while ((row != 0) && (column != 0)){ // since we didn't declare code to row or column, it is not 0 and itll run.  
    cout << "Enter number of rows and columns: \n";
    cin >> row >> column;
    for (int r = 0; r < row; r++){
      for (int c = 0; c < column; c++){
	cout << "X."; // printing from left to right 
	
      }
      cout << "\n";  // # rows from int r 
    }
  }
    
  return 0;  
}
