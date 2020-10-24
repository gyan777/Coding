#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


// The trick here is to diff eevery node with 
using namespace std;

string rotateString (string A) {
  string str = A;
  for (int i = 0; i < A.length(); i++) {
    str[i] = (A[i] == 'z') ? 'a' : (A[i] + 1);
  }
  return str;
}
    
vector<vector<string>> groupStrings(vector<string>& strings) {
  unordered_multimap<string, int> inputStrings;
  vector<vector<string>> result;
  for (int i=0; i < strings.size(); i++) {
    inputStrings[strings[i]] = 0;
  }
        
  for (auto elem: inputStrings) {
    vector<string> newList;
    if (elem.second > 0) continue;
    newList.push_back(elem.first);
    string rotatedString = rotateString(elem.first);
    while (rotatedString != elem.first) {
      if (inputStrings.count(rotatedString)) {
	inputStrings[rotatedString]++;
	newList.push_back(rotatedString);
      }
      rotatedString = rotateString(rotatedString);
    }
    result.push_back(newList);
  }
  return (result);
}

int main (int argc, char **argv) {

  //  vector<string> input = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
  vector<string> input = {"a", "a"};  

  vector<vector<string>> output = groupStrings (input);
  
}
