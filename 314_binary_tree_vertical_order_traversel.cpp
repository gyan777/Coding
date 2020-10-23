#include <iostream>
#include <string>
#include <algorithm>
#include <vector>



using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Do a BFS, add nodes. Assign each nose a coo-ordinate in X,Y
// left chile gets -1 and right chile gets +1
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        TreeNode *currNode = root;
        queue<TreeNode *> nodeQ;
        queue<int> xQ;
        int currX = 0;
        map <int,vector<int>> nodeMatrix;
        vector<vector<int>> result;
        
        if (!root) return (result);
        
        nodeQ.push(currNode);
        xQ.push(currX);
        while (!nodeQ.empty()) {
            currNode = nodeQ.front();
            nodeQ.pop();
            currX = xQ.front();
            xQ.pop();
            nodeMatrix[currX].push_back(currNode->val);
            if (currNode->left) {
               nodeQ.push(currNode->left);   
               xQ.push(currX-1);
            }
            if (currNode->right) {
                nodeQ.push(currNode->right);
                xQ.push(currX+1);
            }
        }
        for (auto &elem : nodeMatrix) {
            result.push_back(elem.second);
        }
        return(result);
    }
};

int main (int argc, char **argv) {

}
