/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
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
  int longestSubarray(vector<int>& nums) {
    int start = 0;
    int count = 0;
    int answer = 0;
    for(int i = 0; i < nums.size(); ++i) {
      count += !nums[i];
      while(count > 1) {
        count -= !nums[start];
        start += 1;
      }
      answer = max(answer, i - start);
    }
    return answer;
  }
};

// Accepted
// 74/74 cases passed (53 ms)
// Your runtime beats 23.1 % of cpp submissions
// Your memory usage beats 65.98 % of cpp submissions (36.5 MB)
// @lc code=end

