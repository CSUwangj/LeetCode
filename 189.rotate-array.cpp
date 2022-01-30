/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
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
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k %= len;
    if(!k) return;
    vector<int> answer(nums.begin() + len - k, nums.end());
    answer.resize(len);
    copy(nums.begin(), nums.begin() + len - k, answer.begin() + k);
    nums = answer;
  }
};

// Accepted
// 38/38 cases passed (24 ms)
// Your runtime beats 93.45 % of cpp submissions
// Your memory usage beats 8.2 % of cpp submissions (26 MB)
// @lc code=end
