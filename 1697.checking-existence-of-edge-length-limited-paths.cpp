/*
 * @lc app=leetcode id=1697 lang=cpp
 *
 * [1697] Checking Existence of Edge Length Limited Paths
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<int> parent;
  int curIndex;
  void init(int n, vector<vector<int>>& edgeList) {
    curIndex = 0;
    sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[2] < b[2];
    });
    parent.resize(n);
    for(int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }
  
  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;
  }

  void solveToLength(int len, vector<vector<int>>& edgeList) {
    for(; curIndex < edgeList.size() && edgeList[curIndex][2] < len; ++curIndex) {
      merge(edgeList[curIndex][1], edgeList[curIndex][0]);
    }
  }
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    init(n, edgeList);
    int len = queries.size();
    vector<int> order(len);
    vector<bool> answer(len);
    for(int i = 0; i < len; ++i) {
      order[i] = i;
    }
    sort(order.begin(), order.end(), [&](int a, int b) {
      return queries[a][2] < queries[b][2];
    });
    for(auto i : order) {
      solveToLength(queries[i][2], edgeList);
      answer[i] = (find(queries[i][0]) == find(queries[i][1]));
    }
    return answer;
  }
};

// Accepted
// 23/23 cases passed (476 ms)
// Your runtime beats 98.73 % of cpp submissions
// Your memory usage beats 84.81 % of cpp submissions (109.6 MB)
// @lc code=end

