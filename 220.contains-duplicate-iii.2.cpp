/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
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
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int len = nums.size();
    if(len == 1) return false;
    pair<int, int> numsPosition[len];
    for(int i = 0; i < len; ++i) {
      numsPosition[i].first = nums[i];
      numsPosition[i].second = i;
    }
    sort(numsPosition, numsPosition + len);
    for(int i = 0; i < len - 1; ++i) {
      for(int j = i + 1; j < len; ++j) {
        if((long)numsPosition[j].first - numsPosition[i].first > t) break;
        if(abs(numsPosition[j].second - numsPosition[i].second) <= k) return true;
      }
    }
    return false;
  }
};

// Accepted
// 53/53 cases passed (12 ms)
// Your runtime beats 99.79 % of cpp submissions
// Your memory usage beats 99.44 % of cpp submissions (14.3 MB)
// @lc code=end

