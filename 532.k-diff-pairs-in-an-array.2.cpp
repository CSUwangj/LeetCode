/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    map<int, int> cnt;
    for(auto i : nums) {
      cnt[i] += 1;
    }

    int answer = 0;
    for(auto [i, c] : cnt) {
      if(k) answer += cnt.count(i + k);
      else answer += c > 1;
    }
    return answer;
  }
};

// Accepted
// 59/59 cases passed (16 ms)
// Your runtime beats 80.36 % of cpp submissions
// Your memory usage beats 39.57 % of cpp submissions (13.6 MB)
// @lc code=end

