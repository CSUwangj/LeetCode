/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
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
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, int> words;
    for(auto word : wordList) {
      words[word] = 0;
    }
    words[beginWord] = 1;
    if(!words.count(endWord)) return 0;
    queue<string> q;
    q.push(beginWord);
    while(q.size()) {
      auto cur = q.front();
      q.pop();
      if(cur == endWord) return words[endWord];
      string nxt = cur;
      for(auto &c : nxt) {
        int curChar = c;
        for(int i = 'a'; i <= 'z'; ++i) {
          c = i;
          if(words.count(nxt) && !words[nxt]) {
            words[nxt] = words[cur] + 1;
            q.push(nxt);
          }
        }
        c = curChar;
      }
    }
    return 0;
  }
};

// Accepted
// 50/50 cases passed (121 ms)
// Your runtime beats 75.11 % of cpp submissions
// Your memory usage beats 54.46 % of cpp submissions (14.7 MB)
// @lc code=end
