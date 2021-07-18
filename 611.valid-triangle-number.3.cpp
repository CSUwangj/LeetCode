/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
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
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int answer = 0;
    for(int i = upper_bound(nums.begin(), nums.end(), 0) - nums.begin(); i < len - 2; i++) {
      int k = i + 2;
      for(int j = i + 1; j < len - 1; ++j) {
        k = lower_bound(nums.begin() + k, nums.end(), nums[i] + nums[j]) - nums.begin();
        answer += k - j - 1;
      }
    }

    return answer;
  }
};

// Accepted
// 233/233 cases passed (272 ms)
// Your runtime beats 28.14 % of cpp submissions
// Your memory usage beats 19.41 % of cpp submissions (13.1 MB)
// @lc code=end

