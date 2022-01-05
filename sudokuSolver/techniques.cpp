#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
// using namespace std;
//Easy Puzzles
//Check if intersection of horiztonal and vertical leave only one option
//Check if only one empty square left in 3x3;
//Check if horiztonal and vertical 1-9 usage;

class Technique
{
private:
  bool singleNumChanges;    //Maybe this isn't necessary if the methods return a boolean
  bool intersectionChanges; //Maybe this isn't necessary if the methods return a boolean
private:
  int countZeros(int *arr[9]);
  int deduceMissingNumber(int *arr[9]);

public:
  void missingSingleNum(int *arr[9][9]);
  void singleDirectionGrouping(int *arr[9][9], string direction);
};

int Technique::countZeros(int *arr[9])
{
  int totalZeros = 0;
  for (int i = 0; i < 9; i += 1)
  {
    if (*(arr[i]) == 0)
    {
      totalZeros += 1;
    }
  }
  return totalZeros;
}

int Technique::deduceMissingNumber(int *arr[9])
{
  int total = 45; //Magic number is sum of 1..9
  for (int k = 0; k < 9; k += 1)
  {
    total -= *(arr[k]);
  }
  return total;
}

void Technique::missingSingleNum(int *arr[9][9])
{
  for (int i = 0; i < 9; i += 1)
  {
    int totalZeros = 0;
    totalZeros = countZeros(arr[i]);
    cout << totalZeros << "\n";
    if (totalZeros == 1)
    {
      int missingValue = deduceMissingNumber(arr[i]);
      for (int z = 0; z < 9; z += 1)
      {
        if (0 == *(arr[i][z]))
        {
          cout << "Missing number is: " << missingValue << ", index " << z << "\n";
          *(arr[i][z]) = missingValue;
          break;
        }
      }
    }
    cout << "No missing number: " << i << "\n";
  }
}

void checkRowIntersection()
{
}

void solveIfPossibleColumns(int *lastCube[9], int num, int idx, int idx2)
{
  cout << "--"
       << "Num: " << num << " Index1: " << idx << " Index2: " << idx2;
  string cellColumns[3] = {"Left", "Middle", "Right"};
  string occupiedRows[3] = {"", "", ""};
  int cellColumnIndex;
  if (idx == 0 || idx2 == 0 || idx == 3 || idx2 == 3 || idx == 6 || idx2 == 6)
  {
    occupiedRows[0] = "Left";
  }
  if (idx == 1 || idx2 == 1 || idx == 4 || idx2 == 4 || idx == 7 || idx2 == 7)
  {
    occupiedRows[1] = "Middle";
  }
  if (idx == 2 || idx2 == 2 || idx == 5 || idx2 == 5 || idx == 8 || idx2 == 8)
  {
    occupiedRows[2] = "Right";
  }

  for (int i = 0; i < 3; i += 1)
  {
    if (occupiedRows[i].length() == 0)
    {
      cout << " Cell Column: " << cellColumns[i];
      cellColumnIndex = i;
    }
  }
  int start;
  if (cellColumns[cellColumnIndex] == "Left")
  {
    start = 0;
  }
  if (cellColumns[cellColumnIndex] == "Middle")
  {
    start = 1;
  }
  if (cellColumns[cellColumnIndex] == "Right")
  {
    start = 2;
  }

  int totalZeros = 0;
  int fillIndex;
  bool isDuplicate = false;
  cout << " Cells: ";
  for (int i = start; i < 9; i += 3)
  {
    cout << *(lastCube[i]) << ", ";
    if (*(lastCube[i]) == 0)
    {
      totalZeros += 1;
      fillIndex = i;
    }
    if (*(lastCube[i]) == num)
    {
      isDuplicate = true;
    }
  }
  cout << " Total Zeros: " << totalZeros;
  if (totalZeros == 1 && !isDuplicate)
  {
    cout << " Fill Index: " << fillIndex;
    *(lastCube[fillIndex]) = num;
  }
  cout << "\n";
  if (totalZeros > 1 && !isDuplicate)
  {
    checkRowIntersection();
  }
}

void checkColumnIntersection(int *intersectingCube[9], int startingPoint)
{
}

// check if last cube has one cell empty(lastCube, starting obj)
void solveIfPossibleRows(int *lastCube[9], int num, int idx, int idx2)
{
  cout << "--"
       << "Num: " << num << " Index1: " << idx << " Index2: " << idx2;
  string cellRows[3] = {"Top", "Middle", "Bottom"};
  string occupiedRows[3] = {"Empty", "Empty", "Empty"};
  int cellRowIndex;

  if (idx <= 2 || idx2 <= 2)
  {
    occupiedRows[0] = "Top";
  }
  if ((idx >= 3 && idx <= 5) || (idx2 >= 3 && idx2 <= 5))
  {
    occupiedRows[1] = "Middle";
  }
  if ((idx >= 6 && idx <= 8) || (idx2 >= 6 && idx2 <= 8))
  {
    occupiedRows[2] = "Bottom";
  }

  for (int i = 0; i < 3; i += 1)
  {
    if (cellRows[i] != occupiedRows[i])
    {
      cout << " Cell Row: " << cellRows[i];
      cellRowIndex = i;
    }
  }
  int start;
  if (cellRows[cellRowIndex] == "Top")
  {
    start = 0;
  }
  if (cellRows[cellRowIndex] == "Middle")
  {
    start = 3;
  }
  if (cellRows[cellRowIndex] == "Bottom")
  {
    start = 6;
  }

  int totalZeros = 0;
  int fillIndex;
  bool isDuplicate = false;
  cout << " Cells: ";
  for (int i = start; i < (start + 3); i += 1)
  {
    cout << *(lastCube[i]) << ", ";
    if (*(lastCube[i]) == 0)
    {
      totalZeros += 1;
      fillIndex = i;
    }
    if (*(lastCube[i]) == num)
    {
      isDuplicate = true;
    }
  }
  cout << " Total Zeros: " << totalZeros;
  if (totalZeros == 1 && !isDuplicate)
  {
    cout << " Fill Index: " << fillIndex;
    *(lastCube[fillIndex]) = num;
  }
  cout << "\n";
  if (totalZeros > 1 && !isDuplicate)
  {
    checkColumnIntersection(lastCube, start);
  }
}

void cubeCombo(int *cube1[9], int *cube2[9], int *lastCube[9], string direction, string cubeCombo)
{
  int cellValue;
  int cube1Index;
  int cube2Index;
  cout << cubeCombo
       << "\n";
  for (int i = 0; i < 9; i += 1)
  {
    if (*cube1[i] > 0)
    {
      cellValue = *cube1[i];
      cube1Index = i;
      for (int k = 0; k < 9; k += 1)
      {
        if (cellValue == *cube2[k])
        {
          cube2Index = k;
          if (direction == "Rows")
          {
            solveIfPossibleRows(lastCube, cellValue, cube1Index, cube2Index);
          }
          else if (direction == "Columns")
          {
            solveIfPossibleColumns(lastCube, cellValue, cube1Index, cube2Index);
          }
        }
      }
    }
  }
}

void checkIntersection()
{
}

void Technique::singleDirectionGrouping(int *cubePointers[9][9], string direction)
{
  // 0, 1, 2
  //==>  Cube combos => 0,1 => 0,2 => 1,2
  // 3, 4, 5
  //==>  Cube combos => 3,4 => 3,5 => 4,5
  // 6, 7, 8
  //==>  Cube combos => 6,7 => 6,8 => 7,8

  //Single Direction Row/Column
  int intersectingCubeCell = 100; //Magic number thats interpreted as 'false';
  if (direction == "Rows")
  {
    for (int i = 0; i < 9; i += 3)
    {
      cubeCombo(cubePointers[i], cubePointers[i + 1], cubePointers[i + 2], direction, "First and Second Cubes"); //Cube combinations
      // if(intersectingCubeCell < 9){
      //   checkIntersection();
      // }
      cubeCombo(cubePointers[i], cubePointers[i + 2], cubePointers[i + 1], direction, "First and Third Cubes");
      cubeCombo(cubePointers[i + 1], cubePointers[i + 2], cubePointers[i], direction, "Second and Third Cubes");
    }
  }
  if (direction == "Columns")
  {
    for (int i = 0; i < 3; i += 1)
    {
      cubeCombo(cubePointers[i], cubePointers[i + 3], cubePointers[i + 6], direction, "First and Second Cubes");
      // if(intersectingCubeCell < 9){
      //   checkIntersection();
      // }
      cubeCombo(cubePointers[i], cubePointers[i + 6], cubePointers[i + 3], direction, "First and Third Cubes");
      cubeCombo(cubePointers[i + 3], cubePointers[i + 6], cubePointers[i], direction, "Second and Third Cubes");
    }
  }
}
