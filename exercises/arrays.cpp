#include <iostream>
#include <vector>
using namespace std;

//Simple array specifying 10 slots, while assigning the first two slots
int arr1[10] = {10, 11};

//Multidimentional array
int someArr[3][3]{{1,1,1}, {2,2,2}, {3,3,3}};

//Range-based for loop
//An array is not copyable so you need to pass by reference, not by value
void iterate() {
  for(auto& row : someArr){
    cout << typeid(row).name() << "\n";
    for(int el: row){
      cout << el << "\n";
    }
  }
}

//Creating dynamic arrays using vector
//Declare the vector/collection
vector<int>collection;

void addToList(int num){
  collection.push_back(num);
}

//Creating a dynamic array using vectors and passing in classes/structs
//Some sort of 3x3 matrix;
//vector<


// int main(){

//   iterate();

//   addToList(40);

//   for(int a: collection){
//     cout << a << "\n";
//   }
//   return 0;
// }