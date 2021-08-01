/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if(target <= nums.front() * 3 || len == 3) {
      return nums[0] + nums[1] + nums[2];
    }
    if(target >= nums.back() * 3) {
      return nums[len - 1] + nums[len - 2] + nums[len - 3];
    }
    int diff = INT_MAX;
    int answer = INT_MIN;
    for(int i = 0; i < len - 2; ++i) {
      if(nums[i] + nums[i + 1] + nums[i + 2] - target > diff) {
        break;
      }
      int start = i + 1;
      int end = len - 1;
      while(start < end) {
        int result = nums[i] + nums[start] + nums[end];
        int d = result - target;
        if(!d) {
          return result;
        } else if(d < 0) {
          if(diff > -d) {
            diff = -d;
            answer = result;
          }
          do { start += 1; } while(start < end && nums[start] == nums[start - 1]);
        } else {
          if(diff > d) {
            diff = d;
            answer = result;
          }
          do { end -= 1; } while(start < end && nums[end] == nums[end + 1]);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 131/131 cases passed (4 ms)
// Your runtime beats 97.91 % of cpp submissions
// Your memory usage beats 11.39 % of cpp submissions (10 MB)
// @lc code=end

