/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void solve(
    vector<vector<int>> &answer,
    vector<int> &tmp,
    vector<int> &candidates,
    int index,
    int rest
  ) {
    if(!rest) {
      answer.push_back(tmp);
      return;
    }
    if(index == candidates.size()) return;
    int curSize = tmp.size();
    while(rest >= 0) {
      solve(answer, tmp, candidates, index + 1, rest);
      rest -= candidates[index];
      tmp.push_back(candidates[index]);
    }
    while(curSize < tmp.size()) tmp.pop_back();
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int> tmp;
    solve(answer, tmp, candidates, 0, target);
    return answer;
  }
};

// Accepted
// 170/170 cases passed (6 ms)
// Your runtime beats 80.84 % of cpp submissions
// Your memory usage beats 46.83 % of cpp submissions (11.2 MB)
// @lc code=end
