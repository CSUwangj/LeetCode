/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
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
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int len = nums.size();
    if(len == 1) return false;
    pair<int, int> numsPosition[len];
    for(int i = 0; i < len; ++i) {
      numsPosition[i].first = nums[i];
      numsPosition[i].second = i;
    }
    sort(numsPosition, numsPosition + len);
    for(int i = 1; i < len; ++i) {
      if(numsPosition[i].first == numsPosition[i - 1].first &&
         numsPosition[i].second - numsPosition[i - 1].second <= k) {
           return true;
      }
    }
    return false;
  }
};

// Accepted
// 51/51 cases passed (116 ms)
// Your runtime beats 99.89 % of cpp submissions
// Your memory usage beats 99.91 % of cpp submissions (61.1 MB)
// @lc code=end
