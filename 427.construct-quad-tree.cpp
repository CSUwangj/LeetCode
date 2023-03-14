/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
class Solution {
  Node* construct(vector<vector<int>>& grid, int left, int top, int size) {
    int one = 0;
    for(int i = 0; i < size; ++i) {
      for(int j = 0; j < size; ++j) {
        one += grid[top+i][left+j];
      }
    }
    if(one == 0 || one == size*size) return new Node(one, true);
    int newSize = size/2;
    Node *topLeft = construct(grid, left, top, newSize);
    Node *topRight = construct(grid, left+newSize, top, newSize);
    Node *bottomLeft = construct(grid, left, top+newSize, newSize);
    Node *bottomRight = construct(grid, left+newSize, top+newSize, newSize);
    return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
  }
public:
  Node* construct(vector<vector<int>>& grid) {
    int size = grid.size();
    return construct(grid, 0, 0, size);
  }
};

// Accepted
// 22/22 cases passed (14 ms)
// Your runtime beats 80.07 % of cpp submissions
// Your memory usage beats 59.42 % of cpp submissions (16.1 MB)
// @lc code=end

