#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

private:  
  int ans = 0;

  int traverseDFS (TreeNode *root) {

    int depth_l=0, depth_r=0;
  
    if (!root) return 0;
  
    if (root->left) {
      depth_l = traverseDFS(root->left);
    }
  
    if (root->right) {
      depth_r = traverseDFS (root->right);
    }
  
    // cout << "val = " << root->val << "\n";
    // cout << "depth_l = " << depth_l  << "\n";
    // cout << "depth_r = " << depth_r << "\n";    

    // This is the number of nodes on the longest path so far
    ans = max (ans, depth_r + depth_l + 1);

    // This is the longest chain of nodes on either the left side
    // or the right side and will be combined into the longest path
    // throug it's parent
    int depth = max(depth_l,depth_r) + 1;

    // cout << "depth = " << depth << "\n";
    
    return (depth);
    
  }

public:  
  int diameterOfBinaryTree(TreeNode* root) {

    if (!root) return 0;

    int depth = traverseDFS(root);

    // What was asked for is the longest path meaning the number of edges
    // which is 1 less than the number of nodes
    return(ans - 1);
  }  
};


  
int main (int argc, char **argv) {

  Solution solo;
  
  TreeNode root, lvl1_r, lvl1_l, lvl2_l, lvl2_r;
  
  root.val=1; root.left=&lvl1_l; root.right=&lvl1_r;
  
  lvl1_l.val=2; lvl1_l.left=&lvl2_l; lvl1_l.right=&lvl2_r;
  lvl1_r.val=3; lvl1_r.left=nullptr; lvl1_l.right=nullptr;

  lvl2_l.val=4; lvl2_l.left=nullptr; lvl2_l.right=nullptr;
  lvl2_r.val=5; lvl2_r.left=nullptr; lvl2_r.right=nullptr;  
  
  int depth = solo.diameterOfBinaryTree(&root);
  cout << depth << "\n";  
}
