/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
  ListNode* reverseKNodes(ListNode* head, int k) {
    ListNode *tail = nullptr;
    ListNode *next;
    while(k--) {
      next = head->next;
      head->next = tail;
      tail = head;
      head = next;
    }
    return tail;
  }
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *newHead = new ListNode();
    ListNode *cur = head;
    ListNode *newTail = newHead;
    while(cur) {
      // cout << cur << ' ' << cur->val << endl;
      bool longEnough = true;
      ListNode *groupHead = cur;
      for(int i = 0; i < k; ++i) {
        if(!cur) {
          longEnough = false;
          break;
        }
        cur = cur->next;
      }
      if(longEnough) {
        newTail->next = reverseKNodes(groupHead, k);
        while(newTail->next) newTail = newTail->next;
      } else {
        newTail->next = groupHead;
      }
    }
    return newHead->next;
  }
};
// @lc code=end

