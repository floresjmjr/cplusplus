#include <iostream>
#include <algorithm>
using namespace std;
//Easy Puzzles
//Check if intersection of horiztonal and vertical leave only one option
//Check if only one empty square left in 3x3;
//Check if horiztonal and vertical 1-9 usage;

//Each technique should continue to be used if it it haves an impact (fills out slots) otherwise it jumps to next technique.

class Technique
{
private:
  bool singleNumChanges;    //Maybe this isn't necessary if the methods return a boolean
  bool intersectionChanges; //Maybe this isn't necessary if the methods return a boolean
public:
  void missingSingleNum(int arr[9][9]);
  void intersection(int rows[9][9], int columns[9][9]);
};

void Technique::missingSingleNum(int arr[9][9])
{
  //Check if only 1 cell left
  for (int i = 0; i < 9; i += 1)
  {
    int totalZeros = count(begin(arr[i]), end(arr[i]), 0);
    if (totalZeros == 1)
    {
      int total = 45;
      //Find which number is missing
      for (int k = 0; k < 9; k += 1)
      {
        total -= arr[i][k];
      }
      for (int z = 0; z < 9; z += 1)
      {
        if (0 == arr[i][z])
        {
          cout << "Missing number is: " << total << ", index " << z << "\n";
          arr[i][z] = total;
          break;
        }
      }

      //Plug in that number that's missing
    }
    cout << "No missing number for row: " << i << "\n";
  }
}

void Technique::intersection(int rows[9][9], int columns[9][9])
{
  //Check if only 1 cell left
}
