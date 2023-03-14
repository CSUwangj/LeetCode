/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  ListNode* head;
  mt19937 generator;
  uniform_real_distribution<double> distribution = uniform_real_distribution<double>(0.0, 1.0);
  function<double(void)> rng = bind(distribution, generator);
public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) {
    this->head = head;
  }
  
  /** Returns a random node's value. */
  int getRandom() {
    ListNode *cur = head;
    double curIndex = 1;
    int result = -1;
    while(cur) {
      if(rng() < 1 / curIndex) result = cur->val;
      cur = cur->next;
      curIndex += 1;
    }
    return result;
  }
};

// Accepted
// 8/8 cases passed (36 ms)
// Your runtime beats 7.46 % of cpp submissions
// Your memory usage beats 8.14 % of cpp submissions (16.9 MB)
// @lc code=end
