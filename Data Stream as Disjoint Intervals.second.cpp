#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

// class SummaryRanges {
//   set<pair<int, int>> m;
// public:
//   void addNum(int val) {
//     auto it = m.lower_bound(make_pair(val, val));
//     int new_begin = val, new_end = val;
//     if(it != m.begin() && ((--it)->second+1 < val)) ++it;
//     while(it != m.end() && val+1 >= it->first && val-1 <= it->second) {
//       new_begin = min(new_begin, it->first);
//       new_end = max(new_end, it->second);
//       it = m.erase(it);
//     }
//     m.insert(make_pair(new_begin, new_end));
//   }
  
//   vector<vector<int>> getIntervals() {
//     vector<vector<int>> ans;
//     vector<int> tmp;
//     for(auto it = m.begin(); it != m.end(); ++it) {
//       tmp.push_back(it->first);
//       tmp.push_back(it->second);
//       ans.push_back(tmp);
//       tmp.clear();
//     }
//     return ans;
//   }
// };

class SummaryRanges {
  vector<vector<int>> m;
public:
  void addNum(int val) {
    auto it = lower_bound(m.begin(), m.end(), vector<int>{val, val});
    int new_begin = val, new_end = val;
    if(it != m.begin() && ((*(--it))[1]+1 < val)) ++it;
    while(it != m.end() && val+1 >= (*it)[0] && val-1 <= (*it)[1]) {
      new_begin = min(new_begin, (*it)[0]);
      new_end = max(new_end, (*it)[1]);
      it = m.erase(it);
    }
    m.insert(it, vector<int> {new_begin, new_end});
  }
  
  vector<vector<int>> getIntervals() {
    vector<vector<int>> ans;
    for(auto &interval: m) {
      ans.push_back(interval);
    }
    return ans;
  }
};

void printResult(vector<vector<int>>& intervals){
  cout << intervals.size() << endl;
  cout << '[';
  for(unsigned int i = 0; i < intervals.size();++i) {
    cout << '[' << intervals[i][0] << ", " << intervals[i][1] << ']' << ",]"[i==intervals.size()-1];
  }
  cout << endl;
}

int main() {
  auto sol = SummaryRanges();
  sol.addNum(1);
  auto res = sol.getIntervals();
  cout << res.size() << endl;
  printResult(res);
  sol.addNum(3);
  sol.addNum(0);
  res = sol.getIntervals();
  printResult(res);
  sol.addNum(7);
  res = sol.getIntervals();
  printResult(res);
  sol.addNum(2);
  res = sol.getIntervals();
  printResult(res);
  sol.addNum(6);
  res = sol.getIntervals();
  printResult(res);
  return 0;
}