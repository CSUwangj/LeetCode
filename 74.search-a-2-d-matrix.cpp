/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size() || !matrix[0].size()) return false;
    int begin = 0, end = matrix.size()-1;
    vector<int> &a = matrix[0];
    while(begin < end) {
      int mid = (begin + end) / 2;
      if(matrix[mid].front() > target) {
        end = mid - 1;
      } else if (matrix[mid].back() < target) {
        begin = mid + 1;
      } else {
        break;
      }
    }
    a = matrix[(begin+end)/2];
    return binary_search(a.begin(), a.end(), target);
  }
};

// Accepted
// 133/133 cases passed (8 ms)
// Your runtime beats 35.04 % of cpp submissions
// Your memory usage beats 78.43 % of cpp submissions (9.4 MB)
// @lc code=end
