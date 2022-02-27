/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int answer = !nums.front();
    int count = 0;
    for(auto n : nums) {
      if(answer == n) {
        count += 1;
      } else {
        if(!count) {
          answer = n;
        } else {
          count -= 1;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 47/47 cases passed (20 ms)
// Your runtime beats 77.76 % of cpp submissions
// Your memory usage beats 52.27 % of cpp submissions (19.7 MB)
// @lc code=end
