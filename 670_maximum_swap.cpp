#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int maximumSwap(int num) {
  vector<int> digits;
  int currNum = num, result = 0; 
  int currLoc = 0, maxLoc = 0, maxDig = 0;
  multimap <int, int, greater<int>> digLocs;
	    
  while (currNum > 0) {
    int digit = currNum % 10;
    currNum = currNum / 10;
    digits.push_back(digit);
    if (digit > digits[maxLoc]) {
      maxLoc = currLoc;
    }
    currLoc++;
  }

  for (int msd = digits.size()-1; msd > 0; msd--) {
    if (digits[maxLoc] > digits[msd]) {
      int tmp = digits[maxLoc];
      digits[maxLoc] = digits[msd];
      digits[msd] = tmp;
      break;
    }
    maxLoc = msd-1;
    for (int i = msd-1; i >= 0; i--) {
      if (digits[i] >= digits[maxLoc]) {
	maxLoc = i;
      }
    }
  }
  
  for (int i = digits.size()-1; i >= 0; i--) {
    result = digits[i] + result * 10;
  }
  return (result);
}

int main (int argc, char **argv) {

  //int x = 98088;
  //int x = 98368;
  int x = 1993;

  cout << maximumSwap(x) << "\n";
}
