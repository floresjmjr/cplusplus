#include <iostream>
#include <vector>
using namespace std;

//Simple array specifying 10 slots, while assigning the first two slots
int arr1[10] = {10, 11};

//Creating dynamic arrays using vector
//Declare the vector/collection
vector<int>collection;

void addToList(int num){
  collection.push_back(num);
}

//Creating a dynamic array using vectors and passing in classes/structs
//Some sort of 3x3 matrix;
//vector<

int main(){

  addToList(40);

  for(int a: collection){
    cout << a << "\n";
  }
  return 0;
}