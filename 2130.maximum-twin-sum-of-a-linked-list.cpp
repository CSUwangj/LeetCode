/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int pairSum(ListNode* head) {
    vector<int> nums;
    while(head) {
      nums.push_back(head->val);
      head = head->next;
    }
    int answer = 0;
    int len = nums.size();
    for(int i = 0; i < len / 2; ++i) {
      answer = max(answer, nums[i] + nums[len - i - 1]);
    }

    return answer;
  }
};

// Accepted
// 46/46 cases passed (200 ms)
// Your runtime beats 99.58 % of cpp submissions
// Your memory usage beats 42.56 % of cpp submissions (126.5 MB)
// @lc code=end

