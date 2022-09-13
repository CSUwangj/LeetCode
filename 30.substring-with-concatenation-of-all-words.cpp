/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> cnt;
    int wordLen = words[0].length();
    int total = words.size();
    int slen = s.length();
    for(auto &word : words) {
      cnt[word] += 1;
    }
    vector<int> answer;
    for(int i = 0; i <= slen - total*wordLen; ++i) {
      if(cnt.count(s.substr(i, wordLen))) {
        int rest = total;
        unordered_map<string, int> cur = cnt;
        int pos = i;
        string curWord = s.substr(pos, wordLen);
        do {
          cur[curWord] -= 1;
          rest -= 1;
          if(!cur[curWord]) cur.erase(curWord);
          pos += wordLen;
          curWord = s.substr(pos, wordLen);
        }while(rest && cur.count(curWord));
        if(rest == 0) {
          answer.push_back(i);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 178/178 cases passed (329 ms)
// Your runtime beats 61.92 % of cpp submissions
// Your memory usage beats 54.83 % of cpp submissions (26.2 MB)
// @lc code=end

