/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
  void solve(
    vector<vector<int>> &answer,
    vector<int> &tmp,
    int index,
    int rest,
    int k
  ) {
    if(rest == 0 && tmp.size() == k) {
      answer.push_back(tmp);
      return;
    }
    if(tmp.size() >= k || index > 9 || index > rest) return;
    solve(answer, tmp, index + 1, rest, k);
    rest -= index;
    tmp.push_back(index);
    solve(answer, tmp, index + 1, rest, k);
    tmp.pop_back();
  }
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> answer;
    vector<int> tmp;
    solve(answer, tmp, 1, n, k);
    return vector<vector<int>>(answer.begin(), answer.end());
  }
};

// Accepted
// 18/18 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.91 % of cpp submissions (6.8 MB)
// @lc code=end

