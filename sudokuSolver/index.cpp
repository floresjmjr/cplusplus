//Files
#include "index.h"
#include "sudokuSolver.cpp"
#include "validateClass.cpp"
#include "techniques.cpp"

int main()
{
  //Create sudoku solver app
  SudokuSolver solver1;

  Technique solverTechniques;
  for (int i = 0; i < 4; i +=1)
  {
    solverTechniques.singleDirectionGrouping(solver1.cubePointers, solver1.columnPointers, solver1.rowPointers, "Rows"); //Remove column and rowPointers when done

    solverTechniques.missingSingleNum(solver1.cubePointers);
    solverTechniques.missingSingleNum(solver1.rowPointers);
    solverTechniques.missingSingleNum(solver1.columnPointers);

    solverTechniques.singleDirectionGrouping(solver1.cubePointers, solver1.columnPointers, solver1.rowPointers, "Columns");
    
    solverTechniques.missingSingleNum(solver1.cubePointers);
    solverTechniques.missingSingleNum(solver1.rowPointers);
    solverTechniques.missingSingleNum(solver1.columnPointers);

    cout << "======= Loop " << i << " ========"
         << "\n";
  }

  //Validate the sudoku state of the of SudokuSolver instance
  SolutionValidator validCheck;
  validCheck.validate(solver1.rowPointers, "Rows");
  validCheck.validate(solver1.columnPointers, "Columns");
  validCheck.validate(solver1.cubePointers, "Cubes");

  solver1.displayState();

  cout << "\n";
  return 0;
}