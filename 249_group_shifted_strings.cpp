#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// Great solution. Instead of brute force rotating the sequence
// create a signture (encoded as difference between adjacent elements)
// so abc get encoded as "bb" and ccc get encoded as "aa"
// Then every new string is added to a hash map with the signature as the key
using namespace std;

vector<vector<string>> groupStrings(vector<string>& strings) {
  unordered_map<string, vector<string>> m;
  for(auto &str: strings) {
    string signature;
    for(int i = 1; i < str.size(); i++) 
      signature.push_back((26 + str[i] - str[i-1]) % 26 + 'a');
    m[signature].push_back(str);
  }
  vector<vector<string>> res;
  for(auto &itr: m)
    res.push_back(itr.second);
  return res;
}

int main (int argc, char **argv) {

  vector<string> input = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
  //  vector<string> input = {"a", "a"};  

  vector<vector<string>> output = groupStrings (input);
  
}
