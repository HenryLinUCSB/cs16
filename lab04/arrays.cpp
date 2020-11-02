// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
  // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
  ifstream ifs;
  int size = MAXSIZE, array[MAXSIZE];
  getArray(ifs, FILENAME, array, size);


  // hints for the tasks:
  // all that needs to be in here is simple calls the functions, like these:
  // in addition to, some print to std.out statements.
  //
  // Your main() will ideally look clean and uncluttered and be made up
  // mostly of function calls.
  //
  // Example:
  // ...
  // printArray(array, size);
  // max = maxArray(array, size);
  // min = minArray(array, size);
  // ...
  // ...etc...


  // PUT MISSING CODE HERE
  print_array(array, size);
  cout << endl;

  int max = maxArray(array, size);
  cout << "Max = " << max << endl;

  int min = minArray(array, size);
  cout << "Min = " << min << endl;
  
  int sum = sumArray(array, size);
  cout << "Sum = " << sum << endl;

  cout << "Evens: "; evensArray(array, size);
  
  cout << "Primes: "; primesArray(array, size); 
   
  return 0;
}


void print_array(int arr[], int asize){
  for(int i = 0; i < asize; i++)
    if(arr[i] < (asize-1))
      cout << arr[i] << ", ";
  
}

int maxArray(int arr[],int asize){
  for(int i = 0 ; i < asize; i++)
    if(arr[0] < arr[i])
      arr[0] = arr[i];
  return arr[0];
}

int minArray(int arr[], int asize){
  for(int i = 0; i < asize ; i++)
    if(arr[0] > arr[i])
      arr[0] = arr[i];
  return arr[0];
}

int sumArray(int arr[], int asize){
  int total = 0;
  for (int i = 0; i < asize; i++)
    total += arr[i];
  return total;
}

void evensArray(int arr[], int asize){
  for (int i = 0; i < asize; i++)
    if(arr[i]%2==0)
      cout << arr[i] << ", ";
  cout << "end" << endl;
}

void primesArray(int arr[], int asize){
  for(int i = 0; i<asize; i++){
    int x = 1;
    if(arr[i] > 1){
      for (int j = 2; j <= arr[i]/2; ++j){
        if(arr[i]%j == 0){
          x = 0;
          break;
      }
    }
    if(x==1)
      cout << arr[i] << ", ";
    }
  }
  cout << "end" << endl;
       
    
     
}


int SeqSearch(int arr[], int array_size, int target){
  int index = 0;
  for (int i = 0; i < array_size ; i++)
    if (arr[i] == target)
      index = i;
    else
      index = -1;
  return index;
}
void AllSearches( int array[], int array_size){
}
