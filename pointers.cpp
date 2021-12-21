#include <iostream>
using namespace std;

int someNum = 25;
int *someOtherNum = &someNum;
int main ()
{
  cout << someNum;
  cout << "\n";
  
  cout << &someNum;
  cout << "\n";
  
  cout << *someOtherNum;
  cout << "\n";

  cout << someOtherNum;
  cout << "\n";

  cout << &someOtherNum;
  cout << "\n";



  return 0;
}