/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if(!head) return nullptr;
    ListNode *quick = head;
    ListNode *slow = head;
    do {
      quick = quick->next;
      if(quick) quick = quick->next;
      slow = slow->next;
    } while(quick && slow && quick != slow);
    if(!quick) return quick;
    slow = head;
    while(quick != slow) {
      slow = slow->next;
      quick = quick->next;
    }
    return quick;
  }
};

// Accepted
// 17/17 cases passed (6 ms)
// Your runtime beats 90.6 % of cpp submissions
// Your memory usage beats 68.59 % of cpp submissions (7.7 MB)
// @lc code=end

