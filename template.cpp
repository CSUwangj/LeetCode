// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']' << endl;
}

ostream& operator<<(ostream &out, const bool &b) {
  if(b) {
    out << "true";
  } else {
    out << "false";
  }
  return out;
}

int main() {
  vector<tuple<>> data = {};
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.;
    cout << ans << endl;
  } 
  return 0;
}