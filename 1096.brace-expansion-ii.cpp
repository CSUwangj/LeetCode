/*
 * @lc app=leetcode id=1096 lang=cpp
 *
 * [1096] Brace Expansion II
 */

// @lc code=start
int len;
vector<string> solve(string &expression, int &index) {
  vector<string> result;
  vector<string> cur = {""};
  while(index < len) {
    char c = expression[index];
    index += 1;
    if(c == '}') {
      break;
    }
    if(c == ',') {
      result.insert(
        result.end(), 
        make_move_iterator(cur.begin()),
        make_move_iterator(cur.end())
      );
      cur = {""};
    } else if(isalpha(c)) {
      for(auto &s : cur) {
        s.push_back(c);
      }
    } else if(c == '{') {
      vector<string> next;
      for(auto &res : solve(expression, index)) {
        for(auto &s : cur) {
          next.push_back(s + res);
        }
      }
      swap(next, cur);
    }
  }
  if(cur.front().length()) {
    result.insert(
        result.end(), 
        make_move_iterator(cur.begin()),
        make_move_iterator(cur.end())
    );
  }
  return result;
}

class Solution {
public:
  vector<string> braceExpansionII(string expression) {
    len = expression.length();
    int index = 0;
    auto answer = solve(expression, index);
    sort(answer.begin(), answer.end());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};
// @lc code=end

