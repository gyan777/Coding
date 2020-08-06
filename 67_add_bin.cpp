#include <iostream>
#include <string>
#include <algorithm>

//Convert each digit to int
//Use full adder logic to generate 

std::string add_bin (const std::string& a, const std::string& b);
  
int main (int argc, char **) {

  std::string a = "1101001", b = "1001";
  std::cout << add_bin(a, b) << "\n";
  
}

std::string add_bin (const std::string& a, const std::string& b) {

  std::string out;
  
  if (a.length() == 0) {
    return (b);
  } else if (b.length() == 0) {
    return (a);
  }

  uint len_a = a.length(),len_b = b.length();
  int cin = 0, a_int = 0, b_int = 0, s;

  while (len_a || len_b) {
    a_int = 0; b_int = 0;
    if (len_a) {
      a_int = a[--len_a] - '0';
    }
    if (len_b) {
      b_int = b[--len_b] - '0';
    }
    s = a_int ^ b_int ^ cin;
    cin = (cin & (a_int ^ b_int)) | (a_int & b_int);
    out += (s + '0');
  }
  if (cin == 1) {
    out += (cin + '0');
  }
  std::reverse(out.begin(), out.end());
  return (out);
}
