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
const int MOD = 1e9 + 7;
constexpr int qmul(int a, int b, int m) {
  int result = 0;
  while(b) {
    if(b & 1) {
      result += a;
      result %= m;
    }
    a += a;
    a %= m;
    b >>= 1;
  }
  return result;
}
constexpr int qpow(int b, int e, int m) {
  int result = 1;
  while(e) {
    if(e & 1) {
      result = qmul(result, b, m);
    }
    b = qmul(b, b, m);
    e >>= 1;
  }
  return result;
}
constexpr int inv(int a) {
  return qpow(a, MOD - 2, MOD);
}

constexpr int C(int m, int n) {
  int result = 1;
  for(int i = max(m, n - m) + 1; i <= n; ++i) {
    result = qmul(result, i, MOD);
  }
  for(int i = 1; i <= min(m, n - m); ++i) {
    result = qmul(result, inv(i), MOD);
  }
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
    int answer = 1;
    while(q.size()) {
      TreeNode *cur = q.front();
      q.pop();
      if(cur->left && cur->right) {
        answer = qmul(answer, C(nodesCount[cur->left], nodesCount[cur] - 1), MOD);
      }
      if(cur->left) q.push(cur->left);
      if(cur->right) q.push(cur->right);
    }
    return (answer + MOD - 1) % MOD;
  }
};

// Accepted
// 161/161 cases passed (364 ms)
// Your runtime beats 30.85 % of cpp submissions
// Your memory usage beats 87.05 % of cpp submissions (31.1 MB)
// @lc code=end

