// Define your FOUR functions here (no more, no less):
// First, the 3 functions for the selectionSort:
// swap_values, find_index_of_swap, sort
#include "headers.h"
#include <iostream>
using namespace std;
void swap_values(int v1, int v2, int array[]){
  int temp;
  temp = array[v1];
  array[v1] = array[v2];
  array[v2] = temp;
  
}


int find_index_of_swap(bool descending, int array[], int size, int starting_index){
  if(descending){
    //descending so that the first value is the largest
    int max = array[starting_index];
    int index_of_max = starting_index;
    for (int index = starting_index + 1; index < size; index ++){
      // if array index is larger than max value, then the max value would be swapped to the array index
      if(array[index] > max){
	max = array[index];
	index_of_max = index;
      }
    }
    return index_of_max;
  }
  //ascending so that the the first value is the smallest
  else{
    int min = array[starting_index];
    int index_of_min = starting_index;
    // if array index is smaller than min value, then the min value would be swapped to array index
    for (int index = starting_index +1; index < size; index++){
      if(array[index] < min){
	min = array[index];
	index_of_min = index;
      }
    }
    return index_of_min;
  }
	
				
    
}

void sort(bool descending, int array[], int size, int starting_index){
  if(size == 0){
    return;
  }
  int findindex = find_index_of_swap(descending, array, size, starting_index);
  if(findindex != starting_index){
    swap_values(findindex, starting_index, array);
  }
  sort(descending, array, size, starting_index);
  
}

// Next, define the function getArray here.
// This is the same one we used in Lab 4, so you can copy it over as is.
void getArray(ifstream& ifs, string FILENAME, int array[], int size)
{
  ifs.open(FILENAME);
  if ( ifs.fail() )
    {
      cerr << "Input file opening failed.\n";
      exit(1);
    }
  for (int i = 0; i < size; i++)
    {
      ifs >> array[i];
    }
}
