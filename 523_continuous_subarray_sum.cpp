#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
        
  if (k == 0) {
    int numZero = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
	numZero++;
	if (numZero == 2) return true;
      } else {
	numZero = 0;
      }
    }
    return (false);
  }
        
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum = nums[i];
    for (int j = i+1; j < nums.size(); j++) {
      sum += nums[j];
      if (!(sum % k)) return true;
    }
  }
  return (false);
}


int main (int argc, char **argv) {

}
