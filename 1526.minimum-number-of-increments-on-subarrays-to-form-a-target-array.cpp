/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
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
  int minNumberOperations(vector<int>& target) {
    int prev = 0;
    int answer = 0;
    for(auto num : target) {
      if(num > prev) {
        answer += num - prev;
      }
      prev = num;
    }
    return answer;
  }
};

// Accepted
// 129/129 cases passed (68 ms)
// Your runtime beats 99.77 % of cpp submissions
// Your memory usage beats 58.96 % of cpp submissions (73.1 MB)
// @lc code=end

