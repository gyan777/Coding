#include <iostream>
#include <vector>
#include <unordered_map>

//Given an array of integers nums and and integer target, return the indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//Add numbes to a map and look if the complement (or diff with the target is in the map.
//note use of insert 

using namespace std;

vector<int> twoSum (const vector<int>& nums, const int& target) {

  vector<int> pair;
  unordered_map<int, int> index_map;
    
  for (int i = 0; i < nums.size(); i++) {
    int diff = target - nums[i];
    if (index_map.count(diff) > 0) {
      pair.push_back(index_map[diff]);
      pair.push_back(i);
      return(pair);
    }
    index_map[nums[i]] = i; //insert the number and index
  }
  return(pair);
}

int main (int argc, char **argv) {

  vector<int> numbers = {3,3};
  vector<int> pair = twoSum (numbers, 6);
  std::cout << pair[0] << " " << pair[1] << "\n";
}
