/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *newHead = new ListNode();
    ListNode *newCur = newHead;
    ListNode *cur = head;
    int pos = 1;
    while(pos < left) {
      newCur->next = cur;
      cur = cur->next;
      newCur = newCur->next;
      pos += 1;
    }
    ListNode *midTail = cur;
    ListNode *midCur = nullptr;
    ListNode *next;
    while(pos <= right) {
      next = cur->next;
      cur->next = midCur;
      midCur = cur;
      cur = next;
      pos += 1;
    }
    newCur->next = midCur;
    newCur = midTail;
    newCur->next = next;
    return newHead->next;
  }
};

// Accepted
// 44/44 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 17.76 % of cpp submissions (7.5 MB)
// @lc code=end

