#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
                
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        int rows = binaryMatrix.dimensions()[0];
        int cols = binaryMatrix.dimensions()[1];
        int leftMostIdx = cols, leftMostRow = 0;
        
        for (int i = 0; i < rows; i++) {
            int l = 0, h = cols-1, mid;
            while (h>=l) {
                mid = l + (h-l)/2;
                if (binaryMatrix.get(i,mid) == 1) {
                    if (mid < leftMostIdx) {
                        leftMostIdx = mid;
                        if (leftMostIdx == 0) {
                            return (leftMostIdx);
                        }
                        leftMostRow = i;
                    }
                    h = mid - 1; 
                } else {
                    if (mid >= leftMostIdx) {
                        break;
                    }
                    l = mid + 1;
                }                       
            }
        }
        
        if (leftMostIdx == cols) 
            return -1;
        else
            return(leftMostIdx);
    }
};

int main (int argc, char **argv) {


}
