/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  pair<ListNode*, int> addTwoNumber(ListNode* l1, int len1, ListNode* l2, int len2) {
    if(!len1 || !len2) return len1 ? make_pair(l1, 0) : make_pair(l2, 0);
    ListNode *nextNode;
    int carry, curVal;
    if(len1 > len2) {
      tie(nextNode, carry) = addTwoNumber(l1->next, len1-1, l2, len2);
      curVal = l1->val + carry;
    } else if(len1 < len2) {
      tie(nextNode, carry) = addTwoNumber(l1, len1, l2->next, len2-1);
      curVal = l2->val + carry;
    } else {
      tie(nextNode, carry) = addTwoNumber(l1->next, len1-1, l2->next, len2-1);
      curVal = l1->val +l2->val + carry;
    }
    ListNode *node = new ListNode(curVal%10, nextNode);
    return make_pair(node, curVal/10);
  }
  
  int length(ListNode* l) {
    int len = 0;
    while(l) {
      len += 1;
      l = l->next;
    }
    return len;
  }
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = length(l1);
    int len2 = length(l2);
    auto [head, carry] = addTwoNumber(l1, len1, l2, len2);
    if(!carry) return head;
    return new ListNode(carry, head);
  }
};

// Accepted
// 1563/1563 cases passed (36 ms)
// Your runtime beats 73.8 % of cpp submissions
// Your memory usage beats 32.62 % of cpp submissions (71.6 MB)
// @lc code=end

