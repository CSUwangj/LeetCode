/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
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
  int findMaxLength(vector<int>& nums) {
    int all = 0;
    int one = 0;
    int answer = 0;
    map<int, int> pos{{0, -1}};
    for(auto n : nums) {
      if(n) {
        one += 1;
      } else {
        one -= 1;
      }
      if(pos.count(one)) {
        answer = max(answer, all - pos[one]);
      } else {
        pos[one] = all;
      }
      all += 1;
    }
    return answer;
  }
};

// Accepted
// 564/564 cases passed (212 ms)
// Your runtime beats 32.57 % of cpp submissions
// Your memory usage beats 14.46 % of cpp submissions (84.3 MB)
// @lc code=end
