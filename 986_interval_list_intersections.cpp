#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

// And even better approach than binary serach is to move left and down only.
using namespace std;

class Solution {
public:

  vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    
    int ptrA = 0, ptrB = 0;
    vector<vector<int>> intervals;
   
    while (ptrA < A.size() && ptrB < B.size()) {
      if ((A[ptrA][0] <= B[ptrB][1]) && (A[ptrA][0] >= B[ptrB][0])) {
	if (A[ptrA][1] <= B[ptrB][1]) {
	  intervals.push_back(A[ptrA]);
	  ptrA++;
	} else {
	  intervals.push_back({A[ptrA][0],B[ptrB][1]});
	  ptrB++;
	}
      } else if ((B[ptrB][0] <= A[ptrA][1]) && (B[ptrB][0] >= A[ptrA][0])) {
	if (B[ptrB][1] <= A[ptrA][1]) {
	  intervals.push_back(B[ptrB]);
	  ptrB++;	  
	} else {
	  intervals.push_back({B[ptrB][0],A[ptrA][1]});
	  ptrA++;
	}

      } else {
	if (A[ptrA][0] > B[ptrB][1]) {
	  ptrB++;
	} else {
	  ptrA++;
	}
      }
      //cout << intervals[intervals.size()-1][0] << ", " << intervals[intervals.size()-1][1] << "\n";
    }
    
    return (intervals);					       
  }
};

int main (int argc, char **argv) {

  Solution sol;
  
  vector<vector<int>> A = {{3,5},{9,20}};
  vector<vector<int>> B = {{4,5},{7,10},{11,12},{14,15},{16,20}};
  
  vector<vector<int>> intervals = sol.intervalIntersection(A, B);

  for (int i = 0; i < intervals.size(); i++) {
    cout << intervals[i][0] << ", " << intervals[i][1] << "\n";
  }
}
