/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start
class Solution {
public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long answer = 0;
    int lastInvalid = -1;
    int prevMinKIndex = -1;
    int prevMaxKIndex = -1;

    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] < minK || nums[i] > maxK) {
        lastInvalid = i;
      }
      if (nums[i] == minK) {
        prevMinKIndex = i;
      }
      if (nums[i] == maxK) {
        prevMaxKIndex = i;
      }

      answer += max(0, min(prevMinKIndex, prevMaxKIndex) - lastInvalid);
    }

    return answer;
  }
};

// Accepted
// 51/51 cases passed (107 ms)
// Your runtime beats 92.65 % of cpp submissions
// Your memory usage beats 90.2 % of cpp submissions (70.4 MB)
// @lc code=end

