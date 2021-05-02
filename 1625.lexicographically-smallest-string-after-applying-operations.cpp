/*
 * @lc app=leetcode id=1625 lang=cpp
 *
 * [1625] Lexicographically Smallest String After Applying Operations
 */

// @lc code=start
// class Solution {
//   string rotate(string &s, int b) {
//     return s.substr(s.length() - b, b) + s.substr(0, s.length() - b);
//   }
//   void add(string &s, int a) {
//     for(int i = 1; i < s.length(); i += 2) {
//       s[i] = (s[i] - '0' + a) % 10 + '0';
//     }
//   }
//   void dfs(string s, set<string> &vis, int a, int b) {
//     if(vis.count(s)) return;
//     vis.insert(s);
//     dfs(rotate(s, b), vis, a, b);
//     for(int i = 0; i < 9; ++i) {
//       add(s, a);
//       dfs(s, vis, a, b);
//     }
//   }
// public:
//   string findLexSmallestString(string s, int a, int b) {
//     set<string> vis;
//     dfs(s, vis, a, b);
//     return *vis.begin();
//   }
// };
constexpr int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
class Solution {
private:
  void minHalf(string &s, bool odd, int a) {
    char mmin = s[odd];
    int cnt = 0;
    for(int i = 1; i < 10; ++i) {
      char test = (s[odd] - '0' + i * a) % 10 + '0';
      if(test < mmin) {
        mmin = test;
        cnt = i;
      }
    }
    // cout << s << ' ' << cnt << endl;
    if(!cnt) return;
    for(int i = odd; i < s.length(); i += 2) {
      s[i] = (s[i] - '0' + cnt * a) % 10 + '0';
    }
  }
public: 
  string findLexSmallestString(string s, int a, int b) {
    int len = s.length();
    int t = len / gcd(b, len);
    string answer = s;
    for(int i = 0; i < t; ++i) {
      rotate(s.rbegin(), s.rbegin() + b, s.rend());
      string tmp = s;
      if(b & 1) minHalf(tmp, false, a);
      minHalf(tmp, true, a);
      // cout << s << ' ' << tmp << endl;
      answer = min(answer, tmp);
    }
    return answer;
  }
};
// @lc code=end

