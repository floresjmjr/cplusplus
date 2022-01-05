#include <iostream>
#include <algorithm>
using namespace std;

class SolutionValidator
{
public:
  bool columns = false;
  bool rows = false;
  bool cubes = false;

public:
  string validate(int *nestedArr[9][9], string name);
};

string SolutionValidator::validate(int *arr[9][9], string name)
{
  for (int i = 0; i < 9; i += 1)
  {
    int container[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int k = 0; k < 9; k += 1)
    {
      int value = *(arr[i][k]);
      cout << value << ", ";
      if (value == 0)
      {
        cout << "Not Complete" << "\n";
        return "Not Complete";
      }
      container[k] = *(arr[i][k]);
      int totalCount = count(begin(container), end(container), value);
      if (totalCount > 1)
      {
        cout << "Mistake made" << "\n"; 
        return "Mistake made";
      }
    }
    cout << "\n";
  }
  cout << "===========================" << "\n";
  cout << name << " contains 1..9 only once" << "\n";
  return name;
}