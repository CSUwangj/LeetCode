/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
      val = 0;
      neighbors = vector<Node*>();
    }
    Node(int _val) {
      val = _val;
      neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
      val = _val;
      neighbors = _neighbors;
    }
};
*/

class Solution {
  map<int, Node*> nodes;
public:
  Node* cloneGraph(Node* node) {
    if(!node) return node;
    Node *newNode = new Node(node->val);
    nodes[node->val] = newNode;
    for(auto neighbor : node->neighbors) {
      if(nodes.count(neighbor->val)) {
        newNode->neighbors.push_back(nodes[neighbor->val]);
      } else {
        newNode->neighbors.push_back(cloneGraph(neighbor));
      }
    }
    return newNode;
  }
};

// Accepted
// 22/22 cases passed (15 ms)
// Your runtime beats 14.73 % of cpp submissions
// Your memory usage beats 59.68 % of cpp submissions (8.7 MB)
// @lc code=end
