#include <iostream>
#include "arrays.cpp"
using namespace std;


//Function passing a fundamental type;


//Function passing an array;

void testing(int arg[]){
  for(int i = 0; i < 3; i += 1){
    cout << arg[i] << "\n";
  }
}

//Function passing a pointer;


int main () {

  testing(arr1);

}