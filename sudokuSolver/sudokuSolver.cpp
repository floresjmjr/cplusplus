#include <string>
#include <iostream>
#include "inputSudoku.cpp"
#include "cubeClass.cpp"
using namespace std;

//SudokuSolver class
class SudokuSolver
{
public:
  int sudokuState[9][9];
  // Cube cubes[9];
public:
  SudokuSolver();
  // void displayPuzzle();
  // void createCubes();
};

//Solver constructor (would like to pass in a nested array intead of global array)
SudokuSolver::SudokuSolver()
{
  for (int i = 0; i < 9; i += 1)
  {
    for (int k = 0; k < 9; k += 1)
    {
      sudokuState[i][k] = sudokuPuzzle[i][k];
    }
  }
}

// void logLine(int arg[])
// {
//   for (int z = 0; z < 9; z += 1)
//   {
//     cout << arg[z];
//   }
// }

// void createCube(int arrStart, int arrEnd, int elStart, int elEnd, Cube cube)
// {
//   int container[9];
//   int indexCounter = 0;
//   for (int line = arrStart; line <= arrEnd; line += 1)
//   {
//     for (int el = elStart; el <= elEnd; el += 1)
//     {
//       int value = sudokuPuzzle[line][el];

//       container[indexCounter] = value;

//       indexCounter += 1;
//     }
//   }
//   logLine(container);
//   // cube(container);
// }

// //Method createCubes definition
// void SudokuSolver::createCubes()
// {
//   int * container[9];
//   createCube(0, 2, 0, 2, cubes[0]); // first cube
//   cout << "\n";
//   cout << (*container[0]);
//   // createCube(0, 2, 3, 5); // second cube
//   // cout << "\n";
//   // createCube(0, 2, 6, 8); // third cube
//   // cout << "\n";
//   // createCube(3, 5, 0, 2); // fourth cube
//   // cout << "\n";
//   // createCube(3, 5, 3, 5); // fifth cube
//   // cout << "\n";
//   // createCube(3, 5, 6, 8); // sixth cube
//   // cout << "\n";
//   // createCube(6, 8, 0, 2); // seventh cube
//   // cout << "\n";
//   // createCube(6, 8, 3, 5); // eighth cube
//   // cout << "\n";
//   // createCube(6, 8, 6, 8); // ninth cube
//   // // return array of cubes
// }


// int main() {
//   SudokuSolver test;
//   Cube pCube = test.cubes[0];
//   cout << pCube.top[0];
//   // test.createCubes();
//   return 0;
// }

