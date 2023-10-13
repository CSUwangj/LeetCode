/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
class Solution {
public:
  vector<int> getAverages(vector<int>& nums, int k) {
    if(2 * k + 1 > nums.size()) return vector<int>(nums.size(), -1);
    vector<int> answer(nums.size());
    long long sum = 0;
    for(int i = 0; i < k; ++i) {
      answer[i] = -1;
      sum += nums[2 * i];
      sum += nums[2 * i + 1];
    }
    for(int i = k; i < nums.size(); ++i) {
      if(i + k >= nums.size()) {
        answer[i] = -1;
        continue;
      }
      sum += nums[i + k];
      answer[i] = sum / (2 * k + 1);
      sum -= nums[i - k];
    }

    return answer;
  }
};

// Accepted
// 39/39 cases passed (251 ms)
// Your runtime beats 70.05 % of cpp submissions
// Your memory usage beats 66.09 % of cpp submissions (130 MB)
// @lc code=end

