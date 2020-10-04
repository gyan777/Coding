#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;


//Naive Soultion; bubblesort just that the outer loop goes till k

int findKthLargest(vector<int>& nums, int k) {

  /***************************************
  for (int i = 0; i < k; i++) {
    for (int j = i+1; j < nums.size(); j++) {
      if (nums[j] > nums[i]) {
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
      }
    }
    cout << nums[i] << "\n";
  }
  return(nums[k-1]);
  ******************************************/

  priority_queue<int,vector<int>,greater<int>> p;

  for (int i = 0; i < nums.size(); i++) {
    if (p.size() < k) {
      p.push(nums[i]);
    } else if (p.top() < nums[i]) {
      p.pop();
      p.push(nums[i]);
    }
  }
  return p.top();
}

int main (int argc, char **argv) {
  //  vector<int> nums = {3,2,3,1,7,4,5,5,6};
  vector<int> nums = {1};  
  int k = 1;
  cout << findKthLargest(nums, k) << "\n";  
}
