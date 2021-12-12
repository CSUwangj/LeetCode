/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
// won't work, because disjoint set means two-way
// but jump is one-way action
class Solution {
  int parent[50000];
  void init(int len) {
    for(int i = 0; i < len; ++i) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if(parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px != py) parent[px] = py;
  }
public:
  bool canReach(vector<int>& arr, int start) {
    int len = arr.size();
    init(len);
    for(int i = 0; i < len; ++i) {
      if(i + arr[i] < len) {
        merge(i, i + arr[i]);
      }
      if(i - arr[i] >= 0) {
        merge(i - arr[i], i);
      }
    }
    for(int i = 0; i < len; ++i) {
      if(!arr[i] && find(i) == find(start)) {
        cout << i << ' ' << find(i) << endl;
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
