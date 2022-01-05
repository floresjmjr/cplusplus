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

//Does this create another memory location??
  cout << &someOtherNum;
  cout << "\n";

//Memory addresses should be the same
  cout << (someOtherNum == &someNum);
  cout << "\n";

//Values should be the same

  cout << (*someOtherNum == someNum);
  cout << "\n";

  cout << (*someOtherNum = 100);
  cout << "\n";

  cout << someNum;
  cout << "\n";

//Pointers and arrays
int arr[10];
int * pointerArr = arr;
  cout << pointerArr;
  cout << "\n";

  cout << arr;
  cout << "\n";

  const char * strPointer = "Hello";    //string literal as double quotes
  cout << (*(strPointer+1));
  cout << "\n";

  cout << (strPointer[1]);
  cout << "\n";


  return 0;
}