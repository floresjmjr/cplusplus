//Files
#include "sudokuSolver.cpp"
#include "validateClass.cpp"
// #include "validate.cpp"

//Libraries
#include <iostream>
using namespace std;


int main() {
  //Create sudoku solver app with input sudoku
  SudokuSolver solverTest;
  // cout << solverTest.sudokuState[4][4];
  SolutionValidator validCheck;
  cout << validCheck.checkRows() << "\n";
  cout << validCheck.checkColumns() << "\n";

  //Dealing with cubes



  if(validCheck.rows && validCheck.columns & validCheck.cubes){
    cout << "All correct";
  }

  cout << "\n";
  return 0;
}