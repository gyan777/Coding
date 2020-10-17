#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

  static bool compareDuplet (const vector<int>& v1, const vector<int>& v2) {
    return ((v1[0] == v2[0]) ? (v1[1] < v2[1]) : (v1[0] > v2[0]));
  }
  
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {

    TreeNode *currNode = root;
    queue<TreeNode *> nodeQ;
    vector<vector<int>> result;
    queue<int> xQ;
    queue<int> yQ;    
    int currX = 0;
    int currY = 0;    
    map<int, vector<vector<int>>> nodePos;

    if (currNode) {
      nodeQ.push(currNode);
      xQ.push(currX);
      yQ.push(currY);      
    } else {
      return result;
    }
      
    while (!nodeQ.empty()) {

      currNode = nodeQ.front(); nodeQ.pop();
      currX = xQ.front(); xQ.pop();
      currY = yQ.front(); yQ.pop();
      nodePos[currX].push_back({currY,currNode->val});
	
      if (currNode->left) {
	nodeQ.push(currNode->left);
	xQ.push(currX-1);
	yQ.push(currY-1);	
      }

      if (currNode->right) {
	nodeQ.push(currNode->right);
	xQ.push(currX+1);
	yQ.push(currY-1);	  	
      }
    }
    
    for (auto xCoord: nodePos) {
      if (xCoord.second.size() > 1) {
	sort(xCoord.second.begin(), xCoord.second.end(),compDuplet);
      }
      vector<int> sortedVals;
      for (int i = 0; i < xCoord.second.size(); i++) {
	sortedVals.push_back(xCoord.second[i][1]);
      }
      result.push_back(sortedVals);
    }
    return (result);    
  }
};

int main (int argc, char **argv) {

  Solution sol;
  
  TreeNode root;
  TreeNode l, r, l1, r1;
  
  root.val = 3;
  root.left = &l;
  root.right = &r;

  l.val = 9;
  l.left = nullptr;
  l.right = nullptr;

  r.val = 20;
  r.left = &l1;
  r.right = &r1;

  l1.val = 15;
  l1.left = nullptr;
  l1.right = nullptr;  

  r1.val = 7;
  r1.left = nullptr;
  r1.right = nullptr;  
  
  vector<vector<int>> list = sol.verticalTraversal(&root);
}
