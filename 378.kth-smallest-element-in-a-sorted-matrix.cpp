/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    if(k == 1) return matrix.front().front();
    if(k == n * n) return matrix.back().back();
    priority_queue<int> pq;
    for(auto &row : matrix) {
      for(auto i : row) {
        pq.push(i);
        while(pq.size() > k) pq.pop();
      }
    }
    return pq.top();
  }
};

// Accepted
// 85/85 cases passed (36 ms)
// Your runtime beats 54.31 % of cpp submissions
// Your memory usage beats 33.33 % of cpp submissions (14.3 MB)
// @lc code=end

