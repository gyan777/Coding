#include <iostream>
#include <vector>
#include <unordered_map>

//Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

//Example 1:

///Input:nums = [1,1,1], k = 2
//Output: 2

// Solution:
// The idea behind this approach is as follows: 
// If the cumulative sum upto two indices, say i and j is at a difference of k i.e. if sum[i] - sum[j] = ksum[i]−sum[j]=k, the sum of elements lying between indices i and j is k.

// Based on these thoughts, we make use of a hashmap mapmap which is used to store the cumulative sum upto all the indices possible along with the number of times the same sum occurs. // i
// ​	
//  ). We traverse over the array numsnums and keep on finding the cumulative sum. Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum. If the same sum occurs again, we increment the count corresponding to that sum in the hashmap. Further, for every sum encountered, we also determine the number of times the sum sum-ksum−k has occured already, since it will determine the number of times a subarray with sum kk has occured upto the current index. We increment the countcount by the same amount.

//After the complete array has been traversed, the countcount gives the required result.
  

using namespace std;

int subarraySum(vector<int>& nums, int k) {
  unordered_map<int,int> sums;
  int sum = 0, count = 0;
  sums.insert({sum,1});
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    if (sums.count(sum-k) > 0) {
      count += sums[sum-k];
    }
    sums[sum]++;
  }
  return(count);
}

int main (int argc, char **argv) {
  
  vector<int> numbers = {0,0,0,0,0,0,0,0,0,0};
  int count = subarraySum (numbers, 0);
  cout << count << "\n";
}
