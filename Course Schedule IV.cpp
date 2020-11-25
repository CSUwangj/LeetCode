// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  vector<vector<bool>> isPrerequisite;
  vector<vector<int>> followUp;
  vector<int> inDegree;
  vector<int> topologicalSort(int n, vector<vector<int>>& prerequisites) {
    inDegree.resize(n);
    fill(inDegree.begin(), inDegree.end(), 0);
    for(auto &p : prerequisites) {
      inDegree[p[1]] += 1;
    }
    queue<int> q;
    for(int i = 0; i < n; ++i) {
      if(inDegree[i] == 0) {
        q.push(i);
      }
    }
    vector<int> result;
    while(q.size()) {
      int cur = q.front();
      q.pop();
      result.push_back(cur);
      for(auto follow: followUp[cur]) {
        inDegree[follow] -= 1;
        if(inDegree[follow] == 0) q.push(follow);
      }
    }
    return result;
  }
  void init(int n, vector<vector<int>>& prerequisites) {
    followUp.resize(n);
    isPrerequisite.resize(n, vector<bool>(n));
    for(auto &p : prerequisites) {
      followUp[p[0]].push_back(p[1]);
    }
  }
public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    init(n, prerequisites);
    auto sortedCourse = topologicalSort(n, prerequisites);
    for(auto course : sortedCourse) {
      for(auto follow : followUp[course]) {
        for(int i = 0; i < n; ++i) {
          isPrerequisite[follow][i] = isPrerequisite[follow][i] | isPrerequisite[course][i];
        }
        isPrerequisite[follow][course] = true;
      }
    }

    vector<bool> answer;
    for(auto &query : queries) {
      answer.push_back(isPrerequisite[query[1]][query[0]]);
    }
    return answer;
  }
};

int main() {
  vector<tuple<int, vector<vector<int>>, vector<vector<int>>>> data = {
    { 2, {{1,0}}, {{0,1},{1,0}}},
    {5,{{0,1},{1,2},{2,3},{3,4}}, {{0,4},{4,0},{1,3},{3,0}}},
    {3, {{1,0},{2,0}}, {{0,1},{2,0}}}
  };
  for(auto &[n, prerequisites, queries]: data) {
    auto sol = Solution();
    auto ans = sol.checkIfPrerequisite(n, prerequisites, queries) ;
    for(auto b : ans) {
      cout << b;
    }
    cout << endl;
  } 
  return 0;
}