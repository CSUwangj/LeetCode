/*
 * @lc app=leetcode id=1096 lang=cpp
 *
 * [1096] Brace Expansion II
 */

// @lc code=start
class Solution {
public:
  vector<string> braceExpansionII(string expression) {
    vector<vector<string>> st;
    vector<string> cur{""};
    vector<string> res;
    for(auto c : expression) {
      switch(c) {
        case '{':
          st.push_back(cur);
          st.push_back(res);
          cur = {""};
          res.clear();
          break;
        case '}':
          {
            if(cur[0].length() != 0) {
              res.insert(
                res.end(), 
                make_move_iterator(cur.begin()),
                make_move_iterator(cur.end())
              );
            }
            auto preRes = st.back();
            st.pop_back();
            auto pre = st.back();
            st.pop_back();
            cur.clear();
            for(auto resE : res) {
              for(auto preE : pre) {
                cur.push_back(preE + resE);
              }
            }
            res = preRes;
          }
          break;
        case ',':
          res.insert(
            res.end(), 
            make_move_iterator(cur.begin()),
            make_move_iterator(cur.end())
          );
          cur = {""};
          break;
        default:
          for(auto &s : cur) {
            s.push_back(c);
          }
      }
    }
    if(cur[0].length() != 0) {
      res.insert(
        res.end(), 
        make_move_iterator(cur.begin()),
        make_move_iterator(cur.end())
      );
    }
    set<string> s(res.begin(), res.end());
    return vector<string>(s.begin(), s.end());
  }
};
// @lc code=end

