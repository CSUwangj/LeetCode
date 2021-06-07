/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 */

// @lc code=start
const int MOD = 1e9 + 7;
struct Node {
  int l, r, y, v;
  bool operator<(const Node& a) const {
    return this->y < a.y;
  }
};
struct SegTree {
  vector<int> lazy;
  vector<int> sum;
  vector<int> mp;
  vector<Node> nodes;
  int n;
  int id(int x) {
    return lower_bound(mp.begin(), mp.end(), x) - mp.begin();
  }

  SegTree(vector<vector<int>>& rectangles) {
    int len = rectangles.size();
    nodes.resize(len * 2);
    mp.resize(len * 2);
    for(int i = 0; i < len; ++i) {
      nodes[i * 2].l = rectangles[i][0];
      nodes[i * 2].r = rectangles[i][2];
      nodes[i * 2].y = rectangles[i][1];
      nodes[i * 2].v = 1;
      mp[i * 2] = rectangles[i][0];
      nodes[i * 2 + 1].l = rectangles[i][0];
      nodes[i * 2 + 1].r = rectangles[i][2];
      nodes[i * 2 + 1].y = rectangles[i][3];
      nodes[i * 2 + 1].v = -1;
      mp[i * 2 + 1] = rectangles[i][2];
    }
    sort(nodes.begin(), nodes.end());
    sort(mp.begin(), mp.end());
    mp.resize(unique(mp.begin(), mp.end()) - mp.begin());
    n = mp.size();
    lazy.resize(n * 8);
    sum.resize(n * 8);
    for(auto &node : nodes) {
      node.l = id(node.l);
      node.r = id(node.r);
    }
  }

  void pull(int l, int r, int o) {
    if(lazy[o] > 0) sum[o] = mp[r + 1] - mp[l];
    else sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2];
  }

  void update(int l, int r, int ql, int qr, int v, int o = 0) {
    cout<< "?" << l << ' '  << r << ' ' << ql << ' ' << qr << endl;
    if(l >= ql && r <= qr) {
      lazy[o] += v;
    } else {
    // cout << l << ' '  << r << ' ' << ql << ' ' << qr << endl;
      int mid = (l + r) >> 1;
      if(mid >= ql) update(l, mid, ql, qr, v, o * 2 + 1);
      if(mid < qr) update(mid + 1, r, ql, qr, v, o * 2 + 2);
    }
    pull(l, r, o);
  }

  int solve() {
    long long prevY = nodes[0].y;
    long long area = 0;
    for(auto &node : nodes) {
      area += sum[0] * (node.y - prevY);
      // cout << node.l << ' ' << node.r << ' ' << sum[0] << ' ' << node.y << ' ' << prevY << endl;
      update(0, n - 1, node.l, node.r - 1, node.v);
      prevY = node.y;
    }
    return area % MOD;
  }
};

class Solution {
public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    auto segTree = SegTree(rectangles);
    return segTree.solve();
  }
};
// @lc code=end

