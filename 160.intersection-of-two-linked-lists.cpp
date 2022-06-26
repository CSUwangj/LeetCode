/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> st;
    while(headA) {
      st.insert(headA);
      headA = headA->next;
    }
    while(headB) {
      if(st.count(headB)) return headB;
      headB = headB->next;
    }
    return nullptr;
  }
};

// Accepted
// 39/39 cases passed (127 ms)
// Your runtime beats 11.21 % of cpp submissions
// Your memory usage beats 14.93 % of cpp submissions (17.1 MB)
// @lc code=end

