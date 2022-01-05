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
  SudokuSolver puzzleSolver1;
  bool inProgress = true;
  Technique solverTechniques;
  puzzleSolver1.displayState();
  //Cube Rows
  solverTechniques.singleDirectionGrouping(puzzleSolver1.cubePointers[0], puzzleSolver1.cubePointers[1], puzzleSolver1.cubePointers[2], "Rows");
  solverTechniques.singleDirectionGrouping(puzzleSolver1.cubePointers[3], puzzleSolver1.cubePointers[4], puzzleSolver1.cubePointers[5], "Rows");
  solverTechniques.singleDirectionGrouping(puzzleSolver1.cubePointers[6], puzzleSolver1.cubePointers[7], puzzleSolver1.cubePointers[8], "Rows");
  //Cube Columns
  // solverTechniques.singleDirectionGrouping(puzzleSolver1.cubePointers[0], puzzleSolver1.cubePointers[3], puzzleSolver1.cubePointers[6], "Columns");
  // solverTechniques.singleDirectionGrouping(puzzleSolver1.cubePointers[1], puzzleSolver1.cubePointers[4], puzzleSolver1.cubePointers[7], "Columns");
  // solverTechniques.singleDirectionGrouping(puzzleSolver1.cubePointers[2], puzzleSolver1.cubePointers[5], puzzleSolver1.cubePointers[8], "Columns");



  puzzleSolver1.displayState();

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