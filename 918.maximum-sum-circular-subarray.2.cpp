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
    map<int, int> sumsCount;
    queue<int> sums;
    sumsCount[0] += 1;
    sums.push(0);
    int len = nums.size();
    int sum = 0;
    int answer = INT_MIN;
    for(int i = 0; i < len; ++i) {
      sum += nums[i];
      answer = max(answer, sum - sumsCount.begin()->first);
      sums.push(sum);
      sumsCount[sum] += 1;
    }
    for(int i = 0; i < len; ++i) {
      sum += nums[i];
      while(sums.size() > len) {
        sumsCount[sums.front()] -= 1;
        if(!sumsCount[sums.front()]) {
          sumsCount.erase(sums.front());
        }
        sums.pop();
      }
      answer = max(answer, sum - sumsCount.begin()->first);
      sums.push(sum);
      sumsCount[sum] += 1;
    }
    return answer;
  }
};

// Accepted
// 111/111 cases passed (443 ms)
// Your runtime beats 5.07 % of cpp submissions
// Your memory usage beats 5.01 % of cpp submissions (89.8 MB)
// @lc code=end

