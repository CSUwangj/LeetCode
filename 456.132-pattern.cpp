/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
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
  bool find132pattern(vector<int>& nums) {
    if(nums.size() < 3) return false;
    stack<int> three;
    int two = INT_MIN;
    three.push(nums.back());
    for(int i = nums.size()-1; i >=0 ; --i) {
      if(nums[i] < two) return true;
      while(three.size() && three.top() < nums[i]) {
        two = three.top();
        three.pop();
      }
      three.push(nums[i]);
    }
    return false;
  }
};

// Accepted
// 102/102 cases passed (60 ms)
// Your runtime beats 99.08 % of cpp submissions
// Your memory usage beats 98.98 % of cpp submissions (37.4 MB)
// @lc code=end

