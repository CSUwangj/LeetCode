/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<int, int> count;
public:
  int maxOperations(vector<int>& nums, int k) {
    for(auto i : nums) count[i] += 1;
    int answer = 0;
    for(auto [num, cnt] : count) {
      if(!count.count(k-num)) continue;
      answer += min(cnt, count[k-num]);
    }
    answer /= 2;
    return answer;
  }
};

// Accepted
// 51/51 cases passed (149 ms)
// Your runtime beats 82.22 % of cpp submissions
// Your memory usage beats 31.86 % of cpp submissions (68.4 MB)
// @lc code=end

