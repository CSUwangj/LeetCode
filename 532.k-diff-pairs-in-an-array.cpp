/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
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
// 60/60 cases passed (11 ms)Vubmissions
// Your memory usage beats 68.98 % of cpp submissions (13.1 MB)
// @lc code=end

