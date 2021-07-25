/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<string, vector<string>> neighbors;
  vector<string> cur;
public:
  void backtrack(
    vector<vector<string>> &answer,
    vector<string> &cur,
    string beginWord,
    string &endWord
    ) {
      if (beginWord == endWord) {
        answer.push_back(cur);
        return;
      }
      for (int i = 0; i < neighbors[beginWord].size(); i++) {
        cur.push_back(neighbors[beginWord][i]);
        backtrack(answer, cur, neighbors[beginWord][i], endWord);
        cur.pop_back();
      }
  }
  
  void init(string beginWord, string endWord, unordered_set<string> &dict) {
    queue<string> q;
    q.push(beginWord);
    if(dict.count(beginWord)) {
      dict.erase(beginWord);
    }
    while(!q.empty())  {
      unordered_set<string> visited;
      while(!q.empty()){
        string cur = q.front(); 
        q.pop();
        string temp = cur;
        for(int i = 0; i < cur.size(); ++i){
          char c = cur[i];
          for(int j = 'a'; j <= 'z'; ++j){
            cur[i] = j;
            if(dict.count(cur)){
              visited.insert(cur);
              neighbors[temp].push_back(cur);
            }
          }
          cur[i] = c;
        }
      }
      if(visited.find(endWord) != visited.end()) break;
      for(auto word : visited) {
        q.push(word);
        dict.erase(word);
      }
    }
  }
  
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    init(beginWord, endWord, dict);
    vector<vector<string>> answer;
    vector<string> container{beginWord};
    backtrack(answer, container, beginWord, endWord); 
    return answer;
  }
};

// Accepted
// 32/32 cases passed (8 ms)
// Your runtime beats 94.58 % of cpp submissions
// Your memory usage beats 81.36 % of cpp submissions (9 MB)
// @lc code=end

