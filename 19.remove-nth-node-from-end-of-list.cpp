/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *newHead = new ListNode(-1, head);
    ListNode *tail = newHead;
    ListNode *del = newHead;
    while(n--) tail = tail->next;
    while(tail->next) {
      tail = tail->next;
      del = del->next;
    }
    del->next = del->next->next;
    return newHead->next;
  }
};

// Accepted
// 208/208 cases passed (11 ms)
// Your runtime beats 27.59 % of cpp submissions
// Your memory usage beats 32.26 % of cpp submissions (10.8 MB)
// @lc code=end

