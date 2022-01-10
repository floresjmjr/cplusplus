#include <fstream>
#include <iostream>
using namespace std;

ifstream infile("problem.txt");

int main()
{
  // string line;
  // while(getline(infile, line)){
  //   cout << line << '\n';
  // }

  int extractedPuzzle[9][9];
  int number;
  int counter = 0;
  int nestedCounter = 0;
  while (infile >> number)
  { //While loop necessary as the >> operator reads a string only until it encounters white space character
    extractedPuzzle[counter][nestedCounter] = number;
    if (nestedCounter == 9)
    {
      counter += 1;
      nestedCounter = 0;
      cout << "\n";
    }
    nestedCounter += 1;
    cout << number << ", ";
  }
  cout << "\n";

  // string arr[9];
  // string line;

  // while(getline(infile, line)){
  //   arr[counter] = line;
  //   cout << line << "\n";
  // }
}