/*
 * @lc app=leetcode id=854 lang=cpp
 *
 * [854] K-Similar Strings
 */

// @lc code=start
// class Solution {
//   int realKSimilarity(string s1, string s2) {
//     queue<string> q;
//     q.push(s1);
//     unordered_set<string> vis;
//     int count = -1;
//     while(q.size()) {
//       int sz = q.size();
//       count += 1;
//       while(sz--) {
//         string s = q.front();
//         q.pop();
//         if(s == s2) return count;
//         for(int i = count; i < s.length(); ++i) {
//           for(int j = i + 1; j < s.length(); ++j) {
//             swap(s[i], s[j]);
//             if(!vis.count(s) && s[count] == s2[count]) {
//               q.push(s);
//               vis.insert(s);
//             }
//             swap(s[i], s[j]);
//           }
//         }
//       }      
//     }
//     return -1;
//   }
// public:
//   int kSimilarity(string s1, string s2) {
//     if(s1 == s2) return 0;
//     string ns1, ns2;
//     for(int i = 0; i < s1.length(); ++i) {
//       if(s1[i] != s2[i]) {
//         ns1.push_back(s1[i]);
//         ns2.push_back(s2[i]);
//       }
//     }
//     return realKSimilarity(ns1, ns2);
//   }
// };
const int MAX = 400;
class Solution {
public:
  int kSimilarity(string s1, string s2) {
    int len = s1.length();
    for(int i = 0; i < len; ++i) {
      if(s1[i] == s2[i]) continue;
      for(int j = i + 1; j < len; ++j) {
        if(s1[i] == s2[j] && s1[j] == s2[i]) {
          swap(s1[i], s1[j]);
          return 1 + kSimilarity(s1.substr(i + 1), s2.substr(i + 1));
        }
      }
      int answer = MAX;
      for(int j = i + 1; j < len; ++j) {
        if(s1[j] == s2[i] && s1[j] != s2[j]) {
          swap(s1[i], s1[j]);
          answer = min(answer, 1 + kSimilarity(s1.substr(i + 1), s2.substr(i + 1)));
          swap(s1[i], s1[j]);
        }
      }
      return answer;
    }
    return 0;
  }
};
// @lc code=end

