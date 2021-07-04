/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix.front().size(); 
    // cout << "---------------" << endl;
    vector<vector<int>> prefix(rows, vector<int>(cols + 1));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        prefix[i][j + 1] = prefix[i][j] + matrix[i][j];
      }
    }

    int answer = INT_MIN;
    for(int i = 0; i < cols; ++i) {
      for(int j = i + 1; j <= cols; ++j) {
        set<int> tmp{0};
        int sum = 0;
        // cout << endl;
        for(int row = 0; row < rows; ++row) {
          sum += prefix[row][j] - prefix[row][i];
          // cout << i << ' ' << j << ' ' << row << ' ' << sum << endl;
          int diff = sum - k;
          auto it = tmp.lower_bound(diff);
          if(it != tmp.end()) {
            answer = max(answer, sum - *it);
            if(answer == k) return answer;
          }
          tmp.insert(sum);
        }
      }
    }

    return answer;
  }
};
// @lc code=end

