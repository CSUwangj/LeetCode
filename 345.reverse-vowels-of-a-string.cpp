/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int vowel[128] = {
  ['A'] = 1,
  ['E'] = 1,
  ['I'] = 1,
  ['O'] = 1,
  ['U'] = 1,
  ['a'] = 1,
  ['e'] = 1,
  ['i'] = 1,
  ['o'] = 1,
  ['u'] = 1
};
class Solution {
public:
  string reverseVowels(string s) {
    int front = 0;
    int back = s.length() - 1;
    while(front < back) {
      while(!vowel[s[front]] && front != back) {
        front += 1;
      }
      while(!vowel[s[back]] && front != back) {
        back -= 1;
      }
      swap(s[front], s[back]);
      front += 1;
      back -= 1;
    }
    return s;
  }
};

// Accepted
// 480/480 cases passed (12 ms)
// Your runtime beats 67.07 % of cpp submissions
// Your memory usage beats 32.73 % of cpp submissions (8 MB)
// @lc code=end

