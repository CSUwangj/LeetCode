/*
 * @lc app=leetcode id=2366 lang=cpp
 *
 * [2366] Minimum Replacements to Sort the Array
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
  long long minimumReplacement(vector<int>& nums) {
    int last = nums.back();
    long long answer = 0;
    for(int i = nums.size() - 2; i >= 0 ;--i) {
      if(nums[i] > last) {
        int parts = nums[i] / last;
        if(nums[i] % last) parts += 1;
        last = nums[i] / parts;
        answer += parts - 1;
      } else {
        last = nums[i];
      }
    }

    return answer;
  }
};

// Accepted
// 47/47 cases passed (49 ms)
// Your runtime beats 99.7 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (54 MB)
// @lc code=end

