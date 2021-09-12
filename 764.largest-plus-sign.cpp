/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
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
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    int left[n][n];
    int up[n][n];
    int right[n][n];
    int down[n][n];
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        left[i][j] = 1;
        up[i][j] = 1;
        right[i][j] = 1;
        down[i][j] = 1;
      }
    }
    for(auto &mine : mines) {
      left[mine[0]][mine[1]] = 0; 
      up[mine[0]][mine[1]] = 0; 
      right[mine[0]][mine[1]] = 0;
      down[mine[0]][mine[1]] = 0;
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(left[i][j] && j) {
          left[i][j] = left[i][j - 1] + 1;
        }
        if(up[i][j] && i) {
          up[i][j] = up[i - 1][j] + 1;
        }
      }
    }
    for(int i = n - 1; i >= 0; --i) {
      for(int j = n - 1; j >= 0; --j) {
        if(right[i][j] && j != n - 1) {
          right[i][j] = right[i][j + 1] + 1;
        }
        if(down[i][j] && i != n - 1) {
          down[i][j] = down[i + 1][j] + 1;
        }
      }
    }
    int answer = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        answer = max(answer, min({left[i][j], right[i][j], up[i][j], down[i][j]}));
      }
    }
    return answer;
  }
};

// Accepted
// 56/56 cases passed (108 ms)
// Your runtime beats 94.04 % of cpp submissions
// Your memory usage beats 89.94 % of cpp submissions (21.9 MB)
// @lc code=end

