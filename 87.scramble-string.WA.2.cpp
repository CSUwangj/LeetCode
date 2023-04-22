/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
unordered_map<string, bool> result;
int cnt[26];
bool sameChars(string &a, string &b) {
  memset(cnt, 0, sizeof(cnt));
  for(auto c : a) {
    cnt[c - 'a'] += 1;
  }
  for(auto c : b) {
    if(!cnt[c - 'a']) return false;
    cnt[c - 'a'] -= 1;
  }
  return true;
}

bool isOk(string a, string b) {
  if(a.length() == 1) return a[0] == b[0];
  if(a == b) return true;
  string key = a + "#" + b;
  if(result.count(key)) return result[key];
  if(!sameChars(a, b)) {
    result[key] = false;
    return false;
  }
  int len = a.length();
  for(int i = 1; i < len - 1; i++) {
    if(isOk(a.substr(0, i), b.substr(0, i)) && isOk(a.substr(i), b.substr(i))) {
      result[key] = true;
      return true;
    }
    if(isOk(a.substr(0, i), b.substr(len - i)) && isOk(a.substr(i), b.substr(0, len - i))) {
      result[key] = true;
      return true;
    }
  }
  result[key] = false;
  return false;
}

class Solution {
public:
  bool isScramble(string a, string b) {
    return isOk(a, b);
  }
};
// @lc code=end

