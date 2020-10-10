#include <iostream>
#include <stack>

using namespace std;

int getOp (const string& s, int& i) {
  int num = 0;
  while ((s[i] <= '9') && (s[i] >= '0')) {
    num = num * 10 + s[i] - '0';
    i++;
  }
  return (num);
}

void skipSpaces (const string& s, int& i) {
  while (s[i] == ' ') {
    i++;
  }
}

int calculate(string s) {

  stack<int> ops;

  int i = 0;
  while (i < s.length()) {
    
    skipSpaces(s, i);

    if (s[i] == '*') {
      int op_a = ops.top();
      ops.pop();
      i++;
      skipSpaces (s, i);
      int op_b = getOp(s, i);
      ops.push(op_a * op_b);
    } else if (s[i] == '/') {
      int op_a = ops.top();
      ops.pop();
      i++;
      skipSpaces (s, i);
      int op_b = getOp(s, i);
      ops.push(op_a / op_b);
    } else if (s[i] == '-') {
      i++;
      skipSpaces (s, i);
      int op_b = getOp(s, i);
      ops.push(-1 * op_b);
    } else if (s[i] == '+') {
      i++;
      int op_b = getOp(s, i);
      ops.push(op_b);
    } else {
      skipSpaces (s, i);      
      int op_b = getOp(s, i);
      ops.push(op_b);
    }
  }

  int res = 0;
  while (!ops.empty()) {
    res += ops.top();
    ops.pop();    
  }

  return (res);
}

int main  (int argc, char **argv) {
  //  cout << calculate ("3+5 / 2") << "\n";
  cout << calculate ("2147483640 + 55") << "\n";  
}
