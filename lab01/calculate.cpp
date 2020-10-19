# include <iostream>
using namespace std;
int main() {
  int var1, var2, var3, total;
  cout << "Please enter 3 numbers." << endl;
  cin >> var1;
  cin >> var2;
  cin >> var3;
  total = 3*(var1+2*var2)-4*var3;
  cout << "The formula result is: ";
  cout << total << endl;
  return 0;
}
