/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    map<int, int> count;
    for(auto num : nums) {
      count[num] += 1;
    }
    int last = -1;
    int lastResult = 0;
    int second = -1;
    int secondResult = 0;
    for(auto [num, cnt] : count) {
      int tmp = lastResult;
      if(last != num - 1) {
        lastResult = lastResult + num * cnt;
      }
      if(secondResult + num * cnt > lastResult) {
        lastResult = secondResult + num * cnt;
      }
      secondResult = tmp;
      last = num;
    }
    return lastResult;
  }
};

// Accepted
// 48/48 cases passed (14 ms)
// Your runtime beats 42.69 % of cpp submissions
// Your memory usage beats 71.31 % of cpp submissions (9.7 MB)
// @lc code=end
