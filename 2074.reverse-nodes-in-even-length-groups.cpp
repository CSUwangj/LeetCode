/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start
class Solution {
public:
  int minimumAverageDifference(vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    long long front = 0;
    long long back = sum;
    int answer = 0;
    int current = INT_MAX;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      front += nums[i];
      back -= nums[i];
      int frontAvarage = front / (i + 1);
      int backAvarage = back ? back / (len - i - 1) : 0;
      int diff = abs(frontAvarage - backAvarage);
      if(diff < current) {
        answer = i;
        current = diff;
      }
    }
    return answer;
  }
};

// Accepted
// 78/78 cases passed (167 ms)
// Your runtime beats 72.25 % of cpp submissions
// Your memory usage beats 76.81 % of cpp submissions (78.4 MB)
// @lc code=end

