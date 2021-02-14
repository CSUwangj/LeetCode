#ifndef LEETCODE_HELPER
#define LEETCODE_HELPER
#include<iostream>
#include<vector>

template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']' << std::endl;
  return out;
}

std::ostream& operator<<(std::ostream &out, const bool &b) {
  if(b) {
    out << "true";
  } else {
    out << "false";
  }
  return out;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream& operator<<(std::ostream &out, ListNode * const head) {
  if(!head) {
    out << "empty list";
    return out;
  }
  out << head->val;
  ListNode *cur = head->next;
  while(cur) {
    out << "->" << cur->val;
    cur = cur->next;
  }
  return out;
}

#endif
