/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Vector {
  int x;
  int y;

  Vector(int x = 0, int y = 0) : x(x), y(y) {}
  Vector(const vector<int> &v) : x(v[0]), y(v[1]) { }

  friend ostream& operator<<(ostream &os, const Vector &v) {
    os << '(' << v.x << ',' << v.y << ')';
    return os;
  }
  bool operator<(const Vector& v) const {
    return this->x < v.x || (this->x == v.x && this->y < v.y);
  }
  Vector operator+(const Vector& v) const {
    return Vector(this->x + v.x, this->y + v.y);
  }
  Vector operator-(const Vector& v) const {
    return Vector(this->x - v.x, this->y - v.y);
  }
};

int cross(const Vector& a, const Vector& b) {
  return a.x * b.y - b.x * a.y;
}
int dot(const Vector& a, const Vector& b) {
  return a.x * b.x + a.y * b.y;
}
class Solution {
public:
  vector<vector<int>> outerTrees(vector<vector<int>>& treesVector) {
    vector<Vector> trees;
    for(const auto &tree : treesVector) {
      trees.push_back(Vector(tree));
    }
    sort(trees.begin(), trees.end());
    int len = trees.size();
    int size = 1;
    vector<int> st{0};
    for(int i = 1; i < len; ++i) {
      while(size > 1 && cross(trees[st[size - 1]] - trees[st[size - 2]], trees[i] - trees[st[size - 1]]) < 0) {
        st.pop_back();
        size -= 1;
      }
      st.push_back(i);
      size += 1;
    }
    int tmp = size;
    for(int i = len - 2; i >= 0; --i) {
      while(size > tmp && cross(trees[st[size - 1]] - trees[st[size - 2]], trees[i] - trees[st[size - 1]]) < 0) {
        st.pop_back();
        size -= 1;
      }
      st.push_back(i);
      size += 1;
    }
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    vector<vector<int>> answer;
    for(auto i : st) {
      answer.push_back({trees[i].x, trees[i].y});
    }
    return answer;
  }
};

// Accepted
// 84/84 cases passed (71 ms)
// Your runtime beats 62.22 % of cpp submissions
// Your memory usage beats 76.3 % of cpp submissions (20.5 MB)
// @lc code=end

