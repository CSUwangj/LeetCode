/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
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
  int maxSubarraySumCircular(vector<int>& nums) {
    map<int, queue<int>> sums;
    sums[0].push(-1);
    int len = nums.size();
    int sum = 0;
    int answer = INT_MIN;
    for(int i = 0; i < len; ++i) {
      sum += nums[i];
      answer = max(answer, sum - sums.begin()->first);
      sums[sum].push(i);
    }
    for(int i = 0; i < len; ++i) {
      sum += nums[i];
      while(sums.begin()->second.front() < i) {
        sums.begin()->second.pop();
        if(sums.begin()->second.empty()) {
          sums.erase(sums.begin());
        }
      }
      answer = max(answer, sum - sums.begin()->first);
      sums[sum].push(i + len);
    }
    return answer;
  }
};

// Accepted
// 111/111 cases passed (1034 ms)
// Your runtime beats 5.07 % of cpp submissions
// Your memory usage beats 5.01 % of cpp submissions (457.3 MB)
// @lc code=end

