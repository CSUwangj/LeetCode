/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
class Solution {
  int pairs(const vector<int> &nums, int diff) {
    int count = 0;
    for(int i = 0; i < nums.size() - 1; ++i) {
      if(nums[i + 1] - nums[i] <= diff) {
        count += 1;
        i += 1;
      }
    }
    return count;
  }
public:
  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums.back() - nums.front();
    while(high > low) {
      int mid = (high + low) / 2;
      if(pairs(nums, mid) < p) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 103/103 cases passed (140 ms)
// Your runtime beats 88.53 % of cpp submissions
// Your memory usage beats 82.46 % of cpp submissions (81.08 MB)
// @lc code=end

