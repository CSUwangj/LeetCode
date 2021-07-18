/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

#define MOD 1000000007

constexpr auto prefix = []{
  array<int, 1002> arr{1, 1};
  long long cur = 1;
  for(int i = 2; i < 1002; ++i) {
    cur = cur * i % MOD;
    arr[i] = cur;
  }
  return arr;
}();
constexpr auto inv = []{
  array<int, 1002> arr{0, 1};
  for(int i = 2; i < 1002; ++i) {
    arr[i] = ((long long)MOD - MOD / i) * arr[MOD % i] % MOD;
  }
  return arr;
}();
class Node {
public:
  int size;
  bool flag;
  Node *l;
  Node *r;
  Node(int s = 1, Node* a = nullptr, Node* b = nullptr) : 
    size(s), flag(false), l(a), r(b) {}
};

class Solution {
public:
  int numOfWays(vector<int>& nums) {
    int len = nums.size();
    Node p[len + 2];
    for(int i = 0; i < len + 2; ++i) {
      p[i].l = p + i - 1;
      p[i].r = p + i + 1;
    }
    long long answer = prefix[len];
    for(auto it = nums.rbegin(); it != nums.rend(); ++it) {
      Node &cur = p[*it];
      cur.flag = true;
      if(cur.l->flag) {
        cur.l->l->r = &cur;
        cur.size += cur.l->size;
        cur.l = cur.l->l;
      }
      if(cur.r->flag) {
        cur.r->r->l = &cur;
        cur.size += cur.r->size;
        cur.r = cur.r->r;
      }
      if(cur.size > 1) answer = answer * inv[cur.size] % MOD;
      // cout << answer << endl;
    }
    return (answer + MOD - 1) % MOD;
  }
};

// Accepted
// 161/161 cases passed (4 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.55 % of cpp submissions (12.8 MB)
// @lc code=end

