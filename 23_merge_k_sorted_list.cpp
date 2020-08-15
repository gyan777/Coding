#include <iostream>
#include <vector>
#include "limits.h"

using namespace std;
/**
 * Definition for singly-linked list.
 **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// FIGURE OUT a BETTR SOLUTION
// This soultion creates a new list and leaves the original lists data
// structure in place. First a traversing pointer is 

ListNode* mergeKLists(vector<ListNode*>& lists) {

  vector<ListNode*> ptr;
  ListNode tmp(0);
  ListNode *currPtr = &tmp, *rtn = currPtr;
  int k = lists.size();
  
  // Add pointers to a new array
  for (int i = 0; i < k; i++) {
    ptr.push_back(lists[i]);
  }

  while (1) {
    int fullyTraversedLists = 0;
    int min = INT_MAX;
    int min_index = 0;
    for (int i = 0; i < k; i++) {
      if (ptr[i] == nullptr) {
	fullyTraversedLists++;
	continue;
      } else {
	if (ptr[i]->val <= min) {
	  min = ptr[i]->val;
	  min_index = i;
	}
      }
    } //for
    if (fullyTraversedLists == k) break;    
    ptr[min_index] = ptr[min_index]->next;
    currPtr->next = new ListNode(min); // insert
    currPtr = currPtr->next;
  } //while
  return(rtn->next);
}

int main (int argc, char **argv) {

  vector<ListNode*> lists;

  ListNode tmp, tmp1, tmp2;

  tmp.val = 1;
  tmp.next = nullptr;
  lists.push_back(&tmp);

  tmp1.val = 4;
  tmp1.next = nullptr;  
  lists[0]->next = &tmp1;

  tmp2.val = 5;
  tmp2.next = nullptr;
  lists[0]->next->next = &tmp2;

  ListNode tmp3, tmp4, tmp5;
  
  tmp3.val = 1;
  tmp3.next = nullptr;
  lists.push_back(&tmp3);

  tmp4.val = 3;
  tmp4.next = nullptr;
  lists[1]->next = &tmp4;

  tmp5.val = 4;
  tmp5.next = nullptr;
  lists[1]->next->next = &tmp5;

  ListNode tmp6, tmp7;

  tmp6.val = 2;
  lists.push_back(&tmp6);  

  tmp7.val = 6;
  lists[2]->next = &tmp7;  
  
  ListNode *rtn = mergeKLists(lists);
}
