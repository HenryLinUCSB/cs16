#include <iostream>
#include <cmath> 
#include <string>
using namespace std;
void compute_coins(int amount, int quarters, int dimes, int pennies);

int main(){
  int c, quarters(0), dimes(0), pennies(0);
  cout << "Enter number of cents (or zero to quit):\n";
  cin >> c; // This make the user input their number of cents.
  int original = c; // I created another int for c because the value of c will be changed later on (subtracting)
  while(((c<1)&&(c!=0))||(c>99)){ // While the input cent is less than 1 or greater than 99 the program would 
    cout << "Amount is out of bounds. Must be between 1 and 99.\n"; // notify the user that it is out of bounds and asks
    cout << "Enter number of cents (or zero to quit):\n";           // for another input
    cin >> c;
    original = c; // After entering value to c, we input the initial value of c into int original(already defined)
   
  }
  while(original!=0){ // If original is not equal to 0, the program while loop would end until it is. The number of cents would be subtracted down to 0 at some point with quarters, dimes, and pennies. 
    
    while(((c>0)&&(c<100))){ // If the entered value cent is within the bound, this loop will run
      if(c>=25){ // if the value c is greater than 25, then it can covered by quarters (25c) and 25 would be subtracted from the value while 1 count for quarters would be added.
	c-=25;
	quarters+=1;
      }
      else if(c>=10){ // Same thing above but for dimes
	c-=10;
	dimes+=1;
      }
      else{ // Same thing above but for pennies. If it is not subtractable by quarters or dimes, we only have pennies left to subtract from. Since nickels were ommitted. 
	c-=1;
	pennies+=1;
      }
    }
    compute_coins(original, quarters, dimes, pennies); //Here we define the subjects inside the void and this calls for tor the void. 
    quarters = 0; // initial count of quarters
    dimes = 0; // initial count of dimes
    pennies = 0; // initial count of pennies
    cout << "Enter number of cents (or zero to quit):\n";
    cin >> c; 
    original = c;
    while(((c<1)&&(c!=0))||(c>99)){ //If the first out of bounds while loop ends, this one would continue to ask .
      cout << "Amount is out of bounds. Must be between 1 and 99.\n";
      cout << "Enter number of cents (or zero to quit):\n";
      cin >> c;
      original = c;
    }
   
    
  }
  

  return 0;
}




void compute_coins(int amount, int quarters, int dimes, int pennies){
  string q = "quarters"; //plural tense for quarters dimes and pennies
  string d = "dimes";
  string p = "pennies";
  if(quarters == 1){ // if either of the coins were to be 1, the word for them in the sentence would be singular.
    q = "quarter";
  }
  if(dimes == 1){
    d = "dime";
  }
  if(pennies == 1){
    p = "penny";
  }
  if((quarters>0)&&(dimes>0)&&(pennies>0)){ // This is all the cases of order that the input cents could be split into quarters, dimes, and pennies.
    cout << amount << " cents can be given in " << quarters << " " << q << ", " << dimes << " " << d << ", " << pennies << " " << p << ".\n";
  }
  else if((quarters==0)&&(dimes>0)&&(pennies>0)){
    cout << amount << " cents can be given in " << dimes << " " << d << ", " << pennies << " " << p << ".\n";
  }
  else if((quarters==0)&&(dimes==0)&&(pennies>0)){
    cout << amount  << " cents can be given in " << pennies << " " << p << ".\n";
  }
  else if ((quarters>0)&&(dimes>0)&&(pennies==0)){
    cout << amount << " cents can be given in " << quarters << " " << q << ", " << dimes << " " << d << ".\n";
  }
  else if((quarters>0)&&(dimes==0)&&(pennies>0)){
    cout << amount << " cents can be given in " << quarters << " " << q << ", " << pennies << " " << p << ".\n";
  }
  else if ((quarters==0)&&(dimes>0)&&(pennies==0)){
    cout << amount << " cents can be given in " << dimes << " " << d << ".\n";
  }
  else if ((quarters>0)&&(dimes==0)&&(pennies==0)){
    cout << amount << " cents can be given in " << quarters << " " << q << ".\n";
  }
  
}
  
    








  
