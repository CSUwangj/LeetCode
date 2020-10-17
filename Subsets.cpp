#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> answer;
    vector<int> tmp;
    int size = 1 << nums.size();
    for(int i = 0; i < size; ++i) {
      for(int index = 0; i >= (1<<index); ++index) {
        if(i & (1<<index)) tmp.push_back(nums[index]);
      }
      answer.push_back(tmp);
      tmp.clear();
    }
    return answer;
  }
};

int main() {
  vector<vector<int>> data = {
    {1, 2, 3},
    {4, 5, 6, 123},
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.subsets(data);
    cout << '[' << endl;
    for(int i = 0; i < ans.size(); ++i) {
      cout << "  [";
      for(int j = 0; j < ans[i].size(); ++j) {
        cout << ans[i][j] << ", ";
      }
      cout << ']' << endl;
    }
    cout << "]" << endl;
  } 
  return 0;
}