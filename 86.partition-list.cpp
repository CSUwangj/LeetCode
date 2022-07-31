/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
  ListNode* partition(ListNode* head, int x) {
    ListNode *newFront = new ListNode(-1);
    ListNode *frontTail = newFront;
    ListNode *newBack = new ListNode(-1);
    ListNode *backTail = newBack;
    while(head) {
      if(head->val < x) {
        frontTail->next = head;
        frontTail = frontTail->next;
      } else {
        backTail->next = head;
        backTail = backTail->next;
      }
      head = head->next;
    } 
    backTail->next = nullptr;
    frontTail->next = newBack->next;
    ListNode* answer = newFront->next;
    delete newFront;
    delete newBack;
    return answer;
  }
};

// Accepted
// 168/168 cases passed (7 ms)
// Your runtime beats 73.71 % of cpp submissions
// Your memory usage beats 32.53 % of cpp submissions (10.3 MB)
// @lc code=end

