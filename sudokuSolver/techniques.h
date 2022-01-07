void displayState(int * sudokuState[9][9]){
  cout << "++=================================++"
       << "\n";
  for (int i = 0; i < 9; i += 1)
  {
    cout << "||";
    for (int k = 0; k < 9; k += 1)
    {
      cout << " " << *(sudokuState[i][k]) << " ";
      if (((k - 2) % 3) == 0)
      {
        cout << "|| ";
      }
    }
    cout << "\n";
    if (((i - 2) % 3) == 0)
    {
      if (i < 8)  //To avoid a third line
      { 
        cout << "||=================================||"
             << "\n";
      }
    }
  }
  cout << "++=================================++"
       << "\n";
}