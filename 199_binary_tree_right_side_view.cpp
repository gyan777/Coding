#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/***************Non-intuitive DFS solution**********************
class Solution {
  std::vector<int> ans;
  int maxDepth = -1;
private:
  void helper(TreeNode* root, int depth) {
    if (root == nullptr) return;
    if (depth > maxDepth) {
      ans.push_back(root->val);
      maxDepth = depth;
    }
    helper(root->right, depth+1);
    helper(root->left, depth+1);
  }
public:
  vector<int> rightSideView(TreeNode* root) {
    helper(root, 0);
    return ans;
  }
}
****************************************************************/

// BFS soultion:
// At each level use the numer of nodes at that level
vector<int> rightSideView(TreeNode* root) {

  TreeNode *currNode;
  queue<TreeNode *> q;
  vector<int> rightView;

  if (root == nullptr) return (rightView);

  q.push(root);
  
  while (!q.empty()) {

    int numOfNodesAtCurrLvl = q.size();
    for (int i = 0; i < numOfNodesAtCurrLvl; i++) {
      TreeNode *currNode = q.front();
      q.pop();
      if (i == 0) {
	rightView.push_back(currNode);
      }
      if (currNode->right) {
	q.push(currNode->right);
      }
      if (currNode->left) {
	q.push(currNode->left);      
      }
    }
  }
  return(rightView);
}

int main (int argc, char **argv) {

  
  
}
