/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
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
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    for(int i = 0; i < nums.size() - 2; ++i) {
      if(nums[i] - nums[i + 1] < nums[i + 2]) {
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }
    return 0;
  }
};

// Accepted
// 84/84 cases passed (28 ms)
// Your runtime beats 99.7 % of cpp submissions
// Your memory usage beats 96.06 % of cpp submissions (21.7 MB)
// @lc code=end

