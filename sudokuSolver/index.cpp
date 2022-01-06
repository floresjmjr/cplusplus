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
  SudokuSolver solver1;
  bool inProgress = true;
  Technique solverTechniques;
  //Cube Rows
  solverTechniques.singleDirectionGrouping(solver1.cubePointers, solver1.columnPointers, solver1.rowPointers, "Rows");
  //Cube Columns
  solverTechniques.singleDirectionGrouping(solver1.cubePointers, solver1.columnPointers, solver1.rowPointers, "Columns");

  solver1.displayState();

  //Start while loop, until variable (inProgres) evaluates to false
  //while(inProgress) {
  //
  //intersection()

  // if(intesection no longer "makes changes"){
    // cout << "Rows missing single numbers" << "\n";
    // solverTechniques.missingSingleNum(puzzleSolver1.rowPointers);

  //   cout << "Columns missing single numbers" << "\n";
  //   solverTechniques.missingSingleNum(puzzleSolver1.columnPointers);

  //   cout << "Cube missing single numbers" << "\n";
  //   solverTechniques.missingSingleNum(puzzleSolver1.cubePointers);
  // }

  // if(intersection and missing single num no longer makes changes){
  //   inProgress = false;
  // }
  //} End while loop

  //Validate the sudoku state of the of SudokuSolver instance
  SolutionValidator validCheck;
  // validCheck.validate(puzzleSolver1.rowPointers, "Rows");
  // validCheck.validate(puzzleSolver1.columnPointers, "Columns");
  // validCheck.validate(puzzleSolver1.cubePointers, "Cubes");


  // if (validCheck.rows && validCheck.columns && validCheck.cubes)
  // {
  //   cout << "All rows, columns and cubes include 1..9 only once!!";
  // }

  //Display sudoku state
  // cout << "\n";
  // puzzleSolver1.displayState();
  cout << "\n";
  return 0;
}