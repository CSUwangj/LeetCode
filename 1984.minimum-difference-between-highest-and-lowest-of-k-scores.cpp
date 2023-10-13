/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
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
  int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int answer = INT_MAX;
    for(int i = 0; i + k <= nums.size(); ++i) {
      answer = min(answer, nums[i + k - 1] - nums[i]);
    }

    return answer;
  }
};

// Accepted
// 118/118 cases passed (7 ms)
// Your runtime beats 99.39 % of cpp submissions
// Your memory usage beats 32.93 % of cpp submissions (13.8 MB)
// @lc code=end

