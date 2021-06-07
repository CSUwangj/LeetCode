/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int cur = nums.front();
    int len = 0;
    int answer = 1;
    for(auto i : nums) {
      if(i == cur + 1) {
        len += 1;
        answer = max(answer, len);
      } else {
        len = 1;
      }
      cur = i;
    }
    return answer;
  }
};
// @lc code=end

