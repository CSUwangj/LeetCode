/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
class Solution {
  pair<int, ListNode*> getLengthAndTail(ListNode *head) {
    ListNode *tail;
    int len = 0;
    while(head) {
      len += 1;
      tail = head;
      head = head->next;
    }
    return make_pair(len, tail);
  }
  ListNode* advance(ListNode *head, int dis) {
    while(head && dis) {
      head = head->next;
      dis -= 1;
    }
    return head;
  }
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto [lenA, tailA] = getLengthAndTail(headA);
    auto [lenB, tailB] = getLengthAndTail(headB);
    if(tailA != tailB) return nullptr;
    if(lenA > lenB) headA = advance(headA, lenA - lenB);
    if(lenB > lenA) headB = advance(headB, lenB - lenA);
    while(headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};

// Accepted
// 39/39 cases passed (116 ms)
// Your runtime beats 12.38 % of cpp submissions
// Your memory usage beats 72.37 % of cpp submissions (14.5 MB)
// @lc code=end

