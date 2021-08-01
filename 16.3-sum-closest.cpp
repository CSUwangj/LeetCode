/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int diff = INT_MAX;
    int answer = -1;
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < len-2; ++i) {
      for(int j = i+1; j < len-1; ++j) {
        if(j != i+1 && nums[j] == nums[j-1]) continue;
        int tar = target-nums[i]-nums[j], start = j+1, end = len;
        while(start < end) {
          int mid = (start + end) / 2;
          if(nums[mid] > tar) {
            if(nums[mid] - tar < diff) {
              diff = nums[mid]-tar;
              answer = nums[mid] + nums[i] + nums[j];
            }
            end = mid;
          } else {
            if(tar - nums[mid] < diff) {
              diff = tar - nums[mid];
              answer = nums[mid] + nums[i] + nums[j];
            }
            start = mid + 1;
          }
        }
      }
    }
    return answer;
  }
};

// Accepted
// 131/131 cases passed (48 ms)
// Your runtime beats 10.58 % of cpp submissions
// Your memory usage beats 60.68 % of cpp submissions (9.9 MB)
// @lc code=end

