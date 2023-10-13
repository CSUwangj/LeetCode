/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
int qpow(int b, int e) {
  int result = 1;
  while(e) {
    if(e & 1) {
      result = 1LL * result * b % MOD;
    }
    b = 1LL * b * b % MOD;
    e >>= 1;
  }
  return result;
}
class Solution {
public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int answer = 0;
    while(left <= right && left < nums.size()) {
      while(right >= 0 && left <= right && nums[left] + nums[right] > target) {
        right -= 1;
      }
      if(right < 0) break;
      if(left < right) {
        answer += qpow(2, right - left);
      } else if (nums[left] * 2 <= target) {
        answer += 1;
      }
      answer %= MOD;
      left += 1;
    }

    return answer;
  }
};

// Accepted
// 62/62 cases passed (126 ms)
// Your runtime beats 89.87 % of cpp submissions
// Your memory usage beats 93.20 % of cpp submissions (47.6 MB)
// @lc code=end

