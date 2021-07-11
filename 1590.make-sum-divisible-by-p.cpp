/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    for(auto &i : nums) i %= p;
    int sum = accumulate(nums.begin(), nums.end(), 0, [=](int a, int b) { 
      return (a + b) % p;
    });
    if(!sum) return 0;
    unordered_map<int, int> prefix{{0, -1}};
    int len = nums.size();
    int invTarget = p - sum;
    int curSum = 0;
    int answer = len;
    for(int i = 0; i < len; ++i) {
      curSum += nums[i];
      curSum %= p;
      if(prefix.count((curSum + invTarget) % p)) {
        answer = min(answer, i - prefix[(curSum + invTarget) % p]);
      }
      prefix[curSum] = i;
    }

    return answer == len ? -1 : answer;
  }
};
// @lc code=end
