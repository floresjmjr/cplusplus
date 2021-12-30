#include <string>
#include <iostream>
#include "inputSudoku.cpp"
#include "cubeClass.cpp"
#include "solved.cpp"
using namespace std;

//SudokuSolver class
class SudokuSolver
{
public:
  int sudokuState[9][9];
  int *cubePointers[9][9]; //Array that holds arrays which have pointers as values that point to the addresses of the sudokuState
public:
  SudokuSolver();
  // void displayPuzzle();
  void formatCubes();
  void buildCube(int sL, int eL, int sC, int eC, int cube);
};

//Solver constructor (would like to pass in a nested array intead of global array)
SudokuSolver::SudokuSolver()
{
  for (int i = 0; i < 9; i += 1)
  {
    for (int k = 0; k < 9; k += 1)
    {
      sudokuState[i][k] = solvedPuzzle[i][k];
    }
  }
  formatCubes();
}

void SudokuSolver::buildCube(int rowStart, int rowEnd, int cellStart, int cellEnd, int cube)
{
  int indexCounter = 0;
  for (int row = rowStart; row <= rowEnd; row += 1)
  {
    for (int cell = cellStart; cell <= cellEnd; cell += 1)
    {
      cubePointers[cube][indexCounter] = &(sudokuState[row][cell]);
      // cout << sudokuState[row][cell];                                   //Useless
      indexCounter += 1;
    }
  }
}

//Method createCubes definition
void SudokuSolver::formatCubes()
{
  buildCube(0, 2, 0, 2, 0); // first cube
  buildCube(0, 2, 3, 5, 1); // second cube
  buildCube(0, 2, 6, 8, 2); // third cube
  buildCube(3, 5, 0, 2, 3); // fourth cube
  buildCube(3, 5, 3, 5, 4); // fifth cube
  buildCube(3, 5, 6, 8, 5); // sixth cube
  buildCube(6, 8, 0, 2, 6); // seventh cube
  buildCube(6, 8, 3, 5, 7); // eighth cube
  buildCube(6, 8, 6, 8, 8); // ninth cube
}
