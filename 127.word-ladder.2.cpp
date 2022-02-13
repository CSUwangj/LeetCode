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
  unordered_set<string> dictionary;
  int len;
  int BBFS(
    unordered_set<string> &sourceSet,
    unordered_set<string> &targetSet,
    unordered_set<string> &nextSet,
    int length
  ) {
    nextSet.clear();
    
    for(auto &s : sourceSet) dictionary.erase(s);
    
    for(auto &s : sourceSet) {
      for(int i = 0; i < len ; ++i) {
        string newWord = s;
        for(char c = 'a'; c <= 'z'; ++c) {
          newWord[i] = c;
          if(targetSet.count(newWord)) return length+1;
          if(dictionary.count(newWord)) nextSet.insert(newWord);
        }
      }
    }
    if(!nextSet.size()) return 0;
    
    if(nextSet.size() < targetSet.size()) return BBFS(nextSet, targetSet, sourceSet, length+1);
    return BBFS(targetSet, nextSet, sourceSet, length+1);
  }
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    len = endWord.length();
    for(auto &s : wordList) if(s.length() == len) dictionary.insert(s);
    if(!dictionary.count(endWord)) return 0;
    
    unordered_set<string> beginSet;
    beginSet.insert(beginWord);
    unordered_set<string> endSet;
    endSet.insert(endWord);
    unordered_set<string> nextSet;
    
    return BBFS(beginSet, endSet, nextSet, 1);
  }
};

// Accepted
// 50/50 cases passed (20 ms)
// Your runtime beats 99.98 % of cpp submissions
// Your memory usage beats 54.46 % of cpp submissions (14.7 MB)
// @lc code=end
