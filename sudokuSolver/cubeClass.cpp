#include <iostream>
using namespace std;

class Cube
{
public:
  int *top[3], *middle[3], *bottom[3];    //pointers belong to the identifier (var name) not the (data) type

public:
  Cube();
  Cube(int c[9]);
};

int cArr[9] = {1, 2, 3, 0, 5, 6, 7, 8, 9};

//Default Cube constructor definition
Cube::Cube(){}

//Cube second constructor definition
Cube::Cube(int c[9])
{
  for (int i = 0; i < 3; i += 1)
  {
    top[i] = &c[i];
    middle[i] = &c[i+3];
    bottom[i] = &c[i+6];
  }
}

// int main() {
//   Cube testCube(cArr);
//   cout << "Value should be 0" << endl;
//   cout << cArr[3] << endl;
//   int * value = testCube.middle[0];
//   cout << *value << endl;
//   cout << "Value should be 1" << endl;
//   cArr[3] = 1;
//   cout << cArr[3] << endl;
//   cout << *value << endl;
//   cout << "Value should be 2" << endl;
//   *value = 2;
//   cout << *value << endl;
//   cout << cArr[3] << endl;
//   cout << endl;
//   return 0;
// }
