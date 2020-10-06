#include <iostream>


int firstBadVersionInRange (const int& start, const int& end) {
  
  //cout << start << "\n";
  //cout << end << "\n";
    
  if (start == end) return start;
    
  int mid = (start/2) + (end/2); // This avoids integer overflow when start and end are large integers
    
  if (isBadVersion(mid)) {
    return (firstBadVersionInRange (start,mid));
  } else {
    return (firstBadVersionInRange (mid+1,end));    
  }
}

int firstBadVersion(int n) {
    
  if (n <= 1) return n;

  return (firstBadVersionInRange (1, n));

}

int main (int argc, char **argv) {
  
}
