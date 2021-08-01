/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

// @lc code=start
class Solution {
public:
  vector<int> mostVisited(int n, vector<int>& rounds) {
    int more = 0;
    for(int i = 1; i < rounds.size(); ++i) {
      more += rounds[i] + n - rounds[i - 1]; 
    }
    more %= n;
    vector<int> answer;
    int begin = rounds.front();
    for(int i = 0; i <= more; ++i) {
      answer.push_back((begin + i + n - 1) % n + 1);
    }
    sort(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 204/204 cases passed (4 ms)
// Your runtime beats 87.2 % of cpp submissions
// Your memory usage beats 64.24 % of cpp submissions (11.2 MB)
// @lc code=end

