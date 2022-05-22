/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool check(vector<int> &nums, int m, int target){
    int current = 0;
    for(auto n : nums) {
      if(current + n <= target) {
        current += n;
      } else {
        current = n;
        m -= 1;
      }
    }
    return m > 0;
  }
public:
  int splitArray(vector<int>& nums, int m) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    if(m == 1) return high;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(check(nums, m, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return high;
  }
};

// Accepted
// 30/30 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 42.53 % of cpp submissions (7.2 MB)
// @lc code=end
