#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string addStrings(string num1, string num2) {

  int i = num1.length(), digit1 = 0;
  int j = num2.length(), digit2 = 0;
  string res;
  int carry = 0;
  
  while (1) {

    if (i) {
      i--;
      digit1 = num1[i] - '0';
    } else {
      digit1 = 0;
    }

    if (j) {
      j--;
      digit2 = num2[j] - '0';
    } else {
      digit2 = 0;
    }
    
    int resDigit = (digit1 + digit2 + carry) % 10;
    carry = (digit1 + digit2 + carry) / 10;
    res += resDigit + '0';
    if (!i && !j) break;
  }

  if (carry) {
    res += carry + '0';
  }
    
  reverse (res.begin(), res.end());
  cout << res << "\n";
  return (res);
}

int main (int argc, char **argv) {
  string num1 = "9";
  string num2 = "1";
  cout << addStrings(num1, num2) << "\n";
}
