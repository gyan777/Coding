#include <iostream>
#include <vector>

using namespace std;

//Start from the maximum ed so a copy is not needed 

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

  int p1 = m-1;
  int p2 = n-1;
  int p = m+n-1;

  while ((p1 >= 0) && (p2 >= 0)) {
    if (nums1[p1] > nums2[p2]) {
      nums1[p] = nums1[p1];
      p1--;
    } else {
      nums1[p] = nums2[p2];
      p2--;
    }
    p--;
      //nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--]; 
  }

  while (p2 >= 0) {
    nums1[p--] = nums2[p2--];
  }
  
}

int main (int argc, char **argv) {
  vector<int> nums1 = {1,2,3,0,0,0};  
  int m = 3;
  vector<int> nums2 = {2,5,6,0,0,0};  
  int n = 3;

  merge(nums1, m, nums2, n);

  for (int i = 0; i < m+n; i++) {
    cout << nums1[i] << "\n";
  }
  
}
