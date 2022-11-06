/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
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
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> count{{0, -1}};
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      sum %= k;
      if(count.count(sum)) {
        if(i - count[sum] > 1) return true;
      } else {
        count[sum] = i;
      }
    }
    return false;
  }
};

// Accepted
// 97/97 cases passed (352 ms)
// Your runtime beats 70.44 % of cpp submissions
// Your memory usage beats 88.57 % of cpp submissions (112.6 MB)
// @lc code=end

