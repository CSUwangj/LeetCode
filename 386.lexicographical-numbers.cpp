/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
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
  vector<int> lexicalOrder(int n) {
    int curInt = 1;
    vector<int> answer{1};
    while(answer.size() < n) {
      if(curInt * 10 <= n) {
        curInt *= 10;
        answer.push_back(curInt);
      } else {
        while(curInt % 10 == 9 || curInt == n) {
          int count = 1;
          curInt /= 10;
        }
        curInt += 1;
        answer.push_back(curInt);
      }
    }

    return answer;
  }
};

// Accepted
// 26/26 cases passed (8 ms)
// Your runtime beats 82.37 % of cpp submissions
// Your memory usage beats 81.38 % of cpp submissions (11 MB)
// @lc code=end

