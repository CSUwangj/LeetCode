/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Node {
  int l, r, y, v;
  bool operator<(const Node& a) const {
    return this->y < a.y;
  }
};
Node segTree[400];
int sum[1600];
int lazy[1600];
int mp[200];
int mappingLen;
int id(int x) {
  return lower_bound(mp, mp + mappingLen, x) - mp;
}
int query() {
  return sum[0];
}
void pull(int l, int r, int o) {
  // cout << "P " << mp[l] << ' ' << mp[r] << endl;
  if(lazy[o] > 0) sum[o] = mp[r + 1] - mp[l];
  else sum[o] = sum[o * 2 + 1] + sum[o * 2 + 2]; 
}
void update(int l, int r, int ql, int qr, int v, int o = 0) {
  if(ql <= l && r <= qr) {
    lazy[o] += v;
  } else {
    int mid = (l + r) >> 1;
    if(ql <= mid) update(l, mid, ql, qr, v, o * 2 + 1);
    if(qr > mid) update(mid + 1, r, ql, qr, v, o * 2 + 2);
  }
  // cout << "#" << o << ' ' << lazy[o] << ' ';
  pull(l, r, o);
  // cout <<"#" << o << ' '<< sum[o] << endl;
}
const int MOD = 1e9 + 7;
class Solution {
  int n;
  long long prevY;
  void init(vector<vector<int>>& rectangles) {
    n = rectangles.size();
    for(int i = 0; i < n ; ++i) {
      segTree[i * 2].l = rectangles[i][0];
      segTree[i * 2].r = rectangles[i][2];
      segTree[i * 2].y = rectangles[i][1];
      segTree[i * 2].v = 1;
      segTree[i * 2 + 1].l = rectangles[i][0];
      segTree[i * 2 + 1].r = rectangles[i][2];
      segTree[i * 2 + 1].y = rectangles[i][3];
      segTree[i * 2 + 1].v = -1;
      mp[i * 2] = rectangles[i][0];
      mp[i * 2 + 1] = rectangles[i][2];
    }
    sort(segTree, segTree + n * 2);
    sort(mp, mp + n * 2);
    mappingLen = unique(mp, mp + n * 2) - mp;
    for(int i = 0; i < 2 * n; ++i) {
      segTree[i].l = id(segTree[i].l);
      segTree[i].r = id(segTree[i].r);
    }
    prevY = segTree[0].y;
  }
  int solve() {
    long long answer = 0;
    // cout << mappingLen << endl;
    for(int i = 0; i < n * 2; ++i) {
      // cout << sum[0] << ' ' << prevY << ' ' << segTree[i].y << endl;
      // cout << mp[segTree[i].l] << ' '<< mp[segTree[i].r] << ' ' << segTree[i].v <<endl;
      answer += query() * (segTree[i].y - prevY);
      update(0, mappingLen - 1, segTree[i].l, segTree[i].r - 1, segTree[i].v);
      prevY = segTree[i].y;
    }
    answer %= MOD;
    return answer;
  }
public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    init(rectangles);
    return solve();
  }
};

// Accepted
// 78/78 cases passed (4 ms)
// Your runtime beats 99.6 % of cpp submissions
// Your memory usage beats 99.6 % of cpp submissions (8.3 MB)
// @lc code=end

