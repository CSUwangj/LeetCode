/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
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
  vector<int> majorityElement(vector<int>& nums) {
    int elements[2];
    int count[2] = {};
    for(auto c : nums) {
      if(c == elements[0]) {
        count[0] += 1;
      } else if(c == elements[1]) {
        count[1] += 1;
      } else if(!count[0]) {
        elements[0] = c;
        count[0] = 1;
      } else if(!count[1]) {
        elements[1] = c;
        count[1] = 1;
      } else {
        count[0] -= 1;
        count[1] -= 1;
      }
    }
    vector<int> answer;
    for(auto candidate : elements) {
      int count = 0;
      for(auto i : nums) {
        count += i == candidate;
      }
      if(count * 3 > nums.size()) {
        answer.push_back(candidate);
      }
    }
    return answer;
  }
};

// Accepted
// 82/82 cases passed (12 ms)
// Your runtime beats 73.07 % of cpp submissions
// Your memory usage beats 46.99 % of cpp submissions (15.9 MB)
// @lc code=end

