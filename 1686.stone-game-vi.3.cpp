\/*
 * @lc app=leetcode id=1686 lang=cpp
 *
 * [1686] Stone Game VI
 */

// @lc code=start
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
class Solution {
public:
  int stoneGameVI(vector<int>& a, vector<int>& b) {
    int len = a.size();
    vector<vector<int>> indice(201);
    for(int i = 0; i < len; ++i) {
      indice[a[i] + b[i]].push_back(i);
    }
    int stones[2] = {};
    int turn = 0;
    for(int i = 200; i >= 0; --i) {
      for(auto index : indice[i]) {
        stones[turn] += turn ? b[index] : a[index];
        turn = !turn;
      }
    }
    return sgn(stones[0] - stones[1]);
  }
};

// Accepted
// 95/95 cases passed (104 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 79.19 % of cpp submissions (111.9 MB)
// @lc code=end
