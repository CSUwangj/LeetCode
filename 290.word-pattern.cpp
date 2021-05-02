/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
  int countWords(string &s) {
    bool isSpace = true;
    int result = 0;
    for(auto c : s) {
      result += (c != ' ') * isSpace;
      isSpace = c == ' ';
    }
    return result;
  }
  string nextWord(string &s, int &index) {
    while(s[index] == ' ') index += 1;
    int len = 0;
    while(index + len < s.length() && s[index + len] != ' ') len += 1;
    index += len;
    return s.substr(index - len, len);
  }
public:
  bool wordPattern(string pattern, string s) {
    if(pattern.length() != countWords(s)) return false;
    unordered_map<char, string> mp;
    unordered_map<string, int> cnt;
    int pos = 0;
    for(auto c : pattern) {
      auto word = nextWord(s, pos);
      if(mp.count(c) && mp[c] != word) return false;
      if(!mp.count(c)){
        mp[c] = word;
        cnt[word] += 1;
      } 
    }
    for(auto [_word, c] : cnt) if(c > 1) return false;
    return true;
  }
};
// @lc code=end

