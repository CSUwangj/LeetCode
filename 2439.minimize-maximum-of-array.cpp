/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
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
  int minimizeArrayValue(vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    double average = 1.0 * sum / nums.size();
    long long current_sum = 0;
    int answer = ceil(average);
    for(int i = 0; i < nums.size(); ++i) {
      current_sum += nums[i];
      if(average * (i + 1) < current_sum) {
        answer = max<int>(answer, (current_sum + i) / (i + 1));
      }
    }
    return answer;
  }
};

// Accepted
// 68/68 cases passed (100 ms)
// Your runtime beats 98.83 % of cpp submissions
// Your memory usage beats 99 % of cpp submissions (70.4 MB)
// @lc code=end

