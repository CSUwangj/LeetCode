/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    ListNode *newHead = new ListNode(INT_MIN);
    while(head) {
      ListNode *cur = newHead;
      while(cur->next && cur->next->val < head->val) {
        cur = cur->next;
      }
      ListNode *tmp = head->next;
      head->next = cur->next;
      cur->next = head;
      head = tmp;
    }
    return newHead->next;
  }
};
// @lc code=end
