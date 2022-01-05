#include <iostream>
using namespace std;

class Person
{
private:
  string firstName;
  string lastName;

public:
  Person()
  {
    firstName = "Unknown First";
    lastName = "Unknown Last";
  }
  Person(string f, string l)
  {
    firstName = f;
    lastName = l;
  }
  void printFullName()
  {
    cout << firstName << " " << lastName;
    cout << "\n";
  }
};

class Employee : public Person
{
protected:
  string jobTitle;

public:
  Employee(string f, string l, string jt) : Person(f, l){
    jobTitle = jt;
  } 
  void printProfile(){
    printFullName();
    cout << jobTitle << "\n";
  }
};

int main()
{

  Person jorge("Jorge", "Flores");
  jorge.printFullName();
  Employee rob("Robert", "Johnson", "Clerk");
  rob.printProfile();
  return 0;
}