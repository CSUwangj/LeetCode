/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
class Solution {
public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> products(2, vector<int>(n + 1, INT_MIN));
    
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        int currentProduct = nums1[i] * nums2[j];
        products[i & 1][j + 1] = max({currentProduct, products[((i ^ 1) & 1)][j + 1], products[i & 1][j], currentProduct + max(0, products[((i ^ 1) & 1)][j])});
      }
    }
    return products[(m ^ 1) & 1][n];
  }
};

// Accepted
// 62/62 cases passed (21 ms)
// Your runtime beats 78.51 % of cpp submissions
// Your memory usage beats 91.41 % of cpp submissions (10.1 MB)
// @lc code=end

