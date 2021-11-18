/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
class Solution {
  pair<int, int> rank(
    vector<vector<int>> &matrix,
    vector<int> &index,
    vector<int> &nums,
    int n,
    int a,
    int b
  ) {
    int ra = 0;
    int rb = 0;
    int ja = n - 1;
    int jb = n - 1;
    for(int i = 0; i < n; ++i) {
      while(jb >= 0 && matrix[index[i]][index[jb]] > b) {
        jb -= 1;
      }
      while(ja >= 0 && matrix[index[i]][index[ja]] >= a) {
        ja -= 1;
      }
      ra += ja + 1;
      rb += n - 1 - jb;
      for(int j = jb + 1; j <= ja; ++j) {
        nums.push_back(matrix[index[i]][index[j]]);
      }
    }
    // cout << ra << ' ' << rb << endl;
    return {ra, rb};
  }
  
  pair<int, int> biselect(
    vector<vector<int>> &matrix,
    vector<int> &index,
    int n,
    int k1,
    int k2
  ) {
    // cout << index << endl;
    // cout << 'b' << n << ' '<< k1 << ' '<< k2 << endl;
    if(index.size() <= 2) {
      vector<int> nums;
      for(auto r : index) {
        for(auto c : index) {
          nums.push_back(matrix[r][c]);
        }
      }
      sort(nums.begin(), nums.end());
      return {nums[k1 - 1], nums[k2 - 1]};
    }
    vector<int> _index;
    for(int i = 0; i < n; i += 2) {
      _index.push_back(index[i]);
    }
    if(!(n & 1)) {
      _index.push_back(index[n - 1]);
    }
    int _n = _index.size();
    int _k1 = (n & 1) ? (k1 + 2 * n) / 4 + 1 : n + 1 + (k1 + 3) / 4;
    int _k2 = (k2 + 3) / 4;
    auto [a, b] = biselect(matrix, _index, _n, _k1, _k2);
    vector<int> nums;
    // cout << a << ' ' << b << endl;
    auto [ra, rb] = rank(matrix, index, nums, n, a, b);
    // cout << nums << endl;
    // cout <<ra << ' ' << k1 << ' ' << rb << ' '<< k2 << endl;
    int x;
    int y;
    if(ra < k1) {
      x = a;
    } else if (k1 + rb - n * n <= 0) {
      x = b;
    } else {
      nth_element(nums.begin(), nums.begin() + k1 + rb - n * n - 1, nums.end());
      x = nums[k1 + rb - n * n - 1];
    }
    if(ra < k2) {
      y = a;
    } else if (k2 + rb - n * n <= 0) {
      y = b;
    } else {
      nth_element(nums.begin(), nums.begin() + k2 + rb - n * n - 1, nums.end());
      y = nums[k2 + rb - n * n - 1];
    }
    // cout << "#" << x << ' '<< y<< endl;
    return {x, y};
  }
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int start = max(0, k - n * n + n - 1);
    k -= n * n - (n - start) * (n - start);
    vector<int> index;
    for(int i = start; i < min(n, start + k); ++i) {
      index.push_back(i);
    }
    return biselect(matrix, index, index.size(), k, k).first;
  }
};

// Accepted
// 86/86 cases passed (24 ms)
// Your runtime beats 95.06 % of cpp submissions
// Your memory usage beats 55.66 % of cpp submissions (13.7 MB)
// @lc code=end

