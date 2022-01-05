#include <iostream>
using namespace std;

//Variable declaration with strcuture declaration
// struct Person {
//   int weight, height;
// } tim;

//A structure declaration
// struct Person {
//   int weight, height;
// };

//Define FavMovie structure
struct FavMovie
{
  string title, genre;
  int year;
};

//Declare jorge variable object
FavMovie jorge;

//Can also have struct type arrays, where each element is an object variable that has members fo the FavMovie structure
FavMovie collection[4];


//Function declaration (parameter doesn't need to match with definition)
void movieDetails(FavMovie something);

//Pointers and structures
FavMovie * jorgePointer = &jorge;

// Main funk!
int main()
{
  //Assign values to member variables;
  jorge.title = "Tofu Man";
  jorge.year = 2050;
  jorge.genre = "Comedy";

  cout << "Jorge's fav movie is " << jorge.title << "!";
  cout << "\n";

  //Invoke function 
  movieDetails(jorge);

  //Pointers in action!
  cout << "Pointers in action!";
  cout << "\n";
  cout << ((*jorgePointer).title == jorge.title);
  cout << "\n";

  return 0;
}

//Function definitions
void movieDetails(FavMovie obj)
{
  cout << obj.title << "\n";
  cout << obj.year << "\n";
  cout << obj.genre << "\n";
}
