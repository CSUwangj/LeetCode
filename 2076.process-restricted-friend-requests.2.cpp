/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
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
  int longestPalindrome(vector<string>& words) {
    int count[26][26] = {};
    int answer = 0;
    for(const auto &word : words) {
      int a = word[0] - 'a';
      int b = word[1] - 'a';
      if(count[b][a]) {
        answer += 4;
        count[b][a] -= 1;
      } else {
        count[a][b] += 1;
      }
    }
    for(int i = 0; i < 26 ; ++i) {
      if(count[i][i]) {
        answer += 2;
        break; 
      }
    }
    return answer;
  }
};

// Accepted
// 120/120 cases passed (447 ms)
// Your runtime beats 87.23 % of cpp submissions
// Your memory usage beats 100.00 % of cpp submissions (166.9 MB)
// @lc code=end

