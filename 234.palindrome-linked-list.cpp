/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  ListNode* reverseList(ListNode* head) {
    ListNode* prev=nullptr;
    ListNode* curr=head;
    while(curr) {
      ListNode* next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
    }
    return prev;
  }
public:
  bool isPalindrome(ListNode* head) {
    int n=0;
    ListNode* iter=head;
    while(iter) iter=iter->next, n++;
    if(n<2) return true;
    // printf("-->%d\n", n);
    iter=head;
    for(int i=1;i<n/2;++i) iter=iter->next;
    ListNode* iter2 = (n%2) ? iter->next->next : iter->next;
    iter->next=nullptr;
    // printf("iter2->val=%d\n",xiter2->val);
    iter=reverseList(head);
    while(iter) {
      if(iter->val!=iter2->val) return false;
      iter=iter->next;
      iter2=iter2->next;
    }
    return true;
  }
};

// Accepted
// 87/87 cases passed (401 ms)
// Your runtime beats 41.44 % of cpp submissions
// Your memory usage beats 95.63 % of cpp submissions (110.3 MB)
// @lc code=end

