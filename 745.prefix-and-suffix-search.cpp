/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 */

// @lc code=start
class WordFilter {
  map<string, string> idx;
  unordered_map<string, int> ans;
public:
    WordFilter(vector<string>& words) {
      int cnt = 0;
      for(auto &word : words) {
        ans[word] = cnt++;
        int len = word.length();
        for(int i = 1; i <= len; ++i) {
          idx[word.substr(len - i) + "?" + word] = word;
        }
      }
    }
    
    int f(string prefix, string suffix) {
      auto target = suffix + "?" + prefix;
      auto it = idx.lower_bound(target);
      int answer = -1;
      while(it != idx.end() && it->first.rfind(target, 0) == 0) {
        answer = max(answer, ans[it->second]);
        ++it;
      }
      return answer;
    }
};

// Accepted
// 13/13 cases passed (713 ms)
// Your runtime beats 52.99 % of cpp submissions
// Your memory usage beats 90.67 % of cpp submissions (108.8 MB)
// @lc code=end

