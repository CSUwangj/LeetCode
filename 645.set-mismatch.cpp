/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int len = nums.size();
    vector<bool> used(len);
    int loss = -1;
    int dup = -1;
    for(auto i : nums) {
      if(!used[i - 1]) used[i - 1] = true;
      else dup = i;
    }
    for(int i = 0; i < len; ++i) {
      if(!used[i]) loss = i + 1;
    }
    return vector<int>{dup, loss};
  }
};

// Accepted
// 49/49 cases passed (81 ms)
// Your runtime beats 49.41 % of cpp submissions
// Your memory usage beats 50.7 % of cpp submissions (21.6 MB)
// @lc code=end

