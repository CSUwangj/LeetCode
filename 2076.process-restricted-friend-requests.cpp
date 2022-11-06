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
    for(const auto &word : words) {
      count[word[0] - 'a'][word[1] - 'a'] += 1;
    }
    int answer = 0;
    for(int first = 0; first < 25; ++first) {
      for(int second = first + 1; second < 26; ++second) {
        if(count[first][second] && count[second][first]) {
          answer += min(count[first][second], count[second][first]) * 4;
        }
      }
    }
    bool hasMid = false;
    for(int i = 0; i < 26; ++i) {
      answer += (count[i][i] & (INT_MAX - 1)) * 2;
      hasMid |= count[i][i] & 1;
    }
    answer += hasMid * 2;
    return answer;
  }
};

// Accepted
// 120/120 cases passed (411 ms)
// Your runtime beats 90.95 % of cpp submissions
// Your memory usage beats 100.00 % of cpp submissions (166.9 MB)
// @lc code=end

