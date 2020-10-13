#include <iostream>
#include <vector>

// Do a binary search to a point in the array where the element exists and then
// searcg outwards from there.

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {

  vector<int> range = {-1,-1};
  int h = nums.size()-1;
  int l = 0, k = 0, j = 0;

  while (h >= l) {
    int mid = l + (h-l)/2;
    if (nums[mid] == target) {
      k = mid; j = mid;
      while ((k < nums.size()-1) && (nums[k+1] == target)) k++;
      while ((j > 0) && (nums[j-1] == target)) j--;
      range = {j, k};
      return (range);
    } else if (target > nums[mid]) {
      l = l+1;
    } else {
      h = h-1;
    }
  }
  return (range);
}    

int main (int argc, char **argv) {
  vector<int> nums = {2,2,3,5,7,7,8,8,10};
  //vector<int> nums = {2,2};  
  int target = 2;
  vector<int> result = searchRange (nums, target);
  cout << result[0] << " " << result[1] << "\n";
}
