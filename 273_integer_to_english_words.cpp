#include <vector>
#include <iostream>
#include <unordered_map>

/* Problem Description
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"
Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/

//Convert the number into Billions, Millions, Thousands and so on first
//and within that convert to hundreds
//One big problem here is to not have any leading and trailing spaces

std::string convertHundreds(int num) {

  std::vector<std::string> units = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                                    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
                                    "Eighteen", "Nineteen"};

  std::vector<std::string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  std::string wordNum, prependString = "";
  int currPow = 0;
  int divisor = 100;
  int digit;
  while (divisor) {
    if (num > 0 && num < 20) {
      wordNum += prependString + units[num];
      break;
    }
    digit = num/divisor;
    if (digit > 0) {
      if (divisor == 100) {
	wordNum += units[digit];
	wordNum += " Hundred";
	prependString = " ";
      } else if (divisor == 10) {
	wordNum += prependString + tens[digit];
	prependString = " ";
      }
    }
    num = num % divisor;
    divisor = divisor / 10;
  }
  return (wordNum);
}

std::string numberToWords(int num) {

  std::string wordNum, prependString = "";
  std::vector<std::string> powersOfTen = {"", "Thousand", "Million", "Billion"};

  if (num == 0) {
    return ("Zero");
  }
  
  int divisor = 1000000000;
  int currPow = 3;
  while (divisor) {
    int hundreds = num/divisor;
    if (hundreds > 0) {
      wordNum += prependString + convertHundreds(hundreds);
      if (currPow > 0) {
	wordNum += " " + powersOfTen[currPow];
      }
      prependString = " ";
    } 
    currPow--;
    num = num % divisor;
    divisor = divisor / 1000;
  }
  return (wordNum);
}

int main (int argc, char **argv) {
  std::cout << numberToWords(123) << "\n";
}

