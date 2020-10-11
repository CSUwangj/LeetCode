#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  static int stoi(string &num, int &end) {
    int ret = 0;
    while (num.length() > end  && isdigit(num[end])) {
      ret *= 10;
      ret += num[end] - '0';
      end += 1;
    }
    return ret;
  }
  static TreeNode* deserialize(string &data, int &pos) {
    if(data[pos] == 'n') {
      pos += 2;
      return NULL;
    }
    TreeNode* root = new TreeNode(stoi(data, pos));
    pos += 1;
    root->left = deserialize(data, pos);
    root->right = deserialize(data, pos);
    return root;
  }
public:
  // Encodes a tree to a single string.
  static string serialize(TreeNode* root) {
    if(!root) return "n,";
    string tmp = to_string(root->val);
    tmp += ",";
    tmp += serialize(root->left);
    tmp += serialize(root->right);
    return tmp;
  }

  // Decodes your encoded data to tree.
  static TreeNode* deserialize(string data) {
    if(data.length() == 2) return NULL;
    int len = data.length();
    int pos = 0;
    TreeNode* root = new TreeNode(stoi(data, pos));
    pos += 1;
    root->left = deserialize(data, pos);
    root->right = deserialize(data, pos);
    return root;
  }
};

int main() {
  auto root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  auto str = Codec::serialize(root);
  cout << str << endl;
  auto tmp = Codec::deserialize(str);
  return 0;
}