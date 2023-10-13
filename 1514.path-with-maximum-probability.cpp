/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution {
public:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<double> distance(n);
    distance[start] = 1;
    int len = edges.size();
    for(int loop = 0; loop < len; ++loop) {
      bool modified = false;
      for(int i = 0; i < len; ++i) {
        int a = edges[i][0];
        int b = edges[i][1];
        double prob = succProb[i];
        if(distance[b]*prob > distance[a]) {
          distance[a] = distance[b]*prob;
          modified = true;
        }
        if(distance[a]*prob > distance[b]) {
          distance[b] = distance[a]*prob;
          modified = true;
        }
      }
      if(!modified) break;
    }
    return distance[end];
  }
};

// Accepted
// 18/18 cases passed (170 ms)
// Your runtime beats 99.13 % of cpp submissions
// Your memory usage beats 99.42 % of cpp submissions (49.2 MB)
// @lc code=end

