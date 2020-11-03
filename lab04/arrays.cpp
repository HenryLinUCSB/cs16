/*
/ Skeleton File for ARRAYS.CPP for CS16, 2020, UCSB
/ Copyright 2020 by Ziad Matni. All rights reserved.
/
*/


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

  int max = maxArray(array, size);
  cout << "Max = " << max << endl;

  int min = minArray(array, size);
  cout << "Min = " << min << endl;
  
  int sum = sumArray(array, size);
  cout << "Sum = " << sum << endl;

  cout << "Evens: "; evensArray(array, size);
  
  cout << "Primes: "; primesArray(array, size); 

  cout << "Searches: " << endl;
  
  AllSearches(array, size);
  cout << endl;
  
  return 0;
}


void print_array(int arr[], int asize){
  for(int i = 0; i < asize-1; i++){   // this will print out 1 element before the last term with , after
      cout << arr[i] << ", ";
  }
  cout << arr[asize-1] << endl; // The last term of this would not have a comma, instead it will get an end line
  
  
}

int maxArray(int arr[],int asize){
  int max = 0;
  for(int i = 0 ; i < asize; i++)
    if(max < arr[i]) //If the array term is less than arr[i], it means that arr[i] is greater
      max = arr[i]; // since arr[i] is greater than every other element, it'll be the greatest
  return max;  // so I set arr[0]=arr[i] and print out the number
}

int minArray(int arr[], int asize){
  int min = 0; // same thing as above but with opposite sign which shows the lowest element
  for(int i = 0; i < asize ; i++)
    if(min > arr[i])
      min = arr[i];
  return min;
}

int sumArray(int arr[], int asize){
  int total = 0;
  for (int i = 0; i < asize; i++){ // for every element, we add the element into total
    total += arr[i];
  }
  return total;
}

void evensArray(int arr[], int asize){
  for (int i = 0; i < asize; i++)
    if(arr[i]%2==0) // Even number should have no remainders
      cout << arr[i] << ", ";
  cout << "end" << endl;
}

void primesArray(int arr[], int asize){
  for(int i = 0; i<asize; i++){ 
    int x = 1;                           // declare variable x = 1
    if(arr[i] <= 1){   // if it is any number less than or equal to 1, then it is not a prime number
      x = 0;
    }// prime numbers cannot be negative or 0 or 1
    for (int j = 2; j < arr[i]/2; j++){  //prime number starts with 2, if the number%j == 0, it is not a prime number..
      if(arr[i]%j == 0){                 // prime number cannot be divided by half of itself, since it can only be divisible by
        x = 0;                           // 1 or itself. 
        break;
      }
    }
    if(x==1)                             // if x == 1 (another way of saying true where 0 is false) then it would print the prime number  
      cout << arr[i] << ", ";
    }

  cout << "end" << endl;
       
    
     
}


int SeqSearch(int arr[], int array_size, int target){
  for (int i = 0; i < array_size ; i++)
    if (arr[i] == target) // if the target is in the array, then the function would return the index of the number. 
      return i;
  return -1; // if not the function will return -1, which the lab instructions told us to do so. 
}
void AllSearches( int array[], int array_size){
  int sequent;
  for(int i = 0; i < NSEARCHES; i++){              // i increase until NSEARCHES 10 in constants. 
    cout << "Looking for " << SEARCHES[i] << ". "; // Searches[] array declared in constants 
    sequent = SeqSearch(array, array_size, SEARCHES[i]);            //sequent search called, either returns index i or -1
    if(sequent != -1)                       // if index is not = 1 then it is found, and the index of the found number position from arr[] would be printed
      cout << "Found at index: " << sequent << endl;
    else               // if i==-1, which is from the seqsearch, then the target is not found in the Array
      cout << "Nout Found!" << endl;
  }
}
