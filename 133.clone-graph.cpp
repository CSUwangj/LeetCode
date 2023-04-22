/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
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
// 22/22 cases passed (7 ms)
// Your runtime beats 61.34 % of cpp submissions
// Your memory usage beats 12.87 % of cpp submissions (9.1 MB)
// @lc code=end
