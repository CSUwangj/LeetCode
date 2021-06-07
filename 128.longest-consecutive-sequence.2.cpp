/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int answer = 0;
    for(auto i : st) {
      if(st.count(i - 1)) continue;
      int cur = i;
      int len = 0;
      while(st.count(cur)) {
        len += 1;
        cur += 1;
      }
      answer = max(answer, len);
    }
    return answer;
  }
};
// @lc code=end

