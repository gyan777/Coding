#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  unordered_map <int, vector<int>> IdxMap;
public:
    Solution(vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++) {
	IdxMap[nums[i]].push_back(i);
      }
    }
    
    int pick(int target) {
      vector<int> indexes = IdxMap[target];
      return (index[rand() % indexes.size()]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main (int argc, char **argv) {

  //int x = 98088;
  //int x = 98368;

}
