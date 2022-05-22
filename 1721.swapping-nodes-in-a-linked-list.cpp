/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int listLength(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
public:
  ListNode* swapNodes(ListNode* head, int k) {
    int len = listLength(head);
    int first = k - 1;
    int second = len - k;
    ListNode *nodeFirst = head;
    while(first--) nodeFirst = nodeFirst->next;
    ListNode *nodeSecond = head;
    while(second--) nodeSecond = nodeSecond->next;
    swap(nodeFirst->val, nodeSecond->val);
    return head;
  }
};

// Accepted
// 132/132 cases passed (548 ms)
// Your runtime beats 99.93 % of cpp submissions
// Your memory usage beats 15.97 % of cpp submissions (180.3 MB)
// @lc code=end

