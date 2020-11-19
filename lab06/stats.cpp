#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;
// function declaration
void Mean(double arrays[], int count, int next, double &mean, double sum);
void Mediann(int count, double &median, double arrays[]);
void Standardd(int count, double stddev, double arrays[], double mean);


int main(){
  // double should be 3 decimals at output
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(3);
  // Asks User to enter filename 
  string filename;
  cout << "Enter filename: ";
  cin >> filename;
  // declare variables
  ifstream ifs;
  double num, sum(0), mean, median, stddev;

  int count(0);
  double next;
  // opening filename and counting the number of elements
  ifs.open(filename);
  while(ifs >> next){
    count++;
  }
  ifs.close();
  
  ifs.open(filename);

  // Creating an Array for Median function, and sorting it with bubble sort
  int x(0);
  double arrays[count];
  while(ifs >> next){
    arrays[x] = next;
    x++;
  }
  // bubble sort
  double place;
  for( int i = 0; i < count - 1; i++){
    for( int j = 0; j < count - i - 1; j++){
      if(arrays[j] > arrays[j+1]){
	place = arrays[j];
	arrays[j] = arrays[j+1];
	arrays[j+1] = place;
      }
    }
  }
  ifs.close();
  //outputting the program...
  //testing
  
  Mean(arrays, count, next, mean, sum);
  Mediann(count, median, arrays);
  Standardd(count, stddev, arrays, mean);
  
}

void Mean(double arrays[], int count, int next, double &mean, double sum){
  for(int i = 0; i < count; i++){
    sum += arrays[i];
  }
  double a = count;
  double b = sum;
  mean = b/a;
  cout << "Mean = " << mean << endl;

}
void Mediann(int count, double &median, double arrays[]){
  if(count%2==0){
    int x = count/2;
    int y = (count/2)-1;
    double a = arrays[x]+arrays[y];
    double b = 2.000;
    median = a/b;
    cout << "Median = " << median << endl;
  }
  else{
    double a = count;
    int x = count/2.000;
    median = arrays[x];
    cout << "Median = " << median << endl;
  }
}

void Standardd(int count, double stddev, double arrays[], double mean){
  double sumforstddev(0);
  for(int i = 0; i < count; i++){
    sumforstddev += pow(arrays[i]-mean,2.000);
  }
  
  stddev = sqrt(sumforstddev/(count-1));
  cout << "Stddev = " << stddev << endl;
}
  
    
    
