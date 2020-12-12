// Declare your FOUR functions here (no more, no less):
// That is, the 3 functions for the selectionSort:
// swap_values, find_index_of_swap, sort
// plus the function getArray
#include <iostream>
using namespace std;

void getArray(ifstream& ifs, string FILENAME, int array[], int size);
void sort(bool descending, int array, int size, int starting_index);
void swap_values(int v1, int v2, int array[]);
int find_index_of_swap(bool descending, int array[], int size, int starting_index);

// Constants for the data file that your program is reading in
// Only change these if you want to test your program with a different array file
// than the one provided for you (ArrayFile.txt).
//
const int MAXSIZE = 20;     // amount of integers in the file (you need this to declare your array size)
const std::string FILENAME = "ArrayFile.txt";    // The file name with the integers

