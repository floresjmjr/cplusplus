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
  bool intersectionCheck = false;
  int totalCandidates = 0;
  int fillingNumber;
  int startingPoint;

private:
  int countZeros(int *arr[9]);
  int deduceMissingNumber(int *arr[9]);
  void solveIfPossibleColumns(int *lastCube[9], int idx, int idx2);
  void solveIfPossibleRows(int *lastCube[9], int idx, int idx2);
  void cubeCombo(int *cube1[9], int *cube2[9], int *lastCube[9], string direction, int *intersect1[9], int *intersect2[9]);
  void checkColumnIntersection(int *intersectingFirstCube[9], int *intersectingSecondCube[9], int *lastCube[9]);
  void checkRowIntersection(int *intersectingFirstCube[9], int *intersectingSecondCube[9], int *lastCube[9]);
public:
  void missingSingleNum(int *arr[9][9]);
  void singleDirectionGrouping(int *cubes[9][9], int *columns[9][9], int *rows[9][9], string direction);
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

// void checkRowIntersection()
// {
// }

void Technique::solveIfPossibleColumns(int *lastCube[9], int idx, int idx2)
{
  cout << "--"
       << "Num: " << fillingNumber << " Index1: " << idx << " Index2: " << idx2;
  string cellColumns[3] = {"Left", "Middle", "Right"};
  string occupiedRows[3] = {"", "", ""};
  int cellColumnIndex;
  intersectionCheck = false;

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
  if (cellColumns[cellColumnIndex] == "Left")
  {
    startingPoint = 0;
  }
  if (cellColumns[cellColumnIndex] == "Middle")
  {
    startingPoint = 1;
  }
  if (cellColumns[cellColumnIndex] == "Right")
  {
    startingPoint = 2;
  }

  totalCandidates = 0;
  int fillIndex;
  bool isDuplicate = false;
  cout << " Cells: ";
  for (int i = startingPoint; i < 9; i += 3)
  {
    cout << *(lastCube[i]) << ", ";
    if (*(lastCube[i]) == 0)
    {
      totalCandidates += 1;
      fillIndex = i;
    }
    if (*(lastCube[i]) == fillingNumber)
    {
      isDuplicate = true;
    }
  }
  cout << " Total Zeros: " << totalCandidates;
  if (totalCandidates == 1 && !isDuplicate)
  {
    cout << " ##Fill Index: " << fillIndex;
    *(lastCube[fillIndex]) = fillingNumber;
  }
  if (totalCandidates > 1 && !isDuplicate)
  {
    intersectionCheck = true;
  }
}

// check if last cube has one cell empty(lastCube, starting obj)
void Technique::solveIfPossibleRows(int *lastCube[9], int idx, int idx2)
{
  cout << "--"
       << "Num: " << fillingNumber << " Index1: " << idx << " Index2: " << idx2;
  string cellRows[3] = {"Top", "Middle", "Bottom"};
  string occupiedRows[3] = {"Empty", "Empty", "Empty"};
  int cellRowIndex;
  intersectionCheck = false;

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
  if (cellRows[cellRowIndex] == "Top")
  {
    startingPoint = 0;
  }
  if (cellRows[cellRowIndex] == "Middle")
  {
    startingPoint = 3;
  }
  if (cellRows[cellRowIndex] == "Bottom")
  {
    startingPoint = 6;
  }

  totalCandidates = 0;
  int fillIndex;
  bool isDuplicate = false;
  cout << " Cells: ";
  for (int i = startingPoint; i < (startingPoint + 3); i += 1)
  {
    cout << *(lastCube[i]) << ", ";
    if (*(lastCube[i]) == 0)
    {
      totalCandidates += 1;
      fillIndex = i;
    }
    if (*(lastCube[i]) == fillingNumber)
    {
      isDuplicate = true;
    }
  }
  cout << " Total Zeros: " << totalCandidates;
  if (totalCandidates == 1 && !isDuplicate)
  {
    cout << " ##Fill Index: " << fillIndex;
    *(lastCube[fillIndex]) = fillingNumber;
  }
  if (totalCandidates > 1 && !isDuplicate)
  {
    intersectionCheck = true;
  }
}

void Technique::checkRowIntersection(int *intersectingFirstCube[9], int *intersectingSecondCube[9], int *lastCube[9]){

}

void Technique::checkColumnIntersection(int *intersectingFirstCube[9], int *intersectingSecondCube[9], int *lastCube[9])
{
  cout << "  **Column Intersection ";
  for (int i = startingPoint; i < 3; i += 1)
  {
    if (*(lastCube[i]) == 0)
    {
      for (int k = i; k < 9; k += 3)
      {
        if (*(intersectingFirstCube[k]) == fillingNumber)
        {
          totalCandidates -= 1;
          cout << " First Intersecting Cube Index: " << k << " Value: " << *(intersectingFirstCube[k]);
        }
        if (*(intersectingSecondCube[k]) == fillingNumber)
        {
          totalCandidates -= 1;
          cout << " Second Intersecting Cube Index: " << k << " Value: " << *(intersectingFirstCube[k]);
        }
        if (totalCandidates == 1)
        {
          *(lastCube[i]) = fillingNumber;
          cout << " ##Fill " << fillingNumber;
          break;
        }
      }
    }
  }

}

void Technique::cubeCombo(int *cube1[9], int *cube2[9], int *lastCube[9], string direction, int *intersectingFirstCube[9], int *intersectingSecondCube[9])
{
  int cube1Index;
  int cube2Index;
  for (int i = 0; i < 9; i += 1)
  {
    if (*cube1[i] > 0)
    {
      fillingNumber = *(cube1[i]);
      cube1Index = i;
      for (int k = 0; k < 9; k += 1)
      {
        if (fillingNumber == *(cube2[k]))
        {
          cube2Index = k;
          if (direction == "Rows")
          {
            solveIfPossibleRows(lastCube, cube1Index, cube2Index);
            if (intersectionCheck)
            {
              checkColumnIntersection(intersectingFirstCube, intersectingSecondCube, lastCube);
            }
          }
          else if (direction == "Columns")
          {
            solveIfPossibleColumns(lastCube, cube1Index, cube2Index);
            if (intersectionCheck)
            {
              checkRowIntersection(intersectingFirstCube, intersectingSecondCube, lastCube);
            }
          }
          cout << "\n";
        }
      }
    }
  }
}

void Technique::singleDirectionGrouping(int *cubePointers[9][9], int *columnPointers[9][9], int *rowPointers[9][9], string direction)
{
  //*Rows
  // 0, 1, 2
  //==>  Cube combos => 0,1,2 => 0,2,1 => 1,2,0
  // 3, 4, 5
  //==>  Cube combos => 3,4,5 => 3,5,4 => 4,5,3
  // 6, 7, 8
  //==>  Cube combos => 6,7,8 => 6,8,7 => 7,8,6
  //if(int i = 0; i < 9; i += 3){}    //Refactor
  if (direction == "Rows")
  {
    cout << "First and Second Cubes - 0, 1, 2"
         << "\n";
    cubeCombo(cubePointers[0], cubePointers[0 + 1], cubePointers[0 + 2], direction, cubePointers[5], cubePointers[8]);
    cout << "First and Third Cubes"
         << "\n";
    cubeCombo(cubePointers[0], cubePointers[0 + 2], cubePointers[0 + 1], direction, cubePointers[4], cubePointers[7]);
    cout << "Second and Third Cubes"
         << "\n";
    cubeCombo(cubePointers[0 + 1], cubePointers[0 + 2], cubePointers[0], direction, cubePointers[3], cubePointers[6]);

    cout << "First and Second Cubes - 3,4,5"
         << "\n";
    cubeCombo(cubePointers[3], cubePointers[3 + 1], cubePointers[3 + 2], direction, cubePointers[2], cubePointers[8]);
    cout << "First and Third Cubes"
         << "\n";
    cubeCombo(cubePointers[3], cubePointers[3 + 2], cubePointers[3 + 1], direction, cubePointers[1], cubePointers[7]);
    cout << "Second and Third Cubes"
         << "\n";
    cubeCombo(cubePointers[3 + 1], cubePointers[3 + 2], cubePointers[3], direction, cubePointers[0], cubePointers[6]);

    cout << "First and Second Cubes - 6,7,8"
         << "\n";
    cubeCombo(cubePointers[6], cubePointers[6 + 1], cubePointers[6 + 2], direction, cubePointers[2], cubePointers[5]);
    cout << "First and Third Cubes"
         << "\n";
    cubeCombo(cubePointers[6], cubePointers[6 + 2], cubePointers[6 + 1], direction, cubePointers[1], cubePointers[4]);
    cout << "Second and Third Cubes"
         << "\n";
    cubeCombo(cubePointers[6 + 1], cubePointers[6 + 2], cubePointers[6], direction, cubePointers[0], cubePointers[3]);
  }
  //*Columns
  // 0, 3, 6
  //==>  Cube combos => 0,3,6 => 0,6,3 => 3,6,0
  // 1, 4, 7
  //==>  Cube combos => 1,4,7 => 1,7,4 => 4,7,1
  // 2, 5, 8
  //==>  Cube combos => 2,5,8 => 2,8,5 => 5,8,2

  // if (direction == "Columns")
  // {
  //   for (int i = 0; i < 3; i += 1)
  //   {
  //     cout << "First and Second Cubes"
  //          << "\n";
  //     cubeCombo(cubePointers[i], cubePointers[i + 3], cubePointers[i + 6], direction);
  //     // if(intersectingCubeCell < 9){
  //     //   checkIntersection();
  //     // }
  //     cout << "First and Third Cubes"
  //          << "\n";
  //     cubeCombo(cubePointers[i], cubePointers[i + 6], cubePointers[i + 3], direction);
  //     cout << "Second and Third Cubes"
  //          << "\n";
  //     cubeCombo(cubePointers[i + 3], cubePointers[i + 6], cubePointers[i], direction);
  //   }
  // }
}
