/*
 * @lc app=leetcode id=1096 lang=cpp
 *
 * [1096] Brace Expansion II
 */

// @lc code=start
class Solution {
public:
  vector<string> braceExpansionII(string expression) {
    vector<set<string>> st;
    set<string> cur{""};
    set<string> res;
    set<string> tmp;
    set<string> pre;
    set<string> preRes;
    for(auto c : expression) {
      switch(c) {
        case '{':
          st.push_back(cur);
          st.push_back(res);
          cur = {""};
          res.clear();
          break;
        case '}':
          if(cur.begin()->length() != 0) {
            res.merge(cur);
            cur = {""};
          }
          preRes = st.back();
          st.pop_back();
          pre = st.back();
          st.pop_back();
          cur.clear();
          for(auto resE : res) {
            for(auto preE : pre) {
              cur.insert(preE + resE);
            }
          }
          res = preRes;
          break;
        case ',':
          res.merge(cur);
          cur = {""};
          break;
        default:
          tmp.clear();
          for(auto &s : cur) {
            tmp.insert(s + c);
          }
          swap(cur, tmp);
      }
    }
    if(cur.begin()->length() != 0) {
      res.merge(cur);
    }
    return vector<string>(res.begin(), res.end());
  }
};
// @lc code=end

