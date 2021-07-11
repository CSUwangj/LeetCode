/*
 * @lc app=leetcode id=1805 lang=cpp
 *
 * [1805] Number of Different Integers in a String
 */

// @lc code=start
class Solution {
  string getNumber(const string &s, int &pos) {
    string result;
    int len = s.length();
    while(pos < len && s[pos] == '0') pos += 1;
    while(pos < len && isdigit(s[pos])) {
      result.push_back(s[pos]);
      pos += 1;
    }
    if(result.length() > 0) return result;
    return "0";
  }
public:
  int numDifferentIntegers(string word) {
    int pos = 0;
    int len = word.length();
    unordered_set<string> st;
    while(pos < len) {
      while(pos < len && !isdigit(word[pos])) pos += 1;
      if(pos < len) st.insert(getNumber(word, pos));
    }

    return st.size();
  }
};
// @lc code=end

