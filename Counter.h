#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Counter
{
  public:
    Counter();
    Counter(string a, int linenumber);
    void Increase();
    void Linetrack(int linenumber);
    void Print();
    bool Same(string a);
  private:
    string word;
    int count;
    vector<int> linetracker;
};

#endif
