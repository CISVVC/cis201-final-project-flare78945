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

  Counter* W1 = NULL;
  vector<Counter> words;
  int linenumber = 1;
  string word;
  char ch;
  bool newword = false;
  bool newline = false;
  
  while (in_file)
  {
    while (in_file.peek() <= 'Z' && in_file.peek() >= 'A')
    {
      ch = in_file.get();
      tolower(ch);
      word += ch;
    }
    while (in_file.peek() <= 'z' && in_file.peek() >= 'a')
    {
      ch = in_file.get();
      word += ch;
    }
    while (in_file.peek() == '\n')
    {
      ch = in_file.get();
      newline = true;
    }
    if ((in_file.peek() < 'A' && in_file.peek() > 'Z') || (in_file.peek() < 'a' && in_file.peek() > 'z') && in_file.peek() != '\n')
    {
      ch = in_file.get();
    }

    for (int i = 0; i < words.size(); i++)
    {
      if (words[i].Same(word))
      {
        words[i].Increase();
        words[i].Linetrack(linenumber);
      }
      else newword = true;
    }
    if (newword)
    {
      W1 = new Counter(word, linenumber);
      words.push_back(*W1);
      newword = false;
    }
    if (newline) {linenumber++;}
  }
  delete[] W1;
  in_file.close();
  for (int i = 0; i < words.size(); i++)
  {
    words[i].Print();
  }
  return 0;
}
