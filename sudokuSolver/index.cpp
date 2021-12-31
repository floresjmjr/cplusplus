//Files
#include "sudokuSolver.cpp"
#include "validateClass.cpp"
#include "techniques.cpp"

//Libraries
#include <iostream>
using namespace std;

int main()
{
  //Create sudoku solver app with input sudoku
  SudokuSolver solver;
  bool inProgress = true;
  Technique solverTechniques;
  //while loop until variable (inProgres) evaluates to false
  //while(inProgress) {
  //
  solverTechniques.missingSingleNum(solver.sudokuState);






  // }

  //Validate the sudoku state of the of SudokuSolver instance
  SolutionValidator validCheck;
  cout << validCheck.checkRows(solver.sudokuState);
  cout << "\n===========================\n";
  cout << validCheck.checkColumns(solver.sudokuState);
  cout << "\n===========================\n";
  cout << validCheck.checkCubes(solver.cubePointers);
  cout << "\n===========================\n";

  if (validCheck.rows && validCheck.columns & validCheck.cubes)
  {
    cout << "All rows, columns and cubes include 1..9 only once!!";
  }

  //Display sudoku state
  cout << "\n";
  return 0;
}