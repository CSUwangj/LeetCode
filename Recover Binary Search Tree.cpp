// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  bool fixed = false;
  void swap(TreeNode *a, TreeNode *b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
  }

  tuple<TreeNode*, TreeNode*> getExtremum(TreeNode *root) {
    if(!root) exit(-1);
    TreeNode *minNode = root, *maxNode = root;
    if(root->left) {
      auto [ minLeftNode, maxLeftNode ] = getExtremum(root->left);
      if(minLeftNode->val < minNode->val) minNode = minLeftNode;
      if(maxLeftNode->val > maxNode->val) maxNode = maxLeftNode;
    }
    if(root->right) {
      auto [ minRightNode, maxRightNode ] = getExtremum(root->right);
      if(minRightNode->val < minNode->val) minNode = minRightNode;
      if(maxRightNode->val > maxNode->val) maxNode = maxRightNode;
    }
    return make_tuple(minNode, maxNode);
  }

public:
  void recoverTree(TreeNode* root) {
    if(!root || fixed) return;
    TreeNode *minRightNode = nullptr, *maxLeftNode = nullptr, *tmp;
    if(root->left) tie(tmp, maxLeftNode) = getExtremum(root->left);
    if(root->right) tie(minRightNode, tmp) = getExtremum(root->right);
    if(maxLeftNode && minRightNode && minRightNode->val < maxLeftNode->val) {
      swap(maxLeftNode, minRightNode);
      fixed = true;
      return;
    } else if(maxLeftNode && maxLeftNode->val > root->val) {
      swap(maxLeftNode, root);
      fixed = true;
      return;
    } else if(minRightNode && minRightNode->val < root->val) {
      swap(minRightNode, root);
      fixed = true;
      return;
    }
    if(root->left) recoverTree(root->left);
    if(root->right) recoverTree(root->right);
  }
};

int main() {
  TreeNode *root = new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr);
  auto sol = Solution();
  sol.recoverTree(root);
  return 0;
}