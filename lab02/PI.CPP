#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int terms(1);
  double pivalue(1);
  int N(-1); // I use -1 for value N so that the while loop can run no matter what.
  cout.setf(ios::fixed);  // for precision and 5 decimals points 
  cout.setf(ios::showpoint);
  cout.precision(5);
  cout << "Enter the number of terms to approximate (or zero to quit):\n";
  cin >> N;
  
  // You need to do something about the formatting requirement here!

  // You also need to do a loop here that keeps asking for number of terms and then calculates pi!
  while (N != 0){
    int x = 3; // starting denominator for the first fraction 
    for(int i = 1; i<N+1; i++){  // This will run until it reaches N+1
      pivalue += (pow(-1.0,i)/x); // I used -1.0 for double because integer/integer will always be an integer also the first term will be -1/3 
      x += 2; // the increment of denominator by 2 
    }
    cout << "The approximation for Leibniz's Formula is " << pivalue*4 << " using " << N << " terms.\n";
    pivalue = 1; // I have to reset the value of pi = 1 or else when you repeat it, it wouldnt get the correct starting value
    cout << "Enter the number of terms to approximate (or zero to quit):\n";
    cin >> N;
  }
  // HINT: You can use cmath for its pow() function, which calculates x raised to the power y when used like: pow(x,y)


  return 0;
}
