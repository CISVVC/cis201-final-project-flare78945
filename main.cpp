#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Counter.h"

using namespace std;

int main() 
{
  const string type = ".txt";
  string filename;
  ifstream in_file;
  cout << "What is the file name? ";
  cin >> filename;
  filename = filename + type;
  in_file.open(filename.c_str());
  if (!in_file)
  {
    cout << "Error in opening file.";
    return 0;
  }
  else
  {
    Counter* W1 = NULL;
    vector<Counter> words;
    int linenumber = 1;
    string word;
    char ch;
    while (in_file)
    {
      if (in_file.peek() <= 'Z' && in_file.peek() >= 'A')
      {
        ch = in_file.get();
        tolower(ch);
        word += ch;
      }
      if (in_file.peek() <= 'z' && in_file.peek() >= 'a')
      {
        ch = in_file.get();
        word += ch;
      }
      else
      {
        ch = in_file.get();
      }

      W1 = new Counter(word, linenumber);
    }
  }
  in_file.close();
  return 0;
}
