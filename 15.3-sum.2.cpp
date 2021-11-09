/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> answer;
    for(int i = 0; i < len - 2; ++i) {
      if(i && i < len - 2 && nums[i] == nums[i - 1]) continue;
      int begin = i + 1, end = len - 1;
      while(begin < end) {
        if(nums[begin] + nums[end] == -nums[i]) {
          answer.push_back(vector<int>{nums[i], nums[begin], nums[end]});
          int curBegin = nums[begin];
          int curEnd = nums[end];
          while(begin < end && nums[begin] == curBegin) ++begin;
          while(begin < end && nums[end] == curEnd) --end;
        } else if (nums[begin] + nums[end] < -nums[i]) {
          ++begin;
        } else {
          --end;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 318/318 cases passed (96 ms)
// Your runtime beats 63.5 % of cpp submissions
// Your memory usage beats 67.25 % of cpp submissions (20.1 MB)
// @lc code=end

