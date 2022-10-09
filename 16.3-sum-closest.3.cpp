/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
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
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int diff = INT_MAX;
    int answer = INT_MIN;
    for(int i = 0; i < len - 2 && answer != target; ++i) {
      int start = i + 1;
      int end = len - 1;
      while(start < end) {
        int result = nums[i] + nums[start] + nums[end];
        if(result == target) return result;
        if(abs(result - target) < diff) {
          diff = abs(result - target);
          answer = result;
        }
        if(result < target) {
          do { start += 1; } while(start < end && nums[start] == nums[start - 1]);
        } else {
          do { end -= 1; } while(start < end && nums[end] == nums[end + 1]);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 162/162 cases passed (728 ms)
// Your runtime beats 16.20 % of cpp submissions
// Your memory usage beats 11.39 % of cpp submissions (16.5 MB)
// @lc code=end

