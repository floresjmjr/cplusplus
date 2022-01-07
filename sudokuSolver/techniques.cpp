#include "index.h"
#include "techniques.h"
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
  if (totalCandidates == 2 && !isDuplicate) //Need to update for instances where there are 3 zeros
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
  if (totalCandidates == 2 && !isDuplicate) //Need to update for instances where there are 3 zeros
  {
    intersectionCheck = true;
  }
}

void Technique::checkRowIntersection(int *intersectingFirstCube[9], int *intersectingSecondCube[9], int *lastCube[9])
{
  cout << "  **Row Intersection ";
  for (int i = startingPoint; i < 9; i += 3)
  {
    cout << *(lastCube[i]) << ", ";
  }
  cout << "\n";
  int previousIndex = -1;
  for (int i = startingPoint; i < 9; i += 3)
  {
    if (*(lastCube[i]) == 0)
    {
      if (totalCandidates == 1)
      {
        *(lastCube[i]) = fillingNumber;
        cout << " ##Fill " << fillingNumber;
      }
      int rowStart;
      if (i == 0 || i == 1 || i == 2)
      {
        rowStart = 0;
      }
      else if (i == 3 || i == 4 || i == 5)
      {
        rowStart = 3;
      }
      else if (i == 6 || i == 7 || i == 8)
      {
        rowStart = 6;
      }
      for (int k = rowStart; k < (rowStart + 3); k += 1)
      {
        if (*(intersectingFirstCube[k]) == fillingNumber)
        {
          totalCandidates -= 1;
          cout << " First Intersecting Cube Index: " << k;
          if (previousIndex > -1)
          {
            *(lastCube[previousIndex]) = fillingNumber;
            cout << " ##Fill " << fillingNumber;
          }
          break;
        }
        if (*(intersectingSecondCube[k]) == fillingNumber)
        {
          totalCandidates -= 1;
          cout << " Second Intersecting Cube Index: " << k;
          if (previousIndex > -1)
          {
            *(lastCube[previousIndex]) = fillingNumber;
            cout << " ##Fill " << fillingNumber;
          }
          break;
        }
      }
      previousIndex = i;
      cout << " PrevIdx: " << previousIndex;
    }
  }
}

void Technique::checkColumnIntersection(int *intersectingFirstCube[9], int *intersectingSecondCube[9], int *lastCube[9])
{
  cout << "  **Column Intersection " << startingPoint;
  for (int j = startingPoint; j < (startingPoint + 3); j += 1)
  {
    cout << *(lastCube[j]) << ", ";
  }
  int previousIndex = -1;
  for (int i = startingPoint; i < (startingPoint + 3); i += 1)
  {
    // cout << "This is i: " << i;
    if (*(lastCube[i]) == 0)
    {
      // cout << "Previous Index Declaration: " << previousIndex;
      if (totalCandidates == 1)
      {
        *(lastCube[i]) = fillingNumber;
        cout << " ##Fill " << fillingNumber;
      }
      int columnStart;
      if (i == 0 || i == 3 || i == 6)
      {
        columnStart = 0;
      }
      else if (i == 1 || i == 4 || i == 7)
      {
        columnStart = 1;
      }
      else if (i == 2 || i == 5 || i == 8)
      {
        columnStart = 2;
      }
      cout << "ColumnStart:" << columnStart;
      for (int k = columnStart; k < 9; k += 3)
      {
        if (*(intersectingFirstCube[k]) == fillingNumber)
        {
          totalCandidates -= 1;
          cout << " First Intersecting Cube Index: " << k;
          if (previousIndex > -1)   //Sometimes the index will be zero, which evaluates to false;
          {
            *(lastCube[previousIndex]) = fillingNumber;
            cout << " ##Fill " << fillingNumber;
          }
          break;
        }
        if (*(intersectingSecondCube[k]) == fillingNumber)
        {
          totalCandidates -= 1;
          cout << " Second Intersecting Cube Index: " << k;
          if (previousIndex > -1)
          {
            *(lastCube[previousIndex]) = fillingNumber;
            cout << " ##Fill " << fillingNumber;
          }
          break;
        }
      }
      previousIndex = i;
      cout << " PrevIdx: " << previousIndex;
    }
  }
}

void Technique::cubeCombo(int *cube1[9], int *cube2[9], int *lastCube[9], string direction, int *intersectingFirstCube[9], int *intersectingSecondCube[9])
{
  int cube1Index;
  int cube2Index;
  for (int i = 0; i < 9; i += 1)
  {
    // cout << "CubeCombo i/val: " << i << " " << *(cube1[i]) << "\n";
    if (*(cube1[i]) > 0)
    {
      fillingNumber = *(cube1[i]);
      cube1Index = i;
      for (int k = 0; k < 9; k += 1)
      {
        // cout << "CubeCombo k/val: " << k << " " << *(cube2[k]) << "\n";
        if (fillingNumber == *(cube2[k]))
        {
          cube2Index = k;
          if (direction == "Rows")
          {
            cout << "Before"
                 << "\n";
            solveIfPossibleRows(lastCube, cube1Index, cube2Index);
            if (intersectionCheck)
            {
              checkColumnIntersection(intersectingFirstCube, intersectingSecondCube, lastCube);
            }
          }
          else if (direction == "Columns")
          {
            cout << "Before"
                 << "\n";
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
  if (direction == "Rows")
  {
    //if(int i = 0; i < 9; i += 3){}    //Refactor
    cout << "First and Second Cubes - 0, 1, 2"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[0], cubePointers[0 + 1], cubePointers[0 + 2], direction, cubePointers[5], cubePointers[8]);

    cout << "First and Third Cubes - 0, 1, 2"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[0], cubePointers[0 + 2], cubePointers[0 + 1], direction, cubePointers[4], cubePointers[7]);

    cout << "Second and Third Cubes - 0, 1, 2"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[0 + 1], cubePointers[0 + 2], cubePointers[0], direction, cubePointers[3], cubePointers[6]);

    cout << "First and Second Cubes - 3,4,5"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[3], cubePointers[3 + 1], cubePointers[3 + 2], direction, cubePointers[2], cubePointers[8]);

    cout << "First and Third Cubes - 3,4,5"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[3], cubePointers[3 + 2], cubePointers[3 + 1], direction, cubePointers[1], cubePointers[7]);

    cout << "Second and Third Cubes - 3,4,5"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[3 + 1], cubePointers[3 + 2], cubePointers[3], direction, cubePointers[0], cubePointers[6]);

    cout << "First and Second Cubes - 6,7,8"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[6], cubePointers[6 + 1], cubePointers[6 + 2], direction, cubePointers[2], cubePointers[5]);

    cout << "First and Third Cubes - 6,7,8"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[6], cubePointers[6 + 2], cubePointers[6 + 1], direction, cubePointers[1], cubePointers[4]);

    cout << "Second and Third Cubes - 6,7,8"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[6 + 1], cubePointers[6 + 2], cubePointers[6], direction, cubePointers[0], cubePointers[3]);
  }

  //*Columns
  // 0, 3, 6
  //==>  Cube combos => 0,3,6 => 0,6,3 => 3,6,0
  // 1, 4, 7
  //==>  Cube combos => 1,4,7 => 1,7,4 => 4,7,1
  // 2, 5, 8
  //==>  Cube combos => 2,5,8 => 2,8,5 => 5,8,2

  if (direction == "Columns")
  {
    //   for (int i = 0; i < 3; i += 1){}   //Refactor
    cout << "First and Second Cubes - 0,3,6"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[0], cubePointers[0 + 3], cubePointers[0 + 6], direction, cubePointers[7], cubePointers[8]);

    cout << "First and Third Cubes - 0,3,6"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[0], cubePointers[0 + 6], cubePointers[0 + 3], direction, cubePointers[4], cubePointers[5]);

    cout << "Second and Third Cubes - 0,3,6"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[0 + 3], cubePointers[0 + 6], cubePointers[0], direction, cubePointers[1], cubePointers[2]);

    cout << "First and Second Cubes - 1,4,7"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[1], cubePointers[1 + 3], cubePointers[1 + 6], direction, cubePointers[6], cubePointers[8]);

    cout << "First and Third Cubes - 1,4,7"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[1], cubePointers[1 + 6], cubePointers[1 + 3], direction, cubePointers[3], cubePointers[5]);

    cout << "Second and Third Cubes - 1,4,7"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[1 + 3], cubePointers[1 + 6], cubePointers[1], direction, cubePointers[0], cubePointers[2]);

    cout << "First and Second Cubes - 2,5,8"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[2], cubePointers[2 + 3], cubePointers[2 + 6], direction, cubePointers[6], cubePointers[7]);

    cout << "First and Third Cubes - 2,5,8"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[2], cubePointers[2 + 6], cubePointers[2 + 3], direction, cubePointers[3], cubePointers[4]);

    cout << "Second and Third Cubes - 2,5,8"
         << "\n";
    displayState(rowPointers);
    cubeCombo(cubePointers[2 + 3], cubePointers[2 + 6], cubePointers[2], direction, cubePointers[0], cubePointers[1]);
  }
}
