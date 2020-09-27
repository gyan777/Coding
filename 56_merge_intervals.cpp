#include <vector>
#include <algorithm>
#include <iostream>

/* Problem Description
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

    intervals[i][0] <= intervals[i][1]

*/

// First sort the intervals on the lower of the indices and then merge

bool comp(const std::vector<int>& v1, const std::vector<int>& v2) {
  return (v1[0] < v2[0]);
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {

  std::vector<std::vector<int>> merged;

  if (intervals.size() <= 1) {
    return (intervals);
  }
  
  std::sort(intervals.begin(), intervals.end(), comp); // by default sort on the first column
  merged.push_back(intervals[0]);
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] > merged.back()[1]) {
      merged.push_back(intervals[i]);
    } else if (intervals[i][1] > merged.back()[1]) {
      merged.back()[1] = intervals[i][1];
    }
  }
  return (merged);
}

int main (int argc, char **argv) {

   std::vector<std::vector<int>> intervals {{1,3},{2,6},{8,10},{15,18}};

   std::vector<std::vector<int>> out = merge(intervals);
  
  for (int i = 0; i < out.size(); i++) {
    std::cout << i << " " << out[i][0] << " " << out[i][1] << "\n";
  }
}

