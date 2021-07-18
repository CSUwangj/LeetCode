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
    for(int i = 0; i < len - 2; i++) {
      for(int j = i + 1; j < len - 1; j++) {
        int l = nums[j] - nums[i];
        int h = nums[i] + nums[j];
        auto low = upper_bound(nums.begin() + j + 1, nums.end(), l);
        auto high = lower_bound(nums.begin() + j + 1, nums.end(), h);
        high -= 1;
        answer += high >= low ? high - low + 1 : 0;
      }
    }

    return answer;
  }
};

// Accepted
// 233/233 cases passed (936 ms)
// Your runtime beats 5.12 % of cpp submissions
// Your memory usage beats 19.41 % of cpp submissions (12.8 MB)
// @lc code=end

