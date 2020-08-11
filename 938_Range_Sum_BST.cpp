#include <iostream>
 
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Search the tree using DFS (recursively). Would iterative be better?
//1-Traverse depth first and compare each node's value, if it is in the range add it to the member variable sum
//2-if the node's value is more than the lower limit L then search the left tree (if equal then skip the left tree)
//3-if the node's value is less than the higher limit R then search the right tree (if equal then skip the right tree)

class Solution {
  int sum = 0; //private by default
public:
    
    int rangeSumBST(TreeNode* root, int L, int R) {
      rangeSumBSTSub(root,L,R);
      return (sum);
    }

    void rangeSumBSTSub(TreeNode* root, int L, int R) {

    if (root == nullptr) {return;}
    if ((root->val >= L) && (root->val <= R)) {
      sum += root->val;
    }

    if (root->val > L) {
      rangeSumBSTSub (root->left, L, R);
    }
    if (root->val < R) {
      rangeSumBSTSub (root->right, L, R);
    }    
  }
};

int main (int argc, char **argv) {

  TreeNode *root = new TreeNode(10);
  TreeNode *tmp;

  tmp = root;
  TreeNode *left = new TreeNode(7);
  tmp->left = left;

  tmp = tmp->left;  
  left = new TreeNode(5);
  tmp->left = left;

  tmp = tmp->left;
  left = new TreeNode(3);
  tmp->left = tmp;
  
  tmp = root;
  TreeNode *right = new TreeNode(15);
  tmp->right = right;

  tmp = tmp->right;
  right = new TreeNode(18);
  tmp->right = right;
  
  Solution solution; 
  
  return (solution.rangeSumBST(root, 7, 15));
}
