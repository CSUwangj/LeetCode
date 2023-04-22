/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
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
  string simplifyPath(string path) {
    string cur;
    vector<string> folders;
    path.push_back('/');
    for(auto c : path) {
      if(c == '/') {
        if(cur == "..") {
          if(folders.size()) folders.pop_back();
        } else if (cur.length() && cur != ".") {
          folders.push_back(cur);
        }
        cur.clear();
      } else {
        cur.push_back(c);
      }
    }


    if(folders.empty()) return "/";

    string answer;
    for(auto &folder : folders) {
      answer.push_back('/');
      answer += folder;
    }
    return answer;
  }
};

// Accepted
// 258/258 cases passed (4 ms)
// Your runtime beats 78.99 % of cpp submissions
// Your memory usage beats 85.65 % of cpp submissions (7.8 MB)
// @lc code=end
