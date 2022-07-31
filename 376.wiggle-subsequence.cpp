/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
template <class T>
inline constexpr int sgn(const T &a) {
  return a > 0 ? 1  :
         a < 0 ? -1 :
         0;
}
class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int len = nums.size();
    if(len < 2) return len;
    
    int pos = 1;
    
    // all same
    while(pos < len && nums[pos] == nums[pos - 1]) pos += 1;
    if(pos == len) return 1;
    
    int answer = 2;
    int sign = sgn(nums[pos] - nums[pos - 1]);
    pos += 1;
    while(pos < len) {
      while(pos < len && sgn(sign + sgn(nums[pos] - nums[pos - 1])) == sign) {
        pos += 1;
      }
      if(pos < len) {
        sign = -sign;
        pos += 1;
        answer += 1;
      }
    }
    
    return answer;
  }
};

// Accepted
// 26/26 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.45 % of cpp submissions (7 MB)
// @lc code=end

