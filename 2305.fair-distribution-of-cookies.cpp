/*
 * @lc app=leetcode id=2305 lang=cpp
 *
 * [2305] Fair Distribution of Cookies
 */

// @lc code=start
class Solution {
  void solve(
    int position,
    int k,
    int &answer,
    vector<int> &children,
    const vector<int>& cookies
  ) {
    int current = *max_element(children.begin(), children.end());
    if(position == cookies.size()) {
      answer = min(answer, current);
      return;
    }
    if(answer <= current) {
      return;
    }

    for(int i = 0; i < k; ++i) {
      children[i] += cookies[position];
      solve(position + 1, k, answer, children, cookies);
      children[i] -= cookies[position];
      if(children[i] == 0) break;
    }
  }
public:
  int distributeCookies(vector<int>& cookies, int k) {
    vector<int> children(k);
    int answer = INT_MAX;
    solve(0, k, answer, children, cookies);

    return answer;
  }
};

// Accepted
// 38/38 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 23.11 % of cpp submissions (6.9 MB)
// @lc code=end

