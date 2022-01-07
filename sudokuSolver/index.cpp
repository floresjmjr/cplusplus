//Files
#include "index.h"
#include "sudokuSolver.cpp"
#include "validateClass.cpp"
#include "techniques.cpp"

int main()
{
  //Create sudoku solver app with input sudoku
  SudokuSolver solver1;
  bool inProgress = true;
  Technique solverTechniques;
  for (int i = 0; i < 5; i +=1)
  {
    //Cube Rows
    solverTechniques.singleDirectionGrouping(solver1.cubePointers, solver1.columnPointers, solver1.rowPointers, "Rows"); //Remove column and rowPointers when done
    //Cube Columns
    solverTechniques.singleDirectionGrouping(solver1.cubePointers, solver1.columnPointers, solver1.rowPointers, "Columns");

    solverTechniques.missingSingleNum(solver1.cubePointers);
    solverTechniques.missingSingleNum(solver1.rowPointers);
    solverTechniques.missingSingleNum(solver1.columnPointers);

    cout << "======= Loop " << i << " ========"
         << "\n";
  }

  solver1.displayState();

  //Start while loop, until variable (inProgres) evaluates to false
  //while(inProgress) {
  // if(intersection and missing single num no longer makes changes){
  //   inProgress = false;
  // }
  //} End while loop

  //Validate the sudoku state of the of SudokuSolver instance
  SolutionValidator validCheck;
  validCheck.validate(solver1.rowPointers, "Rows");
  validCheck.validate(solver1.columnPointers, "Columns");
  validCheck.validate(solver1.cubePointers, "Cubes");

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