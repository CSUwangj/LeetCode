/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
  bool isPredecessor(string &shorterWord, string &longerWord) {
    bool skip = false;
    int len = shorterWord.length();
    int pos = 0;
    while(pos < len) {
      if(skip && shorterWord[pos] != longerWord[pos + 1]) return false;
      if(shorterWord[pos] == longerWord[pos + skip]) pos += 1;
      else skip = true;
    }
    return true;
  }
public:
  int longestStrChain(vector<string>& words) {
    vector<string> strs[17];
    for(auto &word : words) {
      strs[word.length()].push_back(word);
    }
    unordered_map<string, int> len;
    int answer = 1;
    for(int i = 1; i < 17; ++i) {
      for(auto &longerWord : strs[i]) {
        for(auto &shorterWord : strs[i - 1]) {
          if(isPredecessor(shorterWord, longerWord)) {
            len[longerWord] = max(len[shorterWord] + 1, len[longerWord]);
            answer = max(answer, len[longerWord] + 1);
          }
        }
      }
    }
    return answer;
  }
};
// @lc code=end

