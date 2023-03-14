/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> answer(2 * n);

    for(int i = 0; i < n; ++i) {
      answer[2 * i] = nums[i];
      answer[2 * i + 1] = nums[i + n];
    }

    return answer;
  }
};

// Accepted
// 53/53 cases passed (7 ms)
// Your runtime beats 62.32 % of cpp submissions
// Your memory usage beats 61.93 % of cpp submissions (9.8 MB)
// @lc code=end

