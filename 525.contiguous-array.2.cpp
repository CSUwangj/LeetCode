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
    unordered_map<int, int> pos{{0, -1}};
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
// 564/564 cases passed (116 ms)
// Your runtime beats 83.26 % of cpp submissions
// Your memory usage beats 98.62 % of cpp submissions (83.5 MB)
// @lc code=end
