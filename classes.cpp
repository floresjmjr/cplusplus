#include <iostream>
using namespace std;

//Person Example
class Person
{
  string firstName;
  string lastName;

public:
  Person();
  // Person(string first, string last);
  Person(string first, string second);
  void setFullName(string f, string l);
  void getFullName();
} jorge; //This automatically triggers the default constructor and initializes the firstName and lastName variables with "Unknown...

//Since jorge was created with the default constructor lets reasssign the data members (firstName and lastName)

//Defining the default constructor function (they don't need a type identifier)
Person::Person()
{
  firstName = "Unknown First Name";
  lastName = "Unknown Last Name";
}

// Defining another constructor function
Person::Person(string f, string l)
{
  firstName = f;
  lastName = l;
}

//Defining the setFullName function;
void Person::setFullName(string f, string l){
  firstName = f;
  lastName = l;
}


//Defining another constructor function using member inialization
// Person::Person(string f, string l) : firstName(f), lastName(l){}

//Defining the fullname function by bringing out the function from the class block using the scope operator
void Person::getFullName()
{
  cout << firstName << " " << lastName;
  cout << "\n";
};

//Employee class that uses the Person class as a type for its member
class Employee
{
  Person name;
  string jobTitle;
public:
  Employee(string first, string last);
  void employeeProfile();
  void setJobTitle(string t);
};

//Defining the constructor
Employee::Employee(string f, string l){
  Person(f, l);
} 

//Defining the employeeProfile function of the Employee class
void Employee::employeeProfile(){
  cout << "\n";
  cout << jobTitle;
  cout << "\n";
}

void Employee::setJobTitle(string title){
  jobTitle = title;
}


int main()
{
  Person rob;
  rob.getFullName();
  jorge.getFullName();
  jorge.setFullName("Jorge", "Flores");
  jorge.getFullName();

  Employee mike("Mike", "Tyson");
  mike.setJobTitle("Clerk");
  mike.employeeProfile();
  return 0;
}
