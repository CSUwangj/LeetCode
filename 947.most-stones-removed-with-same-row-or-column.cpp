/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {
  int sz = 0;
  unordered_map<int, int> parent;
  int find(int x) {
    if(parent.count(x) && parent[x] != x) {
      parent[x] = find(parent[x]);
    } else if (!parent.count(x)) {
      parent[x] = x;
      sz += 1;
    }
    return parent[x];
  }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
      parent[x] = y;
      sz -= 1;
    }
  }
public:
  int removeStones(vector<vector<int>>& stones) {
    for(const auto &stone : stones) {
      merge(stone[0], ~stone[1]);
    }
    return stones.size() - sz;
  }
};

// Accepted
// 68/68 cases passed (65 ms)
// Your runtime beats 92.41 % of cpp submissions
// Your memory usage beats 55.74 % of cpp submissions (16.6 MB)
// @lc code=end

