#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

bool isPalindrome(string s) {

  if (s == "") return true;
  int i = 0, j = s.length()-1;

  while (i < j) {
    if (!isalnum(s[i])) {
      i++;
      continue;
    }
    
    if (!isalnum(s[j])) {
      j--;
      continue;
    }

    if (('A' <= s[i]) && (s[i] <= 'Z')) {
       s[i] += 'a' - 'A';
    }

    if (('A' <= s[j]) && (s[j] <= 'Z')) {
       s[j] += 'a' - 'A';
    }
   
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return (true);
}

int main (int argc, char **argv) {

  //string s = "A man, a plan, a canal: Panama";
  string s = "Bab";  

  if (isPalindrome(s)) {
    cout << "true\n";
  } else {
    cout << "false\n";    
  }

}
