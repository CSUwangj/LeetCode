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

constexpr int qpow(long long b, int e) {
  long long result = 1;
  while(e) {
    if(e & 1) {
      result = result * b % MOD;
    }
    b = b * b % MOD;
    e >>= 1;
  }
  return result;
}

int _i[1000];
int _c[1000][500];

constexpr int inv(int a) {
  if(_i[a]) return _i[a];
  return _i[a] = qpow(a, MOD - 2);
}
constexpr int C(int m, int n) {
  m = min(m, n - m);
  if(_c[n][m]) return _c[n][m];
  long long result = 1;
  for(int i = m + 1; i <= n; ++i) {
    result = result * i % MOD;
  }
  for(int i = 1; i <= n - m; ++i) {
    result = result * inv(i) % MOD;
  }
  _c[n][m] = result;
  return result;
}

class Solution {
  unordered_map<TreeNode*, int> nodesCount;
  TreeNode *insertBST(TreeNode *root, int val) {
    if(!root) return new TreeNode(val);
    if(root->val < val) {
      root->right = insertBST(root->right, val);
    } else {
      root->left = insertBST(root->left, val);
    }
    return root;
  }
  void countNodes(TreeNode *root) {
    if(!root) return;
    countNodes(root->left);
    countNodes(root->right);
    nodesCount[root] = nodesCount[root->left] + nodesCount[root->right] + 1;
  }
public:
  int numOfWays(vector<int>& nums) {
    TreeNode *root = nullptr;
    for(auto i : nums) {
      root = insertBST(root, i);
    }
    countNodes(root);
    queue<TreeNode*> q;
    q.push(root);
    long long answer = 1;
    while(q.size()) {
      TreeNode *cur = q.front();
      q.pop();
      if(cur->left && cur->right) {
        answer = answer * C(nodesCount[cur->left], nodesCount[cur] - 1) % MOD;
      }
      if(cur->left) q.push(cur->left);
      if(cur->right) q.push(cur->right);
    }
    return (answer + MOD - 1) % MOD;
  }
};


// Accepted
// 161/161 cases passed (40 ms)
// Your runtime beats 93.94 % of cpp submissions
// Your memory usage beats 87.05 % of cpp submissions (32 MB)
// @lc code=end

