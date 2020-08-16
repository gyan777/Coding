#include <iostream>
#include <vector>

//create an array L where L[i] is the prodcut of all numbers till nums[i-1]
//use a variable to do the same for numers from the bootm of the array (variable prev)
//out[i] is then simply L[i] * prev

std::vector<int> productExceptSelf(std::vector<int>& nums) {

  std::vector<int> L(nums.size());
  std::vector<int> out(nums.size());

  if ((nums.size() == 0) || (nums.size() == 1)) {
    return (nums);
  }

  //  L.push_back(1);
  L[0] = 1;
  for (int i = 1; i < nums.size(); i++) {
    L[i] = L[i-1] * nums[i-1];
  }

  int prev = 1;
  for (int i = nums.size()-1; i >= 0; i--) {
    out[i] = prev * L[i] ;
    prev = prev * nums[i];
  }
  return (out);
}

int main (int argc, char **argv) {

  std::vector<int> nums{1,2,3,4};

  std::vector<int> out = productExceptSelf(nums);
  
  for (int i = 0; i < out.size(); i++) {
    std::cout << i << " " << out[i] << "\n";
  }
}

