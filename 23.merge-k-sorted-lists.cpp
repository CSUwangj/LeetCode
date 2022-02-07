/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
class Solution {
  ListNode *merge2Lists(ListNode *a, ListNode *b) {
    ListNode *newHead = new ListNode(0);
    ListNode *cur = newHead;
    while(a && b) {
      if(a->val < b->val) {
        cur->next = a;
        a = a->next;
      } else {
        cur->next = b;
        b = b->next;
      }
      cur = cur->next;
    }
    if(a) cur->next = a;
    else cur->next = b;
    return newHead->next;
  }
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;
    int len = lists.size();
    for(int step = 1; step < len; step <<= 1) {
      for(int first = 0; first + step < len; first += 2 * step) {
        lists[first] = merge2Lists(lists[first], lists[first + step]);
      }
    }
    return lists.front();
  }
};

// Accepted
// 133/133 cases passed (12 ms)
// Your runtime beats 99.77 % of cpp submissions
// Your memory usage beats 58.51 % of cpp submissions (13.3 MB)
// @lc code=end
