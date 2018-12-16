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
