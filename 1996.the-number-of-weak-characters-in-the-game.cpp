/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
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
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b){
      return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    int mmax = 0;
    int cur = 0;
    int curMax = 0;
    int answer = 0;
    for(const auto &property : properties) {
      if(property[0] != cur) {
        cur = property[0];
        mmax = max(mmax, curMax);
        curMax = property[1];
      }
      if(property[1] < mmax) {
        answer += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 44/44 cases passed (1242 ms)
// Your runtime beats 37.02 % of cpp submissions
// Your memory usage beats 99.91 % of cpp submissions (124.7 MB)
// @lc code=end

