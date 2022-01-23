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
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int len = aliceValues.size();
    int indice[len];
    for(int i = 0; i < len; ++i) {
      indice[i] = i;
    }
    sort(indice, indice + len,[&](int a, int b) {
      return aliceValues[a] + bobValues[a] >  aliceValues[b] + bobValues[b];
    });
    int result = 0;
    for(int i = 0; i < len; ++i) {
      if(i & 1) result -= bobValues[indice[i]];
      else result += aliceValues[indice[i]];
    }
    return sgn(result);
  }
};

// Accepted
// 95/95 cases passed (426 ms)
// Your runtime beats 42.08 % of cpp submissions
// Your memory usage beats 98.64 % of cpp submissions (103.1 MB)
// @lc code=end
