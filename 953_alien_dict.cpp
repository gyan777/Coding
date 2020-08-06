#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isAlienSorted(vector<string>& words, string order);
  
int main (int argc, char **argv) {
  vector<string> words = {"aa", "a"};
  if (isAlienSorted(words, "abqwertyuioplkjhgfdszxcvnm")) {
    cout << "Sorted\n";
  } else {
    cout << "Not Sorted\n";    
  }
}

bool isAlienSorted(vector<string>& words, string order) {

  unordered_map<char, int> alphabet;
  alphabet['\0'] = 0;
  for (int i = 0; i < order.length(); i++) {
    alphabet[order[i]] = i+1;
  }

  for (int i = 0; i < words.size()-1; i++) {
    //compare pairs of words
    int j = 0;
    while (alphabet[words[i][j]] == alphabet[words[i+1][j]]) {//Loop terminates when the lenght of the shoter string is hit or one of the characters mismatch, at end og string lenght null chracter '\0' is returned
      j++;
    }
    if (alphabet[words[i][j]] > alphabet[words[i+1][j]]) {
      return(false);
    }
  }
  return (true);
}
