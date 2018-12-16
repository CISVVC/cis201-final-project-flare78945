#include "Counter.h"

Counter::Counter()
{
  word = "";
  count = 0;
  linetracker.push_back(0);
}

Counter::Counter(string a, int linenumber)
{
  word = a;
  count = 1;
  linetracker.push_back(linenumber);
}
void Counter::Increase()
{
  count += count;
}

void Counter::Linetrack(int linenumber)
{
  linetracker.push_back(linenumber);
}

void Counter::Print()
{
  cout << word << " : " << count << " : ";
  for (int i = 0; i < linetracker.size(); i++)
  {
    if (i < (linetracker.size() - 1))
    {
      cout << linetracker[i] << ", ";
    }
    else
    {
      cout << linetracker[i];
    }
  }
}

bool Counter::Same(string a)
{
  if (word == a) {return true;}
  return false;
}
