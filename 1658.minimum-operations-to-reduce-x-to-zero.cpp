/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    unordered_map<int, int> sumLeft, sumRight;
    int len = nums.size();
    int sum = 0;
    for(int i = 0; i < len; ++i) {
      sum += nums[i];
      sumLeft[sum] = i+1;
    }
    sumLeft[0] = 0;
    sum = 0;
    for(int i = 1; i <= len; ++i) {
      sum += nums[len-i];
      sumRight[sum] = i;
    }
    sumRight[0] = 0;
    
    int answer = INT_MAX;
    for(auto [sum, cnt] : sumLeft) {
      if(sumRight.count(x-sum) && cnt+sumRight[x-sum] <= len) answer = min(answer, cnt+sumRight[x-sum]);
    }
    return answer == INT_MAX ? -1 : answer;
  }
};

// Accepted
// 93/93 cases passed (1576 ms)
// Your runtime beats 5.09 % of cpp submissions
// Your memory usage beats 5.08 % of cpp submissions (237.8 MB)
// @lc code=end

