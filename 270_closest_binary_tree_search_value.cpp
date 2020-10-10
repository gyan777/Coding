#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Traverse the tree, if the target is larger than the root value then
// search the right part, otherwise the left part. Need to search the part of the
// tree where values closer to the target will be found.

// do a dfs and compare every node and descend, pass the current known lest difeerence
// and current known closest value down each level of recursion
int dfs (TreeNode* root, double target, double& diff, int& value) {

  if (!root) {
    return (value);
  }

  double newDiff = abs(root->val - target);
  if (newDiff < diff) {
    value = root->val;
    diff = newDiff;
  }

  if (root->val < target) {
    return (dfs (root->right, target, diff, value));
  } else {
    return (dfs (root->left, target, diff, value));    
  }

}

int closestValue(TreeNode* root, double target) {

  double diff = abs(target-root->val);
  
  return (dfs(root,target,diff,root->val));
}

int main (int argc, char **argv) {
			
  //  return (closestValue(root, target));
  
}
