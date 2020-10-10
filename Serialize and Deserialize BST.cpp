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
public:

    // Encodes a tree to a single string.
    static string serialize(TreeNode* root) {
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            TreeNode *cur = q.front();
            q.pop();
            if(!cur) {
                s += 0xff;
                continue;
            } else if (cur->val < 128) {
                s += cur->val;
            } else {
                s += 0x80 | (cur->val / 0b10000000);
                s += 0x80 | (cur->val % 0b10000000);
            }
            q.push(cur->left);
            q.push(cur->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    static TreeNode* deserialize(string data) {
        if(data.length() == 1) return NULL;
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> q;
        q.push(root);
        int cur_index = 0;
        while(q.size() && cur_index < data.length()) {
            TreeNode *cur = q.front();
            q.pop();
            if(data[cur_index] == 0xff) {
                cur->val = 10001;
                cur_index += 1;
                continue;
            } else if(data[cur_index] < 0b10000000) {
                cur->val = data[cur_index];
                cur_index += 1;
            } else {
                cur->val = data[cur_index]&0b01111111;
                cur->val <<= 7;
                cur->val += data[cur_index+1]&0b01111111;
                cur_index += 2;
            }
            cur->left = new TreeNode(0);
            cur->right = new TreeNode(0);
            q.push(cur->left);
            q.push(cur->right);
        }
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